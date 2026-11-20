import hashlib
import json
from pathlib import Path
import struct
import tempfile
import unittest
from cubebaby_mod.ir_writer import IRWriter, save_backup, load_ir_file
from cubebaby_mod.protocol import (
    decode_packet, encode_packet, slot_with_distance, parse_ir_slot, IR_SLOT_SIZE,
)
from test_ir_reader import INFO, SLOT_DATA

ORIGINAL = bytes.fromhex('01 00 00 00 00 00 40 3f')+SLOT_DATA[8:]
SECTOR = ORIGINAL+bytes((i*7)%256 for i in range(4096-len(ORIGINAL)))
BASE = 0x6a000


class Pedal:
    def __init__(self, initial=SECTOR):
        self.memory = bytearray(initial)
        self.requests = []
        self.erase_count = 0
    def respond(self, raw):
        packet = decode_packet(raw)
        self.requests.append(packet)
        payload = packet['payload']
        if packet['opcode'] not in (0x23, 0x21, 0x22) or payload[0] != 0:
            raise AssertionError('Unexpected operation')
        address = int.from_bytes(payload[1:5], 'little')
        index = address-BASE
        if not 0 <= index < 4096: raise AssertionError('Outside selected sector')
        if packet['opcode'] == 0x23:
            size = int.from_bytes(payload[5:8], 'little')
            if size > 113: raise AssertionError('Read exceeds model limit')
            return decode_packet(encode_packet(0x23, payload+bytes(self.memory[index:index+size])))
        if packet['opcode'] == 0x21:
            if index: raise AssertionError('Unaligned erase')
            self.erase_count += 1
            self.memory[:] = b'\xff'*4096
        else:
            size = int.from_bytes(payload[5:8], 'little')
            if size > 128 or len(payload[8:]) != size: raise AssertionError('Invalid write')
            self.memory[index:index+size] = payload[8:]
        return decode_packet(encode_packet(0, b'\0'))


def run_writer(writer, pedal, clock):
    for _ in range(200):
        if writer.complete: return
        request = writer.next_request()
        if request is None:
            clock[0] += .11
            continue
        writer.accept(pedal.respond(request.data))
    raise AssertionError('Writer did not terminate')


class WriterTests(unittest.TestCase):
    def test_distance_preserves_header_coefficients_and_sector_tail(self):
        desired = slot_with_distance(ORIGINAL, 74)
        self.assertEqual(desired[:4], ORIGINAL[:4])
        self.assertEqual(desired[8:], ORIGINAL[8:])
        self.assertEqual(struct.unpack_from('<f', desired, 4)[0], struct.unpack('<f', struct.pack('<f', .74))[0])
        pedal = Pedal(); clock = [0]; backups = []
        def backup(a, slot, data):
            self.assertEqual(pedal.erase_count, 0)
            backups.append((a, slot, data)); return '/backup.json'
        writer = IRWriter(INFO, 1, ORIGINAL, desired, backup, clock=lambda: clock[0])
        run_writer(writer, pedal, clock)
        self.assertTrue(writer.verified)
        self.assertEqual(backups, [(BASE, 1, SECTOR)])
        self.assertEqual(bytes(pedal.memory), desired+SECTOR[IR_SLOT_SIZE:])
        opcodes = [p['opcode'] for p in pedal.requests]
        self.assertEqual(opcodes, [0x23]*37+[0x21]+[0x22]*32+[0x23]*37)
        self.assertEqual(pedal.erase_count, 1)

    def test_stale_snapshot_prevents_erase(self):
        pedal = Pedal(b'\x00'+SECTOR[1:]); clock=[0]
        writer=IRWriter(INFO, 1, ORIGINAL, slot_with_distance(ORIGINAL, 74), lambda *a: '/backup', clock=lambda:clock[0])
        with self.assertRaisesRegex(RuntimeError, 'berubah'): run_writer(writer, pedal, clock)
        self.assertEqual(pedal.erase_count, 0)
        self.assertFalse(writer.modified)

    def test_backup_failure_prevents_erase(self):
        pedal=Pedal(); clock=[0]
        def fail(*args): raise OSError('disk full')
        writer=IRWriter(INFO, 1, ORIGINAL, slot_with_distance(ORIGINAL, 74), fail, clock=lambda:clock[0])
        with self.assertRaises(OSError): run_writer(writer, pedal, clock)
        self.assertEqual(pedal.erase_count, 0)
        self.assertEqual(bytes(pedal.memory), SECTOR)

    def test_no_change_does_not_erase_or_make_backup(self):
        pedal=Pedal(); clock=[0]
        def fail(*args): raise AssertionError('No backup required for unchanged data')
        writer=IRWriter(INFO, 1, ORIGINAL, ORIGINAL, fail, clock=lambda:clock[0])
        run_writer(writer, pedal, clock)
        self.assertTrue(writer.no_change)
        self.assertFalse(writer.modified)
        self.assertEqual(pedal.erase_count, 0)

    def test_verify_mismatch_does_not_report_success(self):
        pedal=Pedal(); clock=[0]
        writer=IRWriter(INFO, 1, ORIGINAL, slot_with_distance(ORIGINAL, 74), lambda *a:'/backup', clock=lambda:clock[0])
        while writer.state != 'verify':
            request=writer.next_request()
            if request is None: clock[0]+=.11; continue
            writer.accept(pedal.respond(request.data))
        pedal.memory[-1] ^= 1
        with self.assertRaisesRegex(RuntimeError, 'Verifikasi gagal'): run_writer(writer,pedal,clock)
        self.assertFalse(writer.complete)
        self.assertFalse(writer.verified)
        self.assertEqual(writer.backup_path,'/backup')

    def test_negative_ack_aborts_without_retry(self):
        pedal=Pedal();clock=[0]
        writer=IRWriter(INFO,1,ORIGINAL,slot_with_distance(ORIGINAL,74),lambda *a:'/backup',clock=lambda:clock[0])
        while writer.state != 'erase':
            req=writer.next_request();writer.accept(pedal.respond(req.data))
        req=writer.next_request();pedal.respond(req.data)
        with self.assertRaisesRegex(RuntimeError, 'kode 5'):
            writer.accept(decode_packet(encode_packet(0,b'\x05')))
        self.assertIsNone(writer.next_request())
        self.assertEqual(pedal.erase_count,1)
        self.assertFalse(any(p['opcode']==0x22 for p in pedal.requests))

    def test_wrong_packet_and_duplicate_request_do_not_advance(self):
        writer=IRWriter(INFO,1,ORIGINAL,slot_with_distance(ORIGINAL,74),lambda *a:'/backup')
        req=writer.next_request()
        self.assertIsNone(writer.next_request())
        self.assertFalse(writer.accept(decode_packet(encode_packet(0,b'\0'))))
        self.assertEqual(len(writer.buffer),0)
        self.assertIsNotNone(writer.awaiting)

    def test_unknown_write_profile_rejected(self):
        altered=dict(INFO, fields_u32=[2]+INFO['fields_u32'][1:])
        with self.assertRaises(ValueError): IRWriter(altered,1,ORIGINAL,ORIGINAL,lambda *a:'/backup')

    def test_durable_backup_load_and_exact_full_sector_restore(self):
        with tempfile.TemporaryDirectory() as tmp:
            path=save_backup(tmp,BASE,1,SECTOR)
            saved=json.loads(Path(path).read_text())
            self.assertEqual(saved['sha256'],hashlib.sha256(SECTOR).hexdigest())
            snapshot,sector=load_ir_file(path,BASE,1)
            self.assertEqual(sector,SECTOR)
            changed=slot_with_distance(ORIGINAL,20)+b'\xff'*(4096-IR_SLOT_SIZE)
            pedal=Pedal(changed);clock=[0]
            writer=IRWriter(INFO,1,changed[:IR_SLOT_SIZE],sector[:IR_SLOT_SIZE],lambda *a:'/new-backup',
                            desired_sector=sector,clock=lambda:clock[0])
            run_writer(writer,pedal,clock)
            self.assertEqual(bytes(pedal.memory),SECTOR)
            self.assertTrue(writer.verified)
            with self.assertRaises(ValueError):load_ir_file(path,BASE+4096,2)
            saved['sha256']='0'*64;Path(path).write_text(json.dumps(saved))
            with self.assertRaises(ValueError):load_ir_file(path,BASE,1)

    def test_ir_json_validated_from_raw_not_declared_coefficients(self):
        with tempfile.TemporaryDirectory() as tmp:
            path=Path(tmp)/'ir.json'
            source=parse_ir_slot(ORIGINAL,1,BASE);source['device_code']=20230
            source['coefficients']=[999]
            path.write_text(json.dumps(source))
            parsed,sector=load_ir_file(path,BASE,1)
            self.assertEqual(len(parsed['coefficients']),512)
            self.assertEqual(parsed['distance_percent'],75)
            self.assertIsNone(sector)
            source['raw_hex']='ff '*IR_SLOT_SIZE;path.write_text(json.dumps(source))
            with self.assertRaises(ValueError):load_ir_file(path,BASE,1)

from pathlib import Path
import struct
import unittest
from cubebaby_mod.ir_reader import IRReader
from cubebaby_mod.protocol import (
    IR_SLOT_SIZE, decode_packet, encode_packet, parse_device_info,
    parse_ir_slot, ir_slot_address, read_request,
)

INFO_PACKET = bytes.fromhex((Path(__file__).parent/'fixtures/device_info_20230.hex').read_text())
INFO = parse_device_info(decode_packet(INFO_PACKET))
SLOT_DATA = struct.pack('<I513f', 0, 0.5, *[i/1024 for i in range(512)])


def respond(reader, data=SLOT_DATA, wrong_address=False):
    request = decode_packet(reader.next_request())
    payload = request['payload']
    if wrong_address:
        address = int.from_bytes(payload[1:5], 'little')+1
        payload = payload[:1]+address.to_bytes(4, 'little')+payload[5:]
    length = int.from_bytes(payload[5:8], 'little')
    start = len(reader.buffer)
    return decode_packet(encode_packet(0x23, payload+data[start:start+length]))


class IRReaderTests(unittest.TestCase):
    def test_real_device_info_fixture(self):
        self.assertEqual(INFO['device_code'], 20230)
        self.assertEqual(INFO['fields_u32'], [1, 20230, 196608, 393216, 430080])
        self.assertEqual(ir_slot_address(INFO, 0), 0x69000)
        self.assertEqual(ir_slot_address(INFO, 7), 0x70000)

    def test_complete_slot_reads_19_bounded_chunks(self):
        reader = IRReader(INFO, 7)
        requests = []
        while not reader.complete:
            packet = decode_packet(reader.next_request())
            requests.append(packet)
            reader.accept(respond(reader))
        self.assertEqual(len(requests), 19)
        self.assertEqual([int.from_bytes(p['payload'][1:5], 'little') for p in requests],
                         [0x70000+i*113 for i in range(19)])
        self.assertEqual([int.from_bytes(p['payload'][5:8], 'little') for p in requests], [113]*18+[22])
        self.assertTrue(all(p['opcode'] == 0x23 and p['payload'][0] == 0 for p in requests))
        snapshot = reader.snapshot()
        self.assertEqual(bytes.fromhex(snapshot['raw_hex']), SLOT_DATA)
        self.assertEqual(snapshot['slot'], 8)
        self.assertAlmostEqual(snapshot['distance_percent'], 50)
        self.assertEqual(len(snapshot['coefficients']), 512)
        self.assertAlmostEqual(snapshot['coefficients'][-1], 511/1024)

    def test_bad_response_does_not_advance(self):
        reader = IRReader(INFO, 0)
        for field in ['opcode', 'address', 'length', 'region']:
            packet = respond(reader)
            if field == 'opcode': packet['opcode'] = 0x22
            else:
                payload = bytearray(packet['payload'])
                payload[{'address': 1, 'length': 5, 'region': 0}[field]] ^= 1
                packet['payload'] = bytes(payload)
            with self.assertRaises(ValueError): reader.accept(packet)
            self.assertEqual(reader.progress, (0, IR_SLOT_SIZE))

    def test_partial_data_cannot_be_exported_as_snapshot(self):
        reader = IRReader(INFO, 0)
        reader.accept(respond(reader))
        with self.assertRaises(ValueError): reader.snapshot()

    def test_unsupported_model_or_invalid_slot_rejected(self):
        for info, slot in [(dict(INFO, device_code=10030), 0), (INFO, -1), (INFO, 8)]:
            with self.assertRaises(ValueError): IRReader(info, slot)

    def test_invalid_storage_base_rejected(self):
        for base in [0, -4096, 0x69001, 0xfffff000, 0x7f000]:
            fields = INFO['fields_u32'][:]
            fields[4] = base
            with self.assertRaises(ValueError): IRReader(dict(INFO, fields_u32=fields), 0)

    def test_erased_or_nan_slot_keeps_raw_without_claiming_values(self):
        for raw in [b'\xff'*IR_SLOT_SIZE, SLOT_DATA[:4]+struct.pack('<f', float('nan'))+SLOT_DATA[8:]]:
            snapshot = parse_ir_slot(raw, 0, 0x69000)
            self.assertFalse(snapshot['format_recognized'])
            self.assertNotIn('coefficients', snapshot)
            self.assertEqual(bytes.fromhex(snapshot['raw_hex']), raw)

    def test_read_request_bounds(self):
        for args in [(0, 0, 0), (0, 0, 114), (0, -1, 1), (0, 0xffffffff, 2), (256, 0, 1)]:
            with self.assertRaises(ValueError): read_request(*args)

import unittest
from cubebaby_mod.memory_job import MemoryJob, PreviewJob, DistanceJob, read_steps, write_steps
from cubebaby_mod.presets import FACTORY_PRESETS, edit_preset, live_address, validate_presets
from cubebaby_mod.protocol import decode_packet, encode_packet
from test_ir_writer import ORIGINAL


def packet(op, payload):
    return decode_packet(encode_packet(op, payload))


class MemoryTests(unittest.TestCase):
    def test_all_256_control_observations_are_accepted_but_never_echoed_as_commands(self):
        for value in range(256):
            with self.subTest(value=value):
                for job in (PreviewJob(ORIGINAL, None), DistanceJob(70, None)):
                    query = decode_packet(job.next_request().data)
                    self.assertTrue(job.accept(packet(0x23, query['payload']+bytes([value]))))
                    while isinstance(job, PreviewJob) and job.phase == 'preflight':
                        query = decode_packet(job.next_request().data)
                        size = int.from_bytes(query['payload'][5:8], 'little')
                        job.accept(packet(0x23, query['payload']+b'\0'*size))
                    commands = [decode_packet(s.request.data)['payload'][8:]
                                for s in job.steps if s.kind == 'ack' and s.address == 0x764]
                    self.assertEqual(commands, [b'\0', b'\1'])

    def test_preview_reads_backup_uploads_then_verifies_bytes_without_checksum_queries(self):
        job = PreviewJob(ORIGINAL, lambda result: None)
        writes = []
        checks = []
        memory = {i: 0 for i in range(0x764, 0x768+2052)}
        memory[0x764] = 1
        while not job.complete:
            req = job.next_request()
            self.assertIsNone(job.next_request())
            parsed = decode_packet(req.data)
            p = parsed['payload']; region = p[0]; address = int.from_bytes(p[1:5], 'little')
            self.assertEqual(region, 4)
            if parsed['opcode'] == 0x22:
                data = p[8:]
                self.assertLessEqual(len(data), 128)
                for i, byte in enumerate(data): memory[address+i] = byte
                writes.append((address, data))
                ack = packet(0, b'\0')
            elif parsed['opcode'] == 0x23:
                size = int.from_bytes(p[5:8], 'little')
                ack = packet(0x23, p+bytes(memory[address+i] for i in range(size)))
            else:
                self.assertEqual(parsed['opcode'], 0x24)
                size = int.from_bytes(p[5:9], 'little')
                checks.append((address, size))
                checksum = sum(memory[address+i] for i in range(size))&65535
                ack = packet(0x24, p+checksum.to_bytes(2, 'little'))
            self.assertFalse(job.accept(packet(0x11, b'unrelated')))
            self.assertTrue(job.accept(ack))
        self.assertEqual(writes[0], (0x764, b'\0'))
        self.assertEqual(writes[-1], (0x764, b'\1'))
        self.assertEqual(bytes(memory[0x768+i] for i in range(2052)), ORIGINAL[4:])
        self.assertEqual(checks, [])
        self.assertEqual(job.original_gate, b'\1')
        self.assertEqual(job.original_data, b'\0'*2052)
        self.assertEqual(bytes(job.results['after']), ORIGINAL[4:])

    def test_checksum_mismatch_never_advances_to_reenable_gate(self):
        job = MemoryJob(write_steps(4, 0x768, b'abc', checksum=True), None, 'RAM')
        job.next_request(); job.accept(packet(0, b'\0'))
        query = decode_packet(job.next_request().data)
        with self.assertRaisesRegex(RuntimeError, 'Checksum'):
            job.accept(packet(0x24, query['payload']+b'\0\0'))
        self.assertFalse(job.complete)

    def test_readback_mismatch_rejects_success(self):
        job = MemoryJob(read_steps(5, 0, 3, 'preset', b'abc'), None, 'Save')
        job.next_request()
        with self.assertRaisesRegex(RuntimeError, 'Verifikasi'):
            job.accept(packet(0x23, b'\5'+b'\0'*4+b'\3\0\0'+b'abd'))

    def test_wrong_address_and_negative_ack_are_not_success(self):
        job = MemoryJob(write_steps(5, 0x80000010, b'\1'), None, 'Effects')
        request = decode_packet(job.next_request().data)
        self.assertEqual(request['payload'][:8], bytes.fromhex('05 10 00 00 80 01 00 00'))
        with self.assertRaises(RuntimeError): job.accept(packet(0, b'\1'))
        self.assertFalse(job.complete)

    def test_preset_edits_preserve_reserved_and_other_presets(self):
        raw = bytearray(FACTORY_PRESETS)
        raw[13:16] = b'\xaa\xbb\xcc'
        edited = edit_preset(raw, 1, 5, 100)
        self.assertEqual(edited[:21], raw[:21])
        self.assertEqual(edited[21], 100)
        self.assertEqual(edited[22:], raw[22:])
        self.assertEqual(live_address(1, 5), 0x80000015)
        with self.assertRaises(ValueError): edit_preset(raw, 1, 13, 0)
        with self.assertRaises(ValueError): edit_preset(raw, 0, 1, 8)
        raw[0] = 9
        with self.assertRaises(ValueError): validate_presets(raw)

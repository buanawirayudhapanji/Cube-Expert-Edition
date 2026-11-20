import unittest
from cubebaby_mod.codec import pack_7bit
from cubebaby_mod.protocol import identity_request, decode_packet


class ProtocolTests(unittest.TestCase):
    def test_identity_request_fixed_assembly_vector(self):
        # Independent 56-bit little-endian regrouping of 00 59 11 00 00 00 FF.
        self.assertEqual(identity_request(), bytes.fromhex('F0 00 32 45 00 00 00 40 7F F7'))
        parsed = decode_packet(identity_request())
        self.assertEqual(parsed['opcode'], 0x11)
        self.assertEqual(parsed['payload'], b'')

    def test_response_checksum_and_length(self):
        payload = b'CubeBaby'
        raw = b'\x00\x59\x11' + len(payload).to_bytes(3, 'little') + payload
        raw += bytes([~sum(payload) & 0xff])
        packet = b'\xf0'+pack_7bit(raw)+b'\xf7'
        self.assertEqual(decode_packet(packet)['payload'], payload)
        for invalid in [raw[:-1], raw[:-1]+bytes([raw[-1]^1]), b'\x01'+raw[1:]]:
            with self.assertRaises(ValueError):
                decode_packet(b'\xf0'+pack_7bit(invalid)+b'\xf7')

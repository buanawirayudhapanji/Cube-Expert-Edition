import random
import unittest
from cubebaby_mod.codec import pack_7bit, unpack_7bit


class CodecTests(unittest.TestCase):
    def test_vectors_from_bit_order(self):
        for raw, encoded in [(b'', b''), (b'\xff', b'\x7f\x01'),
                             (b'\x01\x02', b'\x01\x04\x00'),
                             (b'\xff'*7, b'\x7f'*8)]:
            self.assertEqual(pack_7bit(raw), encoded)
            self.assertEqual(unpack_7bit(encoded), raw)

    def test_roundtrip_packet_boundaries(self):
        rng = random.Random(2026)
        for size in [1, 2, 6, 7, 8, 63, 64, 127, 128, 255, 256, 1024]:
            raw = rng.randbytes(size)
            packed = pack_7bit(raw)
            self.assertEqual(len(packed), (size*8+6)//7)
            self.assertTrue(all(value < 128 for value in packed))
            self.assertEqual(unpack_7bit(packed), raw)

    def test_invalid_bytes_and_padding(self):
        for bad in [b'\x80', b'\x00', b'\x7f\x7f']:
            with self.assertRaises(ValueError):
                unpack_7bit(bad)

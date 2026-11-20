from pathlib import Path
import struct
import tempfile
import unittest
import wave
from cubebaby_mod.wav_ir import load_wav


class WavTests(unittest.TestCase):
    def wav(self, tmp, width, channels, samples, rate=48000):
        path = Path(tmp)/'ir.wav'
        with wave.open(str(path), 'wb') as out:
            out.setparams((channels, width, rate, 0, 'NONE', ''))
            out.writeframes(b''.join(v.to_bytes(width, 'little', signed=True) for v in samples))
        return path

    def test_pcm16_stereo_uses_first_channel_and_zero_pads(self):
        with tempfile.TemporaryDirectory() as tmp:
            ir = load_wav(self.wav(tmp, 2, 2, [32767, 0, -32768, 0]))
        self.assertEqual(ir.coefficients[:2], (1., -32768/32767))
        self.assertEqual(ir.coefficients[2:], (0.,)*510)
        self.assertEqual((ir.rate, ir.channels, ir.bits), (48000, 2, 16))
        raw = ir.record(b'\0'*4, 75)
        self.assertEqual(len(raw), 2056)
        self.assertEqual(raw[:8], struct.pack('<If', 0, .75))

    def test_pcm24_clips_length_without_resampling_or_normalizing(self):
        with tempfile.TemporaryDirectory() as tmp:
            ir = load_wav(self.wav(tmp, 3, 1, [8388607, -8388608]+[4194304]*600, 44100))
        self.assertEqual(len(ir.coefficients), 512)
        self.assertEqual(ir.coefficients[:3], (8388607/8388608, -1., .5))
        self.assertEqual(ir.frames, 602)
        self.assertEqual(ir.rate, 44100)

    def test_unsupported_pcm8_and_invalid_wave_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = self.wav(tmp, 1, 1, [0])
            with self.assertRaises(ValueError): load_wav(path)
            path.write_bytes(b'RIFFbroken')
            with self.assertRaises(ValueError): load_wav(path)

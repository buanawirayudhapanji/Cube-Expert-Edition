import math
from pathlib import Path
import struct
import tempfile
import unittest
from cubebaby_mod.convert_ir import convert_wav


def wav(path, code, bits, rate, channels, data, extensible=False):
    width = bits//8; align = width*channels
    fmt = struct.pack('<HHIIHH', 0xfffe if extensible else code, channels, rate, rate*align, align, bits)
    if extensible:
        fmt += struct.pack('<HHI', 22, bits, 0)+struct.pack('<I', code)+bytes.fromhex('00001000800000aa00389b71')
    body = b'WAVEfmt '+struct.pack('<I', len(fmt))+fmt+b'data'+struct.pack('<I', len(data))+data+(b'\0' if len(data)%2 else b'')
    path.write_bytes(b'RIFF'+struct.pack('<I', len(body))+body)
    return path


class ConversionTests(unittest.TestCase):
    def test_pcm32_stereo_downmix_and_float64_extensible(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp)/'ir.wav'
            result = convert_wav(wav(path, 1, 32, 48000, 2, struct.pack('<4i', 1<<30, 0, -(1<<30), 0)))
            self.assertEqual(result.wave.coefficients[:2], (.25, -.25))
            self.assertEqual(len(result.wave.coefficients), 512)
            result = convert_wav(wav(path, 3, 64, 48000, 1, struct.pack('<2d', .125, -.5), True))
            self.assertEqual(result.wave.coefficients[:2], (.125, -.5))

    def test_resampling_preserves_tone_frequency_at_44100(self):
        with tempfile.TemporaryDirectory() as tmp:
            source = [math.sin(2*math.pi*1000*i/44100)*.3 for i in range(1200)]
            path = wav(Path(tmp)/'ir.wav', 3, 32, 44100, 1, struct.pack('<1200f', *source))
            result = convert_wav(path)
            reference = [math.sin(2*math.pi*1000*i/48000)*.3 for i in range(512)]
            rms = math.sqrt(sum((result.wave.coefficients[i]-reference[i])**2 for i in range(64, 480))/416)
            self.assertLess(rms, .002)
            self.assertEqual(result.wave.rate, 48000)
            self.assertGreater(result.converted_frames, 512)

    def test_downsampling_filters_above_nyquist(self):
        with tempfile.TemporaryDirectory() as tmp:
            values = [math.sin(2*math.pi*40000*i/96000)*.5 for i in range(1600)]
            path = wav(Path(tmp)/'ir.wav', 3, 32, 96000, 1, struct.pack('<1600f', *values))
            result = convert_wav(path)
            rms = math.sqrt(sum(v*v for v in result.wave.coefficients[64:480])/416)
            self.assertLess(rms, .005)

    def test_overrange_float_attenuates_without_boosting_quiet_ir(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp)/'ir.wav'
            converted = convert_wav(wav(path, 3, 32, 48000, 1, struct.pack('<2f', 2., -4.)))
            self.assertEqual(converted.wave.coefficients[:2], (.5, -1.))
            self.assertEqual(converted.attenuation, .25)
            converted = convert_wav(wav(path, 3, 32, 48000, 1, struct.pack('<f', .125)))
            self.assertEqual(converted.wave.coefficients[0], .125)

    def test_bad_alignment_truncated_nonfinite_and_empty_output_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp)/'ir.wav'
            wav(path, 3, 32, 48000, 1, struct.pack('<f', float('nan')))
            with self.assertRaises(ValueError): convert_wav(path)
            wav(path, 1, 16, 48000, 1, b'\0')
            with self.assertRaises(ValueError): convert_wav(path)
            wav(path, 1, 16, 48000, 2, struct.pack('<2h', 100, -100))
            with self.assertRaises(ValueError): convert_wav(path)
            wav(path, 1, 16, 48000, 1, struct.pack('<h', 100))
            path.write_bytes(path.read_bytes()[:-1])
            with self.assertRaises(ValueError): convert_wav(path)

    def test_source_is_never_modified(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = wav(Path(tmp)/'ir.wav', 1, 24, 44100, 1, b'\xff\x7f\0'*1024)
            original = path.read_bytes(); convert_wav(path)
            self.assertEqual(path.read_bytes(), original)

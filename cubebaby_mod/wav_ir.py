"""CubeSuite IR WAV path: PCM, first channel, first 512 samples, zero padding.

0x50A660 accepts PCM format 1; 0x50B2C0 handles block align 2/4 as
signed 16-bit, 3/6 as signed 24-bit. No sample-rate conversion in this path.
Unsupported layouts are rejected instead of guessing the original behavior.
"""
from dataclasses import dataclass
from pathlib import Path
import struct
import wave


@dataclass(frozen=True)
class WaveIR:
    coefficients: tuple
    rate: int
    channels: int
    bits: int
    frames: int

    def record(self, header, distance):
        if len(header) != 4 or not 0 <= distance <= 100:
            raise ValueError('Header/Distance tidak valid')
        return header+struct.pack('<513f', distance/100, *self.coefficients)


def load_wav(path):
    if Path(path).stat().st_size > 128*1024*1024:
        raise ValueError('File WAV terlalu besar')
    try:
        with wave.open(str(path), 'rb') as stream:
            channels, width, rate, frames, compression, _ = stream.getparams()
            if compression != 'NONE' or channels not in (1, 2) or width not in (2, 3):
                raise ValueError('Gunakan WAV PCM 16/24-bit mono atau stereo sesuai CubeSuite')
            data = stream.readframes(min(frames, 512))
    except (wave.Error, EOFError) as exc:
        raise ValueError(f'Format WAV tidak didukung: {exc}') from exc
    if not frames or not rate or len(data) != min(frames, 512)*channels*width:
        raise ValueError('Data WAV kosong atau terpotong')
    divisor = 32767 if width == 2 else 8388608
    values = [int.from_bytes(data[i:i+width], 'little', signed=True)/divisor
              for i in range(0, len(data), channels*width)]
    values.extend([0.]*(512-len(values)))
    return WaveIR(tuple(values), rate, channels, width*8, frames)

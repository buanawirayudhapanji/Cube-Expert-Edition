"""Bounded WAV decoding and windowed-sinc conversion to 48 kHz / 512 samples.

No external runtime dependency. Original source is never changed. Mono is the
average of input channels. Float over-range is attenuated, quiet IRs stay quiet.
"""
from dataclasses import dataclass
import math
from pathlib import Path
import struct
from .wav_ir import WaveIR

RATE = 48000
LENGTH = 512


@dataclass(frozen=True)
class ConvertedIR:
    wave: WaveIR
    source_rate: int
    source_bits: int
    source_channels: int
    source_frames: int
    converted_frames: int
    attenuation: float

    @property
    def description(self):
        length = f'dipotong ke {LENGTH}' if self.converted_frames > LENGTH else f'padding ke {LENGTH}'
        return (f'{self.source_rate} Hz / {self.source_bits}-bit / {self.source_channels} ch → '
                f'48000 Hz mono · {length} sampel'+
                (f' · level ×{self.attenuation:.4f}' if self.attenuation < 1 else ''))


def _decode(path):
    with Path(path).open('rb') as stream:
        stream.seek(0, 2); size = stream.tell(); stream.seek(0)
        if size > 128*1024*1024: raise ValueError('WAV melebihi 128 MiB')
        head = stream.read(12)
        if len(head) != 12 or head[:4] != b'RIFF' or head[8:] != b'WAVE':
            raise ValueError('Gunakan file RIFF/WAVE little-endian')
        end = struct.unpack_from('<I', head, 4)[0]+8
        if end > size or end < 12: raise ValueError('Header WAV terpotong')
        fmt = data_location = None
        chunks = 0
        while stream.tell()+8 <= end:
            chunks += 1
            if chunks > 10000: raise ValueError('Terlalu banyak chunk WAV')
            tag, n = struct.unpack('<4sI', stream.read(8)); start = stream.tell()
            if start+n > end: raise ValueError('Chunk WAV terpotong')
            if tag == b'fmt ':
                if fmt is not None or n < 16 or n > 4096: raise ValueError('Chunk fmt WAV tidak valid')
                fmt = stream.read(n)
            elif tag == b'data':
                if data_location is not None: raise ValueError('Beberapa chunk data belum didukung')
                data_location = (start, n)
            stream.seek(start+n+(n&1))
        if fmt is None or data_location is None: raise ValueError('WAV tidak memiliki fmt/data')
        code, channels, rate, byte_rate, align, bits = struct.unpack_from('<HHIIHH', fmt)
        if code == 0xfffe:
            if len(fmt) < 40 or struct.unpack_from('<H', fmt, 16)[0] < 22:
                raise ValueError('WAVE extensible terpotong')
            valid_bits = struct.unpack_from('<H', fmt, 18)[0]
            if not 1 <= valid_bits <= bits or fmt[28:40] != bytes.fromhex('00001000800000aa00389b71'):
                raise ValueError('Subformat extensible tidak valid')
            code = struct.unpack_from('<I', fmt, 24)[0]
        if not 8000 <= rate <= 384000 or channels not in (1, 2):
            raise ValueError('Gunakan WAV mono/stereo, sample rate 8–384 kHz')
        if not (code == 1 and bits in (8, 16, 24, 32) or code == 3 and bits in (32, 64)):
            raise ValueError('Gunakan WAV PCM 8/16/24/32-bit atau IEEE float 32/64-bit')
        width = bits//8
        if align != width*channels or byte_rate != rate*align:
            raise ValueError('Block align/byte rate WAV tidak cocok')
        start, n = data_location
        if not n or n % align: raise ValueError('Data sampel WAV kosong atau terpotong')
        frames = n//align
        # Only the prefix needed for the output plus the anti-alias filter halo.
        radius = 32/(min(1., RATE/rate)*.94)
        count = min(frames, math.ceil(LENGTH*rate/RATE+radius+2))
        stream.seek(start); raw = stream.read(count*align)
        if len(raw) != count*align: raise ValueError('Data WAV terpotong saat dibaca')
    mono = []
    for frame in range(count):
        values = []
        for channel in range(channels):
            offset = frame*align+channel*width
            if code == 3:
                value = struct.unpack_from('<f' if bits == 32 else '<d', raw, offset)[0]
            elif bits == 8: value = (raw[offset]-128)/128
            else: value = int.from_bytes(raw[offset:offset+width], 'little', signed=True)/2**(bits-1)
            if not math.isfinite(value): raise ValueError('WAV berisi NaN/Infinity')
            values.append(value)
        mono.append(sum(values)/channels)
    return mono, rate, bits, channels, frames


def convert_wav(path):
    data, rate, bits, channels, frames = _decode(path)
    total = math.ceil(frames*RATE/rate)
    if rate == RATE:
        result = data[:LENGTH]
    else:
        cutoff = min(1., RATE/rate)*.94
        radius = 32/cutoff
        result = []
        for i in range(min(total, LENGTH)):
            t = i*rate/RATE
            value = norm = 0.
            for j in range(math.ceil(t-radius), math.floor(t+radius)+1):
                x = t-j; u = cutoff*x
                sinc = 1. if abs(u) < 1e-12 else math.sin(math.pi*u)/(math.pi*u)
                weight = cutoff*sinc*.5*(1+math.cos(math.pi*x/radius))
                norm += weight
                if 0 <= j < len(data): value += data[j]*weight
            result.append(value/norm if norm else 0.)
    result.extend([0.]*(LENGTH-len(result)))
    if not all(math.isfinite(v) for v in result) or not any(abs(v) > 1e-30 for v in result):
        raise ValueError('IR hasil konversi kosong/tidak valid; stereo mungkin saling membatalkan')
    peak = max(abs(v) for v in result)
    attenuation = min(1., 1/peak)
    coefficients = tuple(struct.unpack('<512f', struct.pack('<512f', *(v*attenuation for v in result))))
    return ConvertedIR(WaveIR(coefficients, RATE, 1, 32, LENGTH), rate, bits, channels, frames, total, attenuation)

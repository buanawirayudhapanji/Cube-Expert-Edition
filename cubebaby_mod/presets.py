"""Cube Baby Jun effect records, traced at 0x49F520/0x49F590 (CubeSuite 2.8.10)."""
from dataclasses import dataclass


@dataclass(frozen=True)
class Field:
    name: str
    offset: int
    maximum: int
    switch: int | None = None


FIELDS = (
    Field('VOLUME', 5, 127), Field('IR CAB', 9, 8, 10),
    Field('REVERB', 3, 15, 10), Field('MIX', 7, 118, 11),
    Field('FB', 4, 127, 11), Field('TIME', 6, 31, 11),
    Field('MOD', 8, 15, 11), Field('TONE', 2, 15, 12),
    Field('GAIN', 1, 7, 12), Field('TYPE', 0, 8, 12),
)
FACTORY_PRESETS = bytes.fromhex(
    '07 07 09 05 34 41 14 1e 07 04 01 01 01 00 00 00 '
    '04 02 05 05 2c 46 17 1e 07 05 01 01 01 00 00 00 '
    '01 07 07 05 34 6f 14 0c 05 02 01 01 01 00 00 00')


def validate_presets(raw):
    if len(raw) != 48:
        raise ValueError('Data harus berisi tiga preset, masing-masing 16 byte')
    for start in (0, 16, 32):
        for field in FIELDS:
            if raw[start+field.offset] > field.maximum:
                raise ValueError(f'Nilai {field.name} di luar rentang CubeSuite')
        if any(raw[start+i] > 1 for i in (10, 11, 12)):
            raise ValueError('Nilai sakelar efek tidak dikenal')
    return bytes(raw)


def edit_preset(raw, preset, offset, value):
    validate_presets(raw)
    maxima = {f.offset: f.maximum for f in FIELDS} | {10: 1, 11: 1, 12: 1}
    if preset not in range(3) or offset not in maxima or not 0 <= value <= maxima[offset]:
        raise ValueError('Preset, parameter atau nilai tidak valid')
    result = bytearray(raw)
    result[preset*16+offset] = value
    return bytes(result)


def live_address(preset, offset):
    if preset not in range(3) or offset not in range(13):
        raise ValueError('Alamat parameter preset tidak valid')
    return 0x80000000+preset*16+offset

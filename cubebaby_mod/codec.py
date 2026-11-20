"""Pure offline codec inferred from CubeSuite function 0x00486980.

CubeSuite optionally packs a little-endian bit stream into 7-bit MIDI bytes.
This is not the alternate MIDI scheme that groups seven MSBs in a prefix byte.
Whether a given device uses the packed branch must be established separately.
No MIDI transport is used here.
"""


def pack_7bit(data: bytes) -> bytes:
    result = bytearray()
    accumulator = bits = 0
    for value in data:
        accumulator |= value << bits
        bits += 8
        while bits >= 7:
            result.append(accumulator & 0x7f)
            accumulator >>= 7
            bits -= 7
    if bits:
        result.append(accumulator & 0x7f)
    return bytes(result)


def unpack_7bit(data: bytes) -> bytes:
    result = bytearray()
    accumulator = bits = 0
    for value in data:
        if value > 0x7f:
            raise ValueError('Data MIDI 7-bit berisi byte di atas 0x7F')
        accumulator |= value << bits
        bits += 7
        while bits >= 8:
            result.append(accumulator & 0xff)
            accumulator >>= 8
            bits -= 8
    decoded = bytes(result)
    if pack_7bit(decoded) != data:
        raise ValueError('Panjang atau padding data 7-bit tidak kanonis')
    return decoded

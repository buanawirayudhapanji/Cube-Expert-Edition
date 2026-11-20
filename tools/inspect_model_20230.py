#!/usr/bin/env python3
"""Extract model entry and IR storage descriptor from this CubeSuite version."""
import json
from pathlib import Path
import struct
import sys

binary = Path(sys.argv[1]).read_bytes()
# PE section layout verified by objdump; addresses refer to this exact binary.
def data_bytes(address, size):
    return binary[0x351e00+address-0x754000:0x351e00+address-0x754000+size]

entry_address = 0x7548e0+19*0x54
entry = data_bytes(entry_address, 0x54)
model = struct.unpack_from('<I', entry)[0]
if model != 20230:
    raise ValueError('Binary/model table berbeda dari versi yang dianalisis')
descriptor_address = struct.unpack_from('<I', entry, 0x48)[0]
region, sector_size, base, limit = struct.unpack('<4I', data_bytes(descriptor_address, 16))
print(json.dumps({
    'device_code': model,
    'name': entry[4:0x38].split(b'\0')[0].decode('ascii'),
    'entry_address': hex(entry_address),
    'feature_bits_raw': hex(struct.unpack_from('<I', entry, 0x38)[0]),
    'storage_descriptor_address': hex(descriptor_address),
    'storage_region': region, 'sector_size': sector_size,
    'storage_base': base, 'storage_size': limit,
    'ir_slot_count': 8, 'ir_slot_stride': 4096, 'ir_slot_data_size': 2056,
    'max_raw_read_packet': 128, 'max_read_data_chunk': 113,
}, indent=2))

#!/usr/bin/env python3
"""Reproducible, read-only inspection of a PE executable (standard library)."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct


def inspect(path):
    raw = Path(path).read_bytes()
    if raw[:2] != b'MZ':
        raise ValueError('Input bukan PE/MZ')
    pe = struct.unpack_from('<I', raw, 0x3c)[0]
    if raw[pe:pe+4] != b'PE\0\0':
        raise ValueError('Signature PE tidak cocok')
    machine, n_sections = struct.unpack_from('<HH', raw, pe+4)
    opt_len = struct.unpack_from('<H', raw, pe+20)[0]
    opt = pe+24
    magic = struct.unpack_from('<H', raw, opt)[0]
    if magic != 0x10b:
        raise ValueError('Inspector ini ditujukan untuk PE32')
    base = struct.unpack_from('<I', raw, opt+28)[0]
    sections = []
    for i in range(n_sections):
        pos = opt+opt_len+i*40
        name = raw[pos:pos+8].rstrip(b'\0').decode('ascii')
        vs, rva, size, offset = struct.unpack_from('<IIII', raw, pos+8)
        sections.append(dict(name=name, rva=rva, virtual_size=vs, raw_size=size, offset=offset))
    def va(offset):
        for sec in sections:
            if sec['offset'] <= offset < sec['offset']+sec['raw_size']:
                return f"0x{base+sec['rva']+offset-sec['offset']:08X}"
        return None
    evidence = []
    pattern = re.compile(rb'CubeBaby|CubeSuite|RtMidi|sysex|OnOpenIRFile|OnFactoryIR|OnResetSound|OnSaveEffect')
    for match in re.finditer(rb'[\x20-\x7e]{5,}', raw):
        if pattern.search(match.group()):
            evidence.append(dict(offset=match.start(), address=va(match.start()), text=match.group().decode('ascii')))
    return dict(filename=Path(path).name, sha256=hashlib.sha256(raw).hexdigest(),
                size=len(raw), machine=f'0x{machine:04X}', image_base=f'0x{base:08X}',
                sections=sections, strings=evidence)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('binary')
    args = parser.parse_args()
    print(json.dumps(inspect(args.binary), indent=2))

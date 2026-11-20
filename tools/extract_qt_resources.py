#!/usr/bin/env python3
"""Extract original Qt resource assets from the supplied CubeSuite executable.

Pointers are from qRegisterResourceData call at 0x458940 (resource version 3).
"""
from pathlib import Path
import hashlib
from PySide6.QtCore import qRegisterResourceData, qUnregisterResourceData, QDirIterator, QFile, QIODevice
root = Path(__file__).resolve().parent.parent
binary=(root/'CubeSuite/CubeSuite.exe').read_bytes()
if hashlib.sha256(binary).hexdigest() != '0e0183fd6dc1b347534c9ce1e3677ecda2a6ae77fe3da8d6314d43c7c2cfd2e6':
    raise RuntimeError('Executable berbeda dari versi yang dipetakan; alamat resource tidak boleh diasumsikan')
def off(address): return 0x17ca00+address-0x57e000
resource_data=binary[off(0x5942a8):off(0x6f5de0)]
names=binary[off(0x6f5de0):off(0x6f6498)]
tree=binary[off(0x6f6498):off(0x6f6498)+0x2500]
if not qRegisterResourceData(3,tree,names,resource_data): raise RuntimeError('Qt resource registration failed')
try:
    iterator=QDirIterator(':/',QDirIterator.Subdirectories)
    files=[]
    while iterator.hasNext():
        path=iterator.next()
        if iterator.fileInfo().isFile() and not path.startswith(':/qt'):
            stream=QFile(path)
            if stream.open(QIODevice.ReadOnly):
                data=bytes(stream.readAll());stream.close()
                dest=root/'cubebaby_mod/assets'/path[2:]
                dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes(data)
                files.append((path,len(data)))
    for item in files: print(*item)
finally:
    qUnregisterResourceData(3,tree,names,resource_data)

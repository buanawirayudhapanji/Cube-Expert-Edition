"""Portable, self-contained IR/preset/bank files; no device I/O."""
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import tempfile
import uuid
import sys
from .app_paths import data_root
from .windows_io import replace_write_through
from .presets import validate_presets
from .protocol import parse_ir_slot

FORMAT = 'cubebaby-library-v1'
MAX_FILE = 1024*1024


def durable_directory(path):
    path = Path(path)
    if sys.platform == 'win32':
        path.mkdir(parents=True, exist_ok=True)
        return
    missing = []
    current = path
    while not current.exists():
        missing.append(current); current = current.parent
    for directory in reversed(missing):
        directory.mkdir(exist_ok=True)
        fd = os.open(directory.parent, os.O_RDONLY | os.O_DIRECTORY)
        try: os.fsync(fd)
        finally: os.close(fd)


def replace_file(source, destination):
    if sys.platform == 'win32':
        replace_write_through(source, destination)
    else:
        os.replace(source, destination)


def atomic_json(path, data):
    path = Path(path)
    payload = json.dumps(data, ensure_ascii=False, indent=2, allow_nan=False).encode('utf-8')
    if len(payload) > MAX_FILE:
        raise ValueError('File koleksi melebihi 1 MiB')
    durable_directory(path.parent)
    temp = None
    try:
        with tempfile.NamedTemporaryFile(dir=path.parent, prefix='.saving-', delete=False) as stream:
            temp = Path(stream.name)
            stream.write(payload); stream.flush(); os.fsync(stream.fileno())
        replace_file(temp, path)
        if sys.platform != 'win32':
            fd = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
            try: os.fsync(fd)
            finally: os.close(fd)
    finally:
        if temp is not None:
            temp.unlink(missing_ok=True)
    return path


def packed(raw):
    return {'raw_hex': bytes(raw).hex(), 'sha256': hashlib.sha256(raw).hexdigest()}


def unpacked(data, kind):
    if not isinstance(data, dict) or not isinstance(data.get('raw_hex'), str):
        raise ValueError('Data item tidak lengkap')
    try: raw = bytes.fromhex(data['raw_hex'])
    except ValueError as exc: raise ValueError('Byte mentah bukan hexadecimal yang valid') from exc
    if data.get('sha256') != hashlib.sha256(raw).hexdigest():
        raise ValueError('SHA-256 item tidak cocok; file mungkin rusak')
    if kind == 'preset':
        if len(raw) != 16:
            raise ValueError('Preset harus 16 byte')
        validate_presets(raw*3)
    elif kind == 'ir':
        snapshot = parse_ir_slot(raw, 0, 0)
        if not snapshot['format_recognized'] or not any(snapshot['coefficients']):
            raise ValueError('IR kosong atau koefisien/Distance tidak valid')
    else: raise ValueError('Jenis data tidak dikenal')
    return raw


def clean_name(value):
    if not isinstance(value, str) or not value.strip() or len(value) > 120 or any(ord(c) < 32 for c in value):
        raise ValueError('Nama harus 1–120 karakter tanpa karakter kontrol')
    return value.strip()


def make_item(kind, name, raw=None, irs=None, presets=None, preset=None, ir=None):
    item = {'format': FORMAT, 'device_code': 20230, 'kind': kind, 'name': clean_name(name),
            'created_at': datetime.now(timezone.utc).isoformat()}
    if kind == 'sound': item.update(preset=preset, ir=ir)
    elif kind == 'bank': item.update(irs=irs or [], presets=presets or [])
    else: item.update(packed(raw))
    validate_item(item)
    return item


def validate_item(item):
    if not isinstance(item, dict) or item.get('format') != FORMAT or item.get('device_code') != 20230:
        raise ValueError('File bukan koleksi Cube Baby 20230 yang didukung')
    clean_name(item.get('name'))
    kind = item.get('kind')
    if kind in ('ir', 'preset'):
        unpacked(item, kind)
    elif kind == 'sound':
        for key in ('preset', 'ir'):
            entry = item.get(key)
            if not isinstance(entry, dict): raise ValueError('Paket harus berisi satu preset dan satu IR')
            clean_name(entry.get('name')); unpacked(entry, key)
    elif kind == 'bank':
        total = 0
        for key, entry_kind, limit in (('irs', 'ir', 8), ('presets', 'preset', 3)):
            rows = item.get(key)
            if not isinstance(rows, list) or len(rows) > limit:
                raise ValueError('Jumlah slot bank tidak valid')
            seen = set()
            for entry in rows:
                if not isinstance(entry, dict): raise ValueError('Item bank tidak valid')
                slot = entry.get('slot')
                if type(slot) is not int or slot not in range(limit) or slot in seen:
                    raise ValueError('Slot bank di luar batas atau berulang')
                seen.add(slot); clean_name(entry.get('name')); unpacked(entry, entry_kind)
            total += len(rows)
        if not total: raise ValueError('Bank kosong')
    else: raise ValueError('Jenis koleksi tidak didukung')
    return item


def load_item(path):
    with Path(path).open('rb') as stream: raw = stream.read(MAX_FILE+1)
    if len(raw) > MAX_FILE: raise ValueError('File koleksi terlalu besar')
    try:
        data = json.loads(raw, parse_constant=lambda value: (_ for _ in ()).throw(ValueError('Angka JSON tidak valid')))
    except (UnicodeError, json.JSONDecodeError) as exc:
        raise ValueError('File bukan JSON yang valid') from exc
    return validate_item(data)


class Collection:
    def __init__(self, root=None):
        self.root = Path(root or os.environ.get('CUBEBABY_LIBRARY_DIR') or
                         data_root()/'library_data')

    def save(self, item):
        validate_item(item)
        return atomic_json(self.root/f'{item["kind"]}-{uuid.uuid4().hex}.json', item)

    def entries(self):
        if not self.root.exists(): return [], []
        items, errors = [], []
        for path in sorted(self.root.glob('*.json')):
            try: items.append((path, load_item(path)))
            except (OSError, ValueError) as exc: errors.append(f'{path.name}: {exc}')
        items.sort(key=lambda pair: (pair[1]['kind'], pair[1]['name'].casefold()))
        return items, errors


def bank_entry(slot, item):
    validate_item(item)
    if item['kind'] not in ('ir', 'preset'): raise ValueError('Bank tidak dapat dimasukkan ke bank lain')
    return {'slot': slot, 'name': item['name'], **packed(unpacked(item, item['kind']))}


def preset_to_bank(item, slot):
    validate_item(item)
    if item['kind'] != 'preset' or type(slot) is not int or slot not in range(3):
        raise ValueError('Pilih preset dan target A/B/C')
    return make_item('bank', item['name'], presets=[bank_entry(slot, item)])


def sound_to_bank(item, preset_slot, ir_slot):
    """Map a portable sound to explicit targets without mutating the package."""
    validate_item(item)
    if (item['kind'] != 'sound' or type(preset_slot) is not int or preset_slot not in range(3)
            or type(ir_slot) is not int or ir_slot not in range(8)):
        raise ValueError('Pilih paket preset + IR, target A/B/C, dan slot IR 1–8')
    raw = bytearray(unpacked(item['preset'], 'preset'))
    raw[9] = ir_slot+1
    preset = {'slot': preset_slot, 'name': item['preset']['name'], **packed(raw)}
    ir = {'slot': ir_slot, 'name': item['ir']['name'], **packed(unpacked(item['ir'], 'ir'))}
    return make_item('bank', item['name'], irs=[ir], presets=[preset])

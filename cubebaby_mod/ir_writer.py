"""Transactional sequence for one IR sector: read, durable backup, erase, write, verify.

Only drives requests. No transport, threads, automatic retries, or automatic rollback.
"""
from dataclasses import dataclass
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import time
import uuid
import sys
import tempfile
from .windows_io import replace_write_through
from .protocol import (
    IR_SLOT_SIZE, IR_SLOT_STRIDE, IR_READ_CHUNK, ir_slot_address, read_request,
    parse_read_response, flash_erase_request, flash_write_request, parse_write_ack,
)


@dataclass(frozen=True)
class Request:
    data: bytes
    timeout: float


def save_backup(directory, address, slot, data):
    if len(data) != IR_SLOT_STRIDE:
        raise ValueError('Cadangan sektor harus lengkap 4096 byte')
    directory = Path(directory)
    directory.mkdir(parents=True, exist_ok=True)
    stamp = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    path = directory/f'cubebaby-20230-slot-{slot+1}-{stamp}-{uuid.uuid4().hex[:8]}.json'
    payload = {'format': 'cubebaby-sector-backup-v1', 'device_code': 20230,
               'slot': slot+1, 'address': address, 'size': len(data),
               'sha256': hashlib.sha256(data).hexdigest(), 'sector_hex': data.hex(' ')}
    if sys.platform == 'win32':
        temp = None
        try:
            with tempfile.NamedTemporaryFile(dir=directory, prefix='.backup-', delete=False) as stream:
                temp = Path(stream.name)
                stream.write(json.dumps(payload, indent=2).encode('utf-8'))
                stream.flush()
                os.fsync(stream.fileno())
            replace_write_through(temp, path, replace=False)
        finally:
            if temp is not None:
                temp.unlink(missing_ok=True)
        return str(path)
    with path.open('x', encoding='utf-8') as stream:
        json.dump(payload, stream, indent=2)
        stream.flush()
        os.fsync(stream.fileno())
    # Make the directory entry durable before allowing the sector erase.
    fd = os.open(directory, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(fd)
    finally:
        os.close(fd)
    return str(path)


class IRWriter:
    def __init__(self, info, slot, expected_record, desired_record, backup,
                 desired_sector=None, clock=time.monotonic):
        if not write_profile_supported(info):
            raise ValueError('Profil tulis belum didukung; metadata harus cocok dengan pedal 20230 yang diuji')
        self.address = ir_slot_address(info, slot)
        self.slot = slot
        if len(expected_record) != IR_SLOT_SIZE or len(desired_record) != IR_SLOT_SIZE:
            raise ValueError('Record slot tidak lengkap')
        if desired_sector is not None and (len(desired_sector) != IR_SLOT_STRIDE or
                                           desired_sector[:IR_SLOT_SIZE] != desired_record):
            raise ValueError('Sektor pemulihan tidak cocok')
        self.expected = bytes(expected_record)
        self.desired_record = bytes(desired_record)
        self.desired_sector = bytes(desired_sector) if desired_sector is not None else None
        self.backup = backup
        self.clock = clock
        self.state = 'preflight'
        self.buffer = bytearray()
        self.offset = 0
        self.backup_path = None
        self.wait_until = 0
        self.modified = False
        self.verified = False
        self.no_change = False
        self.awaiting = None
        self.result_sector = None

    @property
    def complete(self): return self.state == 'done'

    @property
    def progress(self):
        count = self.offset if self.state == 'write' else len(self.buffer)
        return self.state, count, IR_SLOT_STRIDE

    def next_request(self):
        if self.complete or self.state == 'failed' or self.awaiting is not None:
            return None
        if self.state == 'settle':
            if self.clock() < self.wait_until:
                return None
            self.state = 'write'
            self.offset = 0
        if self.state in ('preflight', 'verify'):
            size = min(IR_READ_CHUNK, IR_SLOT_STRIDE-len(self.buffer))
            request = Request(read_request(0, self.address+len(self.buffer), size), 2)
        elif self.state == 'erase':
            request = Request(flash_erase_request(self.address), 30)
            # Even a missing ACK cannot prove that the erase did not execute.
            self.modified = True
        elif self.state == 'write':
            data = self.desired_sector[self.offset:self.offset+128]
            request = Request(flash_write_request(self.address+self.offset, data), 10)
        else:
            return None
        self.awaiting = request
        return request

    def accept(self, packet):
        if self.awaiting is None:
            return False
        if self.state in ('preflight', 'verify'):
            size = min(IR_READ_CHUNK, IR_SLOT_STRIDE-len(self.buffer))
            try:
                data = parse_read_response(packet, 0, self.address+len(self.buffer), size)
            except ValueError:
                return False
            self.buffer.extend(data)
            self.awaiting = None
            if len(self.buffer) != IR_SLOT_STRIDE:
                return True
            raw = bytes(self.buffer)
            if self.state == 'preflight':
                if raw[:IR_SLOT_SIZE] != self.expected:
                    self.state = 'failed'
                    raise RuntimeError('Isi slot berubah sejak dibaca. Baca ulang sebelum menyimpan.')
                if self.desired_sector is None:
                    self.desired_sector = self.desired_record+raw[IR_SLOT_SIZE:]
                if self.desired_sector == raw:
                    self.no_change = True
                    self.verified = True
                    self.result_sector = raw
                    self.state = 'done'
                    return True
                try:
                    self.backup_path = self.backup(self.address, self.slot, raw)
                    if not self.backup_path:
                        raise OSError('Lokasi cadangan tidak tersedia')
                except Exception:
                    self.state = 'failed'
                    raise
                self.state = 'erase'
            else:
                if raw != self.desired_sector:
                    self.state = 'failed'
                    raise RuntimeError('Verifikasi gagal: isi sektor berbeda dari data yang dikirim.')
                self.verified = True
                self.result_sector = raw
                self.state = 'done'
            return True
        try:
            parse_write_ack(packet)
        except ValueError:
            return False
        except RuntimeError:
            self.state = 'failed'
            raise
        self.awaiting = None
        if self.state == 'erase':
            self.state = 'settle'
            self.wait_until = self.clock()+0.1
        elif self.state == 'write':
            self.offset += min(128, IR_SLOT_STRIDE-self.offset)
            if self.offset == IR_SLOT_STRIDE:
                self.buffer.clear()
                self.state = 'verify'
        return True


def write_profile_supported(info):
    return (info is not None and info.get('device_code') == 20230 and
            info.get('fields_u32') == [1, 20230, 196608, 393216, 430080])


def load_ir_file(path, address, slot):
    from .protocol import parse_ir_slot
    path = Path(path)
    if path.stat().st_size > 256*1024:
        raise ValueError('File JSON terlalu besar')
    data = json.loads(path.read_text(encoding='utf-8'))
    if not isinstance(data, dict) or data.get('device_code') != 20230:
        raise ValueError('File harus berasal dari Cube Baby kode 20230')
    sector = None
    if data.get('format') == 'cubebaby-sector-backup-v1':
        if data.get('address') != address or data.get('slot') != slot+1:
            raise ValueError('Cadangan berasal dari alamat/slot berbeda')
        value = data.get('sector_hex')
        if not isinstance(value, str):
            raise ValueError('Data cadangan tidak valid')
        sector = bytes.fromhex(value)
        if (len(sector) != IR_SLOT_STRIDE or data.get('size') != IR_SLOT_STRIDE or
                data.get('sha256') != hashlib.sha256(sector).hexdigest()):
            raise ValueError('Ukuran atau SHA-256 cadangan tidak cocok')
        raw = sector[:IR_SLOT_SIZE]
    else:
        value = data.get('raw_hex')
        if not isinstance(value, str):
            raise ValueError('Raw byte slot tidak tersedia')
        raw = bytes.fromhex(value)
    snapshot = parse_ir_slot(raw, slot, address)
    if not snapshot['format_recognized'] and sector is None:
        raise ValueError('Float/Distance file IR tidak dikenali; impor dibatalkan')
    return snapshot, sector

"""Sequential device memory operations; one outstanding request, no retries.

Region 4 RAM preview: 0x507EA0 -> 0x5066C0, chunk ACKs then additive
16-bit checksum (opcode 0x24). Region 5 effects: 0x4A3250/0x49F520.
"""
from dataclasses import dataclass
from .protocol import encode_packet, read_request, parse_read_response, parse_write_ack
from .ir_writer import Request


@dataclass(frozen=True)
class Step:
    request: Request
    kind: str
    region: int
    address: int
    length: int
    key: str = ''
    expected: bytes | None = None


def read_steps(region, address, length, key='', expected=None):
    if length < 1 or expected is not None and len(expected) != length:
        raise ValueError('Ukuran baca/verifikasi tidak valid')
    return [Step(Request(read_request(region, address+i, min(113, length-i)), 2),
                 'read', region, address+i, min(113, length-i), key,
                 None if expected is None else expected[i:i+113])
            for i in range(0, length, 113)]


def write_steps(region, address, data, checksum=False):
    if not data or not 0 <= region <= 255 or not 0 <= address <= 0xffffffff-len(data)+1:
        raise ValueError('Alamat/data tulis tidak valid')
    result = []
    for i in range(0, len(data), 128):
        chunk = data[i:i+128]
        payload = bytes([region])+(address+i).to_bytes(4, 'little')+len(chunk).to_bytes(3, 'little')+chunk
        result.append(Step(Request(encode_packet(0x22, payload), 10), 'ack', region, address+i, len(chunk)))
    if checksum:
        payload = bytes([region])+address.to_bytes(4, 'little')+len(data).to_bytes(4, 'little')
        result.append(Step(Request(encode_packet(0x24, payload), 30), 'checksum', region,
                           address, len(data), expected=(sum(data)&0xffff).to_bytes(2, 'little')))
    return result


class MemoryJob:
    def __init__(self, steps, done, label):
        if not steps:
            raise ValueError('Operasi kosong')
        self.steps = list(steps)
        self.done = done
        self.label = label
        self.index = 0
        self.awaiting = False
        self.modified = False
        self.results = {}

    @property
    def complete(self):
        return self.index == len(self.steps)

    def next_request(self):
        if self.complete or self.awaiting:
            return None
        step = self.steps[self.index]
        self.awaiting = True
        self.modified |= step.kind == 'ack'
        return step.request

    def accept(self, packet):
        if not self.awaiting or self.complete:
            return False
        step = self.steps[self.index]
        if step.kind == 'ack':
            try:
                parse_write_ack(packet)
            except ValueError:
                return False
        elif step.kind == 'read':
            try:
                data = parse_read_response(packet, step.region, step.address, step.length)
            except ValueError:
                return False
            if step.expected is not None and data != step.expected:
                raise RuntimeError('Verifikasi gagal: data baca ulang berbeda')
            self.results.setdefault(step.key, bytearray()).extend(data)
        elif step.kind == 'checksum':
            payload = packet['payload']
            if (packet['opcode'] != 0x24 or len(payload) != 11 or payload[0] != step.region or
                    int.from_bytes(payload[1:5], 'little') != step.address or
                    int.from_bytes(payload[5:9], 'little') != step.length):
                return False
            if payload[9:] != step.expected:
                raise RuntimeError('Checksum memori perangkat berbeda dari data yang dikirim')
        self.awaiting = False
        self.index += 1
        return True

    def recover(self, reason):
        return False

    @property
    def waiting_description(self):
        if self.complete:
            return 'selesai'
        step = self.steps[self.index]
        return (f'{step.kind}, region {step.region}, alamat 0x{step.address:08X}, '
                f'{step.length} byte, langkah {self.index+1}/{len(self.steps)}')


class PreviewJob(MemoryJob):
    """Back up RAM before touching the IR; verify/rollback with byte reads.

    RAM checksum queries used to run while the IR gate was closed. A missing
    checksum response then left the pedal muted. Read-back verification removes
    that dependency and a preflight snapshot makes interrupted uploads recoverable.
    """
    recovery_success = ('Preview gagal: {error}. Isi RAM sebelumnya berhasil dipulihkan dan '
                        'dibaca ulang; perintah aktivasi IR diterima. Preview baru tidak diterapkan.')

    def __init__(self, record, done):
        from .protocol import parse_ir_slot
        if not parse_ir_slot(record, 0, 0)['format_recognized']:
            raise ValueError('Data IR untuk preview tidak valid')
        self.data = bytes(record[4:])
        self.original_gate = self.original_data = None
        self.phase = 'preflight'
        self.data_modified = False
        self.recovering = False
        self.error = None
        super().__init__(read_steps(4, 0x764, 1, 'gate')+
                         read_steps(4, 0x768, len(self.data), 'before'), done, 'Preview IR')

    def next_request(self):
        if not self.complete and not self.awaiting and self.phase == 'upload':
            step = self.steps[self.index]
            if step.kind == 'ack' and step.address >= 0x768:
                self.data_modified = True
        return super().next_request()

    def accept(self, packet):
        accepted = super().accept(packet)
        if accepted and self.phase == 'preflight' and self.complete:
            gate = bytes(self.results['gate'])
            # Observation only. Hardware has returned values outside 0/1;
            # do not interpret this register as an enum or echo it as a command.
            self.original_gate = gate
            self.original_data = bytes(self.results['before'])
            self.phase = 'upload'
            self.steps.extend(write_steps(4, 0x764, b'\0')+
                              write_steps(4, 0x768, self.data)+
                              write_steps(4, 0x764, b'\1')+
                              read_steps(4, 0x768, len(self.data), 'after', self.data)+
                              read_steps(4, 0x764, 1, 'gate_after'))
        return accepted

    def recover(self, reason):
        if self.recovering or not self.modified or self.original_data is None:
            return False
        self.error = reason
        self.recovering = True
        self.phase = 'rollback'
        data_steps = (write_steps(4, 0x764, b'\0')+
                      write_steps(4, 0x768, self.original_data)) if self.data_modified else []
        # 0x764 is a control command, not a confirmed persistent status byte.
        # The original editor always finishes a RAM update with command 1.
        self.steps = (data_steps+write_steps(4, 0x764, b'\1')+
                      read_steps(4, 0x764, 1, 'gate_recovered'))
        if self.data_modified:
            self.steps += read_steps(4, 0x768, len(self.data), 'restored', self.original_data)
        self.index = 0
        self.awaiting = False
        return True


class DistanceJob(MemoryJob):
    """Change only the Distance float; finish with IR command 1, as 0x49E220.

    Reads of 0x764 are diagnostic observations, not a stable on/off state.
    Coefficients are never written by this job.
    """
    recovery_success = ('Distance preview gagal: {error}. Perintah aktivasi IR diterima kembali; '
                        'koefisien IR tidak ditulis ulang. Nilai Distance perlu dibaca ulang.')
    def __init__(self, percent, done):
        import math
        import struct
        if not math.isfinite(percent) or not 0 <= percent <= 100:
            raise ValueError('Distance tidak valid')
        self.value = struct.pack('<f', percent/100)
        self.original_gate = None
        self.recovering = False
        self.error = None
        super().__init__(read_steps(4, 0x764, 1, 'gate'), done, 'Distance preview')

    def accept(self, packet):
        accepted = super().accept(packet)
        if accepted and self.original_gate is None:
            gate = bytes(self.results['gate'])
            self.original_gate = gate
            self.steps.extend(write_steps(4, 0x764, b'\0')+
                              write_steps(4, 0x768, self.value)+
                              write_steps(4, 0x764, b'\1')+
                              read_steps(4, 0x764, 1, 'gate_after')+
                              read_steps(4, 0x768, 4, 'distance', self.value))
        return accepted

    def recover(self, reason):
        if self.recovering or not self.modified or self.original_gate is None:
            return False
        self.error = reason
        self.recovering = True
        self.steps = (write_steps(4, 0x764, b'\1')+
                      read_steps(4, 0x764, 1, 'gate_recovered'))
        self.index = 0
        self.awaiting = False
        return True



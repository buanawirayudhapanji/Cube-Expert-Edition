"""Read one stored IR slot in small, validated, sequential chunks. No writes."""
from .protocol import (
    IR_SLOT_SIZE, IR_READ_CHUNK, ir_slot_address, read_request, parse_read_response, parse_ir_slot,
)


class IRReader:
    def __init__(self, info, slot):
        self.slot = slot
        self.address = ir_slot_address(info, slot)
        self.buffer = bytearray()

    @property
    def complete(self):
        return len(self.buffer) == IR_SLOT_SIZE

    @property
    def progress(self):
        return len(self.buffer), IR_SLOT_SIZE

    def next_request(self):
        if self.complete:
            raise ValueError('Pembacaan slot sudah lengkap')
        length = min(IR_READ_CHUNK, IR_SLOT_SIZE-len(self.buffer))
        return read_request(0, self.address+len(self.buffer), length)

    def accept(self, packet):
        if self.complete:
            raise ValueError('Pembacaan slot sudah lengkap')
        length = min(IR_READ_CHUNK, IR_SLOT_SIZE-len(self.buffer))
        data = parse_read_response(packet, 0, self.address+len(self.buffer), length)
        self.buffer.extend(data)

    def snapshot(self):
        if not self.complete:
            raise ValueError('Data slot belum lengkap')
        return parse_ir_slot(bytes(self.buffer), self.slot, self.address)

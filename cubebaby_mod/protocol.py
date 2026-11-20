"""Offline protocol helpers inferred from CubeSuite V2.8.10.

No device communication. Packet meanings are inferred from static analysis;
identity roundtrip has been verified on one SINCO-CubeBaby pedal via user
output; device-info reads are also verified on model 20230. IR slot reads
still need hardware verification.
"""
from .codec import pack_7bit, unpack_7bit

HEADER = b'\x00\x59'


def identity_request() -> bytes:
    """Candidate identity request: 0x5068B0 -> 0x507DE0 -> 0x507930.

    0x5068B0 requests opcode 0x11 before interpreting device/firmware strings.
    MIDI mode 1 enables 7-bit bitstream encoding in 0x508180.
    """
    raw = HEADER + b'\x11\x00\x00\x00\xff'
    return b'\xf0' + pack_7bit(raw) + b'\xf7'


def decode_packet(sysex: bytes) -> dict:
    """Validate and decode a packed candidate CubeSuite packet offline."""
    if not sysex.startswith(b'\xf0') or not sysex.endswith(b'\xf7'):
        raise ValueError('Pembatas SysEx F0/F7 tidak lengkap')
    raw = unpack_7bit(sysex[1:-1])
    if len(raw) < 7 or raw[:2] != HEADER:
        raise ValueError('Header paket CubeSuite tidak cocok')
    length = int.from_bytes(raw[3:6], 'little')
    if len(raw) != 7+length:
        raise ValueError('Panjang payload tidak cocok')
    payload = raw[6:-1]
    if raw[-1] != (~sum(payload) & 0xff):
        raise ValueError('Checksum payload tidak cocok')
    return {'opcode': raw[2], 'payload': payload, 'raw': raw}


def encode_packet(opcode: int, payload: bytes) -> bytes:
    if not 0 <= opcode <= 255 or len(payload) > 0xffffff:
        raise ValueError('Opcode atau panjang payload tidak valid')
    raw = HEADER + bytes([opcode]) + len(payload).to_bytes(3, 'little') + payload
    raw += bytes([~sum(payload) & 255])
    return b'\xf0' + pack_7bit(raw) + b'\xf7'


def parse_identity(packet: dict) -> dict:
    if packet['opcode'] != 0x11 or len(packet['raw']) != 34:
        raise ValueError('Paket bukan respons identitas 34 byte')
    name = packet['payload'][:16].decode('ascii', errors='backslashreplace').rstrip(' \x00')
    if not name or any(ord(c) < 32 for c in name):
        raise ValueError('Nama perangkat pada respons tidak valid')
    return {'name': name, 'metadata_hex': packet['payload'][16:].hex(' ')}


def device_info_request() -> bytes:
    """Read 20 bytes in region 0, address 0x2100.

    CubeSuite default initialization: 0x5069D0 -> 0x5071F0 -> 0x5063F0,
    read request: 0x507E60 -> 0x5077D0 (opcode 0x23).
    This command does not contain replacement data or invoke a write operation.
    """
    payload = b'\x00' + (0x2100).to_bytes(4, 'little') + (20).to_bytes(3, 'little')
    return encode_packet(0x23, payload)


DEVICE_MODELS = {
    10030: 'Cube Baby', 10130: 'Cube Baby', 20130: 'Cube Baby',
    20030: 'Cube Baby', 20230: 'Cube Baby', 20233: 'Cube Baby',
    20430: 'Cube Baby AC', 20530: 'Cube Baby Bass', 30431: 'Cube Baby Bass',
}


def parse_device_info(packet: dict) -> dict:
    payload = packet['payload']
    if packet['opcode'] != 0x23 or len(payload) != 28:
        raise ValueError('Paket bukan respons baca info perangkat')
    if payload[0] != 0 or int.from_bytes(payload[1:5], 'little') != 0x2100:
        raise ValueError('Region/alamat respons berbeda dari permintaan')
    if int.from_bytes(payload[5:8], 'little') != 20:
        raise ValueError('Panjang data informasi perangkat tidak cocok')
    data = payload[8:]
    # The original 0x5071F0 reads five little-endian 32-bit fields.
    fields = [int.from_bytes(data[i:i+4], 'little') for i in range(0, 20, 4)]
    return {'device_code': fields[1], 'model': DEVICE_MODELS.get(fields[1]),
            'fields_u32': fields, 'data_hex': data.hex(' ')}


IR_SLOT_COUNT = 8
IR_SLOT_STRIDE = 0x1000
IR_SLOT_SIZE = 0x808
IR_RAW_PACKET_LIMIT = 128
IR_READ_CHUNK = IR_RAW_PACKET_LIMIT - 15
IR_STORAGE_LIMIT = 0x80000


def read_request(region: int, address: int, length: int) -> bytes:
    if not 0 <= region <= 255 or not 0 <= address <= 0xffffffff:
        raise ValueError('Region/alamat baca tidak valid')
    if not 1 <= length <= IR_READ_CHUNK or address+length > 0x100000000:
        raise ValueError('Ukuran baca harus 1–113 byte dan tidak melewati batas alamat')
    payload = bytes([region])+address.to_bytes(4, 'little')+length.to_bytes(3, 'little')
    return encode_packet(0x23, payload)


def parse_read_response(packet: dict, region: int, address: int, length: int) -> bytes:
    payload = packet['payload']
    if packet['opcode'] != 0x23 or len(payload) != length+8:
        raise ValueError('Opcode atau panjang respons baca tidak cocok')
    if payload[0] != region or int.from_bytes(payload[1:5], 'little') != address:
        raise ValueError('Region/alamat respons baca tidak cocok')
    if int.from_bytes(payload[5:8], 'little') != length:
        raise ValueError('Ukuran data pada respons baca tidak cocok')
    return payload[8:]


def ir_slot_address(info: dict, slot: int) -> int:
    if info.get('device_code') != 20230 or not 0 <= slot < IR_SLOT_COUNT:
        raise ValueError('Pembacaan slot ini hanya untuk Cube Baby kode 20230, slot 1–8')
    fields = info.get('fields_u32', [])
    if len(fields) != 5:
        raise ValueError('Informasi alamat slot belum tersedia')
    base = fields[4]
    if base <= 0 or base % IR_SLOT_STRIDE or base+7*IR_SLOT_STRIDE+IR_SLOT_SIZE > IR_STORAGE_LIMIT:
        raise ValueError('Alamat penyimpanan IR tidak valid')
    return base+slot*IR_SLOT_STRIDE


def parse_ir_slot(raw: bytes, slot: int, address: int) -> dict:
    """0x4A4070: 4-byte header, float32 Distance/100, 512 float32 coefficients.

    0x4A3ED0 saves this 0x808-byte layout at IR base + slot*0x1000.
    Header meaning is not assumed; readout does not change the active IR.
    """
    import math
    import struct
    if len(raw) != IR_SLOT_SIZE or not 0 <= slot < IR_SLOT_COUNT:
        raise ValueError('Ukuran data atau nomor slot IR tidak cocok')
    values = struct.unpack_from('<513f', raw, 4)
    recognized = all(math.isfinite(v) for v in values) and 0 <= values[0] <= 1
    result = {'slot': slot+1, 'address': address, 'size': len(raw),
              'header_hex': raw[:4].hex(' '), 'raw_hex': raw.hex(' '),
              'format_recognized': recognized, 'all_zero': not any(raw)}
    if recognized:
        result.update(distance_percent=values[0]*100, coefficients=list(values[1:]))
    return result


def flash_write_request(address: int, data: bytes) -> bytes:
    """0x507850/0x506590: region 0, opcode 0x22, max 128 data bytes."""
    if not data or len(data) > 128 or address < 0 or address+len(data) > IR_STORAGE_LIMIT:
        raise ValueError('Alamat/ukuran tulis flash tidak valid')
    return encode_packet(0x22, b'\0'+address.to_bytes(4, 'little')+len(data).to_bytes(3, 'little')+data)


def flash_erase_request(address: int) -> bytes:
    """0x507770/0x5063A0: erase one 4096-byte sector in region 0."""
    if address < 0 or address % IR_SLOT_STRIDE or address+IR_SLOT_STRIDE > IR_STORAGE_LIMIT:
        raise ValueError('Alamat sektor tidak valid')
    return encode_packet(0x21, b'\0'+address.to_bytes(4, 'little'))


def parse_write_ack(packet: dict):
    if packet['opcode'] != 0 or len(packet['payload']) != 1:
        raise ValueError('Bukan ACK tulis/hapus')
    status = packet['payload'][0]
    if status:
        raise RuntimeError(f'Perangkat menolak operasi, kode {status}')


def slot_with_distance(raw: bytes, percent: float) -> bytes:
    import math
    import struct
    if len(raw) != IR_SLOT_SIZE or not math.isfinite(percent) or not 0 <= percent <= 100:
        raise ValueError('Data slot/Distance tidak valid')
    return raw[:4]+struct.pack('<f', percent/100)+raw[8:]

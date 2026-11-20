"""Single candidate identity query; invoked explicitly, never by the monitor."""
import time
from contextlib import ExitStack
import mido
from .midi import message_record
from .protocol import identity_request, decode_packet, parse_identity


def probe_identity(backend, input_name, output_name, timeout=2.0):
    if timeout <= 0 or timeout > 10:
        raise ValueError('Timeout harus lebih dari 0 dan maksimal 10 detik')
    received = []
    with ExitStack() as stack:
        incoming = stack.enter_context(backend.open_input(input_name))
        outgoing = stack.enter_context(backend.open_output(output_name))
        outgoing.send(mido.Message.from_bytes(identity_request()))
        deadline = time.monotonic()+timeout
        while time.monotonic() < deadline:
            message = incoming.poll()
            if message is None:
                time.sleep(0.01)
                continue
            row = message_record(message)
            received.append(row)
            if message.type == 'sysex':
                try:
                    decoded = decode_packet(bytes(message.bytes()))
                except ValueError as exc:
                    row['decode_error'] = str(exc)
                    continue
                row['opcode'] = decoded['opcode']
                row['payload_hex'] = decoded['payload'].hex(' ')
                # Query echoes are not counted as identity responses.
                if decoded['opcode'] == 0x11 and len(decoded['raw']) == 0x22:
                    try:
                        identity = parse_identity(decoded)
                    except ValueError as exc:
                        row['decode_error'] = str(exc)
                        continue
                    return {'status': 'identity_packet_received', 'identity': identity, 'messages': received}
    return {'status': 'no_verified_identity_response', 'messages': received}

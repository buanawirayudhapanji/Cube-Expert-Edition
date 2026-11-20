"""Passive MIDI transport. Does not open an output port or transmit messages."""
from datetime import datetime, timezone


def enumerate_ports():
    import mido
    backend = mido.Backend('mido.backends.rtmidi/LINUX_ALSA')
    return backend, backend.get_input_names(), backend.get_output_names()


def message_record(message, direction="in"):
    return {
        'timestamp': datetime.now(timezone.utc).isoformat(),
        'direction': direction,
        'type': message.type,
        'hex': ' '.join(f'{b:02X}' for b in message.bytes()),
    }

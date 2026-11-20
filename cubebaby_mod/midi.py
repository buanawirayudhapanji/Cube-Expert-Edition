"""Passive MIDI transport. Does not open an output port or transmit messages."""
from datetime import datetime, timezone
import sys


def enumerate_ports():
    import mido
    api = 'WINDOWS_MM' if sys.platform == 'win32' else 'LINUX_ALSA'
    backend = mido.Backend('mido.backends.rtmidi/' + api)
    return backend, backend.get_input_names(), backend.get_output_names()


def message_record(message, direction="in"):
    return {
        'timestamp': datetime.now(timezone.utc).isoformat(),
        'direction': direction,
        'type': message.type,
        'hex': ' '.join(f'{b:02X}' for b in message.bytes()),
    }

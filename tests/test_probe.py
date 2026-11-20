import unittest
from unittest.mock import patch
import mido
from cubebaby_mod.codec import pack_7bit
from cubebaby_mod.probe import probe_identity
from cubebaby_mod.protocol import identity_request


class Port:
    def __init__(self, messages=()):
        self.messages = list(messages)
        self.sent = []
        self.closed = False
    def __enter__(self): return self
    def __exit__(self, *args): self.closed = True
    def send(self, message): self.sent.append(bytes(message.bytes()))
    def poll(self): return self.messages.pop(0) if self.messages else None


class Backend:
    def __init__(self, messages):
        self.incoming = Port(messages)
        self.outgoing = Port()
    def open_input(self, name): return self.incoming
    def open_output(self, name): return self.outgoing


class ProbeTests(unittest.TestCase):
    def test_only_one_query_then_verified_response(self):
        payload = b'A'*27
        raw = b'\x00\x59\x11\x1b\x00\x00'+payload+bytes([~sum(payload)&255])
        response = mido.Message.from_bytes(b'\xf0'+pack_7bit(raw)+b'\xf7')
        backend = Backend([mido.Message.from_bytes(identity_request()), response])
        result = probe_identity(backend, 'in', 'out')
        self.assertEqual(result['status'], 'identity_packet_received')
        self.assertEqual(backend.outgoing.sent, [identity_request()])
        self.assertEqual(len(result['messages']), 2)
        self.assertTrue(backend.incoming.closed and backend.outgoing.closed)

    def test_timeout_no_retry_and_cleanup(self):
        backend = Backend([])
        with patch('cubebaby_mod.probe.time.monotonic', side_effect=[0, 3]):
            result = probe_identity(backend, 'in', 'out')
        self.assertEqual(result['status'], 'no_verified_identity_response')
        self.assertEqual(len(backend.outgoing.sent), 1)
        self.assertTrue(backend.incoming.closed and backend.outgoing.closed)

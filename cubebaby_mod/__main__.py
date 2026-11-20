"""Run with python -m cubebaby_mod [--list | --monitor PORT]."""
import argparse
import json
import sys
from .midi import enumerate_ports, message_record


def main():
    parser = argparse.ArgumentParser(description='CubeBabyMOD — monitor MIDI dan query identitas eksperimental')
    action = parser.add_mutually_exclusive_group()
    action.add_argument('--list', action='store_true', help='Daftar port MIDI')
    action.add_argument('--monitor', metavar='PORT', help='Pantau input, gunakan nama lengkap port')
    action.add_argument('--identify', metavar='INPUT', help='Kirim satu query identitas eksperimental')
    parser.add_argument('--output', metavar='OUTPUT', help='Port output untuk --identify')
    args = parser.parse_args()
    if bool(args.identify) != bool(args.output):
        parser.error('--identify dan --output harus dipakai bersama')
    if not args.list and args.monitor is None and args.identify is None:
        from .gui import run
        return run()
    try:
        backend, inputs, outputs = enumerate_ports()
        if args.list:
            print(json.dumps({'inputs': inputs, 'outputs': outputs}, indent=2))
            return 0
        if args.identify is not None:
            from .probe import probe_identity
            if args.identify not in inputs or args.output not in outputs:
                raise ValueError('Nama port input/output tidak tersedia; periksa --list')
            result = probe_identity(backend, args.identify, args.output)
            print(json.dumps(result, indent=2))
            return 0 if result['status'] == 'identity_packet_received' else 2
        if args.monitor not in inputs:
            raise ValueError(f'Port input tidak tersedia: {args.monitor}')
        with backend.open_input(args.monitor) as port:
            print('Memantau input tanpa mengirim perintah. Ctrl+C untuk berhenti.', file=sys.stderr)
            for message in port:
                print(json.dumps(message_record(message)), flush=True)
        return 0
    except KeyboardInterrupt:
        return 0
    except (RuntimeError, OSError, ValueError, ImportError) as exc:
        print(f'MIDI belum dapat diakses: {exc}', file=sys.stderr)
        return 1


if __name__ == '__main__':
    raise SystemExit(main())

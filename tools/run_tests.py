"""Run regression tests with a per-case watchdog for unattended GUI build runners."""
import argparse
import faulthandler
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--timeout', type=int, default=60)
    args = parser.parse_args()
    if args.timeout < 1:
        parser.error('Timeout harus positif.')

    class Result(unittest.TextTestResult):
        def startTest(self, test):
            super().startTest(test)
            faulthandler.dump_traceback_later(args.timeout, exit=True)

        def stopTest(self, test):
            faulthandler.cancel_dump_traceback_later()
            super().stopTest(test)

    suite = unittest.defaultTestLoader.discover(str(ROOT / 'tests'))
    result = unittest.TextTestRunner(verbosity=2, resultclass=Result).run(suite)
    return 0 if result.wasSuccessful() else 1


if __name__ == '__main__':
    raise SystemExit(main())

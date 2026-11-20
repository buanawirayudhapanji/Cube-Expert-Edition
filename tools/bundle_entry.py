"""Frozen launcher and installation checks; does not import tests or developer data."""
import json
import os
import sys
import traceback
from pathlib import Path

if not getattr(sys, 'frozen', False):
    sys.path.insert(0, str(Path(__file__).resolve().parent.parent))


def launch():
    from cubebaby_mod import __version__
    from PySide6.QtCore import QCoreApplication
    QCoreApplication.setApplicationName('CubeBabyMOD')
    QCoreApplication.setOrganizationName('CubeBabyMOD')
    QCoreApplication.setApplicationVersion(__version__)
    if len(sys.argv) == 3 and sys.argv[1] == '--self-test':
        from cubebaby_mod.bundle_support import self_test
        return self_test(Path(sys.argv[2]))
    if sys.argv[1:2] in (['--install-user'], ['--uninstall-user']):
        from cubebaby_mod.bundle_support import install_user, uninstall_user
        quiet = '--quiet' in sys.argv[2:]
        if not quiet:
            from PySide6.QtWidgets import QApplication, QMessageBox
            app = QApplication.instance() or QApplication(sys.argv)
            if sys.argv[1] == '--uninstall-user':
                answer = QMessageBox.question(None, 'Hapus CubeBabyMOD',
                    'Hapus aplikasi dari akun ini? Koleksi dan cadangan tetap disimpan.',
                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
                if answer != QMessageBox.Yes:
                    return 0
        result = install_user() if sys.argv[1] == '--install-user' else uninstall_user()
        if not quiet:
            QMessageBox.information(None, 'CubeBabyMOD',
                'Aplikasi terpasang. Buka CubeBabyMOD dari menu aplikasi.' if 'program' in result else
                'Aplikasi dihapus. Koleksi dan cadangan tetap disimpan.')
        if sys.stdout is not None:
            print(json.dumps(result, indent=2))
        return 0
    from cubebaby_mod.__main__ import main
    return main()


try:
    raise SystemExit(launch())
except Exception:
    detail = traceback.format_exc()
    if len(sys.argv) == 3 and sys.argv[1] == '--self-test':
        Path(sys.argv[2]).write_text(json.dumps({'ok': False, 'error': detail}), encoding='utf-8')
    else:
        from cubebaby_mod.app_paths import data_root
        directory = data_root()
        directory.mkdir(parents=True, exist_ok=True)
        (directory / 'startup-error.log').write_text(detail, encoding='utf-8')
    if sys.stderr is not None:
        print(detail, file=sys.stderr)
    raise SystemExit(1)

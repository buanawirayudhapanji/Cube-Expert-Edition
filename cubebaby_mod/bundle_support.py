"""Verify a frozen build without opening MIDI output or capturing audio."""
import json
import os
import sys
import tempfile
from pathlib import Path


def self_test(destination):
    from PySide6.QtCore import QCoreApplication, QEvent, qVersion
    from PySide6.QtWidgets import QApplication
    from PySide6 import QtMultimedia
    import rtmidi
    from . import __version__
    from .app_paths import backup_directory, data_root
    from .collection import Collection, make_item, load_item
    from .presets import FACTORY_PRESETS
    from .suite_gui import SuiteWindow, ASSETS

    with tempfile.TemporaryDirectory(prefix='cubebaby-bundle-test-') as temporary:
        os.environ['CUBEBABY_DATA_DIR'] = temporary
        os.environ['CUBEBABY_LIBRARY_DIR'] = str(Path(temporary) / 'library_data')
        os.environ['CUBEBABY_UI_SETTINGS'] = str(Path(temporary) / 'studio.ini')
        app = QApplication.instance() or QApplication([sys.argv[0], '-platform', 'offscreen'])
        window = SuiteWindow()
        window.studio_ui.set_reduced_motion(True)
        window.resize(1000, 680)
        window.show()
        for _ in range(8):
            app.processEvents()
        api = rtmidi.API_WINDOWS_MM if sys.platform == 'win32' else rtmidi.API_LINUX_ALSA
        assert api in rtmidi.get_compiled_api(), 'API MIDI target tidak tersedia'
        assert len((ASSETS / 'factory/cubebaby-20230-ir.bin').read_bytes()) == 8 * 4096
        assert hasattr(QtMultimedia, 'QAudioSource')
        store = Collection()
        item = make_item('preset', 'Uji bundel', FACTORY_PRESETS[:16])
        saved = store.save(item)
        assert load_item(saved) == item
        backup_directory().mkdir(parents=True, exist_ok=True)
        assert str(store.root).startswith(str(Path(temporary)))
        assert window.studio_ui.stack.count() == 4
        result = {
            'ok': True, 'version': __version__, 'platform': sys.platform, 'qt': qVersion(),
            'frozen': bool(getattr(sys, 'frozen', False)), 'pages': 4,
            'midi_api': rtmidi.get_api_name(api), 'multimedia': True,
            'factory_ir_bytes': 8 * 4096, 'collection_round_trip': True,
            'user_data_writable': data_root() == Path(temporary),
            'physical_pedal_tested': False,
        }
        window.close()
        window.deleteLater()
        QCoreApplication.sendPostedEvents(None, QEvent.DeferredDelete)
        app.processEvents()
        destination = Path(destination).resolve()
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    return 0


def _linux_install_paths():
    base = Path(os.environ.get('XDG_DATA_HOME') or Path.home() / '.local' / 'share')
    return base / 'CubeBabyMOD/program', base / 'applications/cubebaby-mod.desktop'


def _desktop_command(path):
    value = str(Path(path).resolve())
    if '\n' in value or '\r' in value:
        raise ValueError('Lokasi instalasi mengandung karakter baris baru.')
    for character in ('\\', '"', '`', '$'):
        value = value.replace(character, '\\' + character)
    return '"' + value.replace('%', '%%') + '"'


def install_user(image=None, icon=None):
    import shutil
    if sys.platform != 'linux':
        raise ValueError('Gunakan Setup.exe untuk instalasi Windows.')
    image = Path(image or os.environ.get('APPIMAGE', '')).resolve()
    if not image.is_file() or not os.environ.get('APPIMAGE') and image.name != 'CubeBabyMOD.AppImage':
        raise ValueError('Jalankan instalasi dari file AppImage.')
    icon = Path(icon or Path(__file__).parent / 'assets/installer/cubebaby-mod.png')
    program, desktop = _linux_install_paths()
    target = program / 'CubeBabyMOD.AppImage'
    command = _desktop_command(target)
    program.mkdir(parents=True, exist_ok=True)
    desktop.parent.mkdir(parents=True, exist_ok=True)
    if image != target.resolve():
        temporary = program / '.CubeBabyMOD.AppImage.new'
        shutil.copy2(image, temporary)
        temporary.chmod(0o755)
        os.replace(temporary, target)
    shutil.copy2(icon, program / 'cubebaby-mod.png')
    entry = ('[Desktop Entry]\nType=Application\nName=CubeBabyMOD\n'
             'Comment=Editor efek dan koleksi IR Cube Baby\n'
             f'Exec={command}\nIcon={program / "cubebaby-mod.png"}\n'
             'Terminal=false\nCategories=AudioVideo;Audio;\nStartupNotify=true\n')
    temporary = desktop.with_suffix('.desktop.new')
    temporary.write_text(entry, encoding='utf-8')
    os.replace(temporary, desktop)
    return {'program': str(target), 'desktop_entry': str(desktop)}


def uninstall_user():
    if sys.platform != 'linux':
        raise ValueError('Gunakan uninstaller Windows.')
    program, desktop = _linux_install_paths()
    desktop.unlink(missing_ok=True)
    for name in ('CubeBabyMOD.AppImage', 'cubebaby-mod.png', '.CubeBabyMOD.AppImage.new'):
        (program / name).unlink(missing_ok=True)
    try:
        program.rmdir()
    except OSError:
        pass
    return {'data_preserved': True}

from pathlib import Path
import os
from PyInstaller.utils.hooks import copy_metadata

root = Path(SPECPATH).parent
icons = Path(os.environ['CUBEBABY_BUILD_ICON_DIR'])
metadata = []
for package in ('mido', 'python-rtmidi', 'PySide6_Essentials', 'PySide6_Addons', 'shiboken6'):
    metadata += copy_metadata(package)
analysis = Analysis(
    [str(root / 'tools' / 'bundle_entry.py')],
    pathex=[str(root)],
    datas=[(str(root / 'cubebaby_mod' / 'assets'), 'cubebaby_mod/assets'),
           (str(icons / 'cubebaby-mod.png'), 'cubebaby_mod/assets/installer')] + metadata,
    hiddenimports=['mido.backends.rtmidi', 'rtmidi', 'PySide6.QtMultimedia'],
    excludes=['tkinter', 'PyQt5', 'PyQt6', 'PySide2'],
)
archive = PYZ(analysis.pure)
executable = EXE(
    archive, analysis.scripts, [], exclude_binaries=True,
    name='CubeBabyMOD', console=False, icon=str(icons / 'cubebaby-mod.ico'),
)
bundle = COLLECT(executable, analysis.binaries, analysis.datas, name='CubeBabyMOD')

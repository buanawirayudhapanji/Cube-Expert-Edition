"""Writable user data for installed bundles; keep source checkout paths unchanged."""
import os
import sys
from pathlib import Path


def data_root():
    override = os.environ.get('CUBEBABY_DATA_DIR')
    if override:
        return Path(override).expanduser()
    if not getattr(sys, 'frozen', False):
        return Path(__file__).resolve().parent.parent
    if sys.platform == 'win32':
        base = Path(os.environ.get('LOCALAPPDATA') or Path.home() / 'AppData' / 'Local')
    elif sys.platform == 'darwin':
        base = Path.home() / 'Library' / 'Application Support'
    else:
        base = Path(os.environ.get('XDG_DATA_HOME') or Path.home() / '.local' / 'share')
    return base / 'CubeBabyMOD'


def backup_directory():
    return data_root() / 'backups'

"""Create a source snapshot, excluding original executables and user data."""
from pathlib import Path
from zipfile import ZipFile, ZIP_DEFLATED

ROOT = Path(__file__).resolve().parent.parent
destination = ROOT/'CubeBabyMOD-cubesuite-editor.zip'
with ZipFile(destination, 'w', ZIP_DEFLATED) as archive:
    for name in ('README.md', 'INSTALL.md', 'PANDUAN_BANK.md', '.gitignore', '.dockerignore', 'requirements.txt', 'requirements-build.txt', '.github', 'packaging', 'cubebaby_mod', 'tests', 'tools', 'analysis'):
        source = ROOT/name
        paths = source.rglob('*') if source.is_dir() else [source]
        for path in sorted(paths):
            if path.is_file() and '__pycache__' not in path.parts and path.suffix not in ('.pyc', '.pyo'):
                archive.write(path, path.relative_to(ROOT))
print(destination)

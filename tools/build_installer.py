"""Build native bundles, Linux AppImage/install archive, or Windows Setup.exe."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import platform
import shutil
import subprocess
import sys
import tarfile
import urllib.request

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
from cubebaby_mod import __version__


def run(command, **kwargs):
    print('+', ' '.join(map(str, command)), flush=True)
    subprocess.run(list(map(str, command)), check=True, **kwargs)


def icons(directory):
    os.environ.setdefault('QT_QPA_PLATFORM', 'offscreen')
    from PySide6.QtWidgets import QApplication
    from PySide6.QtGui import QPixmap, QPainter, QFont
    from PySide6.QtCore import Qt
    from cubebaby_mod.theme_tokens import qc
    app = QApplication.instance() or QApplication([])
    directory.mkdir(parents=True, exist_ok=True)
    tile = QPixmap(256, 256)
    tile.fill(qc('accent', False))
    painter = QPainter(tile)
    painter.setRenderHint(QPainter.TextAntialiasing)
    painter.setPen(qc('on_accent', False))
    font = QFont(app.font())
    font.setPixelSize(112)
    font.setBold(True)
    painter.setFont(font)
    painter.drawText(tile.rect(), Qt.AlignCenter, 'CB')
    painter.end()
    for suffix in ('png', 'ico'):
        if not tile.save(str(directory / ('cubebaby-mod.' + suffix))):
            raise RuntimeError('Gagal membuat ikon ' + suffix)


def tool(name, work):
    metadata = json.loads((ROOT / 'packaging/toolchain.json').read_text())[name]
    target = work / name
    target.parent.mkdir(parents=True, exist_ok=True)
    if not target.exists() or hashlib.sha256(target.read_bytes()).hexdigest() != metadata['sha256']:
        with urllib.request.urlopen(metadata['url'], timeout=90) as response:
            payload = response.read()
        if hashlib.sha256(payload).hexdigest() != metadata['sha256']:
            raise RuntimeError('Checksum alat build berubah: ' + name)
        target.write_bytes(payload)
    target.chmod(0o755)
    return target


def appimage(bundle, work, output, icon_dir, appimagetool=None):
    appdir = work / 'CubeBabyMOD.AppDir'
    if appdir.exists():
        shutil.rmtree(appdir)
    payload = appdir / 'usr/lib/cubebaby-mod'
    shutil.copytree(bundle, payload, symlinks=True)
    shutil.copy2(icon_dir / 'cubebaby-mod.png', appdir / 'cubebaby-mod.png')
    (appdir / '.DirIcon').symlink_to('cubebaby-mod.png')
    (appdir / 'cubebaby-mod.desktop').write_text(
        '[Desktop Entry]\nType=Application\nName=CubeBabyMOD\n'
        'Comment=Editor efek dan koleksi IR Cube Baby\nExec=CubeBabyMOD\n'
        'Icon=cubebaby-mod\nTerminal=false\nCategories=AudioVideo;Audio;\n'
        f'X-AppImage-Version={__version__}\n', encoding='utf-8')
    (appdir / 'AppRun').write_text(
        '#!/bin/sh\nset -eu\n'
        'app_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)\n'
        'if [ -z "${QT_QPA_PLATFORMTHEME:-}" ] && [ -n "${DBUS_SESSION_BUS_ADDRESS:-}" ]; then\n'
        '    export QT_QPA_PLATFORMTHEME=xdgdesktopportal\nfi\n'
        'exec "$app_dir/usr/lib/cubebaby-mod/CubeBabyMOD" "$@"\n', encoding='utf-8')
    (appdir / 'AppRun').chmod(0o755)
    if appimagetool is None:
        executable = tool('appimagetool', work / 'tools')
        run([executable, '--appimage-extract'], cwd=executable.parent, stdout=subprocess.DEVNULL)
        appimagetool = executable.parent / 'squashfs-root/AppRun'
    runtime = tool('runtime', work / 'tools')
    artifact = output / f'CubeBabyMOD-{__version__}-linux-x86_64.AppImage'
    env = os.environ.copy()
    env.pop('APPIMAGE', None)
    env.pop('APPDIR', None)
    env['ARCH'] = 'x86_64'
    run([appimagetool, '--runtime-file', runtime, appdir, artifact], env=env)
    artifact.chmod(0o755)
    smoke = output / 'linux-bundle-check.json'
    smoke_env = os.environ.copy()
    smoke_env['APPIMAGE'] = str(artifact)
    run([appdir / 'AppRun', '--self-test', smoke], env=smoke_env, timeout=90)
    stage = work / 'linux-installer'
    stage.mkdir(exist_ok=True)
    shutil.copy2(artifact, stage / 'CubeBabyMOD.AppImage')
    installer = stage / 'install.sh'
    installer.write_text('#!/bin/sh\nset -eu\n'
                         'here=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)\n'
                         'exec "$here/CubeBabyMOD.AppImage" --install-user\n', encoding='utf-8')
    installer.chmod(0o755)
    (stage / 'README.txt').write_text(
        'CubeBabyMOD untuk Linux x86_64 (glibc 2.35 atau lebih baru).\n'
        'Jalankan ./install.sh untuk memasang ke akun pengguna dan menu aplikasi.\n'
        'Tanpa sudo dan tanpa instalasi Python. File AppImage juga dapat langsung dijalankan.\n'
        'Untuk menghapus aplikasi: jalankan AppImage dengan --uninstall-user.\n'
        'Koleksi/cadangan tetap disimpan; uninstall tidak menghapus data tersebut.\n', encoding='utf-8')
    archive = output / f'CubeBabyMOD-{__version__}-linux-x86_64-install.tar.gz'
    with tarfile.open(archive, 'w:gz') as stream:
        for item in sorted(stage.iterdir()):
            stream.add(item, arcname='CubeBabyMOD/' + item.name)
    return [artifact, archive]


def windows(bundle, output, icon_dir, iscc=None):
    if iscc is None:
        iscc = shutil.which('ISCC.exe')
        for base in (os.environ.get('ProgramFiles(x86)'), os.environ.get('ProgramFiles')):
            if not iscc and base:
                candidates = sorted(Path(base).glob('Inno Setup */ISCC.exe'), reverse=True)
                if candidates:
                    iscc = candidates[0]
    if not iscc:
        raise RuntimeError('Inno Setup 6 belum tersedia; pasang lalu jalankan ulang build.')
    run([iscc, f'/DAppVersion={__version__}', f'/DBundleDir={bundle}',
         f'/DOutputDir={output}', f'/DIconFile={icon_dir / "cubebaby-mod.ico"}',
         ROOT / 'packaging/windows/CubeBabyMOD.iss'])
    run([bundle / 'CubeBabyMOD.exe', '--self-test', output / 'windows-bundle-check.json'], timeout=90)
    return [output / f'CubeBabyMOD-{__version__}-windows-x64-setup.exe']


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--format', choices=('linux', 'windows', 'bundle'), required=True)
    parser.add_argument('--work-dir', type=Path, default=ROOT / 'build/package')
    parser.add_argument('--output-dir', type=Path, default=ROOT / 'dist')
    parser.add_argument('--appimagetool', type=Path)
    parser.add_argument('--iscc', type=Path)
    args = parser.parse_args()
    if args.format == 'windows' and sys.platform != 'win32':
        parser.error('Installer Windows harus dibangun di Windows.')
    if args.format == 'linux' and (sys.platform != 'linux' or platform.machine() != 'x86_64'):
        parser.error('AppImage ini harus dibangun pada Linux x86_64.')
    work, output = args.work_dir.resolve(), args.output_dir.resolve()
    work.mkdir(parents=True, exist_ok=True)
    output.mkdir(parents=True, exist_ok=True)
    icon_dir = work / 'icons'
    icons(icon_dir)
    env = os.environ.copy()
    env['CUBEBABY_BUILD_ICON_DIR'] = str(icon_dir)
    env.setdefault('PYINSTALLER_CONFIG_DIR', str(work / 'cache'))
    run([sys.executable, '-m', 'PyInstaller', '--noconfirm', '--clean',
         '--distpath', work / 'frozen', '--workpath', work / 'pyinstaller',
         ROOT / 'packaging/CubeBabyMOD.spec'], env=env)
    bundle = work / 'frozen/CubeBabyMOD'
    for name in ('README.md', 'PANDUAN_BANK.md', 'packaging/THIRD_PARTY_NOTICES.txt'):
        shutil.copy2(ROOT / name, bundle / Path(name).name)
    if args.format == 'linux':
        artifacts = appimage(bundle, work, output, icon_dir, args.appimagetool)
    elif args.format == 'windows':
        artifacts = windows(bundle, output, icon_dir, args.iscc)
    else:
        artifacts = [bundle]
    sums = []
    for artifact in artifacts:
        if artifact.is_file():
            sums.append(hashlib.sha256(artifact.read_bytes()).hexdigest() + '  ' + artifact.name)
    if sums:
        (output / ('SHA256SUMS-' + args.format + '.txt')).write_text('\n'.join(sums) + '\n')
    print('Paket selesai:', *map(str, artifacts), sep='\n')


if __name__ == '__main__':
    main()

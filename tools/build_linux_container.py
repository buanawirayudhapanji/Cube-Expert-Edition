"""Build an AppImage on Debian 12 / Python 3.12 with data/source mounted separately."""
import argparse
import os
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--skip-image-build', action='store_true')
    args = parser.parse_args()
    image = 'cubebaby-mod-builder:0.1.0'
    output = ROOT / 'dist'
    output.mkdir(exist_ok=True)
    if not args.skip_image_build:
        subprocess.run(['docker', 'build', '-f', str(ROOT / 'packaging/Dockerfile.linux'),
                        '-t', image, str(ROOT)], check=True)
    subprocess.run(['docker', 'run', '--rm', '--user', f'{os.getuid()}:{os.getgid()}',
                    '-v', f'{ROOT}:/src:ro', '-v', f'{output}:/out', image,
                    'python', '/src/tools/build_installer.py', '--format', 'linux',
                    '--work-dir', '/tmp/cubebaby-package', '--output-dir', '/out'], check=True)


if __name__ == '__main__':
    main()

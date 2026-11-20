# Installer CubeBabyMOD 0.1.0

## Linux x86_64

Paket dibangun pada Ubuntu 22.04, untuk sistem glibc 2.35 atau lebih baru. Python dan Qt sudah disertakan. Audio/MIDI tetap memakai layanan dan izin perangkat sistem.

- Jalankan file `CubeBabyMOD-0.1.0-linux-x86_64.AppImage` setelah diberi izin eksekusi.
- Untuk memasang ke menu aplikasi, ekstrak `CubeBabyMOD-0.1.0-linux-x86_64-install.tar.gz`, lalu jalankan `./install.sh`. Tidak memakai sudo.
- Aplikasi dipasang di `~/.local/share/CubeBabyMOD/program`; data Koleksi dan cadangan berada di folder terpisah di bawah `~/.local/share/CubeBabyMOD`.
- Untuk uninstall, jalankan AppImage dengan `--uninstall-user`. Koleksi dan cadangan tetap disimpan.
- Jika FUSE tidak tersedia, runtime AppImage mendukung `--appimage-extract-and-run` atau ekstrak dengan `--appimage-extract` lalu jalankan `squashfs-root/AppRun`.
- Pemilih file menggunakan integrasi sistem. Launcher memilih portal desktop bila sesi D-Bus tersedia dan platform theme belum ditentukan.

## Windows x64

Jalankan `CubeBabyMOD-0.1.0-windows-x64-setup.exe`. Mendukung Windows 10/11 x64. Installer per pengguna tidak memerlukan hak administrator; pintasan desktop opsional, menu aplikasi dan uninstaller disertakan.

Program berada di `%LOCALAPPDATA%\Programs\CubeBabyMOD`. Koleksi dan cadangan berada di `%LOCALAPPDATA%\CubeBabyMOD`, sehingga uninstall atau pembaruan aplikasi tidak menghapus data tersebut. Pengaturan UI tetap memakai QSettings CubeBabyMOD/Studio.

## Data dan verifikasi

Paket tidak menyertakan koleksi, cadangan, konfigurasi lokal, log, kredensial atau distribusi CubeSuite asli dari folder pengembang. Aset aplikasi/factory IR yang dipakai source disertakan. Data dari checkout lama tidak dipindahkan otomatis; ekspor/impor JSON tetap dapat digunakan.

`SHA256SUMS-linux.txt` / `SHA256SUMS-windows.txt` memuat checksum hasil build. File `*-bundle-check.json` dan `windows-installed-check.json` adalah hasil pengujian executable, bukan bukti uji pedal fisik. Seluruh uji yang mengubah preset/IR memakai backend simulasi; perangkat/audio langsung tetap perlu diuji pengguna.

## Membuat ulang paket

Persyaratan build: Python 3.10+ pada OS target, dependency dalam `requirements-build.txt`, Inno Setup 6+ untuk Windows; atau Docker untuk Linux. PyInstaller harus dijalankan pada OS target.

Linux dengan Docker, dari root repo:

```bash
python3 tools/build_linux_container.py
```

Linux tanpa Docker (hasil mengikuti baseline glibc mesin build):

```bash
python -m pip install -r requirements-build.txt
python tools/build_installer.py --format linux
```

Windows PowerShell, dengan Python dan Inno Setup tersedia:

```powershell
python -m venv .venv-build
.\.venv-build\Scripts\python -m pip install -r requirements-build.txt
.\.venv-build\Scripts\python tools\build_installer.py --format windows
```

Hasil berada di `dist/`. File `.spec` mengumpulkan assets, metadata/lisensi dependency, backend RtMidi dinamis dan QtMultimedia; hooks Qt PyInstaller mengumpulkan plugin platform dan multimedia. Alat AppImage diperiksa menggunakan SHA-256 yang dipatok di `packaging/toolchain.json`; jika rilis continuous berubah, perbarui URL/checksum setelah memeriksa rilis resmi.

Workflow `.github/workflows/build-installers.yml` membangun kedua platform lewat GitHub Actions pada branch `codex/installers-*`; workflow juga menyediakan trigger manual setelah tersedia pada default branch. Windows menjalankan tes source, membangun Setup, memasang secara silent ke folder uji, menguji executable yang terpasang, lalu menghapus instalasi uji.

Untuk pengembangan source, `python -m cubebaby_mod` tetap memakai `library_data/` dan `backups/` pada proyek. Override `CUBEBABY_DATA_DIR` mengubah root data; `CUBEBABY_LIBRARY_DIR` tetap memiliki prioritas untuk Koleksi.

# Kesetaraan CubeSuite 2.8.10 — Cube Baby 20230

Lingkup awal: seluruh fitur Cube Baby, bukan modul perangkat lain di CubeSuite.
Pengguna kemudian mengizinkan bank virtual, konversi IR, A/B, serta preset file.
Tidak ada penambahan model amp DSP atau slot fisik.
Status keseluruhan: editor utama tersedia; belum identik 100%.

Prioritas terbaru pengguna: **kesetaraan fitur dan perilaku terlebih dahulu**.
Tampilan sederhana diterima; kesamaan piksel/style bukan syarat tahap ini.

| Fitur | Implementasi | Bukti fisik |
|---|---|---|
| Deteksi MIDI, identitas, info model | Tersedia | Dikonfirmasi pengguna |
| Delapan slot IR, baca dan simpan Distance | Tersedia, baca ulang sektor | Slot 2 dikonfirmasi |
| Backup/pemulihan sektor | Tersedia | Pemulihan dikonfirmasi pengguna |
| Impor WAV + konversi otomatis | PCM8/16/24/32, float32/64, extensible, mono/stereo → 48 kHz mono/512 sampel | Konversi diuji; uji suara pedal masih diperlukan |
| Pilih banyak WAV, folder, refresh, satu klik preview | Tersedia | Menunggu uji pedal |
| Preview IR dan Distance RAM | Backup/verifikasi data RAM, perintah aktivasi dengan ACK; kontrol 0x764 tidak dianggap status tetap | Pengguna membuktikan data IR cocok; cek byte kontrol lama menolak pada langkah terakhir. Perbaikan terbaru perlu konfirmasi suara pedal |
| Preset A/B/C, 10 parameter | Tersedia, alamat/rentang dari binary | Menunggu uji pedal |
| SW1/SW2/SW3 dan kelompok kontrol | Tersedia | Menunggu uji pedal |
| Save Effects / Factory Effects | Tersedia, baca ulang 48 byte | Menunggu uji pedal |
| USB Loopback | Tersedia, register 0x3000 | Menunggu uji pedal |
| Factory IR | Tersedia, 8 sektor BFI.bin | Simulasi 8 backup/verifikasi lulus |
| Ikon/gambar pedal asli | Diekstrak dari Qt resource program asli | Tampil pada uji GUI offscreen |
| Layout/piksel/stylesheet identik | Ditunda sesuai arahan pengguna | Bukan syarat tahap fitur |
| Bank/preset virtual offline, impor target A/B/C | Tersedia; snapshot/backup/readback | Simulasi lulus, belum uji fisik |
| Bank IR1–8 + preset A/B/C | Tersedia; pemetaan sparse dan cadangan sebelum penulisan | Simulasi kegagalan sebagian lulus |
| Perbandingan A/B IR | Tersedia; preview RAM, Distance/peak opsional | Simulasi tanpa flash write lulus |
| Firmware Update lokal/cloud/bootloader | Belum diterapkan | Tidak diuji/dikirim |

## Yang masih diperlukan untuk menyatakan versi identik

1. Membandingkan perilaku fungsi panel asli dengan editor Linux, termasuk
   pemilihan slot, pemilihan file, dialog dan preview otomatis. Kesamaan
   ukuran/posisi/style kontrol ditunda.
2. Konversi WAV otomatis telah ditambahkan sesuai permintaan modifikasi baru.
   Jalur legacy CubeSuite dipertahankan sebagai helper analisis, bukan default
   import GUI. Konfirmasi hasil suara konversi dan A/B pada pedal masih diperlukan.
3. Memetakan tuntas updater firmware: format paket baru/lama, bootloader,
   pemilihan hardware, urutan hapus/tulis, checksum dan reconnection.
   `CubeSuite/bin/pdf/CUBE_BABY.pdf` menyebut beberapa revisi hardware dengan
   firmware berbeda. Berkas `cubebaby_A_20220706.up` bawaan memakai header
   CONFIG; parser baru pada `0x500ED0` memeriksa Data Number. Kecocokan keduanya
   belum terbukti; nama Cube Baby atau VID/PID saja belum cukup memilih image.
4. Konfirmasi pedal fisik untuk efek, preview WAV/Distance, Loopback, Save
   Effects dan kedua factory reset. Simulasi membuktikan urutan kode dan
   penanganan error, belum membuktikan respons firmware yang sebenarnya.

## Penelusuran model dan menu

`0x4E01A0` menguji bit fitur dari tabel model terhadap daftar QString mulai
`0x75C438`. Indeks 7 (`0x80`) menunjuk `0x754748`, teks UTF-16 `Cube Baby*`.
Model 20230 memiliki bit `0x80`, jadi editor terkait adalah ctor `0x49DEE0`
(Jun), bukan hanya editor IR klasik ctor `0x4A3510`. Ini alasan panel efek
diterapkan untuk model pengguna. Profil tulis tetap persis metadata yang
dibaca dari pedal; nama/VID/PID saja tidak mengaktifkan penulisan.

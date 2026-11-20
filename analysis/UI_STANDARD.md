# Standar tipografi dan spacing Studio

Standar ini mengadaptasi peran teks Material Design untuk Qt Widgets desktop. Ukuran dalam logical pixel Qt, bukan sp/dp Android. Tidak menambah font, library atau aset. Identitas kuning dan tema gelap/terang tetap.

Referensi primer: [Material typography](https://github.com/material-components/material-components-android/blob/master/docs/theming/Typography.md) dan [spacing 8/4](https://m2.material.io/design/layout/spacing-methods.html). Sumber nilai aplikasi: `cubebaby_mod/ui_metrics.py`; penerapan QSS: `cubebaby_mod/theme_styles.py`.

## Hirarki teks

| Peran | Ukuran | Weight | Penggunaan |
| --- | ---: | ---: | --- |
| pageTitle | 28 | 700 | Judul keempat halaman |
| brand / logo | 20 | 700 | Identitas aplikasi |
| cardTitle | 16 | 700 | Judul seluruh panel, termasuk IR A/B |
| fieldLabel | 14 | 500 | Label parameter/target, status koneksi, judul kelompok form |
| body / subtitle | 14 | 400 | Instruksi utama, isi, deskripsi halaman |
| button | 14 | 500 | Teks tombol; aksi utama boleh 700 |
| muted / statusText | 12 | 400 | Teks bantu, metadata, catatan dan footer |
| eyebrow / badge | 12 | 500 | Kategori, nama kelompok navigasi dan badge |

Font sans aplikasi memakai pilihan yang sama seperti sebelumnya: Inter bila tersedia, jika tidak Noto Sans/fallback Qt. Semua ukuran bersumber dari token. Log MIDI dan angka meter memakai monospace untuk memudahkan pembacaan angka. Label tidak dikecilkan saat mode ringkas. Tinggi baris widget mengikuti font metrics native Qt; teks delegate memakai ruang baris 20 px untuk judul dan 16 px untuk metadata.

Judul panel tidak dipakai untuk teks instruksi/status. Nama pengguna/file tidak diubah. A/B kini memakai judul panel yang sama, tanpa override ukuran lokal. Metadata Koleksi dinaikkan dari 11 menjadi 12 px dan baris item diberi ruang tambahan.

## Spacing

Grid dasar 4 px; nilai yang digunakan 4 / 8 / 12 / 16 / 24 / 32 px.

| Relasi | Normal | Ringkas |
| --- | ---: | ---: |
| Padding panel utama, keempat sisi | 16 | 12 |
| Jarak antar isi panel | 12 | 8 |
| Padding modul di dalam panel | 12 | 8 |
| Jarak isi modul | 8 | 4 |
| Pasangan label dan keterangan | 4 | 4 |
| Jarak default antar kontrol/grid | 8 | 8 |
| Jarak antar kolom halaman | 16 | 16 |
| Padding dialog | 24 | 24 |
| Jarak kelompok dialog | 12 | 12 |
| Padding tombol/input, vertikal | 8 | 4 |
| Padding tombol/input teks, horizontal | 12 | 12 |
| Padding input angka, horizontal | 8 | 8 |

Form preset/bank memakai kepadatan ringkas dan gap grid 4 px, agar seluruh isian dan tombol simpan terjangkau pada layar setinggi 680 px. Ukuran teks tetap sama. Dialog paket memakai kepadatan normal. Margin bawaan Qt distandarkan untuk menghindari campuran default 6/9 px.

Mode desktop ringkas berlaku pada lebar 900–1199 px. Perilaku mobile, reflow tab, target sentuh minimal 44 px, dan shortcut dipertahankan. Padding panel meter, WAV, IR, A/B, Koleksi dan Zona berbahaya mengikuti aturan yang sama.

## Penerapan per halaman

- Editor suara: label Slot/Volume/parameter memakai fieldLabel; hint preset dan catatan IR memakai muted; padding presetHero/modul dan panel utama dibedakan secara konsisten.
- Koleksi: nama item 14 px, metadata 12 px, inset item 12 px dan tinggi item 112 px; detail/target dan seluruh panel mengikuti density yang sama.
- Bandingkan IR: judul kedua panel setara judul panel lainnya; metadata dan teks opsi memakai caption; indikator dan ringkasan tetap tersedia tanpa scroll halaman pada 1000×680.
- Perangkat: kelompok koneksi, output MIDI, Loopback dan bantuan dipisah dengan gap kelompok; label Output diletakkan dekat input, tombol Baca informasi mengikuti lebar teks; status bukan judul panel.
- Dialog: preset, bank, paket dan konfirmasi memakai padding/keterangan yang konsisten; form panjang memakai density ringkas.

## File perubahan

- Baru: `cubebaby_mod/ui_metrics.py`, `tests/test_ui_metrics.py`, `anti-slop/audit-002-2026-11-20.md`, dokumen ini.
- Diubah: `theme_styles.py`, `studio_ui.py`, `studio_components.py`, `audio_meter.py`, `library_gui.py`, `device_ui.py` di folder `cubebaby_mod`.
- Render diperbarui: `analysis/theme-screenshots/*.png`.

Logika MIDI, parsing data, alur audio, state/handler, konfirmasi dan format preset/bank/IR tetap. Batas tampilan meter +60 dari tahap sebelumnya tetap. Git tidak memiliki metadata yang dapat dikenali, sehingga tidak membuat commit.

## Verifikasi dan serah terima

- PASS R-06/R-31: tes font hasil render memastikan judul > isi > caption, ukuran peran sama di semua halaman, tema dan density; token terpusat.
- PASS R-03/R-35: render dan uji geometri empat halaman beserta tab pada 1000×680 online/offline, serta 1920×1080; scroll halaman 0. Uji round trip ukuran mobile/desktop tetap lulus.
- PASS R-25: 28 pasangan kontras tema lolos formula repo.
- PASS R-26/R-32/C-2/C-4: handler dan kontrol asli dipertahankan; regresi menu/dropdown, fokus, shortcut, slider dan konfirmasi dijalankan dalam suite.
- PASS R-23/R-37/C-1: tidak membuat aset/ornamen baru; arah UI mengikuti aplikasi dan permintaan pengguna. ENERGY 2 / RHYTHM 2 / MOTION 1 tetap.
- Batas verifikasi: render dan backend simulasi, belum uji pedal/audio fisik atau pembesaran teks 200%. Tidak mengklaim audit aksesibilitas menyeluruh.

Checklist manual pada desktop pengguna:

- [ ] Periksa judul, label, isi, keterangan dan padding empat halaman pada 1000×680 serta ukuran layar yang dipakai.
- [ ] Buka dialog preset/bank/paket dan pastikan seluruh nilai serta tombol simpan terbaca.
- [ ] Cek status offline/online/sibuk/gagal, fokus, Tab, Alt+1–Alt+4 dan disabled controls.
- [ ] Uji pedal: A/B/C, Volume, efek, baca/simpan slot uji, audio meter, WAV/IR dan Reset peak.
- [ ] Uji Koleksi/target/impor/ekspor/capture/send, listen IR A/B, Distance/peak, cadangan/pemulihan, Loopback, Log MIDI dan pembatalan reset.

Hasil akhir:

- 191 tes lulus pada kode akhir: 92 tes / 55,294 detik dan 99 tes / 94,577 detik. Seluruh suite discovery dibagi dua batch tanpa duplikasi untuk menghindari batas waktu eksekusi. Log: `analysis/typography-tests-part0.log` dan `analysis/typography-tests-part1.log`.
- Tiga regresi baru memastikan font yang benar-benar dirender tetap konsisten, inset panel seragam setelah reflow, dialog ≤640 px dan nilai angka maksimum muat dalam input.
- `python -m compileall -q cubebaby_mod tests tools` lulus. Tidak ditemukan konfigurasi lint/build terpisah.
- 28 pasangan kontras lulus. Smoke launch `python -m cubebaby_mod` offscreen bertahan hingga timeout 4 detik (exit 124), tanpa traceback; ALSA tidak menemukan `/dev/snd/seq`, sesuai lingkungan tanpa perangkat MIDI fisik.
- Dialog hasil render: preset 579 px, bank 533 px, paket 465 px sebelum penyesuaian akhir padding angka; uji akhir tetap memastikan seluruhnya ≤640 px.
- Semua tab empat halaman online/offline pada 1000×680 diuji dengan scroll halaman 0. Screenshot tema gelap/terang diperbarui dan diperiksa, termasuk Perangkat dan Koleksi.

Pembaruan dropdown/Koleksi: area panah 32 px dengan chevron 12 px terpusat dan ruang teks kanan 40 px. Kartu Koleksi memakai kolom adaptif minimal 240 px, tinggi 112 px, gutter/spacing dari delegate; menjadi default bila belum ada preferensi eksplisit. Tampilan Daftar tetap tersedia. Lihat `anti-slop/dropdown-collection-003-2026-11-20.md`.

# Audit dan rencana tema kuning–hitam / kaca

Audit sebelum mengubah kode (20 November 2026): warna tersebar di `studio_ui.py`
(STYLE bertumpuk dan konversi HSV tema terang), `studio_components.py` (delegate),
`rendering_ui.py` (meter/waveform), `ui_states.py` (ilustrasi/skeleton),
`audio_meter.py` (gaya angka/CLIP), `device_ui.py` (rich text log), `gui.py` dan
`suite_gui.py` (gaya awal), serta `assets/ui/check.svg`. Audit lengkap dipisahkan
sebagai artefak selama pengerjaan. Layout masih memakai instance widget lama.

Tetap dijaga: StudioUI.navigate/sync, objectName sidebar/nav/badge/statusText,
seluruh effect_controls/effect_switches, preset dan handler koleksi, AudioMeter
capture/tick/PCM, handler IR/MIDI, modal/konfirmasi, selection dan preferensi UI.
Tidak ada widget data atau handler MIDI/audio yang diganti pada tahap ini.

Rencana bertahap:
1. Token Python eksplisit Dark/Light dan QSS tunggal; hitung komposit/kontras.
2. Latar ambient native Qt dan permukaan kaca dengan backdrop cache; efek
   Penuh/Ringan/Mati, reduced transparency, reduced motion dan fallback solid.
3. Migrasi semua warna QSS/paint/ikon/log/meter ke token, termasuk dialog/popover.
4. Pengaturan tampilan terlihat di top bar, tema sebelum first paint, transisi
   singkat dan pembaruan widget tanpa membangun ulang data/logika.
5. Tes kontras, cache/performa, tema/state/dialog, regresi penuh dan screenshot
   empat halaman pada kedua tema. Sertakan laporan rasio dan checklist manual.

Padanan native: Qt Widgets tidak mempunyai CSS custom properties/backdrop-filter.
Token terpusat digunakan oleh QSS dan painter; backdrop diburamkan sekali dan
cache dipakai ulang pada permukaan statis. Tidak ada blur per item atau meter.
Kaca bersarang dibatasi; efek dinonaktifkan pada reduced transparency. Tidak ada
penambahan dependency. FPS/perangkat fisik tidak diklaim tanpa pengukuran.

## Implementasi akhir

- `theme_tokens.py`: semua warna aktif, alpha dan token semantik Dark/Light.
  Nilai sekunder/disabled dan warna teks status disesuaikan berdasarkan rasio,
  sementara fill utama tetap kuning keemasan dengan teks hitam hangat.
- `theme_styles.py`: satu QSS untuk tombol, tab, kontrol, tooltip, native popup,
  dialog, selection, scrollbar, state disabled/hover/pressed/focus dan toast.
- `theme_ui.py`: ambient tiga radial glow; backdrop blur native dicache, 20 px
  untuk halaman dan 28 px untuk dialog (Ringan 16 px). Permukaan memakai tint,
  border/highlight, bayangan lembut lokal. Tidak ada blur per item atau meter.
  Sidebar/top bar/footer glass-1, kartu glass-2, dialog/popover/toast glass-3.
  Kartu bersarang memakai permukaan tonal, tanpa blur bertingkat berulang.
- Kontrol Tampilan (◐) selalu tersedia: Sistem/Terang/Gelap, efek kaca
  Penuh/Ringan/Mati, Kurangi transparansi dan Kurangi gerakan. Preferensi UI
  dibaca sebelum first paint. Pergantian memakai snapshot fade 180 ms;
  reduced motion tidak memakai fade/drift. Drift ambient satu siklus 60 detik,
  memakai texture cache dan offset saja; Ringan menghentikan drift.
- Fallback solid ketika blur tidak tersedia, high contrast sistem aktif,
  pengurangan transparansi dipilih, atau env CUBEBABY_REDUCED_TRANSPARENCY=1.
  Qt tidak mengekspos preferensi OS reduced-transparency secara langsung;
  opsi eksplisit ini merupakan padanan native, bukan atribut CSS palsu.
- Frame guard mengamati keterlambatan event UI saat monitor aktif dan dapat
  menurunkan Penuh ke Ringan untuk sesi itu. Pilihan tersimpan tidak ditimpa.
- Meter mempertahankan bacaan asli. Gradient/marker dua warna dicache; paint
  opaque lokal dan update terkoalesensi tidak membangun ulang editor. Animasi
  yang sedang berjalan ditargetkan ulang tanpa merestart clock Qt setiap sampel.
- A/B dibedakan dengan judul/ikon serta border kuning dan info teal. Log IN/OUT
  punya label dan warna token; rich text lama ikut diperbarui saat tema berubah
  tanpa mengubah record, pause, filter atau posisi log. CLIP memakai ikon/teks.
- Gembok pada tombol/indikator nonaktif, fokus ring + offset, hover glow lokal;
  tidak memakai graphics blur/shadow effect pada subtree meter/daftar bergerak.

## Berkas

Ditambah: `cubebaby_mod/theme_tokens.py`, `theme_styles.py`, `theme_ui.py`,
`tests/test_theme_ui.py`, `tools/check_theme_contrast.py`,
`tools/capture_theme_screenshots.py`, `tools/benchmark_glass.py`,
`analysis/TEMA_KUNING_KACA.md`, `analysis/KONTRAS_TEMA.md`,
`analysis/PERF_KACA.json`, serta PNG dalam `analysis/theme-screenshots/`.

Diperbarui: `studio_ui.py`, `studio_components.py`, `rendering_ui.py`,
`ui_states.py`, `ui_preferences.py`, `audio_meter.py`, `device_ui.py`, `gui.py`,
`suite_gui.py`, `assets/ui/check.svg`, dan `README.md`.
Fixture `test_suite_gui.py`, `test_connection.py`, `test_write_gui.py` kini
membuang jendela setelah selesai agar widget tersembunyi tidak menumpuk saat
pengujian stylesheet global. Kepemilikan window produksi tetap dipertahankan;
callback UI tertunda mengabaikan owner yang sudah dihancurkan.

## Bukti kontras dan performa

[Tabel lengkap 28 pasangan](KONTRAS_TEMA.md) dihitung dengan komposit alpha
seluruh kombinasi puncak tiga glow, dua tingkat kaca, seleksi dan fallback.
Rasio terburuk Dark: primer 4,95:1, sekunder 4,59:1, disabled 3,23:1.
Light: primer 13,11:1, sekunder 5,56:1, disabled 3,82:1.
Teks tombol kuning: Dark 13,35:1; Light 11,55:1.
Teks normal >=4,5:1; disabled dan fokus/marker penting >=3:1.

[Probe frame](PERF_KACA.json) memakai data simulasi dan event loop Qt offscreen,
bukan layar/vsync atau USB nyata. Ukurannya dilaporkan apa adanya; target animasi
sekitar 60 pembaruan/detik, bukan klaim bahwa semua perangkat pasti tepat 60 fps.
Cache backdrop tidak dihitung ulang per frame. Frame guard/fallback diuji terpisah.

Validasi: suite regresi **183 tes lulus**, pengujian tambahan render/audio/tema
setelah optimasi paint lulus, skala Qt 125%/150% dan startup offscreen lulus.
Tidak ada konfigurasi lint/build terpisah. Pencarian warna hardcode UI bersih di
luar file token; tes memastikan ini. Tidak ada dependency baru. PCM, buffer/capture,
protokol/transport MIDI, parser, konversi serta format file tersimpan tidak diubah.
Audio USB, hasil suara, Orca/AT-SPI dan FPS layar Wayland fisik belum teruji.

## Screenshot

Semua gambar menggunakan backend/data contoh dalam folder sementara. Bacaan
meter adalah contoh visual, bukan hasil pengukuran perangkat pengguna.

| Halaman | Dark | Light |
| --- | --- | --- |
| Editor | [Gambar](theme-screenshots/dark-editor.png) | [Gambar](theme-screenshots/light-editor.png) |
| Koleksi | [Gambar](theme-screenshots/dark-koleksi.png) | [Gambar](theme-screenshots/light-koleksi.png) |
| Bandingkan IR | [Gambar](theme-screenshots/dark-bandingkan-ir.png) | [Gambar](theme-screenshots/light-bandingkan-ir.png) |
| Perangkat | [Gambar](theme-screenshots/dark-perangkat.png) | [Gambar](theme-screenshots/light-perangkat.png) |
| Popover | [Gambar](theme-screenshots/dark-popover.png) | [Gambar](theme-screenshots/light-popover.png) |
| Dialog reset | [Gambar](theme-screenshots/dark-dialog-reset.png) | [Gambar](theme-screenshots/light-dialog-reset.png) |
| Toast | [Gambar](theme-screenshots/dark-toast.png) | [Gambar](theme-screenshots/light-toast.png) |

## Checklist manual di desktop pengguna

- [ ] Tutup aplikasi lama; jalankan `python -m cubebaby_mod` dari proyek ini.
- [ ] Periksa empat halaman di kedua tema, termasuk popup/dropdown dan dialog.
- [ ] Coba Sistem dan pergantian tema saat aktif; buka ulang untuk preferensi.
- [ ] Periksa fokus Tab/Shift+Tab/F6, ikon gembok dan alasan kontrol nonaktif.
- [ ] Coba Penuh/Ringan/Mati, Kurangi transparansi, reduced motion dan high contrast.
- [ ] Uji monitor gitar aktif dengan kaca; bandingkan frame pacing/CPU di Wayland.
- [ ] Periksa semua fungsi preset, koleksi, A/B, cadangan, log dan pembatalan reset
  memakai slot uji/pedal fisik. Pastikan perubahan visual tidak mengubah hasil audio.

# Studio UI / UX

Tujuan: membantu pemain memilih suara, membandingkan, lalu menyimpan tanpa
mencampur pengelolaan koleksi dengan diagnostik. Fitur dan protokol tetap sama.

## Keputusan desain

- Empati: pengguna ingin mencoba sambil bermain, mengingat target A/B/C atau
  slot 1–8, dan mengetahui apakah proses selesai atau perlu menunggu.
- Definisi masalah: satu layar lama mencampur editor, transfer, log, dan koleksi;
  istilah teknis dan tombol berulang memperberat pencarian tindakan.
- Alur utama: koneksi → Editor suara → coba → simpan. Koleksi untuk menyusun
  suara, Bandingkan IR untuk keputusan A/B, Perangkat untuk pemeliharaan.
- Hirarki: navigasi samping tetap, judul dan petunjuk singkat, kartu tugas,
  tombol primer berwarna, kontrol efek dikelompokkan, indikator koneksi/sibuk.
- Pengurangan kebingungan: status kosong memberi langkah pertama, nama target
  tampil pada tombol simpan IR, target koleksi muncul sesuai jenis item,
  pencarian + filter, opsi reset dibuka hanya saat diperlukan.
- Akses: teks Indonesia, tooltip, fokus/keyboard Qt, pintasan Alt+1–4,
  desktop standar 1000×680, minimum adaptif 360×480, gulir vertikal bila perlu.

## Batas perubahan

StudioUI memindahkan kontrol dan mempertahankan sinyal yang sudah digunakan.
Pemilihan sumber A/B diperjelas lewat dialog sumber; data kandidat tetap
snapshot lokal yang memakai pekerjaan preview RAM yang sama. Dialog preset
menggunakan checkbox untuk switch, tanpa mengubah byte data atau rentangnya.
Protokol, backup, validasi, rollback, konversi WAV, dan transport tidak diganti.

## Validasi

Pemeriksaan render Qt offscreen pada empat halaman dalam kondisi offline dan
perangkat simulasi, termasuk ukuran 1000×680. Pengujian menegaskan kontrol tetap
hidup setelah layout lama dihapus, navigasi/filter tidak menulis MIDI, daftar
WAV muncul setelah pemilihan, dan tombol simpan tetap menjalankan job terverifikasi.
Seluruh pengujian regresi dijalankan. Tampilan dan suara pada pedal fisik belum
divalidasi dalam sesi ini; akses USB/ALSA tidak tersedia di lingkungan pengujian.

## Audit dan rencana tahap adaptif (20 November 2026)

Audit sebelum perubahan: aplikasi memakai Qt Widgets/QSS, bukan HTML/CSS.
`StudioUI` memiliki sidebar, header, empat halaman dan footer; kontrol koneksi,
`preset_selector`, `effect_controls`, `effect_switches`, WAV dan target IR tetap
milik jendela utama. `LibraryPanel` memiliki daftar, filter, detail, handler
impor/ekspor, `set_ab()` dan `play_ab()`. `AudioMeter` memiliki pemilihan input,
monitor dan bacaan meter. Pemindahan widget harus memakai instance yang sama,
tanpa menyambung ulang jalur MIDI/audio. ObjectName `sidebar`, `nav`, `badge`,
`statusText`, `card`, `effectTabs`, `deviceTabs` tetap dipertahankan.

Rencana: (1) wadah adaptif native Qt; (2) sidebar/bottom navigation dan panel
alternatif; (3) kontrol sentuh dan aksi tetap; (4) token tema terang/gelap/sistem;
(5) uji resize bolak-balik, handler, regresi dan DPI. Tidak ada dependensi baru.

Implementasi:

| Lebar logis Qt | Tata letak |
| --- | --- |
| ≥1200 | Sidebar biasa; Editor dan Koleksi dua kolom; IR A/B berdampingan |
| 900–1199 | Sidebar ikon; panel Editor bergantian dalam tab |
| 600–899 | Navigasi bawah; Koleksi/detail bergantian; IR A/B bertumpuk |
| 360–599 | Baris kontrol bertumpuk; navigasi ikon; aksi simpan tetap di bawah |

Qt layouts dan resize observer menggantikan Grid/clamp/container queries.
Panel alternatif memakai tab native, bukan drawer animasi atau bottom sheet.
Konten tidak digulir horizontal. Pada layar sempit atau tinggi tidak mencukupi,
konten dapat digulir vertikal agar tidak ada fungsi yang tertutup. Target desktop
1000×680 tetap tanpa scroll halaman pada kondisi standar. Daftar/log tetap punya
gulir internal. Nama IR dan judul detail dapat membungkus; daftar panjang memakai
elipsis dengan tooltip nama lengkap serta detail item untuk membaca isinya.

Tema tersedia di `? → Pilih tema`: gelap (default), terang, atau mengikuti sistem.
Preferensi tema disimpan di QSettings, terpisah dari data suara. Tombol utama,
navigasi bawah dan kontrol pada mode sempit diperbesar untuk sentuh. Aksi simpan
bawah meneruskan klik ke tombol asli, termasuk konfirmasi dan kondisi nonaktif.

### Checklist manual serah terima tahap adaptif

- [ ] Resize empat halaman dari 1400 ke 1000, 800, 580, 360 px lalu kembali.
- [ ] Periksa nama/file panjang, daftar banyak item, log panjang dan status error.
- [ ] Di layar sempit, ganti Efek/Monitoring dan Koleksi/Detail; coba aksi simpan.
- [ ] Bandingkan IR A/B dengan kartu bertumpuk dan switch yang tetap terlihat.
- [ ] Coba gelap, terang, mengikuti sistem; tutup/buka aplikasi untuk preferensi.
- [ ] Periksa skala sistem KDE 125%/150%, touchscreen, fokus dan navigasi keyboard.
- [ ] Uji sambung/putus, baca/simpan slot uji, meter input dan WAV pada pedal fisik.

Validasi otomatis memakai Qt offscreen dan backend simulasi. Tidak menggantikan
uji perangkat USB, driver audio, touchscreen, screen reader atau KDE Wayland fisik.

Hasil: 162 tes regresi; uji resize logis 1400/1000/800/580/360 px dan kembali;
uji resize terpisah dengan `QT_SCALE_FACTOR=1.25` dan `1.5`; compile Python;
startup `python -m cubebaby_mod` offscreen. Tidak ada konfigurasi lint/build
frontend terpisah pada repo. ZIP dibuat dengan `tools/package_source.py`.

## Audit dan rencana aksesibilitas (20 November 2026)

Sebelum perubahan: role slider/spinbox/tab/dialog disediakan widget Qt native;
sebagian `accessibleName` dan buddy label sudah ada. Belum ada pengumuman status
native, skip navigation, atau susunan fokus eksplisit setelah reparenting.
`StudioUI.navigate()`, `adapt_layout()`, `sync_feedback()` menjadi titik integrasi;
`effect_controls`, `effect_switches`, `AudioMeter` dan `LibraryPanel` tetap memakai
instance/signal/handler yang sama. Dialog memakai `exec()` dan pembatalan native;
konfirmasi timpa sudah memberi fokus awal pada Batal. Tidak memindahkan kepemilikan
widget atau mengubah handler data pada tahap ini.

Rencana: (1) helper native untuk nama/deskripsi nilai dan pengumuman status;
(2) nama panel/tab dan urutan fokus mengikuti halaman; (3) skip ke konten lewat
keyboard serta pemulihan fokus saat resize/navigasi; (4) label dialog dan fokus
Batal; (5) tes QAccessible value/role, keyboard, dialog Esc dan status; regresi.
ARIA adalah API web; aplikasi memakai padanan QAccessible, tanpa atribut HTML
palsu, dependency baru, atau pengumuman meter yang terus-menerus.

### Implementasi aksesibilitas native

- `accessibility_ui.py`: helper deskripsi nilai dengan rentang asli,
  `StatusAnnouncer`, skip link fokus, dan susunan fokus mengikuti layout aktif.
- `studio_ui.py`: nama panel/tab/tujuan, F6/Shift+F6, Alt+1–4 juga saat sidebar
  tersembunyi, fokus dipertahankan saat reparenting, dan Ctrl+K tetap ke pencarian.
- `library_gui.py`: nama input dialog preset/bank/paket dan pesan validasi paket.
- `device_ui.py` / `ui_states.py`: nama/deskripsi konfirmasi dan fokus awal Batal
  pada reset. Modalitas, siklus fokus, serta Esc tetap memakai perilaku Qt native.
- `tests/test_accessibility_ui.py`: uji semantik QAccessible, keyboard, fokus,
  pengumuman, modalitas/pembatalan, dan pembuatan dialog tanpa penulisan MIDI.
- `README.md` dan dokumen ini memuat petunjuk serta batas validasi.

Padanan ARIA menggunakan semantik native: `QSlider` mengekspos role Slider dan
value interface (nilai kini/minimum/maksimum); deskripsi memberi satuan/konteks
angka tanpa menebak model amp atau satuan fisik yang belum diverifikasi.
`QTabBar` mengekspos PageTabList/PageTab beserta state selected; induk dan panel
memiliki nama kontekstual. `QDialog` tetap modal dengan role Dialog. Pada Qt yang
mendukungnya, status memakai `QAccessibleAnnouncementEvent` Polite, atau Assertive
untuk error. Qt lama memakai event perubahan deskripsi/alert sebagai fallback;
pengucapannya perlu diverifikasi dengan pembaca layar yang dipakai pengguna.

Status utama terhubung/terputus/berhasil/gagal, perubahan status monitor (termasuk
input gagal dibuka), dan pesan impor diumumkan setelah penggabungan 120 ms.
Pengumuman tidak mengambil fokus dan tidak membacakan Peak/RMS setiap frame.
Status koneksi memakai simbol berbeda beserta teks/deskripsi; dirty state memiliki
penjelasan teks, dan pilihan/toggle memakai state native, bukan warna saja.

### Checklist manual aksesibilitas

- [ ] Dengan Orca di KDE, baca nama, nilai dan rentang slider/spinbox serta opsi input.
- [ ] Periksa Tab/Shift+Tab, skip link Enter/Space, F6 dan Shift+F6 pada semua halaman.
- [ ] Coba Alt+1–4 dan Ctrl+K pada sidebar biasa, ikon dan navigasi bawah.
- [ ] Pindah tab dengan keyboard; pastikan nama tab dan state selected terbaca.
- [ ] Resize saat slider fokus; pastikan fokus dan posisi edit tetap masuk akal.
- [ ] Dengarkan pengumuman terhubung, terputus, tersimpan, error audio dan MIDI;
  pastikan tidak membacakan meter terus-menerus atau memindahkan fokus.
- [ ] Buka dialog preset/bank/paket, konfirmasi timpa dan reset; periksa Batal,
  fokus di dalam dialog, Esc membatalkan, dan fokus kembali ke pemicu.
- [ ] Periksa simbol/teks status dan state toggle tanpa mengandalkan warna.

Tes Qt offscreen memeriksa semantik dan perilaku event; belum menguji keluaran
suara Orca/AT-SPI, screen reader lain, atau perangkat fisik. Tidak ada perubahan
protokol, parsing, logika audio, data preset/bank/IR maupun dependency.

## Audit dan rencana performa (20 November 2026)

Sebelum perubahan: `AudioMeter.tick()` mengambil sampel setiap 50 ms dan hanya
mengubah widget meter; tidak memanggil editor. `LevelBar` menggambar hold di atas
QProgressBar, sedangkan `render()` juga mengulang stylesheet angka. `Waveform`
menghitung peak dan membuat QPainterPath pada setiap paint. A/B sudah menahan
pemanggilan `set_values` ketika sumber tidak berubah, tetapi sumber yang pernah
dipakai belum dicache dan peak diringkas ulang saat sync. `LibraryPanel.render()`
membaca stat/meringkas payload pada setiap filter; QListWidget memakai delegate
viewport tanpa widget per item. Pertahankan `CollectionList`, UserRole/path,
selection model, seluruh handler serta kepemilikan widget.

Rencana: (1) animasi native Qt terpisah dari snapshot angka/pengukuran, repaint
hanya pada bar, berhenti ketika tersembunyi/reduced motion; (2) path waveform
normalisasi dan ekstraksi IR memakai LRU terbatas; resize cukup transform;
(3) ukuran item seragam, layout batched untuk daftar besar dan cache metadata
sampai muat ulang; (4) uji pengukuran tetap, cache/invalidation, viewport paint,
seleksi item akhir dan seluruh regresi. Tidak mengubah PCM, timer pengambilan
50 ms, MIDI, parsing inti, format data atau menambah dependency. rAF/CSS compositor
bukan API Qt Widgets; animasi Qt menargetkan sekitar 60 fps, bukan jaminan fps.

### Implementasi dan batas performa

File baru: `cubebaby_mod/rendering_ui.py`, `tests/test_rendering_performance.py`.
File diperbarui: `audio_meter.py`, `suite_gui.py`, `library_gui.py`, `studio_ui.py`,
`README.md`, serta dokumen ini.

Editor mempertahankan `AudioMeter.tick()`, PCMLevels, timer 50 ms, rumus level,
hold/clipping, sumber audio dan penanganan gagal. `AnimatedLevelBar` hanya
menginterpolasi isian dengan QVariantAnimation; nilai native/aksesibilitas tetap
snapshot asli. Callback frame hanya meminta repaint bar, tanpa sync editor atau
perubahan geometry. Animasi berhenti ketika panel tersembunyi, reset/stop, atau
Kurangi gerakan aktif. Stylesheet angka hanya diganti ketika warna berubah.
Qt Widgets tetap melakukan paint raster lokal; bukan jaminan 60 fps atau
compositing transform-only seperti browser.

Koleksi menggunakan QListView + QAbstractListModel read-only dengan kontrak
CollectionList/selection/UserRole yang dipakai handler lama. Tidak ada objek
QListWidgetItem per entri; adapter baris dibuat hanya saat handler meminta item.
Delegate native menggambar viewport, ukuran item seragam, dan mode Batched 128
item dipakai untuk ≥500 hasil. Ringkasan tampilan disiapkan on-demand dan disimpan
dalam cache LRU 512 entri. Waktu file dicache untuk sortir Terbaru. Cache dibuang
saat refresh. Payload validasi penyimpanan lama tetap berada di RAM; filter/sortir
masih berskala dengan jumlah entri. Muat ulang diperlukan untuk perubahan file
eksternal. Format/storage tidak diganti oleh virtualisasi tampilan.

File WAV/IR di Editor dan kandidat A/B berbagi cache path berdasarkan isi sampel.
Path/peak dihitung sekali per cache miss; resize memakai transform, sementara
cache ekstraksi IR memakai parser lama. Kedua cache LRU dibatasi masing-masing 32
entri. Hasil cache hanya dipakai untuk visual, tidak untuk mengubah data suara
atau operasi pedal. Perangkat, cadangan, log serta protokol tidak diubah.

### Checklist manual performa

- [ ] Genjreng sambil menggeser efek; pastikan meter halus dan editor tidak kehilangan fokus.
- [ ] Periksa Peak/RMS/Hold, CLIP, Reset peak, stop dan input terputus tetap benar.
- [ ] Sembunyikan/tampilkan panel meter; capture tetap sesuai state semula dan animasi tidak berjalan tersembunyi.
- [ ] Aktifkan Kurangi gerakan; bar menampilkan nilai langsung.
- [ ] Buka ribuan item Koleksi, scroll cepat, cari/sortir, multi-select, pilih item terakhir dan ekspor.
- [ ] Ubah file koleksi eksternal lalu Muat ulang; nama/ringkasan/tanggal diperbarui.
- [ ] Ganti IR A/B berulang, ubah satu sumber, resize, dan pastikan gambar/peak sesuai isi terbaru.
- [ ] Ukur CPU/frame pacing pada KDE Wayland dan pedal fisik; pengujian offscreen tidak mengukur FPS/GPU nyata.

Validasi otomatis meliputi enam tes baru: isolasi animasi/nilai asli, reduced
motion/reset, kesetaraan koordinat dan batas cache waveform, cache ekstraksi IR,
metadata cache/invalidation, serta viewport 5.001 item dengan ekspor item terakhir.
Seluruh suite mencakup 174 tes. Compile/startup offscreen dan ZIP diperiksa;
tidak ada konfigurasi lint/build terpisah atau dependency baru.

## Audit penuntasan performa (20 November 2026)

Audit ulang: animasi meter dan cache waveform sudah terpisah dari kontrol editor,
namun Koleksi masih membuat QListWidgetItem dan metadata untuk seluruh hasil.
Langkah lanjutan: gunakan QListView + QAbstractListModel read-only dengan metadata
on-demand. Pertahankan atribut `LibraryPanel.list`, UserRole path/jenis/detail,
`currentRowChanged`, `itemSelectionChanged`, `itemActivated`, metode item/seleksi
saat ini, semua aksi file/pedal, keyboard dan gaya visual. Adapter baris hanya
dibuat saat pemanggil memintanya; tidak menyimpan objek widget/item per entri.
Uji regresi ditambah pembuktian lazy metadata, batas cache, keyboard/grid,
seleksi lintas filter, model Qt valid dan ekspor item terakhir.

Interval PCM, transform bar dan cache terbatas tetap dipakai. API browser rAF/CSS
bukan stack aplikasi ini; target frame visual tetap melalui animation driver Qt.
Tidak mengubah struktur file tersimpan, parser, engine audio maupun transport.

### Hasil penuntasan dan pemeriksaan seluruh poin performa

| Poin | Implementasi | Verifikasi |
| --- | --- | --- |
| Meter sekitar 60 fps | Animation driver Qt, transform isian bar lokal; snapshot akurat terpisah | Interpolasi tidak mengubah nilai native, Peak/RMS, timer 50 ms atau sync editor |
| Frame ringan | Tidak mengubah geometry/stylesheet/editor per frame; berhenti tersembunyi/reduced motion | Uji animasi, reset dan perpindahan halaman |
| Virtualisasi Koleksi | QAbstractListModel + QListView, metadata on-demand, cache LRU 512 | 10.000 entri tanpa ringkasan eager; cache dibatasi; QAbstractItemModelTester |
| Fungsi daftar terjaga | UserRole, adapter row, selection signals, keyboard, List/Grid, aktivasi Enter | Multi-select/filter/stale handle, item terakhir dan ekspor pada 5.001 entri |
| Waveform/IR dicache | LRU path/peak normalisasi dan ekstraksi sampel, masing-masing 32 | Geometri ekuivalen, resize tanpa hitung ulang, cache invalidation/batas |

File lanjutan: `cubebaby_mod/collection_view.py` (baru), `library_gui.py`,
`studio_ui.py`, `tests/test_rendering_performance.py`, `README.md`, dokumen ini.
Peta file tampilan: `collection_view.py` menyediakan CollectionList/CollectionRow
beserta signal kompatibel; `LibraryPanel.render()` memasok referensi path/item
ke model; `display_details()` mengisi metadata ketika model diminta. UserRole,
UserRole+1, UserRole+2 tetap path/jenis/detail. Handler impor/ekspor, kirim, staging,
rename/duplicate/delete dan semua akses pedal tetap berada pada jalur lama.

Uji tambahan menyertakan key End/Shift+Up/Enter, pemilihan setelah filter, mode
Grid pada layar sempit, handle lama invalid setelah reset dan model tester Qt.
Checklist manual performa di atas tetap berlaku. FPS/pacing aktual, screen reader
fisik dan audio/USB tetap memerlukan pengujian pada desktop/perangkat pengguna;
tes offscreen tidak dapat mengesahkan angka fps atau suara perangkat fisik.

Hasil akhir tahap penuntasan: **176 tes lulus**; resize pada skala Qt 125% dan
150% lulus; compile, startup offscreen serta integritas ZIP berhasil diperiksa.
Tidak ada perubahan protokol, engine audio, format preset/bank/IR atau dependency.

# CubeBabyMOD — editor, koleksi preset, bank virtual, dan IR A/B

Editor Linux/CachyOS untuk **Cube Baby 20230**, mengacu pada CubeSuite 2.8.10
lokal di `CubeSuite/`, dengan fitur tambahan yang diminta pengguna: bank virtual,
konversi IR otomatis, A/B, serta koleksi preset untuk target A/B/C. Updater
firmware belum tersedia. Tampilan Studio menyediakan navigasi samping, kontrol efek berkelompok, dan alur koleksi yang terpisah.
Matriks lengkap ada di `analysis/PARITY.md`.

## Installer Linux dan Windows

Paket AppImage Linux dan Setup.exe Windows beserta cara build tersedia pada [panduan installer](INSTALL.md). Paket membawa Python/Qt dan menyimpan Koleksi/cadangan di folder pengguna.

## Tampilan Studio

- **Editor suara**: pilih A/B/C, atur Volume atau klik tahap di rantai efek. Klik **Simpan efek** untuk menyimpan perubahan. **Urungkan** mengembalikan slot yang dipilih ke nilai terakhir yang dibaca atau disimpan. Tab kanan berisi meter, File WAV, dan Slot IR.
- **Koleksi**: pilih daftar atau kartu, cari, filter, dan urutkan item. Lepas WAV atau JSON untuk mengimpor. Gunakan Ctrl atau Shift untuk memilih beberapa item. Menu **…** menyediakan ganti nama, duplikat, ekspor, dan hapus. Enter membuka Detail dan Delete meminta konfirmasi hapus. Pengiriman ke pedal memakai satu pilihan, termasuk bank yang dapat berisi banyak slot.
- **Bandingkan IR**: kartu A/B menampilkan metadata format pedal dan bentuk gelombang. Gunakan tombol atau pintasan A/B untuk berganti, dengan status memuat dan aktif setelah verifikasi RAM. Pintasan hanya bekerja di halaman ini. Tab tetap memindahkan fokus. Ringkasan menunjukkan puncak amplitudo sumber dan kesamaan data. Opsi jarak mikrofon serta level puncak dilengkapi penjelasan.
- **Perangkat**: Koneksi menampilkan informasi yang dibaca dari pedal dan bantuan pemilihan MIDI. Cadangan IR menampilkan cadangan sektor yang tervalidasi dari folder backups, termasuk subfolder transfer. Buat cadangan membaca sektor penuh. Pulihkan memakai cadangan slot yang sama dan jalur tulis terverifikasi. Log MIDI menyediakan filter IN/OUT/Status, jeda, salin, ekspor, dan pilihan mengikuti pesan baru. Bersihkan mengosongkan tampilan, sementara Ekspor mempertahankan catatan sesi. Reset ada di **Zona berbahaya**, memerlukan ketikan RESET lalu konfirmasi lama.

Pindah halaman dengan Alt+1 sampai Alt+4. Sidebar bisa diringkas. Pada ukuran minimum 1000 × 680, seluruh halaman dapat diakses tanpa menggulir halaman. Daftar yang panjang dan log MIDI memiliki area gulir sendiri.

## State dan umpan balik

Saat offline, Editor suara menampilkan ilustrasi pedal dan langkah sambungan USB.
Koleksi dan pemilihan kandidat A/B tetap tersedia. Proses membaca preset/IR
menampilkan skeleton dan indikator proses. Pemilihan file serta pemuatan ulang
koleksi dari tombol menampilkan skeleton selama aksi berlangsung.

Titik pada slot A/B/C menandakan perubahan sejak nilai terakhir dibaca/disimpan.
Ctrl+S membuka konfirmasi Simpan efek, dan Batalkan mengembalikan slot yang sedang
dipilih. Dialog timpa, hapus, dan reset memakai Batal sebagai pilihan awal.
Penghapusan item menyediakan Urungkan hapus selama sesi masih terbuka.
Penulisan sukses mendapat tanda centang selama 1,5 detik.

Error proses tersedia melalui toast merah dan Detail error. Coba lagi mengulang
pembacaan yang masih tersedia, atau membuka pemeriksaan koneksi/cadangan sebelum
pengiriman ulang. Periksa cadangan dan kondisi slot setelah penulisan terhenti.

## Interaksi dan preferensi

Transisi halaman dan toast memakai fade ease-out 180 ms. Pengaturan efek UI
desktop dari Qt digunakan sebagai acuan pengurangan gerakan. Tombol **?**
membuka bantuan pintasan dan opsi **Kurangi gerakan animasi** yang dapat dipilih
langsung. Skeleton tidak berdenyut saat opsi ini aktif. Nilai yang diedit
disorot singkat dan tooltip muncul setelah sekitar 400 ms.

Pintasan tersedia melalui **?** dan tooltip. 1/2/3 memilih preset A/B/C di Editor
suara. Ctrl+S menyimpan dengan konfirmasi, Ctrl+R membaca ulang preset, Ctrl+Z
membatalkan perubahan slot, dan Space mulai/stop monitor. Ctrl+K membuka
pencarian Koleksi. A/B berganti kandidat di Bandingkan IR. Input teks tetap
memakai interaksi pengetikan dan undo bawaan.

Sidebar, halaman/tab terakhir, posisi gulir daftar, pilihan input audio, port
MIDI, dan tampilan Koleksi disimpan lewat QSettings CubeBabyMOD/Studio.
Pengaturan UI ini terpisah dari file preset, bank, dan IR. Memulihkan preferensi
tidak membuka koneksi atau memulai capture audio.

Layout kini mengikuti lebar jendela memakai layout native Qt, tanpa dependency
baru. Pada ≥1200 px tersedia dua kolom; 900–1199 px memakai sidebar ikon dan
tab alternatif Editor; di bawah 900 px navigasi pindah ke bawah, detail Koleksi
menjadi panel alternatif, dan kartu IR A/B bertumpuk. Di bawah 600 px baris
kontrol bertumpuk, tombol sentuh diperbesar, dan aksi simpan tetap terlihat.
Ukuran minimum jendela 360×480 px. Pada desktop standar 1000×680 tidak ada scroll
halaman; pada ukuran sempit/pendek konten dapat digulir vertikal agar seluruh
fungsi tetap terjangkau. Tidak ada gulir halaman horizontal. Daftar dan log
tetap dapat digulir di dalam panelnya.

Pilih **Tampilan (◐) → Tema → Sistem / Terang / Gelap** di top bar. Pilihan
manual tersimpan sebelum jendela ditampilkan. Mode Sistem mengikuti Qt/KDE dan
memakai Gelap jika sistem tidak melaporkan preferensi. Tema kuning–hitam hangat
memakai token terpusat; tidak lagi memakai konversi warna tema lama.

**Tampilan → Efek kaca → Penuh / Ringan / Mati** mengatur backdrop native yang
diburamkan dan dicache. Kurangi transparansi, mode high contrast OS yang tersedia
di Qt, dan `CUBEBABY_REDUCED_TRANSPARENCY=1` memakai permukaan solid. Kurangi gerakan
menghentikan drift ambient dan animasi; preferensi reduced motion OS dihormati.
Saat frame UI terlambat berulang, efek Penuh turun ke Ringan untuk sesi berjalan.

Laporan warna, fallback, pengujian dan delapan screenshot ada di
[analisis tema](analysis/TEMA_KUNING_KACA.md),
[tabel kontras](analysis/KONTRAS_TEMA.md), dan [probe frame](analysis/PERF_KACA.json).
Panel alternatif memakai tab, bukan drawer/bottom sheet. Nama lengkap tersedia
melalui tooltip dan panel detail jika nama di daftar harus disingkat.

## Aksesibilitas

**F6** melewati navigasi ke kontrol halaman; **Shift+F6** kembali ke navigasi.
Skip link **Lewati navigasi ke konten** muncul ketika mendapat fokus dan dapat
diaktifkan dengan Enter atau Space. Urutan Tab mengikuti panel aktif, termasuk
saat sidebar menjadi navigasi bawah. Alt+1–4 tetap berpindah halaman.

Slider/spinbox mengekspos nama, nilai dan rentang melalui aksesibilitas native
Qt. Tab memakai role/state native, dan dialog modal dapat dibatalkan dengan Esc.
Reset berfokus awal pada Batal. Status koneksi, penyimpanan dan kegagalan memakai
pengumuman aksesibilitas, tanpa memindahkan fokus atau membacakan meter setiap
frame. Status memakai simbol/teks selain warna. Tidak ada atribut HTML/ARIA karena
antarmuka menggunakan Qt Widgets. Keluaran pembaca layar Orca/AT-SPI masih perlu
diuji pada desktop pengguna; tes otomatis memakai Qt offscreen.

## Performa tampilan

Meter memakai animasi visual Qt yang menargetkan sekitar 60 fps. Hanya isian bar
yang diinterpolasi dengan transform saat digambar; nilai Peak/RMS/Hold dan
clipping tetap berdasarkan pengukuran 50 ms yang sama. Animasi tidak memanggil
state editor, tidak mengubah geometry/layout per frame, dan berhenti saat meter
tersembunyi atau opsi Kurangi gerakan aktif. Qt Widgets menggambar ulang area bar;
ini bukan `requestAnimationFrame` atau compositor CSS. FPS nyata mengikuti beban
sistem dan perlu diperiksa pada desktop pengguna.

Koleksi memakai QListView + model virtual read-only: tidak membuat QListWidgetItem
untuk setiap entri. Ringkasan dan metadata tampilan dibuat ketika diminta oleh
viewport/pembaca layar, lalu disimpan dalam LRU maksimal 512 entri. Ukuran item
seragam dan layout bertahap 128 item untuk hasil berjumlah ≥500. Cache waktu file
dipakai untuk sortir Terbaru; Muat ulang membuang cache. Filter, multi-select,
keyboard, List/Grid dan seluruh aksi tetap menggunakan jalur yang sama.
Data koleksi yang telah divalidasi tetap dimuat ke RAM oleh penyimpanan lama;
virtualisasi ini berlaku pada model tampilan, bukan perubahan format/storage.

Waveform menyimpan path normalisasi dan peak menurut isi sampel; resize cukup
memakai transform gambar. Ekstraksi sampel IR A/B juga dicache, masing-masing
cache LRU dibatasi 32 entri. Isi baru memakai cache key baru. File preset/bank/IR
dan parser/konversi audio tidak berubah. Uji viewport mencakup 5.001 item dan
seleksi/ekspor item terakhir. Uji model mencakup 10.000 entri, metadata on-demand,
batas cache, keyboard, multi-select, List/Grid dan validasi model native Qt.

Kiriman perubahan efek live memakai jeda minimum 40 ms antarkiriman.
Nilai pertama dikirim langsung, sementara perubahan cepat selanjutnya digabung
per preset/parameter sampai slot kiriman berikutnya. Nilai terakhir tetap berada
di antrean tunggal sampai terkirim.

## Monitor level gitar

Di **Editor suara → Meter gitar**, klik **Cari input**, pilih input
audio pedal/interface, lalu **Mulai monitor**. Meter memakai skala relatif hingga +27 dB. Angka 0 relatif setara −27 dBFS dan +27 relatif setara 0 dBFS. Perubahan skala hanya memengaruhi tampilan. Meter menampilkan peak, RMS,
peak hold, dan tanda clipping; **Reset peak** menghapus hold/indikator clip.
Tidak menulis pedal, mengeluarkan suara, atau merekam file.

MIDI hanya membawa kontrol. Agar meter merespons genjrengan, suara Cube Baby
harus tersedia sebagai input audio di sistem, melalui USB audio jika didukung
atau output pedal ke audio interface. Mikrofon laptop mengukur tangkapan
mikrofon, bukan langsung output pedal. Angka dBFS adalah level digital input,
bukan dB SPL ruangan dan bukan pengukuran loudness LUFS. Level input/mixer
sistem memengaruhi angka yang dibaca. Meter membaca sekitar setiap 50 ms;
latensi tambahan bergantung driver/buffer audio.

Monitor menggunakan PySide6.QtMultimedia. Jika modul/backend audio tidak tersedia,
status menjelaskan masalahnya dan fitur editor lain tetap dapat dipakai.
Capture memakai tujuan QBuffer di RAM, tanpa mengandalkan stream hasil
`QAudioSource.start()` tanpa argumen. Buffer dikuras setiap pembaruan meter;
error backend dan buffer berlebih menghentikan capture serta melepaskan input.

## Paket preset + IR

Di **Koleksi → Buat baru → Paket preset + IR**, pilih satu pengaturan preset dan satu IR
untuk disimpan bersama dalam satu file. Saat mengirim paket, pilih target A/B/C
dan slot IR 1–8; nomor Kabinet IR pada preset disesuaikan otomatis. Data kedua
bagian dibawa lengkap, sehingga tidak bergantung pada file WAV sumber.

Transfer memakai cadangan dan verifikasi yang sama dengan bank: IR dahulu,
baru preset. Kegagalan dapat meninggalkan hasil sebagian dan dilaporkan beserta
lokasi cadangan. Preset lain tidak ditulis, tetapi penggunaan slot IR yang sama
akan mengikuti kabinet baru. Panduan dan batasan ada di `PANDUAN_BANK.md`.

## Bank, preset virtual, dan A/B

Menu **Koleksi** berisi preset dan bank virtual. Perbandingan tersedia di **Bandingkan IR**. Panduan lengkap tersedia di
`PANDUAN_BANK.md`.

- **Buat preset / Edit salinan preset** bekerja offline. Simpan banyak file preset di
  koleksi laptop, pilih **Preset tujuan A/B/C**, lalu **Kirim ke pedal**.
  Dua preset lain dan byte cadangan pada target dipertahankan. Cadangan seluruh
  preset dibuat sebelum penulisan; hasilnya dibaca ulang.
- **Impor file** menerima WAV dan JSON koleksi. **Ekspor file JSON**
  menghasilkan JSON portabel berisi data serta SHA-256, tanpa ketergantungan
  pada file WAV sumber. Koleksi tersimpan di `library_data/` (dapat diarahkan
  lewat `CUBEBABY_LIBRARY_DIR`). Folder ini dan `backups/` tidak masuk paket source.
- **Buat bank** memetakan koleksi IR ke slot 1–8 dan preset ke A/B/C. Slot
  yang dikosongkan di bank tidak disentuh. **Salin seluruh bank pedal**
  mencadangkan delapan IR serta tiga preset tersimpan ke koleksi laptop.
- Seluruh target bank dibaca dan dicadangkan sebelum penulisan pertama.
  Transfer berurutan, memverifikasi setiap sektor dan preset. Jika terputus,
  laporan mencantumkan slot selesai serta lokasi cadangan; tidak mengklaim
  bank lengkap atau menjalankan rollback seluruh bank secara otomatis.
- **IR pilihan/editor → A/B**, lalu **Dengarkan A/B**, bergantian mencoba IR di
  RAM tanpa menulis slot flash. Distance yang sama dan penyamaan level puncak
  opsional membantu perbandingan. Kandidat/file koleksi tidak diubah.

## Jalankan

```bash
cd /data/Projects/Cubebabymod
python -m cubebaby_mod
```

Dependensi: Python, PySide6, mido, python-rtmidi. Pada CachyOS:

```bash
sudo pacman -Syu --needed python pyside6 python-mido python-rtmidi alsa-utils usbutils
```

1. Tutup aplikasi lain yang membuka port pedal, lalu **Hubungkan**. Identitas,
   info perangkat, tiga preset dan USB Loopback dibaca berurutan.
2. Pilih **Preset A/B/C** untuk mengedit record tersebut. TYPE, GAIN, TONE,
   MOD, TIME, FB, MIX, REVERB, IR CAB, VOLUME dan SW1/SW2/SW3 mengikuti
   alamat/rentang program asli. Parameter dikirim live; **Save Effects**
   menyimpan ketiga preset dan memverifikasi hasil baca ulang. Pemilihan
   preset di editor tidak mengirim perintah aktivasi preset yang belum
   ditemukan pada jalur program asli.
3. **Tambah WAV** memilih banyak file sekaligus, seperti CubeSuite. **Folder**
   menampilkan daftar file dari sebuah folder. Satu klik WAV dalam daftar
   memuat IR dan mengirim preview ke RAM pedal. Distance dapat diperbarui live.
   **Save to IR N** menyimpan ke slot pilihan setelah membaca target dan
   membuat cadangan sektor. Preview sendiri tidak menulis slot flash.
4. Untuk membaca IR tersimpan, pilih slot 1–8 dan **Baca slot IR**. Preview,
   perubahan Distance dan penyimpanan tersedia setelah pembacaan.
   Mengubah Distance saja tidak otomatis memuat IR slot ke RAM. Sebelum
   Preview, perubahan bersifat lokal sampai disimpan. Sesudah Preview aktif,
   hanya empat byte Distance diperbarui; koefisien tetap. Urutan pembaruan
   diakhiri perintah aktivasi `1`, mengikuti editor asli.
5. **Factory Effects** mengembalikan tiga preset bawaan. **Factory IR**
   mengembalikan delapan sektor IR dari bagian 0x9000–0x10FFF BFI.bin asli.
   Setiap sektor dicadangkan dan diverifikasi sebelum lanjut ke sektor lain.
6. Tab **Perangkat → Cadangan & pemulihan IR** menyediakan log IN/OUT/EVENT, ekspor IR JSON,
   impor JSON/cadangan sektor, info perangkat dan monitor MIDI pasif.

## Format WAV

Impor WAV sekarang memakai konversi otomatis: PCM 8/16/24/32-bit atau IEEE float
32/64-bit, termasuk WAVE extensible yang sesuai, mono/stereo, 8–384 kHz.
Stereo digabung dengan rata-rata kanal, di-resample ke 48 kHz menggunakan
windowed-sinc dengan filter anti-alias, kemudian dipotong atau ditambah nol
menjadi 512 sampel. Float yang melebihi rentang diturunkan agar peak ≤1;
IR pelan tidak dikeraskan otomatis. IR kosong/NaN/Infinity/data terpotong
ditolak. Konversi tidak mengubah file WAV asli dan tidak menambah dependensi.
Header record WAV baru empat byte nol sesuai 0x49EC50.
Perubahan Distance pada record lama mempertahankan header/koefisien; impor
IR JSON mempertahankan header target. Cadangan sektor mengembalikan seluruh
byte apa adanya.

## Cadangan dan verifikasi

Operasi sektor: baca 4096 byte terbaru, cocokkan snapshot, simpan JSON di
`backups/` dengan SHA-256 dan fsync file/direktori, erase, tunggu ACK dan
100 ms, tulis 32 paket 128 byte, lalu baca ulang seluruh 4096 byte. Cadangan
gagal atau snapshot berubah menghentikan operasi sebelum erase. Padding di
luar record 2056 byte dipertahankan, kecuali pemulihan sektor penuh.

Pemulihan: baca slot target, buka Perangkat → Cadangan & pemulihan IR, pilih **Muat IR /
cadangan JSON**, pilih cadangan, lalu kembali ke editor dan **Pulihkan ke
slot N**. Nomor slot, alamat, ukuran dan SHA-256 harus cocok. Slot terhapus
atau rusak dapat dipulihkan dari cadangan penuh.

Semua akses MIDI berurutan dengan satu permintaan aktif. Preview RAM membaca
observasi byte kontrol dan cadangan 2052 byte RAM sebelum menulis. Upload memakai ACK setiap
chunk, mengaktifkan preview kembali, lalu memverifikasi seluruh data lewat
baca ulang byte per byte; tidak bergantung pada respons checksum opcode 0x24.
Upload gagal memicu satu upaya mengembalikan data RAM sebelumnya, diikuti
verifikasi dan perintah aktivasi. Byte 0x764 adalah kontrol; baca ulangnya tidak
disyaratkan sama dengan perintah terakhir dan tidak dibatasi ke nilai 0/1,
baik sebelum maupun sesudah upload. Program tidak menganggap observasi
byte itu sebagai bukti status audio aktif/nonaktif. Jika preflight tidak
dibalas, tidak ada penulisan/penonaktifan.
Cadangan RAM hanya berlaku selama sesi, bukan cadangan slot flash. Penyimpanan
efek/Loopback memakai baca ulang. Perubahan Distance RAM diakhiri perintah
aktivasi `1` sebelum verifikasi float, seperti fungsi asli 0x49E220; tidak
menggunakan nilai kontrol yang terbaca sebelumnya sebagai status untuk dipulihkan.
Jika pembaruan terhenti, satu perintah aktivasi dikirim kembali. Koefisien tidak
ditulis ulang. ACK aktivasi bukan bukti independen bahwa audio sudah terdengar.
Jika pemulihan juga gagal, status dinyatakan belum dapat dipastikan. Tidak ada
retry data atau rollback flash otomatis.
Penutupan diblokir selama operasi yang sudah mulai menulis berlangsung.
Timeout/error menutup koneksi dan tidak dilaporkan sebagai keberhasilan.

## Bukti pengujian

- Pedal pengguna: identitas, metadata `[1,20230,196608,393216,430080]`, slot 2,
  perubahan Distance 75→74, dan pemulihan sudah dikonfirmasi lewat log dan
  laporan pengguna. Ini bukan hasil akses fisik dari lingkungan analisis.
- **183 uji otomatis lulus**: protokol, alamat live, preservasi preset lain
  dan byte cadangan, kelompok sakelar, WAV stereo/padding, preview RAM,
  checksum gagal, timeout, Save WAV tanpa baca slot manual, serta pemulihan
  delapan sektor dengan delapan cadangan. Pengujian tambahan mencakup slider
  live saat digeser, antrean perubahan lintas preset, dan multi-file WAV.
  Regresi Distance mencakup tidak ada upload IR implisit, preservasi koefisien
  dan gate, ACK negatif, timeout, kegagalan pemulihan, serta nilai tidak berubah.
  Regresi Preview meliputi perangkat tanpa respons checksum RAM, timeout sebelum
  penulisan, upload parsial, hasil verifikasi berbeda, ACK gate ditolak dan
  rollback yang juga gagal. Log error memuat tahap, region, alamat dan panjang.
  Dua regresi terbaru memodelkan byte kontrol yang kembali ke 0 setelah ACK
  aktivasi: Preview dan Distance tetap memverifikasi data tanpa rollback palsu.
  Nilai kontrol 0–255 diuji untuk kedua job; tidak ada nilai observasi yang
  disalin sebagai perintah atau menghalangi penulisan data yang tervalidasi.
- Tes fitur baru: konversi/resampling dan anti-alias, file rusak/nonfinite,
  penyimpanan atomik, bank/JSON/SHA-256, koleksi banyak preset, impor spesifik
  A/B/C, preservasi slot lain/byte cadangan, seluruh backup-before-erase,
  bank terputus sebagian, snapshot preset stale, A/B hanya RAM, serta UI offline.
- Paket preset + IR diuji untuk penyimpanan offline, pemetaan kedua target,
  preservasi data lain, pembatalan, dan kegagalan IR sebelum penulisan preset.
  Meter audio diuji untuk peak/RMS dBFS, clipping, potongan frame, input terputus,
  kegagalan membuka input, dan pembersihan capture setelah sampel tidak valid.
- Efek, WAV preview, Loopback dan factory reset versi baru diuji dengan
  simulasi perangkat; belum dikonfirmasi pada pedal fisik. Lingkungan
  eksekusi tidak menyediakan `/dev/snd` atau akses USB.

```bash
QT_QPA_PLATFORM=offscreen python -m unittest discover -s tests -v
```

Bukti reverse engineering ada di `analysis/PROTOKOL.md`. File asli CubeSuite
tidak dimodifikasi. Paket source dapat dibuat ulang dengan
`python tools/package_source.py`; cadangan pribadi/log tidak dimasukkan.

## CLI

```bash
python -m cubebaby_mod --list
python -m cubebaby_mod --monitor 'NAMA PORT INPUT DARI --list'
python -m cubebaby_mod --identify 'NAMA PORT INPUT' --output 'NAMA PORT OUTPUT'
```

Nama endpoint bisa berubah setelah reconnect. GUI mencocokkan input/output
dengan nama sama dan tidak otomatis memilih Midi Through.

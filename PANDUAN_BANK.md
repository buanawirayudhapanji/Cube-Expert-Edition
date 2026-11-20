# Bank virtual dan preset file

Jalankan aplikasi seperti biasa, lalu buka menu **Koleksi**. Untuk A/B, gunakan menu **Bandingkan IR**.
Koleksi di laptop dapat menyimpan banyak item; pedal tetap 8 IR dan 3 preset.

## Membuat preset tanpa pedal

1. Klik **Buat preset / Edit salinan preset**.
2. Beri nama, atur TYPE/GAIN/TONE, efek, IR CAB, volume dan SW1/SW2/SW3.
3. Save menyimpan ke koleksi laptop. Untuk membuat varian, pilih preset
   koleksi, buka editor, ubah nama/parameter dan Save; file lama tetap ada.
4. Untuk berbagi atau menyimpan file terpisah, pilih preset lalu **Ekspor file JSON**.
   Gunakan **Impor file** untuk memasukkan kembali JSON tersebut.

## Paket satu preset beserta IR

1. Di **Koleksi**, klik **Paket preset + IR**.
2. Beri nama paket. Pilih pengaturan preset dan IR kabinet dari koleksi atau
   salinan editor saat ini. Pilih IR yang sesuai; aplikasi tidak menganggap
   IR di editor otomatis sama dengan IR yang digunakan preset pada pedal.
   Jika sumber belum ada, buat/simpan preset dan impor WAV ke koleksi dahulu.
3. Klik **Simpan paket**. Pembuatan paket bekerja offline dan tidak menulis pedal.
4. Pilih item **[Paket suara]**. Tentukan **Preset tujuan** A/B/C dan
   **Slot IR tujuan** 1–8, lalu **Kirim ke pedal…**.
5. Periksa kedua target pada konfirmasi. Nomor Kabinet IR pada preset akan
   disesuaikan otomatis ke slot tujuan, termasuk bila sumber sebelumnya 0.
   Parameter lain dan sakelar efek tetap mengikuti preset.
6. Tunggu hingga transfer selesai dan terverifikasi. Pilih A/B/C lewat
   footswitch pedal untuk memakai suara yang dikirim.

Paket berisi data preset dan IR secara mandiri, termasuk Distance, dengan
validasi SHA-256 masing-masing. **Ekspor file JSON** dan **Impor file** juga
mendukung paket; tidak membutuhkan WAV atau berkas sumber setelah dibuat.
Preset biasa dan bank lama tetap bisa dipakai.

Sebelum menulis, sistem mencadangkan sektor IR target dan seluruh preset.
IR ditulis serta diverifikasi lebih dulu; jika gagal, preset paket belum
diterapkan. Setelah itu preset target ditulis dan dibaca ulang, mempertahankan
preset lain dan byte cadangan target. Slot IR yang dipilih akan diganti, sehingga
preset lain yang menggunakan slot tersebut akan mendengar IR baru.

Transfer dua bagian ini tidak atomik. Jika IR sudah selesai tetapi penulisan
preset gagal, IR baru dapat sudah tersimpan sementara preset belum sesuai.
Laporan menampilkan hasil sebagian dan lokasi cadangan; jangan menganggapnya
berhasil. Gunakan prosedur pemulihan di bawah bila diperlukan.

## Mengirim satu preset ke A, B, atau C

1. Hubungkan Cube Baby dan tunggu informasi/preset selesai dibaca.
2. Pilih preset dari daftar koleksi dan tentukan **Preset tujuan A/B/C**.
3. Klik **Kirim ke pedal…** dan periksa nama serta target di dialog.
4. Tunggu status transfer selesai dan terverifikasi. Pilih preset itu lewat
   footswitch A/B/C pada pedal untuk memakainya.

Impor satu preset mengganti parameter target, mempertahankan dua preset lain
dan tiga byte cadangan target. Sebelum penulisan, tiga preset lama disimpan
dalam `presets-before.json`, yang dapat diimpor kembali sebagai bank pemulihan.

Preset membawa angka **IR CAB**, bukan isi IR. Jika preset menunjuk IR CAB 4,
suara kabinetnya mengikuti isi slot IR 4 pada pedal. Untuk memindahkan preset
beserta isi kabinet yang sesuai, gunakan bank berikut.

## Menyusun bank Clean, Rock, Metal, atau per lagu

1. Impor WAV/JSON IR ke koleksi, dan buat/masukkan preset yang diperlukan.
2. Klik **Buat bank**, beri nama, pilih isi untuk target IR1–8 dan preset A/B/C.
3. Pilih **Biarkan slot pedal tetap** untuk target yang tidak ingin diganti.
4. Pastikan IR CAB setiap preset menunjuk slot IR yang sesuai dalam bank.
5. Save menyimpan satu bank portabel di laptop. Pilih bank lalu **Kirim pilihan
   ke pedal…** untuk menerapkan pemetaan itu. Dropdown target preset/IR tunggal
   tidak mengubah pemetaan yang sudah disimpan di dalam bank.

**Salin seluruh bank pedal** membuat bank dari delapan IR serta tiga preset
yang tersimpan pada pedal. Perubahan efek live yang belum disimpan ke pedal
dapat disimpan tersendiri lewat **Simpan preset editor**.

## Konversi IR otomatis

WAV dari Tambah WAV maupun impor koleksi diubah otomatis ke mono 48 kHz dan
512 sampel. PCM8/16/24/32 dan float32/64 (termasuk extensible yang cocok)
didukung. Stereo dirata-ratakan; format terkompresi tidak diterima. Sample
rate diubah dengan filter anti-alias; file panjang dipotong, file pendek
ditambah nol. File sumber tidak ditimpa. Peak yang lebih dari1 diturunkan,
IR yang pelan tidak dinormalisasi menjadi keras. Hasil kosong/nonfinite
ditolak sebelum dapat dikirim. Informasi konversi ditampilkan saat Tambah WAV.

## Membandingkan dua IR

1. Buka **Bandingkan IR**, klik **Pilih IR…** pada A dan B, lalu pilih IR
   dari koleksi atau editor. Di Koleksi, tombol **Jadikan IR A/B** juga tersedia.
2. Mainkan gitar, lalu klik **Dengarkan A** atau **Dengarkan B**. Tunggu satu upload
   selesai sebelum berganti. Kedua kandidat tetap disimpan di sesi aplikasi.
3. **Gunakan Distance editor yang sama** aktif secara default. Penyamaan
   **level puncak** opsional menyesuaikan peak ke0,8; ini bukan pengukuran
   kesamaan loudness perseptual. File asli dalam koleksi tidak berubah.

A/B memakai RAM saja. Simpan ke slot merupakan aksi terpisah melalui editor
atau **Kirim ke pedal**. A/B tidak menambah kapasitas pedal.

## Bila proses gagal

- Semua target bank dibaca dan dicadangkan sebelum penulisan pertama. Jika
  validasi, pembacaan atau penyimpanan cadangan gagal, penulisan belum dimulai.
- Setiap sektor dicek lagi sebelum erase dan diverifikasi byte per byte
  setelah ditulis. Preset diperiksa ulang sebelum disimpan agar perubahan
  yang terjadi selama transfer tidak ditimpa.
- Bank tidak dapat ditulis secara atomik pada perangkat ini. Jika terputus
  setelah beberapa slot selesai, status melaporkan bagian yang selesai dan
  lokasi cadangan. Tidak ada retry penulisan atau rollback seluruh bank otomatis.
- Untuk IR, gunakan cadangan sektor pada Perangkat → Cadangan & pemulihan IR dan slot asalnya.
  Untuk preset, impor `presets-before.json` dari folder transfer sebagai bank,
  periksa target A/B/C, lalu kirim kembali. Pemulihan juga membuat cadangan baru.
- Jangan menganggap tulisan data terverifikasi sebagai bukti suara sudah
  terdengar. Pengujian fitur baru dilakukan dengan simulator; hasil fisik
  tetap perlu dicoba pada pedal.

Data koleksi ada di `library_data/`, cadangan di `backups/transfer-…/`.
Salin kedua folder tersebut saat memindahkan proyek. ZIP source tidak memuat
koleksi pribadi atau cadangan runtime. Ekspor JSON bersifat mandiri, memiliki
kode model, versi format, rentang parameter dan SHA-256 yang diperiksa saat impor.

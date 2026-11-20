# Fitur tambahan yang diizinkan pengguna

Pengguna meminta bank virtual, konversi IR otomatis, A/B, dan banyak preset
file untuk diimpor ke target A/B/C, dengan penanganan error. Fitur ini melampaui
kesetaraan CubeSuite awal; tidak mengubah jumlah slot DSP/flash perangkat.

## Format dan koleksi

`collection.py`: JSON mandiri berformat `cubebaby-library-v1`, model20230,
jenis ir/preset/bank, nama, raw_hex dan SHA-256 setiap record. Batas file1MiB,
nama1–120 karakter tanpa kontrol, bank maksimal8 IR/3 preset, target integer
unik dalam batas. IR harus2056 byte, float finite/Distance0–100 dan koefisien
tidak seluruhnya nol. Preset16 byte memakai rentang parameter dari editor
asli; byte13–15 disimpan tetapi dipertahankan dari target saat deploy.

Koleksi memakai nama file UUID, tidak menggunakan nama user sebagai path.
Save: file temp satu filesystem, flush/fsync, replace atomik, fsync direktori.
Pembuatan direktori turut fsync parent sebelum backup digunakan untuk erase.
File rusak pada koleksi dilaporkan tanpa menyembunyikan item valid. Impor
batch memvalidasi semua input sebelum save pertama; error disk tetap dapat
menghasilkan koleksi lokal sebagian, dengan jumlah item berhasil dilaporkan.
File sumber tidak dieksekusi, diekstrak, atau digunakan sebagai referensi path.

## Konversi

`convert_ir.py`: parser RIFF/WAVE little-endian terbatas128MiB dengan validasi
ukuran chunk, fmt/block-align/byte-rate, batas rate8–384kHz dan1–2 kanal.
Mendukung PCM8/16/24/32, IEEE float32/64, GUID extensible PCM/float yang sesuai.
Decoder membaca prefix yang diperlukan beserta halo FIR, bukan seluruh file.
Stereo dirata-ratakan. Konversi48kHz memakai windowed-sinc Hann32/cutoff,
cutoff0,94*min(1,48000/input_rate). Output512 float32 dengan trim/zero-pad.
Peak di atas1 diturunkan; tidak mengangkat IR kecil. NaN/Infinity/hasil kosong,
stereo yang saling membatalkan, chunk terpotong, dan format terkompresi ditolak.
Helper `wav_ir.load_wav` tetap untuk pembandingan jalur legacy; GUI memakai
konverter baru. Semua konversi memakai standard library, tanpa paket tambahan.

## Transfer

`transfers.BankTransfer` membekukan rencana menjadi bytes, membaca seluruh
4096 byte setiap target IR dan48 byte preset sebelum penulisan. Semua cadangan
disimpan durable sebelum erase pertama. IRWriter membaca ulang target tepat
sebelum erase; record maupun padding yang berubah sejak backup membatalkan
penulisan berikutnya. Record baru tidak menimpa padding target.

Preset diperiksa kembali sesudah transfer IR; jika snapshot48 byte berubah,
tidak ada write preset. Hanya13 parameter target ditambal ke snapshot terbaru
yang cocok. Dua preset yang tidak dipilih serta byte reserved target dipertahankan.
Write memakai region5 alamat0 panjang48, jalur yang dipetakan dari CubeSuite,
kemudian seluruh48 byte diverifikasi. Backup preset berupa bank pemulihan3
record yang dapat diimpor lewat UI koleksi.

Transfer bank tidak atomik di pedal. Kesalahan setelah beberapa slot selesai
melaporkan completed slots dan folder backup, mempertahankan cadangan, berhenti
tanpa retry write atau rollback seluruh bank. UI dan close terkunci selama
transfer; semua pekerjaan tetap berbagi pending tunggal MIDI asli. Collection
offline tidak memulai I/O pedal. Bank kosong/salah model/checksum/rentang/target
ditolak sebelum ada permintaan ke perangkat.

## A/B dan preset offline

`library_gui.py`: editor13 parameter offline dengan validasi rentang dan nama,
save-as item baru, ekspor/impor, pemetaan8IR/3preset sparse, capture bank dari
slot tersimpan, capture satu preset dari editor, serta pemilihan target preset.
Impor preset menyimpan parameter tetapi tidak menjanjikan aktivasi preset lewat
selector software; footswitch pedal memilih preset yang aktif, sesuai jalur
protokol yang sudah dipetakan. Isi IR harus dibawa melalui bank bila diperlukan.

A/B menyimpan dua snapshot bytes mandiri di sesi, lalu memakai PreviewJob
yang sama. Tidak ada region0 erase/write atau region5 write dari A/B.
Distance yang sama dan peak0,8 opsional diterapkan pada salinan preview;
file koleksi tidak dimutasi. UI mencegah pergantian saat pekerjaan lain aktif.
IR koleksi yang dimuat ke editor mempertahankan seluruh raw bytes/header dan
presisi Distance sampai pengguna mengeditnya, bukan membulatkan ulang diam-diam.

## Verifikasi dan batas

120 pengujian unik lulus. Tambahan28 pengujian mencakup format koleksi/korupsi,
SHA/rentang/duplikasi target,40 preset tersimpan, atomic-save failure, konversi
stereo/float/extensible, frekuensi44100→48000, anti-alias96000→48000, file WAV
rusak/nonfinite, transfer ke C saja, reserved-byte preservation, all-backups-
before-first-erase, disk full, bank terputus setelahIR1, preset stale, A/B
RAM-only dan peak matching, capture bank read-only, serta create/import offline.
UI dirender offscreen untuk memastikan tab dapat dibuka dan kontrol terlihat.

Semua akses perangkat baru diuji lewat simulator. Belum ada klaim hasil suara
atau transfer bank/preset fisik. `CubeSuite/CubeSuite.exe` tetap SHA-256
0e0183fd6dc1b347534c9ce1e3677ecda2a6ae77fe3da8d6314d43c7c2cfd2e6.

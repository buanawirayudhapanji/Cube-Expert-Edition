# Hasil awal reverse engineering CubeSuite

Tanggal: 19 November 2026. Analisis statis terhadap file lokal, ditambah respons identitas dari pedal
yang dikirim pengguna. Query identitas telah berhasil pada satu perangkat;
pembacaan informasi model melalui opcode 0x23 juga berhasil pada pedal kode 20230.
Pembacaan isi slot IR masih perlu pengujian hardware. Semua alamat di bawah adalah virtual address pada image base
`0x00400000`, bukan offset file.

## Identitas binary

- File: `CubeSuite/CubeSuite.exe`, ukuran 3.945.984 byte.
- SHA-256: `0e0183fd6dc1b347534c9ce1e3677ecda2a6ae77fe3da8d6314d43c7c2cfd2e6`.
- PE32 x86, aplikasi native Windows; tidak memiliki CLR runtime header.
- String versi: `CubeSuite V2.8.10` pada `0x00580D50`.
- Dependensi Qt5 Core/Gui/Widgets/Network dan WinMM.
- RtMidi membuka input/output melalui Windows MIDI; terdapat fungsi
  `midiOutLongMsg` dan callback penerimaan MIDI.

## Perangkat yang dilaporkan pengguna

USB `301a:5555`, nama `USB2.0 Device`, port MIDI `USB2.0 Device MIDI 1`.
Input/output muncul melalui ALSA. Nomor `hw:2,0,0` bersifat sementara. Tidak adanya
pesan saat knob diputar belum membuktikan koneksi gagal.

Lingkungan analisis tidak memiliki `/dev/snd`; `lsusb` juga gagal menginisialisasi
libusb. Query tidak dijalankan langsung dari lingkungan analisis. Pengguna telah
menjalankan CLI identitas di laptopnya dan memperoleh respons `SINCO-CubeBaby`.
Pada fase awal hanya perintah baca yang diterapkan. Implementasi penyimpanan
slot di bagian pembaruan terakhir kini menambahkan operasi tulis eksplisit.
Penulisan belum dijalankan dari lingkungan analisis ke pedal fisik.

## Rantai transport yang ditemukan

| Alamat | Peran berdasarkan kode |
|---|---|
| `0x00486300` | Membuka input RtMidi dan memasang callback `0x004867E0` |
| `0x004864F0` | Membuka output RtMidi |
| `0x004867E0` | Meneruskan byte input ke buffer melalui `0x0050FE40` |
| `0x00486810` | Membuka input dan output |
| `0x00486980` | Membungkus data dengan F0/F7 dan mengirim melalui RtMidi |
| `0x00486AD0` | Mengatur flag pengemasan 7-bit dan membersihkan buffer input |
| `0x00486AF0` | Wrapper pengiriman yang mengembalikan jumlah byte mentah |
| `0x00508080` | Memanggil transport pengiriman sesuai mode koneksi |
| `0x00508180` | Membuka koneksi; mode 1 mengaktifkan pengemasan 7-bit |

Fungsi pengirim memiliki dua cabang: mengemas 8-bit menjadi 7-bit atau menyalin
byte mentah. `cubebaby_mod/codec.py` mengimplementasikan cabang pengemasan. Belum
dipastikan apakah seluruh revisi Cube Baby memakai cabang yang sama.

Bit stream disusun little-endian: setiap byte sumber ditambahkan ke accumulator,
lalu dikeluarkan per 7 bit terendah. Ini berbeda dari format MIDI yang memakai
satu byte MSB diikuti tujuh byte data.

Contoh yang mengikuti instruksi assembly:

| Data sumber | Data 7-bit |
|---|---|
| `FF` | `7F 01` |
| `01 02` | `01 04 00` |
| tujuh byte `FF` | delapan byte `7F` |

## Struktur paket kandidat

Berdasarkan builder pada `0x00507680` sampai `0x00507930`:

| Offset mentah | Ukuran | Arti |
|---|---|---|
| 0 | 2 byte | Header, nilai awal global `0x00756AD0` adalah `00 59` |
| 2 | 1 byte | Opcode |
| 3 | 3 byte | Panjang payload, little-endian |
| 6 | N byte | Payload |
| 6 + N | 1 byte | `(~sum(payload)) & 0xFF` |

Dengan mode packed: paket mentah dikemas ke byte 7-bit, lalu dibungkus F0/F7.
`decode_packet()` baru mendukung cabang packed dan memvalidasi header, panjang,
padding, serta checksum. Nama fungsi dan struktur ini adalah rekonstruksi,
bukan nama asli dari source code vendor.

## Query identitas

Rantai `0x005068B0 -> 0x00507DE0 -> 0x00507930` mengirim opcode `0x11` tanpa payload.
Fungsi pertama kemudian menunggu opcode `0x11` dengan parameter panjang paket mentah `0x22`
(34 byte, termasuk header dan checksum; payload 27 byte) dan menafsirkan informasi perangkat/versi. Ini mendukung interpretasi
bahwa opcode tersebut adalah query identitas. Respons pengguna mengonfirmasi
opcode dan format ini pada pedal SINCO-CubeBaby yang diuji.

- Paket mentah: `00 59 11 00 00 00 FF`.
- SysEx mode packed: `F0 00 32 45 00 00 00 40 7F F7`.
- Program baru tidak mengirimnya otomatis.
- CLI `--identify INPUT --output OUTPUT` mengirim tepat satu query dan menunggu
  maksimal dua detik; tanpa retry.
- Echo query tidak dianggap respons. Respons harus memiliki opcode, panjang,
  header dan checksum yang cocok. `0x00507AA0` membandingkan jumlah byte mentah
  terhadap parameter panjang sebelum memvalidasi checksum. Identitas model belum diinterpretasikan.

## Variasi perangkat

Tabel mulai `0x007548E0` berisi 42 entri berukuran `0x54` byte, ditelusuri oleh
`0x00488EB0`. Entri awal berisi kode numerik dan nama ASCII. Hasil disimpan pada
`device_table.json`. Kode tersebut adalah kode internal software, bukan USB VID/PID.

| Nama | Kode internal yang ditemukan |
|---|---|
| Cube Baby | 10030, 10130, 20130, 20030, 20230, 20233 |
| Cube Baby AC | 20430 |
| Cube Baby Bass | 20530, 30431 |

USB ID saja belum cukup untuk memilih revisi firmware atau model yang tepat.

## Implementasi dan verifikasi

Aplikasi baru di `cubebaby_mod/` berisi GUI monitor pasif, CLI daftar port/monitor,
codec offline, validator paket, koneksi GUI, dan pembacaan info perangkat
eksperimental. Lima puluh tiga uji otomatis lulus: framing SysEx, input/output terpisah, kegagalan backend, unplug,
batas panjang codec, padding, checksum, query tunggal, timeout, dan cleanup port.
GUI juga diuji offscreen, termasuk saat ALSA tidak tersedia. Uji transport
memakai simulasi; fixture identitas berasal dari respons pedal pengguna.
Respons baca informasi model asli dari pengguna juga menjadi fixture.
Data isi slot IR dalam uji masih berupa simulasi.

Belum tersedia: editor efek penuh, import WAV, preview live dan pembaruan firmware.
Pembacaan slot telah dibuktikan melalui ekspor pengguna; penyimpanan slot
masih memerlukan pengujian fisik.

## Langkah teknis berikutnya

1. Uji satu perubahan Distance tersimpan, lalu simpan log penulisan/verifikasi.
2. Cocokkan nilai Distance hasil baca ulang terhadap rencana perubahan.
3. Uji pemulihan cadangan sebelum memperluas dukungan format IR.
4. Bandingkan paket terhadap rekaman CubeSuite asli bila ada perbedaan perilaku.

Analisis dapat diulang dengan `bash analysis/run-ghidra.sh` setelah Ghidra
terpasang. Script tidak mengubah executable asli dan menaruh workspace Ghidra
sementara dalam direktori baru di `/tmp`. Inventaris binary dapat diulang dengan
`python tools/inspect_binary.py CubeSuite/CubeSuite.exe`.

## Berkas bukti

`decompiled_protocol/` berisi 19 fungsi protokol yang diekspor Ghidra secara
terarah. Pseudocode diperiksa terhadap assembly, terutama jalur query identitas,
ukuran respons, dan bit packing. Pseudocode bukan source asli dan dapat memiliki
tipe/parameter yang kurang tepat; instruksi assembly menjadi acuan saat berbeda.

`decompiled_context/` berisi 490 fungsi konteks yang berhasil diekspor pada pass
analisis penuh. Ini subset konteks, bukan dekompilasi lengkap CubeSuite. Daftar
alamat ada pada `context_function_addresses.txt`. Pass analisis otomatis selesai;
ekspor konteks dihentikan setelah bukti untuk tahap ini memadai. Workspace penuh
pass tersebut tidak disimpan. Pass protokol terarah selesai dan tersimpan dalam
log `ghidra_protocol.log`.

`run-ghidra.sh` secara default mengekspor fungsi protokol terarah. Tambahkan
`--full` untuk menjalankan analisis otomatis, penelusuran pemanggil, dan ekspor
konteks; proses tersebut lebih lama.


## Pembaruan GUI dan pembacaan info perangkat

GUI kini mempunyai tombol Hubungkan/Putuskan, pemilihan input/output, pembacaan
identitas nonblocking, log IN/OUT/EVENT, dan tombol Baca info perangkat.
Respons yang gagal checksum atau tidak cocok dengan permintaan tidak dianggap
berhasil. Timeout identitas menutup kedua port; timeout info mempertahankan
identitas dan mengizinkan percobaan manual berikutnya. Tidak ada retry otomatis.

Identitas nyata dari pengguna disimpan sebagai fixture
`tests/fixtures/identity_response.hex`, dengan nama perangkat `SINCO-CubeBaby`.
Tidak ada versi firmware yang ditebak dari byte metadata identitas.

Rantai pembacaan metadata model:

| Fungsi | Peran berdasarkan kode |
|---|---|
| `0x005069D0` | Default profile memilih alamat informasi 0x2100 |
| `0x005071F0` | Membaca 20 byte dari region 0, lalu mengurai lima uint32 little-endian |
| `0x005063F0` | Membagi operasi baca menjadi chunk dan memvalidasi respons |
| `0x00507E60` | Mengirim permintaan baca opcode 0x23 melalui builder 0x005077D0 |
| `0x00507BA0` | Memeriksa opcode 0x23, region, alamat, panjang dan checksum; menyalin data |
| `0x00506590` | Operasi tulis opcode 0x22; tidak diterapkan di aplikasi baru |

Payload permintaan baca info:
`00 00 21 00 00 14 00 00` = region 0, alamat 0x2100 (uint32 LE), panjang 20 (uint24 LE).
Respons diharapkan mengembalikan metadata delapan byte yang sama diikuti 20 byte
data. Field uint32 kedua pada data (offset 4) adalah kode internal model menurut
0x005071F0. Field pertama dan field ketiga/keempat tetap disimpan sebagai angka mentah.
Field kelima kemudian teridentifikasi sebagai alamat dasar penyimpanan slot IR
melalui penelusuran fungsi penyimpanan yang dijelaskan di bawah.

Tombol baca ini hanya aktif untuk identitas persis `SINCO-CubeBaby`. Perintahnya
direkonstruksi dari analisis statis dan kini telah berhasil pada pedal pengguna. Jika timeout atau
kode model tidak dikenali, aplikasi tidak melanjutkan operasi lain. Pada tahap koneksi belum ada operasi tulis. Tahap penyimpanan di bagian
terakhir menambahkan Distance/IR JSON; reset dan pembaruan firmware tetap tidak tersedia.

`decompiled_settings/` memuat delapan fungsi terkait yang diekspor untuk tahap
ini. Script `ReadSettings.java` dan `run-ghidra.sh` dapat mengulang ekspor tersebut.


## Profil 20230 dan pembacaan slot IR

Respons konfigurasi asli pengguna mengembalikan `[1, 20230, 196608, 393216, 430080]`
dua kali dengan data identik. Data ini menjadi fixture `device_info_20230.hex`.
Field kelima, 430080 atau `0x69000`, dipakai sebagai alamat dasar IR berdasarkan
rantai `0x005071F0 -> +0x2CA74 -> fungsi penyimpanan slot`.

Tabel model di `0x00754F1C` memuat kode 20230, nama Cube Baby, feature bits mentah
`0x80`, dan pointer descriptor `0x007548D0`. Descriptor menunjuk region 0,
sektor 4096 byte, ukuran penyimpanan 524288 byte. Makna lengkap feature bits dan
pemilihan seluruh fitur UI tidak diasumsikan. Hasil ekstraksi ada pada
`model_20230.json`; script `tools/inspect_model_20230.py` dapat mengulangnya.

Format blok IR yang sama ditemukan di dua editor CubeSuite:

| Fungsi standar / Jun | Bukti |
|---|---|
| `0x004A42C0` / `0x0049EFD0` | Daftar delapan pilihan slot |
| `0x004A4070` / `0x0049EC50` | Menyusun blok 0x808 byte: header 4 byte, float32 Distance, 512 koefisien float32 |
| `0x004A3ED0` / `0x0049E970` | Menyimpan pada alamat dasar IR + index slot * 0x1000 |
| `0x004A3770` / `0x0049E220` | Nilai slider Distance dibagi konstanta float32 100.0 di 0x00584580 |
| `0x005071F0` | Kode 20230 (0x4F06) membatasi paket baca mentah 128 byte |

Editor standar dan Jun memiliki fitur lain yang berbeda. Aplikasi baru hanya
menerapkan pembacaan layout IR bersama tersebut, dibatasi untuk kode 20230.
Belum ada klaim dukungan semua kontrol efek dari kedua editor.

Alamat slot dihitung dari respons metadata terbaru: `base + (slot-1)*4096`.
Base harus sejajar sektor dan seluruh delapan blok harus berada di dalam batas
region 0 sebesar 0x80000 byte. Satu blok 2056 byte dibaca menggunakan 19 permintaan
opcode 0x23: 18 permintaan 113 byte data dan satu permintaan 22 byte.
Fungsi 0x005063F0 mengurangi batas mentah 128 byte dengan overhead 15 byte
sebelum menentukan ukuran data setiap permintaan. Setiap respons
harus cocok region, alamat, panjang dan checksum sebelum buffer diperpanjang.

Data yang berhasil dibaca ditampilkan sebagai Distance tersimpan pada skala
0–100 dan jumlah koefisien. Header empat byte tetap mentah karena makna lengkapnya
belum dipastikan. Interpretasi float hanya dilakukan jika nilainya finite dan
Distance berada pada rentang 0–1 sebelum dikalikan 100. Slot yang tidak cocok
format tetap dapat diekspor sebagai data mentah setelah seluruh pembacaan selesai.
Ini pemeriksaan kewajaran format, bukan bukti bahwa koefisien sama dengan suara
pedal sampai pembacaan hardware diverifikasi.

GUI menambahkan pilihan slot 1–8, Baca slot IR, dan Ekspor slot IR JSON. Snapshot
mencakup 2056 byte record yang dipetakan, bukan seluruh sektor 4096 byte. Data
JSON menyimpan byte mentah, header, alamat, nomor slot, serta Distance/koefisien
bila format dikenali. Sample rate belum dipastikan sehingga tidak dibuat WAV.
Pada tahap pembaca belum ada perintah tulis. Pembaruan penyimpanan di bawah
menambahkan perubahan Distance/IR tersimpan; aktivasi slot tetap melalui pedal.

Timeout, putus koneksi, atau pembatalan membuang buffer parsial dan tidak membuat
snapshot. Tidak ada retry otomatis. Percobaan manual baru dimulai dari awal.
Pengujian tahap pembaca mencakup dua respons nyata dari pengguna, pembacaan 19 chunk,
slot terakhir, penolakan respons salah alamat/ukuran, model/alamat tidak didukung,
slot terhapus/NaN, timeout setelah sebagian data, putus koneksi, dan ekspor JSON.
Pembacaan kemudian dikonfirmasi lewat ekspor slot 2 dari pengguna: kode 20230,
alamat 434176 (0x6A000), ukuran 2056 byte, header `01 00 00 00`, Distance 75
dan 512 koefisien yang tidak kosong. Penulisan masih diuji memakai simulasi.


## Penyimpanan Distance, impor IR JSON dan pemulihan

Fitur penyimpanan menyasar record slot tersimpan, bukan kontrol live RAM.
Pemetaan live `0x004A3770 / 0x0049E220 -> 0x00507EA0 -> 0x005066C0` juga ditemukan,
namun belum diterapkan karena memakai urutan penutupan IR, perubahan RAM,
pengaktifan kembali, dan verifikasi checksum opcode 0x24 tersendiri.

Jalur penyimpanan flash yang diterapkan:

| Alamat | Bukti |
|---|---|
| `0x004A3ED0` / `0x0049E970` | Hapus sektor alamat IR base + slot*4096, jeda 100 ms, lalu tulis record |
| `0x005063A0 -> 0x00507D60 -> 0x00507770` | Opcode erase 0x21, payload region uint8 + alamat uint32 LE; menunggu ACK sukses |
| `0x00506590 -> 0x00507CD0 -> 0x00507850` | Opcode tulis 0x22, payload region + alamat + panjang uint24 LE + data; chunk 128 byte untuk model ini |
| `0x00507B30` | ACK sepanjang 8 byte mentah: opcode 0, satu byte status; status 0 diterima |
| `0x004A5930` | Baca ulang dan bandingkan dengan data tulis sebelum melaporkan sukses |

Implementasi baru memperluas preservasi sektor: membaca seluruh 4096 byte
sebelum erase, menyimpan cadangan JSON dengan SHA-256 melalui flush/fsync file
serta direktori, dan mempertahankan byte sektor di luar record 2056 byte.
Jika record berubah sejak snapshot dibaca atau cadangan gagal, tidak ada erase.
Jika data sudah sama persis, tidak ada erase/tulis maupun cadangan baru.

Perubahan Distance mengganti hanya empat byte float32 offset 4. Header asli
pengguna `01 00 00 00` tetap dipertahankan; arti header tidak diasumsikan.
Impor JSON biasa mengganti Distance dan koefisien dari raw byte tervalidasi,
seraya mempertahankan header target. Daftar koefisien yang tertulis di JSON tidak
dipercaya tanpa rekonstruksi dari raw byte. Format float harus finite dan
Distance 0–1. WAV tidak diterima sampai format konversinya dipastikan.

Simpan hanya aktif untuk identitas SINCO-CubeBaby dan profil metadata persis
`[1,20230,196608,393216,430080]`. Ini membatasi penulisan ke layout yang dibaca
pada pedal pengguna, bukan seluruh perangkat yang bernama Cube Baby.

Urutan normal: 37 baca preflight (113 byte data maksimum), cadangan durable,
1 erase, ACK status 0, jeda 100 ms nonblocking, 32 tulis x 128 byte data,
kemudian 37 baca verifikasi. Seluruh 4096 byte harus cocok. Batas data tulis
128 mengikuti fungsi 0x00506590; batas data baca 113 mengikuti 0x005063F0 yang
mengurangi overhead 15 dari batas respons mentah 128.

ACK gagal, timeout atau mismatch menghentikan urutan tanpa retry dan tanpa
rollback otomatis. Setelah permintaan erase dibuat, status dianggap mungkin
berubah meskipun ACK hilang. GUI menutup koneksi saat gagal dan mencantumkan
lokasi cadangan; user dapat membaca ulang target lalu memuat cadangan penuh
untuk pemulihan. Cadangan harus cocok kode perangkat, slot, alamat, ukuran dan
SHA-256. Pemulihan mengembalikan seluruh sektor, termasuk padding/header asli,
dan membuat cadangan kondisi terkini terlebih dahulu.

53 uji otomatis lulus, termasuk urutan operasi tepat, backup-before-erase,
preservasi header/koefisien/padding, stale snapshot, backup disk full, ACK negatif,
read-back mismatch, timeout setelah erase, impor JSON, pemulihan sektor rusak,
dan GUI yang tidak menutup di tengah erase/tulis. Pengujian tulis memakai pedal
simulasi. Belum ada hasil tulis/pemulihan dari pedal fisik.

Pseudocode tambahan tersedia pada `decompiled_write/` dan dapat diekspor ulang
dengan `WriteIR.java`. Cadangan runtime disimpan di direktori `backups/` proyek;
file sumber CubeSuite tidak dimodifikasi.

## Penyamaan panel Cube Baby (19 November 2026)

Bagian sebelumnya mencatat status historis tiap tahap. Status terbaru ada di
PARITY.md. Log dan laporan pengguna sesudah tahap writer mengonfirmasi Distance
slot 2 berubah 75→74 dengan byte float `a4 70 3d 3f`, seluruh sektor baca ulang
cocok, dan pengguna mengonfirmasi pemulihan ke semula berhasil.

### Preset dan parameter live

Menu model 20230 memiliki bit 0x80. Daftar QString pada 0x75C438 indeks 7
menunjuk 0x754748 (Cube Baby*), ctor 0x49DEE0. Init 0x49EEA0 membaca region 5,
alamat 0, panjang 48; tiga record 16 byte. Save 0x49EB20 memanggil 0x4A3250
untuk 48 byte yang sama. 0x49F520 menulis byte tunggal ke region 5 dengan alamat
0x80000000 + indeks_preset*16 + offset. Selector preset hanya memilih record
lokal; tidak ditemukan perintah aktivasi preset dalam jalur tersebut.

| Offset | Parameter | Maksimum | Kelompok |
|---|---|---|---|
| 0 | TYPE | 8 | SW1 |
| 1 | GAIN | 7 | SW1 |
| 2 | TONE | 15 | SW1 |
| 3 | REVERB | 15 | SW3 |
| 4 | FB | 127 | SW2 |
| 5 | VOLUME | 127 | Selalu |
| 6 | TIME | 31 | SW2 |
| 7 | MIX | 118 | SW2 |
| 8 | MOD | 15 | SW2 |
| 9 | IR CAB | 8 | SW3 |
| 10 | SW3 | 1 | Sakelar |
| 11 | SW2 | 1 | Sakelar |
| 12 | SW1 | 1 | Sakelar |
| 13–15 | Belum diketahui | — | Dipertahankan saat edit |

Rentang: 0x49F590; binding offset: 0x49EEA0; enable kelompok: 0x4A02E0.
Factory Effects 0x49E910 memilih konstanta 48 byte di 0x58487C untuk 20230.
USB Loopback dibaca ctor dari region 0, alamat 0x3000, satu byte; handler
0x49EC30 menulis byte bool ke alamat yang sama tanpa erase sektor aplikasi.

### Preview IR dan Distance

0x4A0120/0x49E220 -> 0x507EA0 -> 0x5066C0: region 4, gate 0x764=0,
data pada 0x768, gate 0x764=1. IR penuh berisi float Distance dan 512 float
koefisien (2052 byte), perubahan Distance saja empat byte. Setiap penulisan
memakai chunk 128 byte dengan ACK, kemudian opcode 0x24.

Builder 0x507700: payload region uint8 + address uint32LE + length uint32LE.
Parser 0x5079C0: respons raw 18 byte, payload 11 byte dengan metadata sama
serta sum16LE. Checksum memori adalah sum(byte data) & 0xFFFF; berbeda dari
checksum komplemen 8-bit pembungkus. Penolakan ACK, timeout dan checksum
mismatch menghentikan urutan; gate tidak dibuka lagi setelah checksum gagal.

### WAV dan reset IR

0x50A660 menerima WAVE format PCM1. 0x50B2C0 mengonversi block-align 2/4
menjadi signed16/32767 dan 3/6 menjadi signed24/8388608, mengambil kanal
pertama. Jalur pemilihan file 0x49E630 memanggil konversi 512 sampel,
melengkapi nol, kemudian preview 0x4A0120; tidak memanggil resampler generik.
Layout PCM16/24 mono/stereo diterapkan. Layout lain belum diaktifkan.

Record WAV baru dibuat 0x49EC50 dengan memset nol dan header empat byte nol,
float Distance offset 4, koefisien offset 8. Karena itu header 0 digunakan
untuk WAV baru. Ini berbeda dari modifikasi record slot yang sudah dibaca atau
impor JSON, yang mempertahankan header target sebagai aturan masing-masing.

Factory IR 0x49E350 memuat BFI.bin untuk 20230, sumber offset 0x9000 panjang
0x8000 ke IR base. Implementasi membagi delapan sektor dan menggunakan writer
backup/verify yang sama. Image pabrik memiliki header 1 pada delapan record.

### Implementasi dan batas validasi terbaru

GUI default sekarang SuiteWindow; Window lama tetap backend transport dan
writer yang diuji. Seluruh pekerjaan memori memakai satu slot pending yang
sama, sehingga efek/preview tidak berbarengan dengan IR flash. 73 uji otomatis
lulus; penambahan 20 uji unik mencakup paket live, preset, WAV, preview, reset,
checksum gagal dan timeout. Uji fitur baru memakai simulator, bukan USB fisik.
Firmware updater dan penyamaan visual persis belum selesai; jangan menyebut
rilis ini identik 100% atau menganggap uji simulasi sebagai bukti hardware.

### Prioritas fungsi dan perilaku interaksi

Arahan pengguna berikutnya menunda kesamaan visual; hanya kesetaraan fungsi
menjadi sasaran tahap ini. Penelusuran 0x49EFD0 menghubungkan itemClicked
(0x5843A4), bukan itemDoubleClicked, ke OnIrFileSelected. 0x49E710 memanggil
getOpenFileNames dan mengganti daftar file setelah pilihan tidak kosong.
Implementasi kini memilih banyak WAV sekaligus, menampilkan path lengkap dan
memulai preview dengan satu klik. Memilih daftar file belum mengirim preview.

Loop koneksi 0x49EFD0 menghubungkan valueChanged(int) setiap slider/spin ke
onEffectValueChange; implementasi sebelumnya menunggu slider dilepas atau spin
selesai diedit. Sekarang perubahan langsung dikirim live. Saat ACK masih
tertunda, nilai terbaru diantrekan per pasangan (preset, offset); nilai antara
untuk parameter sama dapat digabung agar tidak menumpuk, namun nilai akhir
selalu dikirim. Antrean tidak menukar tujuan ketika selector preset berganti.
Save Effects tetap dinonaktifkan sampai semua ACK selesai, dan error/stop
membuang antrean serta cache. Ini menjaga satu request aktif tanpa mematikan
slider selama pengguna menggesernya. 76 uji unik lulus, termasuk tiga regresi
untuk interaksi live dan pemilihan banyak file. Kesetaraan fungsi penuh belum
dinyatakan selesai; format WAV lain, updater dan uji pedal tetap tercatat.

## Bug Distance membuat IR menghilang — perbaikan

Pengguna melaporkan IR langsung hilang saat Distance diganti. Inspeksi kode
menemukan preview_distance memanggil full preview ketika preview_active=False;
padahal perubahan Distance tidak seharusnya mengunggah ulang koefisien tanpa
permintaan Preview. Jalur Distance lama juga menutup gate 0x764 lalu menunggu
checksum sebelum mengembalikannya; error/timeout di antaranya menutup koneksi
dan dapat meninggalkan IR nonaktif. Belum ada log pedal untuk memastikan jalur
mana yang memicu gejala pengguna; kedua risiko kode diperbaiki dan diuji.

Distance setelah membaca slot kini hanya mengubah rencana lokal sampai Save;
tidak ada upload IR implisit. Jika preview sudah aktif, DistanceJob membaca
status gate region 4 alamat 0x764, menerima hanya 0/1, menutup gate dengan ACK,
menulis empat byte float ke 0x768, mengembalikan gate asli dengan ACK, kemudian
membaca ulang status dan float. Rentang koefisien mulai 0x76C tidak ditulis.
Verifikasi dilakukan setelah gate dikembalikan, bukan saat IR masih ditutup.

Jika ACK/error/timeout menghentikan urutan setelah perintah tulis mulai,
DistanceJob melakukan satu upaya pemulihan gate asli dan memverifikasinya lewat
baca ulang. Ini khusus Distance karena koefisien tidak pernah ditimpa; tidak
memaksakan gate aktif bila sebelumnya nonaktif, tidak mengulangi tulis Distance,
dan tidak melaporkan nilai Distance sukses sesudah recovery. Recovery gagal
menutup koneksi dengan status belum dapat dipastikan, tanpa loop retry.
Pemulihan ini tidak diterapkan pada upload IR parsial yang koefisiennya mungkin
belum lengkap. Event editingFinished tanpa nilai berubah tidak mengirim data.

Polling juga berhenti ketika callback recovery menutup port agar tidak mencoba
poll pada port None. Total 83 uji unik lulus, termasuk tujuh regresi Distance:
no full upload dari stored slot, gate sebelumnya nonaktif, ACK negatif,
timeout, unchanged focus, gate tidak dikenal, dan recovery yang juga ditolak.
Pengujian merupakan simulasi; perbaikan belum dikonfirmasi pada pedal fisik.

## Tindak lanjut timeout Preview IR

Pengguna mengonfirmasi Preview IR masih terhenti dengan pesan timeout setelah
perbaikan Distance. Perbaikan sebelumnya hanya mengubah DistanceJob; Preview
masih memakai urutan gate0 + checksum + upload + checksum + gate1 + checksum.
Log MIDI lengkap dari kegagalan ini belum tersedia, sehingga belum terbukti
permintaan mana yang tidak dibalas (atau respons mana yang ditolak parser).

Jalur aktif kini PreviewJob, menggantikan dan menghapus preview_steps lama.
Sebelum penulisan, baca region4 gate 0x764 dan 2052 byte mulai 0x768 ke snapshot
sesi. Jika pembacaan tidak lengkap, berhenti tanpa menonaktifkan IR atau menulis.
Setelah snapshot lengkap dan gate 0/1 dikenali: gate0 dengan ACK, upload data
2052 byte chunk128 dengan ACK, gate1 dengan ACK, lalu baca ulang semua data
serta gate. Sukses hanya bila semuanya cocok byte per byte. Tidak mengirim
opcode0x24 di jalur Preview, sehingga respons checksum RAM tidak diperlukan.

Jika error setelah gate dimodifikasi, lakukan satu recovery: bila data mungkin
sudah ditulis, gate0 + unggah snapshot RAM asli + pulihkan gate asli, lalu
verifikasi data/gate. Jika baru gate yang dimodifikasi, cukup pulihkan gate
asli dan verifikasi. ACK hilang dianggap mungkin sudah menerapkan penulisan.
Tidak ada retry upload baru; recovery yang gagal berhenti dan melaporkan
ketidakpastian, tanpa klaim pemulihan berhasil. Ini memulihkan RAM sesi, bukan
mengubah sektor flash maupun melakukan factory reset.

MemoryJob.waiting_description menambahkan jenis langkah, region, alamat,
panjang dan indeks ke pesan error. Jika perangkat menolak/tidak mendukung
pembacaan region4, preflight akan timeout tanpa perubahan RAM dan log memberi
alamat yang perlu ditelusuri dari respons fisik. Tidak menganggap baca ulang
RAM telah terverifikasi pada hardware hanya karena simulator mendukungnya.

88 pengujian unik lulus. Lima regresi baru menguji preflight timeout tanpa
write, timeout di chunk kedua (0x7E8) yang mengembalikan seluruh snapshot asli,
readback mismatch dengan gate sebelumnya nonaktif, rollback yang ditolak tanpa
retry tak terbatas, serta gate-close ditolak sebelum penulisan koefisien.
Pengujian Preview lama yang mengharapkan IR tetap mati ketika checksum gagal
diganti regresi Preview berhasil tanpa adanya respons opcode0x24 sama sekali.
Konfirmasi fisik tetap memerlukan pengguna menjalankan ulang versi terbaru dan
mengirim MIDI log JSON apabila masalah masih muncul.

## Koreksi asumsi byte kontrol 0x764 berdasarkan log pedal

Log pengguna 2026-11-19T13:34:29.597331+00:00 mencatat mismatch hanya pada
langkah 59/59: read region4 0x764 panjang1. Pada urutan PreviewJob ini, seluruh
2052 byte data IR sudah dibandingkan dan cocok di langkah-langkah sebelumnya.
Penolakan berasal dari syarat tambahan expected=01 pada pembacaan kontrol;
bukan bukti upload koefisien gagal. Nilai aktual byte tidak tercantum dalam
kutipan log, jadi tidak disimpulkan bahwa perangkat pasti mengembalikan 00 atau
bahwa mekanisme tepatnya sudah diketahui.

Asumsi sebelumnya bahwa 0x764 adalah status aktif/nonaktif persisten terlalu
kuat dan kini dicabut. Jalur asli 0x4A0120 dan 0x49E220 menulis kontrol 0,
memperbarui data, kemudian menulis 1; tidak mengharuskan baca ulang byte kontrol
sama dengan nilai tulis. PreviewJob tetap memverifikasi data byte per byte dan
ACK perintah aktivasi. Pembacaan kontrol akhir hanya dicatat di EVENT diagnostik,
tidak dibandingkan dengan 01 dan tidak memicu rollback bila berbeda.

DistanceJob juga mengakhiri pembaruan dan recovery dengan perintah1, mengikuti
0x49E220, bukan mengirim ulang kontrol_before yang tidak terbukti mencerminkan
status audio. Preview rollback tetap mengembalikan snapshot data RAM secara
byte-exact lalu mengirim perintah1. Pesan sukses/recovery kini membedakan
verifikasi data, ACK perintah, dan konfirmasi audio yang tetap memerlukan pedal.
Istilah status/gate di catatan tahap sebelumnya bukan spesifikasi register
hardware yang terkonfirmasi; penjelasan terbaru ini menggantikannya.

90 pengujian unik lulus. Dua regresi baru mensimulasikan ACK aktivasi diterima
lalu kontrol terbaca0: data IR tetap cocok dan preview tidak di-rollback; Distance
hanya memperbarui float lalu mengirim1, tidak menimpa koefisien atau menolak
operasi karena kontrol terbaca berbeda. Perilaku auto-clear pada simulator
adalah skenario pengujian, bukan klaim mekanisme firmware fisik.

## Hapus sisa pembatasan kontrol pada preflight

Log berikutnya dari pengguna: "Status IR di RAM tidak dikenali; preview tidak
ditulis [selesai]". Penyebabnya pemeriksaan gate not in (00,01) yang masih
tersisa di preflight PreviewJob dan DistanceJob setelah koreksi perbandingan
akhir. Pemeriksaan awal itu merupakan asumsi yang sama dan seharusnya ikut
dihapus pada koreksi sebelumnya. Nilai aktual tetap tidak diketahui dari
kutipan EVENT, selain bahwa kode lama membacanya di luar 0/1.

Kedua pembatasan enum sekarang dihapus. Observasi satu byte masih diperoleh
melalui parser paket ketat (opcode/region/alamat/panjang/checksum pembungkus
harus cocok), namun nilai 0–255 semuanya sah sebagai observasi. Nilainya tidak
menentukan sukses upload, tidak disalin sebagai perintah, dan tidak menonaktifkan
verifikasi 2052 byte data IR atau ACK perintah 0/1 yang mengikuti editor asli.

92 uji unik lulus. Satu uji memeriksa seluruh 256 observasi pada kedua job:
preflight menerima masing-masing byte dan perintah tetap hanya 00 lalu01.
Regresi GUI tambahan memodelkan kontrol FF sebelum dan sesudah upload: data
preview tetap diverifikasi dan tidak memicu rollback. Regresi lama yang
mengharuskan Distance menolak FF diganti sesuai bukti/semantik terbaru. Pencarian
kode memastikan pesan penolakan enum dan perbandingan nilai kontrol tersebut
tidak tersisa pada jalur aktif. Konfirmasi audio tetap belum diterima.

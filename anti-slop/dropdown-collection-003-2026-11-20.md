# Serah terima dropdown dan kartu Koleksi

Permintaan diselesaikan tanpa mengubah warna/tipografi, data atau handler perangkat.

- Dropdown: badan dan area panah kini menyatu, tanpa kotak native terpisah. Area panah 32 px, chevron 12 px terpusat. Tombol tampilan dan menu tombol memakai chevron dengan posisi yang sama; teks mendapat ruang kanan khusus. Disabled tetap memakai ikon lock. SVG fungsional dihasilkan melalui cache tema yang sudah dipakai ikon check/lock.
- Koleksi: kartu menjadi default jika belum ada preferensi eksplisit. Tampilan Daftar dan preferensi manual tetap tersedia. Kolom adaptif minimal 240 px, tinggi 112 px; pada render 1440 px terisi 2 kolom dan pada 1920 px terisi 3 kolom. Kartu membungkus ke baris berikutnya, dengan lebar terbagi rata.
- Scrollbar daftar mendapat gutter tetap untuk mencegah jumlah kolom berubah ketika scrollbar muncul; handle tidak digambar bila seluruh item sudah muat.
- Nama/metadata, pilihan tunggal/jamak, filter/sort, menu item, impor/ekspor, capture, staging dan pengiriman tetap. Tidak mengubah MIDI, audio, meter +60, format preset/bank/IR atau konfirmasi.

File: `cubebaby_mod/theme_styles.py`, `theme_ui.py`, `studio_ui.py`, `collection_view.py`, `studio_components.py`; tes baru `tests/test_collection_layout_ui.py`; penyesuaian awal mode pada `tests/test_rendering_performance.py`. Audit sebelum edit ada di `anti-slop/audit-003-2026-11-20.md`. Render `analysis/theme-screenshots/*.png` diperbarui.

Pemeriksaan akhir (backend simulasi/offscreen):

- PASS R-03/R-35: pengisian 2/3 kolom dan wrapping diuji lewat rect item, resize kembali, tidak ada scroll horizontal; empat halaman dan tab 1000×680 online/offline tetap tanpa scroll halaman.
- PASS R-26/C-2/C-4: multi-select bertahan saat resize/toggle, pencarian/aktivasi keyboard tetap; teks menu dan dropdown serta handler amp dilindungi regresi.
- PASS R-25/R-34: ikon mengikuti token tema, posisi chevron tengah diperiksa pada pixel render gelap/terang; 28 pasangan kontras tetap lulus.
- PASS R-23/R-31/R-37/C-1: hanya memperbaiki affordance panah dan memanfaatkan ruang panel sesuai permintaan; tidak membuat ilustrasi, navigasi atau dekorasi baru. Identitas dan arah UI tetap.
- Tidak ada akses pedal/audio fisik. Tidak mengklaim uji perangkat atau audit aksesibilitas penuh. Git tidak dikenali, sehingga tidak membuat commit.

Checklist pengguna:

- [ ] Cek panah dan teks dropdown aktif/nonaktif pada tema gelap/terang, termasuk tombol tampilan dan menu koneksi.
- [ ] Resize Koleksi, pilih beberapa item, filter/sort dan ganti Kartu/Daftar; cek tooltip nama panjang.
- [ ] Cek aksi Koleksi dan target pengiriman pada slot uji pedal fisik.

Hasil tes akhir: 193 tes lulus, seluruh suite dibagi empat batch tanpa duplikasi (43 + 45 + 51 + 54). Log di `analysis/cards-tests-batch0.log` sampai `cards-tests-batch3.log`. Dua regresi layout/panah baru serta 8 regresi rendering juga lulus tersendiri. Dua batch awal yang lebih panjang dihentikan SIGTERM oleh lingkungan, tanpa assertion gagal; empat batch terakhir menguji seluruh kode akhir.

`python -m compileall -q cubebaby_mod tests tools` dan 28 pemeriksaan kontras lulus. Tidak ada konfigurasi lint/build terpisah. Smoke launch `python -m cubebaby_mod` offscreen bertahan sampai timeout 4 detik (exit 124), tanpa traceback. Lingkungan tetap tidak menyediakan `/dev/snd/seq` untuk uji MIDI fisik.

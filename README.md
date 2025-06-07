# 📘 Aplikasi Absensi Siswa (C++ CLI)

Aplikasi ini adalah sistem absensi sederhana berbasis terminal (Command Line Interface) yang ditujukan untuk mencatat kehadiran siswa setiap hari, dengan pembagian peran antara **Admin** dan **Guru Kelas**. Aplikasi ini dibuat menggunakan bahasa **C++** dengan pendekatan **Object-Oriented Programming (OOP)**.

---

## 📂 Struktur Proyek

├── main.cpp
├── Student.h
├── Student.cpp
├── StudentDatabase.h
├── StudentDatabase.cpp
├── AbsensiController.h
├── AbsensiController.cpp
├── siswa.txt # Database siswa
├── absensi.txt # Data absensi harian

yaml
Copy
Edit

---

## 🛠️ Cara Compile dan Jalankan

### 💻 Compile

Buka terminal/CMD di folder proyek dan jalankan:

```bash
g++ -std=c++11 main.cpp Student.cpp StudentDatabase.cpp AbsensiController.cpp -o absensi
▶️ Jalankan Program
Di Windows (CMD):

cmd
Copy
Edit
absensi
Di Linux/macOS:

bash
Copy
Edit
./absensi
👥 Peran Pengguna
1. Admin
Menambahkan siswa baru

Menghapus siswa

Melihat daftar semua siswa

2. Guru
Input absensi per hari berdasarkan kelas

Melihat rekap absensi satu siswa

Menampilkan semua siswa berdasarkan kelas

Menampilkan rekap absensi semua siswa per kelas

📄 Format File
siswa.txt
nginx
Copy
Edit
NIS NAMA KELAS
Contoh:

yaml
Copy
Edit
1001 Aulia XIIIPA
1002 Budi XIIPS
absensi.txt
nginx
Copy
Edit
TANGGAL NIS STATUS
Contoh:

yaml
Copy
Edit
2025-06-06 1001 H
2025-06-06 1002 A
Kode status:

H = Hadir

I = Izin

S = Sakit

A = Alpha (tanpa keterangan)

💡 Fitur Utama
✅ Absensi harian per kelas

✅ Rekap absensi per siswa

✅ Rekap absensi semua siswa per kelas

✅ CRUD data siswa (oleh admin)

✅ File output otomatis (siswa.txt, absensi.txt)

✅ Modular dan terstruktur dengan class OOP

⚙️ Ketergantungan
Kompiler C++ seperti g++ (MinGW, GCC, Clang)

Dukungan -std=c++11 atau lebih baru

👨‍💻 Dibuat Oleh
Untuk memenuhi tugas proyek Mata Kuliah Pemrograman Dasar
Disusun oleh: Satama Safika
NIM: 22/492880/TK/53955
Tahun Ajaran: 2024/2025

yaml
Copy
Edit

---

### ✅ Sekarang tinggal:
1. Buka VS Code atau editor favorit kamu.
2. Buat file baru: `README.md`
3. Tempelkan seluruh isi di atas.
4. Simpan — dan selesai! 🎉

Kalau kamu ingin saya bantu juga buat versi laporan atau dokumentasi 

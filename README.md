# 📘 Aplikasi Absensi Siswa (C++ CLI)

Aplikasi ini adalah sistem absensi sederhana berbasis terminal (Command Line Interface) yang ditujukan untuk mencatat kehadiran siswa setiap hari, dengan pembagian peran antara **Admin** dan **Guru Kelas**. Aplikasi ini dibuat menggunakan bahasa **C++** dengan pendekatan **Object-Oriented Programming (OOP)**.

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

## 🛠️ Cara Compile dan Jalankan

### 💻 Compile
Buka terminal/CMD dan jalankan:

```bash
g++ -std=c++11 main.cpp Student.cpp StudentDatabase.cpp AbsensiController.cpp -o absensi

### ▶️ Jalankan Program
Di Windows (CMD):
absensi

Di Linux/macOS:
./absensi

## 👥 Peran Pengguna
**1. Admin**
- Menambahkan siswa baru
- Menghapus siswa
- Melihat daftar semua siswa

**2. Guru**
- Input absensi per hari berdasarkan kela
- Melihat rekap absensi satu siswa
- Menampilkan semua siswa berdasarkan kelas
- Menampilkan rekap absensi semua siswa per kelas

## 💡 Fitur Utama
- Absensi harian per kelas
- Rekap absensi per siswa\
- Rekap absensi semua siswa per kelas
- CRUD data siswa (oleh admin)
- File output otomatis (siswa.txt, absensi.txt)
- Modular dan terstruktur dengan class OOP

## 👨‍💻 Dibuat Oleh
Untuk memenuhi tugas proyek Pemrograman Dasar
Disusun oleh: Satama Safika
NIM: 22/492880/TK/53955
Tahun Ajaran: 2024/2025

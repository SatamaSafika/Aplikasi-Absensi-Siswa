# 📘 Aplikasi Absensi Siswa (C++ CLI)

Aplikasi ini adalah sistem absensi sederhana berbasis terminal (Command Line Interface) yang ditujukan untuk mencatat kehadiran siswa setiap hari. Aplikasi memiliki dua peran utama: **Admin** dan **Guru Kelas**, dan ditulis menggunakan bahasa **C++** dengan pendekatan **Object-Oriented Programming (OOP)**.

## 🛠️ Cara Compile dan Jalankan

### 💻 Compile

Buka terminal/CMD di folder proyek dan jalankan:  
```bash
g++ -std=c++11 main.cpp Student.cpp StudentDatabase.cpp AbsensiController.cpp -o absensi
```

### ▶️ Jalankan Program
**Di Windows (CMD):**  
```bash
absensi
```

**Di Linux/macOS:**  
```bash
./absensi
```

## 👥 Peran Pengguna
**1. Admin**  
- Menambahkan siswa baru  
- Menghapus siswa  
- Melihat daftar semua siswa  

**2. Guru**  
- Menginput absensi harian berdasarkan kelas  
- Melihat rekap absensi satu siswa  
- Menampilkan daftar siswa per kelas  
- Menampilkan rekap semua siswa per kelas  

## 💡 Fitur Utama  
✅ Input absensi harian  
✅ Rekap absensi per siswa dan per kelas  
✅ Tambah & hapus data siswa  
✅ File absensi (absensi.txt) dan siswa (siswa.txt) otomatis tersimpan  
✅ Program modular & berbasis class OOP  

## 👨‍💻 Dibuat Oleh  
Untuk memenuhi tugas proyek Mata Kuliah Pemrograman Dasar  
Disusun oleh: Satama Safika   
NIM: 22/492880/TK/53955  
Tahun Ajaran: 2024/2025  

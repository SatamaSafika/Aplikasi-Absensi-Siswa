#include "AbsensiController.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

void AbsensiController::commandLoop() {
    StudentDatabase db("siswa.txt");
    char choice;

    do {
        std::cout << "\n== Menu Utama Absensi Siswa ==\n";
        std::cout << "1. Admin\n";
        std::cout << "2. Guru\n";
        std::cout << "Tekan tombol lain untuk keluar.\n";
        std::cout << "Pilihan: ";
        std::cin >> choice;

        switch (choice) {
            case '1': adminMenu(db); break;
            case '2': guruMenu(db); break;
            default: std::cout << "Keluar dari aplikasi.\n"; break;
        }
    } while (choice == '1' || choice == '2');
}

void AbsensiController::adminMenu(StudentDatabase& db) {
    char choice;
    do {
        std::cout << "\n== Menu Admin ==\n";
        std::cout << "1. Tambah Siswa\n";
        std::cout << "2. Hapus Siswa\n";
        std::cout << "3. Lihat Semua Siswa\n";
        std::cout << "Tekan tombol lain untuk kembali.\n";
        std::cout << "Pilihan: ";
        std::cin >> choice;

        switch (choice) {
            case '1': tambahSiswa(db); break;
            case '2': hapusSiswa(db); break;
            case '3': listSiswa(db); break;
            default: std::cout << "Kembali ke menu utama.\n"; break;
        }
    } while (choice == '1' || choice == '2' || choice == '3');
}

void AbsensiController::guruMenu(StudentDatabase& db) {
    char choice;
    do {
        std::cout << "\n== Menu Guru ==\n";
        std::cout << "1. Input Absensi Hari Ini\n";
        std::cout << "2. Lihat Rekap Absensi Siswa\n";
        std::cout << "3. Lihat Daftar Siswa per Kelas\n";
        std::cout << "4. Rekap Semua Siswa per Kelas\n";
        std::cout << "Tekan tombol lain untuk kembali.\n";
        std::cout << "Pilihan: ";
        std::cin >> choice;

        switch (choice) {
            case '1': inputAbsensi(db); break;
            case '2': lihatRekap(db); break;
            case '3': listSiswa(db); break;
            case '4': rekapSemuaSiswaPerKelas(db); break;
            default: std::cout << "Kembali ke menu utama.\n"; break;
        }
    } while (choice == '1' || choice == '2' || choice == '3' || choice == '4');
}

void AbsensiController::tambahSiswa(StudentDatabase& db) {
    std::string nis, nama, kelas;
    std::cout << "Masukkan NIS: "; std::cin >> nis;
    std::cout << "Masukkan Nama: "; std::cin >> nama;
    std::cout << "Masukkan Kelas: "; std::cin >> kelas;

    Student newStudent(nis, nama, kelas);
    db.addStudent(newStudent);
}

void AbsensiController::hapusSiswa(StudentDatabase& db) {
    std::string nis;
    std::cout << "Masukkan NIS siswa yang ingin dihapus: ";
    std::cin >> nis;
    db.deleteStudent(nis);
}

void AbsensiController::listSiswa(const StudentDatabase& db) {
    db.listAllStudents();
}

void AbsensiController::inputAbsensi(const StudentDatabase& db) {
    std::string tanggal, status;
    std::cout << "Masukkan tanggal absensi (YYYY-MM-DD): ";
    std::cin >> tanggal;

    std::ofstream file("absensi.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Gagal membuka file absensi.txt\n";
        return;
    }

    std::string kelas;
    std::cout << "Masukkan nama kelas (contoh: XIIIPA): ";
    std::cin >> kelas;

    std::cout << "\nMasukkan status H=Hadir, I=Izin, S=Sakit, A=Alpha\n";

    for (const Student& s : db.getAllStudents()) {
        if (s.getKelas() == kelas) {
            std::cout << s.getNama() << " (" << s.getNIS() << "): ";
            std::cin >> status;
            file << tanggal << " " << s.getNIS() << " " << status << "\n";
        }
    }

    file.close();
    std::cout << "Absensi berhasil dicatat.\n";
}

void AbsensiController::lihatRekap(const StudentDatabase& db) {
    std::string nis;
    std::cout << "Masukkan NIS siswa: ";
    std::cin >> nis;

    std::ifstream file("absensi.txt");
    if (!file.is_open()) {
        std::cerr << "Gagal membuka file absensi.txt\n";
        return;
    }

    int h = 0, i = 0, s = 0, a = 0;
    std::string tanggal, nisBaca, status;
    while (file >> tanggal >> nisBaca >> status) {
        if (nisBaca == nis) {
            if (status == "H") h++;
            else if (status == "I") i++;
            else if (status == "S") s++;
            else if (status == "A") a++;
        }
    }

    file.close();

    const Student* student = db.findStudentByNIS(nis);
    if (student) {
        std::cout << "\nRekap Absensi untuk " << student->getNama() << " (" << nis << ")\n";
        std::cout << "Hadir : " << h << "\n";
        std::cout << "Izin  : " << i << "\n";
        std::cout << "Sakit : " << s << "\n";
        std::cout << "Alpha : " << a << "\n";
    } else {
        std::cout << "Data siswa tidak ditemukan.\n";
    }
}

void AbsensiController::rekapSemuaSiswaPerKelas(const StudentDatabase& db) {
    std::string kelas;
    std::cout << "Masukkan nama kelas (contoh: XIIIPA): ";
    std::cin >> kelas;

    std::ifstream file("absensi.txt");
    if (!file.is_open()) {
        std::cerr << "Gagal membuka file absensi.txt\n";
        return;
    }

    // Map NIS -> {H, I, S, A}
    std::map<std::string, std::map<char, int>> rekap;

    std::string tanggal, nis, status;
    while (file >> tanggal >> nis >> status) {
        rekap[nis][status[0]]++;
    }
    file.close();

    std::cout << "\n== Rekap Absensi Siswa Kelas " << kelas << " ==\n";
    std::cout << "NIS\tNama\t\tH\tI\tS\tA\n";
    std::cout << "-----------------------------------------------------\n";

    for (const Student& s : db.getAllStudents()) {
        if (s.getKelas() == kelas) {
            std::string nis = s.getNIS();
            std::cout << nis << "\t" << s.getNama() << "\t\t"
                      << rekap[nis]['H'] << "\t"
                      << rekap[nis]['I'] << "\t"
                      << rekap[nis]['S'] << "\t"
                      << rekap[nis]['A'] << "\n";
        }
    }
}

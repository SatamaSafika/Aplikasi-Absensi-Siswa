#include "StudentDatabase.h"
#include "Student.h"  // ← WAJIB ADA agar Student dikenali
#include <fstream>
#include <sstream>
#include <iostream>

StudentDatabase::StudentDatabase(const std::string& fileName) : fileName(fileName) {
    loadDatabase();
}

void StudentDatabase::loadDatabase() {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Database siswa tidak ditemukan. Mulai dari kosong." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nis, nama, kelas;
        if (iss >> nis >> nama >> kelas) {
            students.emplace_back(nis, nama, kelas);
        }
    }

    file.close();
}

void StudentDatabase::saveDatabase() {
    std::ofstream file(fileName, std::ios::trunc);
    for (const auto& student : students) {
        file << student.getNIS() << " "
             << student.getNama() << " "
             << student.getKelas() << std::endl;
    }
    file.close();
}

void StudentDatabase::addStudent(const Student& student) {
    students.push_back(student);
    saveDatabase();
    std::cout << "Siswa berhasil ditambahkan." << std::endl;
}

void StudentDatabase::listStudentsByClass(const std::string& kelas) const {
    bool found = false;
    for (const auto& student : students) {
        if (student.getKelas() == kelas) {
            std::cout << student.toString() << std::endl;
            found = true;
        }
    }
    if (!found) std::cout << "Tidak ada siswa di kelas " << kelas << "." << std::endl;
}

void StudentDatabase::listAllStudents() const {
    if (students.empty()) {
        std::cout << "Belum ada siswa dalam database." << std::endl;
        return;
    }
    for (const auto& student : students) {
        std::cout << student.toString() << std::endl;
    }
}

const Student* StudentDatabase::findStudentByNIS(const std::string& nis) const {
    for (const auto& student : students) {
        if (student.getNIS() == nis) {
            return &student;
        }
    }
    return nullptr;
}

void StudentDatabase::deleteStudent(const std::string& nis) {
    auto it = students.begin();
    while (it != students.end()) {
        if (it->getNIS() == nis) {
            it = students.erase(it);
            saveDatabase();
            std::cout << "Siswa dengan NIS " << nis << " berhasil dihapus." << std::endl;
            return;
        } else {
            ++it;
        }
    }
    std::cout << "Siswa tidak ditemukan." << std::endl;
    
}

std::vector<Student> StudentDatabase::getAllStudents() const {
    return students;
}


#include "Student.h"
#include <sstream>

Student::Student(std::string nis, std::string nama, std::string kelas)
    : nis(nis), nama(nama), kelas(kelas) {}

std::string Student::getNIS() const { return nis; }
std::string Student::getNama() const { return nama; }
std::string Student::getKelas() const { return kelas; }

std::string Student::toString() const {
    std::ostringstream oss;
    oss << "NIS: " << nis << ", Nama: " << nama << ", Kelas: " << kelas;
    return oss.str();
}

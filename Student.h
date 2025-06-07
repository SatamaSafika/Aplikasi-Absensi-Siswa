#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string nis;
    std::string nama;
    std::string kelas;

public:
    Student(std::string nis, std::string nama, std::string kelas);

    std::string getNIS() const;
    std::string getNama() const;
    std::string getKelas() const;
    std::string toString() const;
};

#endif // STUDENT_H

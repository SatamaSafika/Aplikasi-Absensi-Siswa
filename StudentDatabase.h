#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H

#include <vector>
#include <string>
#include "Student.h"  // ← TAMBAHKAN INI

class StudentDatabase {
private:
    std::vector<Student> students;
    std::string fileName;

    void loadDatabase();
    void saveDatabase();

public:
    StudentDatabase(const std::string& fileName);

    void addStudent(const Student& student);
    const Student* findStudentByNIS(const std::string& nis) const;
    void deleteStudent(const std::string& nis);
    void listStudentsByClass(const std::string& kelas) const;
    void listAllStudents() const;
    std::vector<Student> getAllStudents() const;
};

#endif // STUDENTDATABASE_H

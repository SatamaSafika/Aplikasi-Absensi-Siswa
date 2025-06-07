#ifndef ABSENSICONTROLLER_H
#define ABSENSICONTROLLER_H

#include "StudentDatabase.h"

class AbsensiController {
public:
    void commandLoop();
    void adminMenu(StudentDatabase& db);
    void guruMenu(StudentDatabase& db);

private:
    void inputAbsensi(const StudentDatabase& db);
    void lihatRekap(const StudentDatabase& db);
    void tambahSiswa(StudentDatabase& db);
    void hapusSiswa(StudentDatabase& db);
    void listSiswa(const StudentDatabase& db);
    void rekapSemuaSiswaPerKelas(const StudentDatabase& db); // ← Tambahkan ini

};

#endif // ABSENSICONTROLLER_H

#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
public:
    string nama;
    int umur;
    string jurusan;
    string fakultas;

    virtual string status() = 0;
};

class MahasiswaAktif : public Mahasiswa {
public:
    MahasiswaAktif(string nama, int umur, string jurusan, string fakultas) {
        this->nama = nama;
        this->umur = umur;
        this->jurusan = jurusan;
        this->fakultas = fakultas;
    }

    string status() {
        return "Mahasiswa Aktif";
    }
};

class Alumni : public Mahasiswa {
public:
    Alumni(string nama, int umur, string jurusan, string fakultas) {
        this->nama = nama;
        this->umur = umur;
        this->jurusan = jurusan;
        this->fakultas = fakultas;
    }

    string status() {
        return "Alumni";
    }
};

int main() {
    // Membuat objek mahasiswa aktif
    MahasiswaAktif mahasiswa_aktif("John Doe", 20, "Informatika", "Teknik");

    // Membuat objek alumni
    Alumni alumni("Jane Smith", 25, "Akuntansi", "Ekonomi");

    // Mengakses atribut dan metode pada objek mahasiswa aktif
    cout << "Nama: " << mahasiswa_aktif.nama << endl;
    cout << "Umur: " << mahasiswa_aktif.umur << endl;
    cout << "Jurusan: " << mahasiswa_aktif.jurusan << endl;
    cout << "Fakultas: " << mahasiswa_aktif.fakultas << endl;
    cout << "Status: " << mahasiswa_aktif.status() << endl;

    cout << endl;

    // Mengakses atribut dan metode pada objek alumni
    cout << "Nama: " << alumni.nama << endl;
    cout << "Umur: " << alumni.umur << endl;
    cout << "Jurusan: " << alumni.jurusan << endl;
    cout << "Fakultas: " << alumni.fakultas << endl;
    cout << "Status: " << alumni.status() << endl;

    return 0;
}
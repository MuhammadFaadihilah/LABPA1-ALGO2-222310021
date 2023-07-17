#include <iostream>
#include <string>

class Perpustakaan {
private:
    std::string bukuYangDipinjam;

public:
    void setBukuYangDipinjam(const std::string& buku) {
        bukuYangDipinjam = buku;
    }

    std::string getBukuYangDipinjam() const {
        return bukuYangDipinjam;
    }
};

class Pelajar {
private:
    std::string nama;

public:
    void pinjamBuku(Perpustakaan& perpustakaan, const std::string& buku) {
        perpustakaan.setBukuYangDipinjam(buku);
    }

    void kembalikanBuku(Perpustakaan& perpustakaan) {
        std::string bukuDikembalikan = perpustakaan.getBukuYangDipinjam();
        perpustakaan.setBukuYangDipinjam("");
        std::cout << "Pelajar " << nama << " mengembalikan buku: " << bukuDikembalikan << std::endl;
    }

    void setNama(const std::string& namaPelajar) {
        nama = namaPelajar;
    }

    std::string getNama() const {
        return nama;
    }
};

int main() {
    Perpustakaan perpustakaan;
    Pelajar pelajar;

    pelajar.setNama("John Doe");

    pelajar.pinjamBuku(perpustakaan, "Harry Potter");
    std::cout << "Pelajar " << pelajar.getNama() << " meminjam buku: " << perpustakaan.getBukuYangDipinjam() << std::endl;

    pelajar.kembalikanBuku(perpustakaan);

    return 0;
}
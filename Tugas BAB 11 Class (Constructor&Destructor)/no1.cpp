#include <iostream>
using namespace std;

class Contoh {
private:
    int nilai;
public:
    Contoh(int n) {
        nilai = n;
    }
    int getNum() {
        return nilai;
    }
};

int main() {
    Contoh obj(10);
    cout << "Nilai yang diinput: " << obj.getNum() << endl;
    return 0;
}

//Penjelasan program:
//1. Program di atas mendefinisikan sebuah kelas bernama `Contoh`.
//2. Di dalam kelas `Contoh`, terdapat sebuah variabel anggota private bernama `nilai`.
//3. Terdapat sebuah constructor dengan parameter `int` yang digunakan untuk menginisialisasi nilai variabel anggota `nilai`.
//4. Terdapat juga sebuah metode publik `getNum()` yang mengembalikan nilai variabel anggota `nilai`.
//5. Di dalam fungsi `main()`, objek `obj` dari kelas `Contoh` dibuat dengan memberikan argumen `10` ke constructor.
//6. Kemudian, nilai yang disimpan dalam objek `obj` dicetak menggunakan `cout`.

//Program di atas merupakan penerapan dari constructor. Constructor `Contoh(int n)` digunakan untuk menginisialisasi nilai variabel anggota `nilai` saat objek dibuat. Pada saat objek `obj` dibuat di dalam fungsi `main()`, constructor `Contoh(int n)` akan dipanggil dan menginisialisasi nilai dengan 10. Kemudian, nilai yang disimpan dalam objek `obj` dicetak menggunakan `cout`.
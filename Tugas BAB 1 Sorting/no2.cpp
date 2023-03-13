#include <iostream>
#include <string>
using namespace std;

int main() {
    // input data buku
    int m;
    cout << "Masukkan jumlah buku : ";
    cin >> m;
    string buku[m];
    for (int i=0; i<m; i++) {
      cout << "Masukan judul buku ke-" << i+1 << "; ";
      cin >> buku[i];
    }

    // insertion sort
    for (int i=1; i<m; i++) {
        string key = buku[i];
        int j=i-1;
        while(j>=0 &&key< buku[j]){
            buku[j+1] = buku[j];
            j--;
        }
        buku[j+1] = key;
    }

    // output data buku yang sudah diurutkan
    cout << "\ndata buku yang sudah diurutkan:\n";
    for (int i=0; i<m; i++) {
        cout << i+1 << ". " << buku[i] << endl;
    }
    return 0;
}
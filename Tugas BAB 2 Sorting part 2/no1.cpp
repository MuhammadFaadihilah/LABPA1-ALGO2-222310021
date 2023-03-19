#include <iostream>
using namespace std;

void swap(int arr[], int pos1, int pos2) { //membuat fungsi swap yang didalamnya terdapat tipe data integer dan beberapa variabel
  
  int temp; //mendeklarasikan integer temp
  
  temp = arr[pos1]; //menginialisasikan temp yang bernilai sama dengan array pos2
  
  arr[pos1] = arr[pos2]; // menginialisasikan nilai array pos1 sama dengan array pos2
  
  arr[pos2] = temp; //array pos2 bernilai sama dengan variabel temp
  
}
int partition(int arr[], int low, int high, int pivot) { //tipe data integer untuk variabel partition, yang di dalam nya ada tipe data untuk membuat array
  
  int i = low; //integer i bernilai low
  
  int j = low; //inetger j bernilai low
  
  while (i <= high) { //looping untuk nilai tertinggi
    
    if (arr[i] > pivot) {
      i++;
    } else {
      swap(arr, i, j); //memanggil fungsi swap
      i++;
      j++;
    }
  }
  
  return j - 1; //bernilai kembali jika sudah selesai diinisialisasikan
}

void quickSort(int arr[], int low, int high) { //membuat fungsi quicksort yang didalam nya ada tipe data integer dan variabel array, low dan high untuk nilai nya
  
  if (low < high) { //looping untuk mengurutkan nilai dari kecil ke terbesar
    
    int pivot = arr[high]; //tipe data pivot bernilai sama dengan nilai array tertinggi
    
    int pos = partition(arr, low, high, pivot); //integer pos bernilai variabel partition yang di dalamnya ada array, low, high dan pivot
    
    quickSort(arr, low, pos - 1); //memanggil fungsi quicksort yang didalamnya ada array,low,pos - 1
    
    quickSort(arr, pos + 1, high);// memanggil fungsi quicksort yang di dalamnya ada array, pos+1, dan high
  }
}
int main() {
  
  int n; //membuat tipe data untuk menentukan panjang array
  cout << "Tentukan panjang array : "; //output 
  cin >> n; //memanggil variabel n
  int arr[n]; //array bernilai n akan menampilkan urutan array
  
  for (int i = 0; i < n; i++) { //looping integer i bernilai 0 lalu i lebih kecil daripada n ,dan increment untuk menambah 1
    cin >> arr[i]; //input array yang bernilai i
  }
  
  quickSort(arr, 0, n - 1); //memanggil fungsi quicksort yang didalamnya terdapat array,0, nilai n dikurang 1
  cout << "Berikut adalah array yang telah di sortir: "; //output 
  
  for (int i = 0; i < n; i++) { //looping untuk menampilkan urutan array
    
    cout << arr[i] << " "; //output
  }
}
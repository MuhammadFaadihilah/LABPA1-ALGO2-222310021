#include <iostream>
#include <algorithm>
using namespace std;

const int maxArray = 50;
int number[maxArray];

int binarySearch (int e, int f, int i){
  if (i >= 1) {
    int tengah = 1 + (i - 1)/2;
    if (number[tengah] == e)
      return tengah;
    if (number[tengah] > e)
      return binarySearch (e,f,tengah - 1);
      return binarySearch (e,tengah + 1, i);
    }
  return -1;
}

int main(){
  int f;

    cout <<"Masukkan banyak data yang akan dimasukkan pada array : ";
    cin >> f;


  for (int i=0 ; i<f ; i++){
    cout <<"data ke- "<< i+1 <<" : ";
    cin >> number[i];
  }
    sort (number, number + f);

  int z;
    cout <<"Masukkan data yang ingin dicari :";
    cin >> z;

  int result = binarySearch (z, 0 ,f -1);
  if (result == -1 )
    cout <<"Data tidak ditemukan." <<endl;
  else
    cout <<"Data ditemukan pada index ke "<<result<<endl;

  return 0;
}
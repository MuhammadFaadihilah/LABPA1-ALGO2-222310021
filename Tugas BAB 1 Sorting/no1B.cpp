#include <iostream>
using namespace std;

int main(){
	int f;
	cout<<"masukan banyak array:";
	cin>>f;
	int x[f];
	for(int i=0; i<f; i++){
		cout<<"masukan angka ke "<<i<<" :";
		cin>>x[i];
		cout<<endl;
	}
	for(int i=1; i<f; i++){
		int key = x[i];
		int j = i-1;
		while(j>=0 && x[j] < key){
			x[j+1] = x[j];
			j--;
		}
		x[j+1] = key;
		cout<<"proses sorting"<<endl;
		for(int m=0;m<f;m++){
		cout<<x[m]<<" ";
	    }
	    cout<<endl;
	}
	cout<<"hasil akhir"<<endl;
	for(int m=0;m<f;m++){
		cout<<x[m]<<" ";
	}
}
// insertion sort dimulai dari memilah data yang akan
// urutkan menjadi 2 bagian //
#include <iostream>
using namespace std;

int main() {
  int n, data[100];

  // Menginput jumlah data
  cout << "Masukkan jumlah data: ";
  cin >> n;

  // Menginput data
  for (int i = 0; i < n; i++) {
    cout << "Masukkan data ke-" << i + 1 << ": ";
    cin >> data[i];
  }

  // Menampilkan data array
  cout << "Data Array: ";
  for (int i = 0; i < n; i++) {
    cout << data[i] << " ";
  }
  cout << endl;

  // Menampilkan data genap dan ganjil
  cout << "Nomor Genap: ";
  for (int i = 0; i < n; i++) {
    if (data[i] % 2 == 0) {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  cout << "Nomor Ganjil: ";
  for (int i = 0; i < n; i++) {
    if (data[i] % 2 == 1) {
      cout << data[i] << " ";
    }
  }
  cout << endl;

  return 0;
}

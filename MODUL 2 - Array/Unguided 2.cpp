#include <iostream>
using namespace std;

int main() {
  int dimensi[3]; // Array untuk menyimpan dimensi

  // Minta pengguna memasukkan dimensi
  cout << "Masukkan jumlah elemen untuk setiap dimensi:\n";
  for (int i = 0; i < 3; ++i) 
  {
    cout << "Dimensi " << i + 1 << ": ";
    cin >> dimensi[i];
  }

  // Alokasikan memori secara dinamis untuk array 3 dimensi
  int*** arr = new int**[dimensi[0]];
  for (int i = 0; i < dimensi[0]; ++i) 
  {
    arr[i] = new int*[dimensi[1]];
    for (int j = 0; j < dimensi[1]; ++j) 
    {
      arr[i][j] = new int[dimensi[2]];
    }
  }

  // Masukkan elemen
  cout << "\nMasukkan elemen array:\n";
  for (int i = 0; i < dimensi[0]; ++i) 
  {
    for (int j = 0; j < dimensi[1]; ++j) 
    {
      for (int k = 0; k < dimensi[2]; ++k) 
      {
        cout << "Array[" << i << "][" << j << "][" << k << "] = ";
        cin >> arr[i][j][k];
      }
    }
  }

  // Tampilkan elemen array
  cout << "\nElemen array:\n";
  for (int i = 0; i < dimensi[0]; ++i) 
  {
    for (int j = 0; j < dimensi[1]; ++j) 
    {
      for (int k = 0; k < dimensi[2]; ++k) 
      {
        cout << arr[i][j][k] << " ";
      }
      cout << endl;
    }
  }

  // Bebaskan memori untuk array 3 dimensi (kebalikan dari urutan alokasi)
  for (int i = 0; i < dimensi[0]; ++i) 
  {
    for (int j = 0; j < dimensi[1]; ++j) 
    {
      delete[] arr[i][j];
    }
    delete[] arr[i];
  }
  delete[] arr;
  return 0;
}

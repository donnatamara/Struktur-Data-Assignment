#include <iostream>
using namespace std;

int main() 
{
  // Deklarasi variabel untuk menyimpan dimensi array
  int x, y, z;

  // Meminta pengguna untuk memasukkan dimensi array
  cout << "Masukkan jumlah baris: ";
  cin >> x;
  cout << "Masukkan jumlah kolom: ";
  cin >> y;
  cout << "Masukkan jumlah layer: ";
  cin >> z;

  // Deklarasi array dengan dimensi yang diinputkan pengguna
  int arr[x][y][z];

  // Input elemen array dengan menggunakan fungsi perulangan
  for (int a = 0; a < x; a++) 
  {
    for (int b = 0; b < y; b++) 
    {
      for (int c = 0; c < z; c++) 
      {
        cout << "Input array[" << a << "][" << b << "][" << c << "] = ";
        cin >> arr[a][b][c];
      }
    }
    cout << endl;
  }

  // Output elemen array
  for (int a = 0; a < x; a++)
    {
        for (int b = 0; b < y; b++)
        {
            for (int c = 0; c < z; c++)
            {
                cout << "Data Array[" << a << "][" << b << "][" << c <<"] = " << arr[a][b][c] << endl;
            }
        }
    }
    cout << endl;

/// Output array
     for (int a = 0; a < x; a++)
    {
        for (int b = 0; b < y; b++)
        {
            for(int c = 0; c < z; c++)
            {
                cout << arr[a][b][c] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
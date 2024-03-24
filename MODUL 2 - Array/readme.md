# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Donna Nur Tamara</p>

## Dasar Teori

Array merupakan struktur data yang paling dasar dalam sebuah bahasa pemrograman. Array adalah. Dalam bahasa pemrograman C++, ukuran dan tipe array tidak dapat diubah setelah deklarasinya[1]. Dibawah ini adalah beberapa jenis array yang umum diketahui:

### 1. Array Satu Dimensi
Array satu dimensi adalah tipe variabel yang berisi kumpulan data dengan tipe data yang sama dan disusun dalam satu baris atau satu dimensi. Elemen dalam array memiliki sebuah indeks yang berguna untuk mengakses elemen tersebut, indeksnya dimulai dari 0 dan berakhir pada jumlah semua elemen dikurangi satu.

### 2. Array Dua Dimensi
Array dua dimensi adalah tipe variabel yang berisi kumpulan array satu dimensi dengan tipe data sama dan tersusun dalam bentuk tabel atau matriks, dimana baris dan kolom mewakili dimensi data. Setiap elemen dalam array ini diakses dengan dua indeks, yaitu indeks baris dan indeks kolom. Indeks baris menentukan posisi elemen di baris tertentu, dan indeks kolom menentukan posisi elemen di kolom tertentu. 

### 3. Array Multidimensi
Array multidimensi adalah penggabungan antara array satu dimensi dan dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini dapat memiliki indeks lebih dari dua dimensi dan dapat divisualisasikan sebagai struktur berlapis yang mana setiap dimensi mewakili satu lapisan.

### 4. Array Empat Dimensi
Array empat dimensi adalah tipe variabel yang berisi array dengan empat dimensi saja dan memiliki tipe data yang sama, di mana setiap dimensi mewakili satu tingkatan struktur data serta dapat divisualisaikan sebagai struktur berlapis, di mana setiap dimensi mewakili satu lapisan.

### 5. Array Lima Dimensi
Array lima dimensi adalah tipe variabel yang berisi array dengan lima dimensi dan memiliki tipe data yang sama, setiap dimensi mewakili satu tingkatan struktur data, dapat divisualisasikan sebagai struktur berlapis dengan lima tingkatan. Array ini memiliki kompleksitas yang sangat tinggi dan membutuhkan memori yang besar juga. Akses dalam array dengan dimensi tinggi seperti pada array ini dapat memakan waktu dan sumber daya.

## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
//PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array 
    int arr[2] [3] [3] ;
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z <<"] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for(int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
```
Kode diatas merupakan kode program untuk menginput serta menampilkan elemen-elemen dalam sebuah array 3 dimensi dengan ukuran 2x3x3 (memiliki 2 blok, setiap blok berisi 3 baris dan 3 kolom).

Menggunakan nested loop (loop bersarang) untuk menginputkan dan menampilkan elemen-elemen array dengan mengakses indeks array sesuai dimensinya. 

Untuk menaampilkan array dalam format tabel dapat menggunakan nested loop juga, di mana setiap elemen dipisahkan dengan spasi. Kemudian mengembalikan nilai 0 sebagai penanda bahwa program telah sukses berjalan.


### 2. Program Mencari Nilai Maksimal pada Array
```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Kode diatas merupakan kode program untuk mencari nilai maksimum beserta lokasi indeksnya pada sebuah array yang diinputkan oleh pengguna. 

Variabel `maks` diperlukan untuk menyimpan nilai maksimum, variabel `a` untuk panjang array, `i` sebagai penghitung, dan `lokasi` untuk menyimpan indeks nilai maksimum. Lalu pengguna diminta memasukkan panjang array melalui `cin`.

Kode diatas menggunakan fungsi loop untuk menginputkan setiap elemen array sesuai dengan indeksnya. Fungsi loop juga digunakan untuk membandingkan setiap elemen array dengan nilai maksimum saat ini saat, jika ditemukan elemen yang lebih besar dari nilai maksimum maka nilai maksimum diperbarui dan lokasi indeksnya disimpan.

Lalu hasilnya, program akan menampilkan nilai maksimum yang telah ditemukan dan lokasi indeksnya dalam array.

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
<img width="755" alt="Screenshot 2024-03-22 135832" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/5b814f82-0d1a-4cc2-a5b4-9c4dde439aa4">

```C++
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
```
#### Output:
<img width="187" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/4f0760f4-1f13-4c7d-b492-12c6b1f3645e">


Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/134fd3ba-fde5-4586-b3c0-720659a0c5b8">

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
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
```
#### Output:
<img width="130" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/40957724-cfa9-49a9-83b6-036326393fbd">

#### Full code Screenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/2c24a53f-b4e5-4542-835d-3a2dcf9350d0">




### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata–rata dari suatu array dengan input yang dimasukan oleh user!

```C++

```
### Output:
<img width="214" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/4df486cb-80a1-4670-b7d0-a86d4e92114e">

<img width="143" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/0141d4bf-ae7f-482d-8432-55b4cd6375ea">


### Full code Screenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/25491c83-b91c-4284-ae9e-a8e82a9b5804">

<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/96a0a926-abaa-4bed-985a-5965733c8fdc">



## Kesimpulan
Kesimpulannya, array adalah suatu struktur data yang sangat penting dalam bahasa pemrograman c++, digunakan untuk menyimpan dan memanipulasi data dengan cara yang efisien.

## Referensi
[1] “C++ Arrays (With examples).” https://www.programiz.com/cpp-programming/arrays [accesed 24 march 2024].

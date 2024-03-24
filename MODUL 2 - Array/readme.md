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
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Kesimpulannya, array adalah suatu struktur data yang sangat penting dalam bahasa pemrograman c++, digunakan untuk menyimpan dan memanipulasi data dengan cara yang efisien.

## Referensi
[1] “C++ Arrays (With examples).” https://www.programiz.com/cpp-programming/arrays [accesed 24 march 2024].
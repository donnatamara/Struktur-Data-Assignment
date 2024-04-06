# <h1 align="center">Laporan Praktikum Modul Searching</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori
Searching atau dapat disebut pencarian adalah suatu proses untuk mengumpulkan sejumlah informasi didalam pengingat computer dan kemudian mencari kembali informasi yang diperlukan secepat mungkin. Ada beberapa cara dalam pencarian sebuah data [1]. Beberapa jenis searching yang umum diketahui yaitu:
### Binary Search
Binary search merupakan sebuah teknik pencarian pada array/list dengan elemen terurut dengan menghapus bagian data pada setiap langkah, dengan cara menentukan nilai tengah (median) dari data, lalu melakukan perbandingan untuk menentukan apakah nilai yang dicari berada pada sebelum atau sesudahnya, lalu menentukan bagian lainnya dengan cara yang sama[2].

Biasanya algoritma ini sering digabungkan dengan algoritma sorting karena data yang akan digunakan harus sudah terurut terlebih dahulu. Langkah-langkah pengurutannya adalah:
1. Urutkan data dalam array secara terurut.
2. Tentukan nilai tengah dari array.
3. Bandingkan nilai tengah dengan nilai yang dicari.
4. Jika nilai tengah sama dengan nilai yang dicari, maka pencarian selesai.
5. Jika nilai tengah lebih besar dari nilai yang dicari, maka cari nilai di setengah kiri array.
6. Ulangi langkah 2-6 sampai nilai yang dicari ditemukan atau tidak ditemukan [2].

### Sequential Search
Sequential search atau dapat disebut linear search adalah teknik pencarian data dalam array dengan membaca satu demi satu dan diurutkan dari indeks pertama hingga indeks terakhir, maupun sebaliknya. Algoritma ini biasa digunakan untuk data berpola acak. 

Pencarian dimulai dari elemen pertama, kemudian periksa apakah cocok dengan angka yang sedang dicari, jika tidak maka periksa dengan elemen berikutnya. Jika bertemu dengan angka yang sedang dicari maka pencarian selesai [3].


## Guided
### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.  
```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
    
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/01189237-4ae9-4c2b-8e59-28f8f1514563)

kode diatas merupakan kode program yang melakukan pencarian data menggunakan sequential search dalam sebuah array. Dengan data pada variabel `n` adalah 10 yang merupakan jumlah elemen pada array. Menggunakan variabel `ketemu` ntuk menunjukkan apakah nilai yang dicari ditemukan atau tidak. 

Pertama program akan mengisi array `data` dengan nilai-nilai yang telah ditemukan. Kemudian program membandingkan nilai `cari` dengan setiap elemen array `data` dari elemen pertama hingga elemen terakhir menggunakan perulangan `for`. Jika nilai yang dicari ditemukan, maka variabel `ketemu` akan diubah menjadi `true` dan perulangan dihentikan. Program menampilkan hasilnya, jika nilai yang dicari ditemukan maka indeksnya juga ditampilkan. Jika nilai tidak ditemukan, maka pesan "tidak dapat ditemukan" akan ditampilkan.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i, j; 
    for(i = 0; i < length; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch(int data[], int length) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // Tampilkan data awal
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukkan data yang ingin anda cari : ";
    cin >> cari;

    cout << "\n Data diurutkan : ";
    // Urutkan data dengan selection sort
    selection_sort(data, length);

    // Tampilkan data setelah diurutkan 
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    binarysearch(data, length);
    _getche();
    return EXIT_SUCCESS;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/c5fbb13f-7fbf-47f7-881c-c8d31eb71543)

Kode diatas adalah program pencarian data dengan menggunakan selection sort binary search untuk mencari suatu nilai dalam sebuah array. Fungsi selection Sort digunakan untuk mengurutkan data, sedangkan binary search digunakan untuk mencari nilai yang diurutkan.

Menggunakan library `iomanip` yang berguna untuk memformat output (seperti setw untuk mengatur lebar), `conio.h` dengan fungsi `_getche()` diatas berguna untuk membaca satu karakter dari keyboard tanpa menampilkannya di layar.

Pertama array `data` diisi dengan nilai-nilai contoh dan panjangnya akan dihitung, dengan variabel `cari` sebagai penyimpan nilai yang ingin dicari. Kemudian data awal pada array `data` ditampilkan menggunakan looping dan fungsi `setw` guna memformat outputnya nanti. Lalu, pengguna diminta untuk memasukkan nilai yang ingin dicari. Program akan mengurutkan data dalam array `data` secara menaik dengan menggunakan fungsi `binarysearch`. Program akan mencetak pesan bahwa angka yang dicari ditemukan atau tidak serta menampilkan data setelah diurutkan. Program mengembalikan `EXIT_SUCCESS` yang artinya program telah selesai dijalankan.



## Unguided

### 1. 

```C++

```

#### Output:

#### Full code Screenshot:


### 2. 

```C++

```

#### Output:
 

#### Full code Screenshot:



### 3. 

```C++

```

#### Output:

### Full code Sreenshot:


## Kesimpulan

Kesimpulannya, 

## Referensi

[1] Tarigan, Wanra. "Algoritma Pemrograman dan Struktur Data". Eureka Media Aksara, 2022.
[2] P. I. Daulay, “Penerapan Algoritma Pemrograman dalam Pembelajaran Ilmu Komputer,” Bahasa dan Matematika, vol. 1, no. 6, pp. 91–103, doi: 10.61132/arjuna.v1i6.297.
[3] “Linear Search (With code).” https://www.programiz.com/dsa/linear-search
[4] 

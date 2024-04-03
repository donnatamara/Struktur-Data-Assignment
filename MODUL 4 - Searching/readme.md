# <h1 align="center">Laporan Praktikum Modul Searching</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori
Searching atau dapat disebut pencarian adalah suatu proses untuk mengumpulkan sejumlah informasi didalam pengingat computer dan kemudian mencari kembali informasi yang diperlukan secepat mungkin. Ada beberapa cara dalam pencarian sebuah data [1]. 

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

kode diatas merupakan kode program yang melakukan pencarian data menggunakan sequential search.

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

Kode diatas adalah program pencarian data dengan menggunakan binary search.


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

[1] Tarigan, Wanra. Algoritma Pemrograman dan Struktur Data. Eureka Media Aksara, 2022.
[2] 
[3] 
[4] 

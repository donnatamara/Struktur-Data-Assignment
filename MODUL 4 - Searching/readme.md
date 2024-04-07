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
Sequential search atau dapat disebut linear search adalah teknik pencarian data dalam array dengan membaca satu demi satu dan diurutkan dari indeks pertama hingga indeks terakhir, maupun sebaliknya. Algoritma ini biasa digunakan untuk data berpola acak dan tidak cocok digunakan untuk array berukuran besar. 

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

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mencetak semua posisi kemunculan huruf dalam string
void binarysearch(const string& str, char target) {
    bool found = false;
    cout << "Huruf \"" << target << "\" ditemukan pada indeks: ";
    for (int i = 0; i < str.length(); ++i) {
        if (tolower(str[i]) == tolower(target)) {
            found = true;
            cout << i << " ";
        }
    }
    if (!found) {
        cout << "tidak ditemukan";
    }
    cout << endl;
}

int main() {
    string kalimat = "Saya belajar algoritma dan struktur data.";
    char huruf;
    
    cout << "\nKalimat: " + kalimat << endl;
    cout << "\nMasukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Mengubah huruf menjadi huruf kecil untuk pencarian yang tidak case-sensitive
    huruf = tolower(huruf);

    // Memanggil fungsi binarysearch untuk mencari dan mencetak semua posisi kemunculan huruf
    binarysearch(kalimat, huruf);

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/756f1114-5b8d-4ae4-ada7-dff4898bbe39)


Kode di atas adalah kode program yang dapat mencari dan mencetak berapa saja kemunculan huruf yang akan dicari oleh pengguna dalam sebuah kalimat yang sudah diinputkan beserta indeksnya menggunakan algoritma binary search.

Pertama, program akan mendefinisikan fungsi `binarysearch` dengan dua parameter yaitu `str` (tempat pencarian dilakukan) dan `target` (huruf yang ingin dicari), variabel `found` diinisialisasi sebagai `false` yang menandakan bahwa huruf belum ditemukan. Kemudian, setelah pengguna memasukkan huruf yang akan dicari, program akan mencetak pesan "ditemukan pada indeks:" setelah itu program akan melakukan perulangan dari indeks awal hingga indeks akhir. 

Pada tiap itersi perulangan, program akan membandingkan karakter pada indeks saat ini dengan huruf yang dicari. Jika karakternya sama, maka program akan mencetak indeksnya pada output. Jika program tidak menemukan huruf yang dicari, program akan mencetak pesan "tidak ditemukan".

Pada fungsi main, variabel `kalimat` yang bertipe string diisi dengan kalimat contoh. Selanjutnya program meminta pengguna untuk memasukkan huruf yang akan dicari, lalu mengubah hurufnya menjadi huruf kecil menggunakan fungsi `tolower`. Kemudian, program memanggil fungsi `binarysearch` untuk mencari dan mencetak semua indeks posisi kemunculan huruf yang diinputkan oleh pengguna dalam string `kalimat`.


#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/65ba7e61-1697-4f35-905a-c91d6ca8f53f)




### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!


```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int banyak = 0;
    const int max = 100; // Maksimum panjang kalimat
    int indeksVokal[max];
    int index = 0;

    for (int i = 0; i < kalimat.length(); i++) {
        char huruf = tolower(kalimat[i]); // Mengubah huruf menjadi huruf kecil
        if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u') {
            banyak++;
            indeksVokal[index++] = i;
        }
    }

    cout << "Banyak huruf vokal: " << banyak << endl;
    if (banyak > 0) {
        cout << "Indeks huruf vokal: ";
        for (int i = 0; i < index; i++) {
            cout << indeksVokal[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/170716df-ebb9-4b41-a491-1a3baf0091a4)

Kode di atas merupakan kode program yang meminta pengguna memasukkan sebuah kalimat, kemudian menghitung jumlah huruf vokal beserta indeks dari setiap huruf vokal dalam kalimat tersebut.

Pertama, program akan mendeklarasikan variabel `kalimat` sebagai string yang berguna untuk menyimpan kalimat yang dimasukkan oleh pengguna. Kemudian, pengguna diminta untuk memasukkan sebuah kalimat menggunakan `getline` agar dapat membaca spasi dalam kalimta tersebut.

Program melakukan iterasi melalui setiap karakter dalam kalimat menggunakan perulangan `for`, yang mana pada setiap karakternya diubah menjadi huruf kecil menggunakan fungsi `tolower` untuk mempermudan pengecekan. Apabila karakter tersebut merupakan huruf vokal, maka variabel `banyak` akan ditambah satu dan indeks karakter akan disimpan pada `indeksVokal`. Program akan mengembalikan nilai 0 yang artinya program telah sukses berjalan.

Program menampilkan jumlah huruf vokal yang ditemukan dan jika ditemukan, program akan menampilkan indeks-indeks huruf vokal yang telah disimpan dalam array `indeksvokal`.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/c3bf2ec2-81bd-43fe-b435-4e467c6e83e7)



### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>

using namespace std;

void sequentialSearch(const int data[], int size, int target, int indices[], int& count) {
    count = 0; 
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            indices[count] = i; // Simpan indeks jika angka ditemukan
            count++; 
        }
    }
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]); // Menghitung panjang array secara dinamis
    int target, count;
    const int max = 100; // Ukuran maksimum untuk array indeks
    int indices[max];

    cout << "Masukkan angka yang ingin Anda cari: ";
    cin >> target;

    sequentialSearch(data, size, target, indices, count);

    if (count > 0) {
        cout << "Angka " << target << " ditemukan sebanyak " << count << " kali, pada indeks:" << endl;
        for (int i = 0; i < count; i++) {
            cout << indices[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam data." << endl;
    }

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/4224ce16-f093-490c-8369-09c80d8a969f)

Kode di atas merupakan kode program untuk melakukan pencarian nilai pada array `data` menggunakan algoritma sequential search dengan pengguna dapat memasukkan sendiri nilai yang ingin dicari (contoh diatas adalah angka 4).

Pertama, variabel `count` diatur menjadi 0, program melakukan iterasi pada array `data` dengan menggunakan perulangan `for` untuk mencari kemunculan angka target. Jika angka target ditemukan pada indeks ke-i, maka indeks tersebut disimpan dalam `indices` dan nilai `count` ditambah satu.

Pada fungsi `main`, program menghitung ukuran array `data` dengan membagi ukuran total dengan ukuran setiap elemen tunggalnya. Kemudian, program meminta pengguna untuk memasukkan angka target yang ingin dicari, lalu melakukan pencarian angka target dengan menggunakan fungsi `sequentialsearch`. 

Program mengecek apakah angka target ditemukan setidaknya satu kali. Jika ya, prorgam akan mengembalikan angka 0 tanda bahwa program telah selesai dijalankan serta pada output akan ditampilkan jumlah kecunculan angka target beserta indeksnya. Jika tidak, program akan mencetak "Angka tidak ditemukan dalam data.".

### Full code Sreenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/e5a04487-d02a-4f3f-867e-07189b9c2c86)





## Kesimpulan

Kesimpulannya, pada algoritma searching adalah proses menemukan sebuah data yang diinginkan dalam sebuah kumpulan data. Memiliki dua jenis yang umum diketahui yaitu binary search dan sequential search. Binary search merupakan pencarian dengan membagi array atau list menjadi dua bagian secara berulang dan membandingkan elemen yang dicari dengan elemen tengah. Sedangkan sequential search atau dapat disebut linear search merupakan pencarian dengan membandingkan elemen yang dicari dengan setiap elemen dalam array secara berurutan.

## Referensi

[1] Tarigan, Wanra. "Algoritma Pemrograman dan Struktur Data". Eureka Media Aksara, 2022.

[2] P. I. Daulay, “Penerapan Algoritma Pemrograman dalam Pembelajaran Ilmu Komputer,” Bahasa dan Matematika, vol. 1, no. 6, pp. 91–103, doi: 10.61132/arjuna.v1i6.297.

[3] “Linear Search (With code).” https://www.programiz.com/dsa/linear-search


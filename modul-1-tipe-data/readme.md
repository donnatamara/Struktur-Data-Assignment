# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

Tipe data merupakan salah satu konsep dasar dalam pemrograman komputer, tipe data adlah sebuah pengelompokkan sebuah data berdasarkan jenis data dalam sebuah bahasa pemrograman. Tipe data menentukan jenis data yang dapat disimpan dalam variabel dan operasi yang dapat dilakukan pada variabel tersebut [1]. Dibawah ini adalah jenis tipe data yang biasanya digunakan:

### 1. Tipe Data Primitif:

Tipe data primitif merupakan sebuah jenis data pada bahasa pemrograman yang telah ditentukan oleh sistem dan tersedia pada banyak bahasa pemrograman, hal yang membedakan antara bahasa pemrograman yang satu dengan yang lain adalah pada jumlah bit didalam tipe data primitif tergantung pada bahasa pemrograman, compiler, dan sistem operasinya. 
Contohnya:
- Int: Digunakan untuk menyimpan bilangan bulat seperti 12, 1, 4, dan lain sebagainya.
- Float: Digunakan untuk menyimpan bilangan desimal seperti 1.5, 2.1, 3.14, dan lain sebagainya.
- Char: Digunakan untuk menyimpan huruf atau simbol seperti A, B, C, dan lain sebagainya.
- Boolean: Digunakan untuk menyimpan nilai boolean yang hanya memiliki dua nilai saja yaitu true atau false.

### 2. Tipe Data Abstrak:

Tipe data abstrak atau Abstrak Data Type (ADT) adalah sebuah tipe data yang dibentuk oleh programernya sendiri. Tipe data ini dapat berisi berbagai jenis data. Fitur class dalam Object Oriented Programming (OOP) mirip dengan struktur data struct pada bahasa C, ada perbedaan pada akses default antara keduanya yaitu struct bersifat public dan class bersifat privat.

### 3. Tipe Data Koleksi:

Tipe data koleksi atau Collection Data Type digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data ini dapat menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara terstruktur. Beberapa contoh tipe data koleksi meliputi:

- Array: Struktur data statis yang didalamnya berisi elemen-elemen tipe data yang sama, elemen-elemen tersebut menggunakan indeks untuk aksesnya dan ukurannya tetap yang ditentukan saat pendeklarasian.
- Vector: Mirip seperti array tetapi jumlah elemennya dinamis dan alokasi memorinya dilakukan otomatis dan bersebelahan.
- Map: Map mirip juga seperti array, namun indeksnya dapat berupa selain tipe data integer. Pada map, indeks dapat disebut juga dengan "key", self balancing tree khususnya black tree menggunakan std::map. 

## Guided

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
// Main program
main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;
    // It allow user to enter the operands
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1 / num2;
        break;
    // If the operator is other than +, -, * or /,
    // error massage will display
    default:
        cout << "Error! operator is not correct";
    } // Switch statement ends
    return 0;
}
```

#### Output:
<img width="960" alt="Screenshot 2024-03-09 181046" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/f109d046-df2e-44c6-a40e-8f58f0d6d8fa">

Kodingan di atas adalah kode yang menjalankan sebuah program yang meminta pengguna untuk memasukkan sebuah operator matematika (+, -, *, /) dan dua angka, progam di atas menggunakan fungsi 'switch' untuk melakukan operasi sesuai dengan operator yang dimasukkan, jika operator yang dimasukkan tidak sesuai dengan yang ada pada program, maka program akan mencetak error.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

//struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    // Menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // Mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // Mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```

#### Output:
<img width="960" alt="Screenshot 2024-03-09 181112" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/de885d7a-d522-4e16-ba04-a0a80adb159f">

Kodingan di atas adalah kode yang menjalankan program yang menggunakan fungsi "struct" untuk menampilkan informasi mahasiswa, pada kode diatas `Mahasiswa` memiliki tiga data anggota yaitu `name`, `address`, dan `age`.

Di dalam struct ada fungsi `display()` yang digunakan untuk mencetak informasi mahasiswa ke layar. Menggunakan fungsi `main()`, dan membuat dua variabel `Mahasiswa` (mhs1 dan mhs2). Setelah mengisi nilai ke struct, program akan mencetak isi struct tersebut menggunakan fungsi `printf()` yang hasilnya akan berupa informasi nama, alamat, dan usia masing-masing mahasiswa.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```

#### Output:
<img width="960" alt="Screenshot 2024-03-09 192753" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/f311bda2-fc4b-43e6-89b1-40615dd49fae">

Kodingan di atas adalah program penggunaan array yang terdiri dari lima elemen bertipe integer. Array diatas bernama `nilai` yang terdiri dari lima elemen, nilai pada array `nilai` diinisialisasi menggunakan indeks untuk setiap elemen array.

Menggunakan fungsi `cout` untuk mencetak nilai dari setiap array `nilai`, setelah mencetak isi dari setiap elemen array, program akan mengembalikan nilai 0 dari fungsi `main()` yang dapat diartikan bahwa program tersebut berjalan sukses.

## Unguided

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas persegi
float hitungLuasPersegi(float sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung volume balok
float hitungVolumeBalok(float panjang, float lebar, float tinggi) {
    return panjang * lebar * tinggi;
}

int main() {
    char pilihanMenu; // Variabel yang digunakan untuk memproses menu pilihan user
    float ukuranSisi, panjang, lebar, tinggi; // Variabel untuk menampung data input dari user

    // Menampilkan menu pilihan
    cout << "1. Hitung Luas Persegi\n2. Hitung Volume Balok\nPilih Menu (1, 2): ";
    cin >> pilihanMenu;

    switch (pilihanMenu) {
    case '1':
        cout << "Masukkan panjang sisi persegi: ";
        cin >> ukuranSisi;
        // Menampilkan hasil perhitungan luas persegi
        cout << "Luas Persegi dengan sisi " << ukuranSisi << " adalah: " << hitungLuasPersegi(ukuranSisi) << endl;
        break;
    case '2':
        cout << "Masukkan panjang, lebar, dan tinggi balok: " << endl;
        cout << "Panjang: ";
        cin >> panjang;
        cout << "Lebar: ";
        cin >> lebar;
        cout << "Tinggi:";
        cin >> tinggi;
        // Menampilkan hasil perhitungan volume balok
        cout << "Volume Balok dengan panjang " << panjang << ", lebar " << lebar << ", dan tinggi " << tinggi << " adalah: "
             << hitungVolumeBalok(panjang, lebar, tinggi) << endl;
        break;
    default:
        cout << "Menu Tidak Ada";
    }

    return 0;
}
```

#### Output:
<img width="960" alt="Screenshot 2024-03-09 192908" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/516ae316-fdbb-49da-979b-30eb1614ca26">

Kodingan di atas adalah program yang memungkinkan pengguna untuk menghitung luas persegi atau volume balok berdasarkan pilihan menu yang telah dibuat. Dimulai dari fungsi `hitungLuasPersegi` untuk menghitung luas persegi berdasarkan panjang sisi, `hitungVolumeBalok` untuk menghitung volume balok berdasarkan panjang, lebar, dan tinggi.

Program menjalankan fungsi `main()` untuk memilih menu dengan menampilkan pilihan 1 atau 2 dan pengguna diminta untuk memasukkan karakter yang sesuai dengan pilihan menu. Menggunakan fungsi `switch` untuk menjalankan bagian kode yang sesuai dengan pilihan pengguna. Jika pengguna memilih menu 1 maka program akan menjalankan fungsi `hitungLuasPersegi`, jika pengguna memilih menu 2 maka program akan menjalankan `hitungVolumeBalok`, dan jika pengguna memasukkan pilihan menu selain menu 1 atau 2 maka program menampilkan pesan `Menu Tidak Ada`. program kemudian mengembalikan nilai 0 yang menandakan bahwa program telah sukses berjalan.

#### Kesimpulan materi tipe data primitif:

Kesimpulannya adalah tipe data primitif merupakan jenis tipe data yang telah ditentukan oleh sistem dan tersedia pada banyak bahasa pemrograman. Contoh tipe data primitif adalah int untuk menyimpan bilangan bulat, float untuk menyimpan bilangan desimal, char untuk menyimpan huruf atau simbol, dan boolean untuk menyimpan nilai boolean yang hanya berisi dua kemungkinan nilai, yaitu true atau false.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

#### Class

Class digunakan untuk membuat tipe data baru, tetapi biasanya digunakan untuk membuat tipe data yang lebih kompleks. Class mendukung konsep enkapsulasi, di mana anggota-anggota data (variabel) dan fungsi-fungsi yang berkaitan dapat disembunyikan atau diakses secara terbatas. 
#### Struct

Struct atau structure, adalah tipe data yang dapat digunakan untuk mengelompokkan sejumlah variabel dengan tipe data yang berbeda ke dalam satu kesatuan.Secara default, semua anggota (variabel) struktur dapat diakses secara publik [2].

#### Perbedaan

Perbedaan utama antara class dan struct dalam C++ adalah hak akses default untuk anggota-anggotanya. Secara default, anggota struct adalah public, sedangkan anggota class adalah private. Class lebih banyak digunakan untuk objek yang dimana setiap proses di dalamnya saling berhubungan. Sedangkan struct biasa digunakan untuk struktur data atau objek yang sebenarnya, menyimpan data menggunakan variabel dan membuat fungsi [2].

#### Contoh Program

```C++
#include <iostream>
#include <string>
using namespace std;

//Class biasa yang belum publik akses
class Makanan_Daerah {
    string nama;
    string jenis;
    string asal;
};

//Class yang sudah menjadi publik akses
class Makanan_Daerah2 {
public:
    string nama;
    string jenis;
    string asal;
};

struct Makanan_Daerahh {
    string nama;
    string jenis;
    string asal;
};

int main() {
    Makanan_Daerahh md1;
    Makanan_Daerah2 md2;
    
    md1.nama = "Nasi Megono";
    md1.jenis = "Kering";
    md1.asal = "Pekalongan";
    cout << "==== Makanan 1 ===="
        << "\nNama Makanan: " << md1.nama
        << "\nJenis: Makanan " << md1.jenis
        << "\nAsal Daerah: " << md1.asal << endl;

    md2.nama = "Soto Tauto ";
    md2.jenis = "Basah";
    md2.asal = "Pekalongan";
    cout << "==== Makanan 2 ===="
        << "\nNama Makanan: " << md2.nama
        << "\nJenis: Makanan " << md2.jenis
        << "\nAsal Daerah: " << md2.asal << endl;

    return 0;
}
```

#### Output:
<img width="960" alt="Screenshot 2024-03-09 193003" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/87a5583c-b7fb-4844-9746-b03b149c6841">

Kodingan diatas adlaha program dengan penggunaan `class`, `struct`, dan obejk-objek dari kedua dalam bahasa pemrograman.

Dalam class Makanan_Daerah, anggota-anggota seperti `nama`, `jenis`, dan `asal` tidak dideklarasikan sebagai public, tetapi secara default, mereka memiliki hak akses private. Class Makanan_Daerah 2 memiliki semua anggota public, yang berarti variabel `nama`, `jenis`, dan `asal` dapat diakses dari luar class.

Struct Makanan_Daerahh memiliki tiga anggota yang semuanya adalah public secara default. Ini berarti semua anggota `nama`, `jenis`, dan `asal` bisa diakses langsung dari luar struct.
Di dalam `main()`, dua objek yang dibuat adalah `md1` dari tipe struct `Makanan_Daerahh` dan `md2` dari tipe class `Makanan_Daerah2`.
Setelah itu, nilai-nilai atribut dari kedua objek diatur dan dicetak ke layar menggunakan cout.

Hasilnya adalah dua objek `md1` dan `md2` yang berbeda, masing-masing memiliki atribut `nama makanan`, `jenis`, dan `asal daerah` yang berbeda pula.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi map
    map<int, int> nilai;
    nilai[0] = 24;
    nilai[1] = 48;
    nilai[2] = 57;
    nilai[3] = 90;
    nilai[4] = 21;

    // Mencetak nilai dari map
    for (const auto& pair : nilai) {
        cout << "Element " << pair.first + 1 << " : " << pair.second << endl;
    }

    return 0;
}
```

#### Output:
<img width="960" alt="Screenshot 2024-03-09 194116" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/28d51732-51af-4920-8508-1a6b5b8dae40">

Kodingan di atas adalah penggunaan dari struktur data map pada bahasa pemrograman C++. Untuk objek `nilai` dideklarasikan sebagai sebuah map yang memiliki kunci dan nilai bertipe integer. Pasangan dari key-value ditambahkan ditambahkan ke dalam map `nilai` menggunakan operator indeks`[ ]`. Program melakukan iterasi melalui setiap elemen map menggunakan fungsi loop for untuk mencetak nilai dari setiap pasangan nilai. Hasilnya adalah untuk mencetak semua nilai ke layar tanpa indeks pada array.

#### Perbedaan Array dan Map:

Array adalah kumpulan data yang diakses dengan berdasarkan indeks (mulai dari 0 sampai ukuran array-1). array adalah kumpulan elemen dengan tipe data yang sama yang disimpan secara berurutan[3]. Ukurannya ditentukan saat proses deklarasi dan tidak dapat diubah selama program berjalan, cocok digunakan untuk pengumpulan data yang diakses secara berurutan dan ukurannya dapat diketahui sebelumnya.

Sedangkan map, merupakan struktur data yang menyimpan pasangan kunci-nilai (key-value pairs), elemen-elemennya tidak dapat disimpan dalam urutan tertentu, tetapi disusun berdasarkan penerapan struktur data. Elemen pada map dapat dihapus, ditambahkan, dan dicari dengan menggunakan kunci, dengan ukuran yang dapat berubah secara dinamis. Map cocok digunakan untuk memetakan kunci ke nilai dan digunakan dalam situasi di mana struktur data asosiatif diperlukan.

Jadi, pemilihan antara keduanya tergantung pada kebutuhan dari program dan cara data akan diakses dan disimpan. Jika membutuhkan koleksi data yang sederhana dan ukurannya tetap maka gunakan array, tetapi jika perlu memetakan kunci ke nilai dan mengelola data secara dinamis maka gunakan map.

## Kesimpulan

Kesimpulannya, tipe data memiliki tiga jenis yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi. Tipe data primitif meliputi integer, float, character, dan boiolean. Tipe data abstrak meliputi struct dan class, struct memiliki askses default yang bersifat public sedangkan class bersifat private. Tipe data koleksi meliputi array, vector, dan map. Array adalah struktur data statis, berukuran tetap, berisi tipe data yang sama secara beruruta. Vector adalah struktur data dinamis, ukurannya dapat disesuaikan, dan alokasi memorinya dilakukan otomatis dan bersebelahan. Sedangkan Map adalah struktur data yang memetakan kunci (key) ke nilai (value), setiap kuncinya harus unik.

## Referensi

[1] R. Hidayat, "Pengertian Tipe Data dan Penggunaannya dalam Bahasa Pemrograman," J. Informatika dan Teknologi Univ. Gunadarma, 2020.
[2] A. Aristo, “Swift: Class vs. Struct - Dipantry - Medium,” Medium, Dec. 28, 2021. [Online]. Available: https://medium.com/dipantry/swift-class-vs-struct-c0b279b1dfaf.
[3] P. Van Weert and M. Gregoire, C++17 Standard Library Quick Reference. Apress, 2019.

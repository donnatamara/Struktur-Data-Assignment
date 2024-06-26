# <h1 align="center">Laporan Praktikum Modul Struct</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### 1. Variabel
Variabel adalah lokasi penyimpanan dalam memori komputer yang menyimpan nilai. Dalam pemrograman, variabel digunakan untuk menyimpan data yang dapat dimanipulasi dan dirujuk dalam sebuah program. Mereka memiliki tipe data tertentu dan pengidentifikasi unik, memungkinkan para pemrogram untuk bekerja dengan berbagai jenis informasi secara efisien [1]. 

Mereka memainkan peran penting dalam bahasa pemrograman seperti C++ dengan memungkinkan para pemrogram untuk memanipulasi dan bekerja dengan data secara efisien [2]. Variabel memiliki 2 jenis yaitu:
- Variabel lokal: Dibuat didalam fungsi, dan dapat dipanggil hanya oleh fungsi yang mendeklarasikannya. Variabel lokal dalam C++ adalah variabel yang dideklarasikan dalam fungsi atau blok kode yang berbeda dengan variabel global. Variabel lokal hanya dapat diakses dalam fungsi atau blok kode di mana mereka dideklarasikan dan tidak dapat diakses dari luar fungsi atau blok kode tersebut [3].
- Variabel global: Dibuat diluar fungsi, dapat dipanggil oleh semua fungsi yang ada didalam program. Variabel global adalah variabel yang dideklarasikan di luar semua fungsi atau blok kode, membuatnya dapat diakses dari mana pun dalam program tanpa batasan lingkup lokal. Dalam C++, variabel yang dideklarasikan di luar fungsi main() secara otomatis dianggap sebagai variabel global. Variabel global dibuat saat program dimulai dan dimusnahkan ketika program berakhir, ini disebut durasi statis [3].


### 2. Struct
Struct adalah tipe data bentukan yang terdiri dari sejumlah tipe data standar maupun tipe data bentukan lainnya yang telah terdefinisi sebelumya. Keyword yang digunakan untuk mendeklarasikan sebuah struktur adalah struct. Struct dalam pemrograman C++ digunakan untuk membentuk tipe data dengan anggota (member) tertentu. Pendeklarasian struct dilakukan dengan menentukan anggota-anggotanya, seperti variabel-variabel yang akan digunakan dalam program. Sebagai contoh, dalam struct tgl, terdapat anggota hari, bulan, dan tahun [4].

Struct dalam bahasa C++ adalah struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda yang tersedia dalam C++. Tipe data yang baru, dapat dibentuk di luar tipe data yang sudah ada dengan menggabungkan beberapa tipe data tersebut sesuai dengan kebutuhan program atau aplikasi yang dirancang. Struct digunakan untuk mengelompokkan data terkait ke dalam satu unit yang lebih besar. Dalam C++, struct mirip dengan class, namun dengan perbedaan utama bahwa semua anggotanya secara default bersifat public, sehingga memungkinkan akses langsung ke anggota struct tersebut.

Struct dalam konteks pemrograman C++ digunakan untuk mendefinisikan tipe data kustom yang memungkinkan pengguna untuk mengorganisasi data dengan cara yang terstruktur. Struct memungkinkan pengguna untuk membuat entitas data yang terdiri dari beberapa variabel dengan tipe data yang berbeda, yang dapat membantu dalam mengatur dan mengelola data dengan lebih efisien dalam program C++ [5].



## Guided

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/6d33a949-68ce-400c-ae25-8ddfb9f682f0)

Kodingan di atas adalah kode program yang digunakan untuk menyimpan informasi buku menggunakan struct untuk penyimpanannya lalu ditampilkan ke layar. Menggunakan struct bernama `buku` yang terdiri dari lima anggota yaitu `judulBuku`, `pengarang`, `penerbir`, `tebalHalaman`, dan `hargaBuku`. 

Pertama dengan mendeklarasikan variabel `favorit` lalu disimpan pada struct `buku`, kumudian informasi buku favorit diisi satu per satu, seperti judul, pengrang, penerbit, jumlah halaman, dan harga buku, lalu variabel `favorit` ditampilkan ke layar. 


#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/18a3dd95-a310-4b10-8d8b-b5c2832a59ed)


### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/b7310d2d-8a04-480e-a9d9-1e0001e27237)


```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/d2cc2132-0982-45b0-8647-b9d1cf7138e4)

Kode di atas adalah kode program yang menunjukkan cara menggunakan struct dan turunan untuk menyimpa dan menampilkan informasi tentang hewan dengan berbagai karakteristiknya. Dengan menampilkan struktur dari hewan, hewan darat, dan hewan laut, menggunakan struct untuk menyimpan informasi tentang tiga hewan (serigala, kelinci, dan ikan). Struct `hewan` menyimpan informasi seperti nama, jenis kelamin, cara berkembang biak, alat pernapasan, tempat hidup, dan apakah hewan itu karnivora atau tidak. 

Struct `hewanDarat` diturunkan dari `hewan` dan menambah informasi tentang jumlah kaki dan apakah hewan darat itu menyusui. Struct `hewanLaut` juga diturunkan dari `hewan` dan menambah informasi tentang jumlah kaki serta apakah hewan darat tersbut menyusui atau tidak. Struct `hewanLaut` diturunkan dari `hewan` dan menambah informasi tentang bentuk sirip dan bentuk pertahanan diri. 

Kemudian program mendeklarasikan variabel untuk setiap hewan dan mengisi informasinya, yang mana pada variabel `kelinci` dengan tipe `hewanDarat` menyimpan informasi tentang kelinci, termasuk jumlah kaki (4), menyusui (yes), dan suara ("Citcit"). Variabel `ikan` dengan tipe `hewanLaut` menyimpan informasi tentang ikan, termasuk bentuk sirip ("Sirip ekor") dan bentuk pertahanan diri ("Sisik"). Variabel `serigala` dengan tipe `hewan` menyimpan informasi tentang serigala, termasuk jenik kelamin ("Jantan"), cara berkembang biak ("Melahirkan"), alat pernapasan ("Paru-paru"), tempat hidup ("Hutan terbuka"), dan apakah hewan itu karnivora (yes). Kemudian program akan menampilkan informasi tersebut ke layar.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/a4274371-87b0-410a-ad5b-17a4b35c6a19)


## Unguided

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

```C++
#include <iostream>
using namespace std;

// Mendefinisikan struktur buku
struct buku
{
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main()
{
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    for (int i = 0; i < 5; i++)
    {
        cout << "\nMasukkan data buku ke-" << i + 1 << ":" << endl;
        cout << "Judul Buku: ";
        cin.ignore(); // Bersihkan buffer input sebelumnya
        getline(cin, favorit.judulBuku[i]);

        cout << "Pengarang: ";
        getline(cin, favorit.pengarang[i]);

        cout << "Penerbit: ";
        getline(cin, favorit.penerbit[i]);

        cout << "Tebal Halaman: ";
        cin >> favorit.tebalHalaman[i];

        cout << "Harga Buku: ";
        cin >> favorit.hargaBuku[i];
    }

    // Menampilkan informasi buku favorit
    cout << "\n\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "\n\tData Buku ke-" << i + 1 << ":" << endl;
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
    }

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/85225dfa-4c0c-4841-98e7-1b08a7f65f3c)

Kode di atas adalah program yang menampilkan informasi tentang buku favorit yang telah dimasukkan data 5 buku oleh pengguna, termasuk judul, pengarang, penerbit, tebal halaman, dan harga. 

Pertama, program akan mendefinisikan struktur `buku` yang digunakan untuk menyimpan informasi tentang buku yaitu `judulBuku`, `pengarang`, `penerbit`, `tebalHalaman`, dan `hargaBuku` yang anggotanya dibatasi maksimal 5 buku. Kemudian, program akan menjalankan fungsi utama, mendeklarasikan variabel `favorit` dengan tipe `buku` sebagai penyimpanannya. Lalu, pengguna diminta memasukkan data untuk 5 buku dan kemudian inputan disimpan dalam variabel `favorit`. 

Setelah itu, program akan menampilkan informasi dari 5 buku yang telah disimpan dalam variabel `favorit` yang berisi judul, buku, pengarang, penerbit, tebal halaman, dan harga buku pada setiap buku. Program akan mengembalikan nilai 0 yang menandakan bahwa program telah selesai dijalankan dengan sukses.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/b2a73aec-3ca8-4747-a83c-9ae531bd6b60)



### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?


```C++
#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan struktur buku
struct buku
{
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main()
{
    const int jumlah_buku = 3; // Jumlah buku yang ingin dimasukkan

    // Mendeklarasikan variabel favorit sebagai array dari struktur buku
    buku favorit[jumlah_buku];

    // Mengisi data ke dalam array favorit
    favorit[0].judulBuku = "The Alpha Girl's Guide";
    favorit[0].pengarang = "Henry Manampiring";
    favorit[0].penerbit = "Gagas Media";
    favorit[0].tebalHalaman = 253;
    favorit[0].hargaBuku = 79000;

    favorit[1].judulBuku = "Lukacita";
    favorit[1].pengarang = "Valerie Patkar";
    favorit[1].penerbit = "Bhuana Ilmu Populer";
    favorit[1].tebalHalaman = 448;
    favorit[1].hargaBuku = 93000;

    favorit[2].judulBuku = "Laut Bercerita";
    favorit[2].pengarang = "Leila S. Chudori";
    favorit[2].penerbit = "Kepustakaan Populer Gramedia";
    favorit[2].tebalHalaman = 394;
    favorit[2].hargaBuku = 92000;

    // Menampilkan informasi buku favorit
    for (int i = 0; i < jumlah_buku; i++)
    {
        cout << "\tBuku Favorit " << i + 1 << endl;
        cout << "\tJudul Buku : " << favorit[i].judulBuku << endl;
        cout << "\tPengarang : " << favorit[i].pengarang << endl;
        cout << "\tPenerbit : " << favorit[i].penerbit << endl;
        cout << "\tTebal Halaman: " << favorit[i].tebalHalaman << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit[i].hargaBuku << endl;
        cout << endl;
    }

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/88505993-d2a9-4ef5-9586-5aaecaeb25d2)

Kode diatas yaitu contoh pendeklarasian variabel `favorit` sebagai array dari struct `buku`, mengisi data ke dalamnya dan menampilkannya. Jika dideklarasi variabel `favorit` dibuat berjenis array dari struct `buku` dengan ukuran `jumlah_buku`, maka setiap elemen pada array `favorit` akan menjadi satu dengan judul, pengarang, penerbit, tebal halaman, dan harga buku yang berbeda-beda, yang kemudian diisi dengan data untuk setiap elemennya. Kemudian, program akan menampilkan informasi buku focorit dengan menggunakan loop `for` unutk mengakses dan menampilkan data dari setiap elemen array `favorit`.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/6e5ac82c-6296-401d-950b-5da60e7649f5)



## Kesimpulan

Kesimpulannya, struct adalah sebuah struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan mpenggabungan antara berbagai macam variabel dengan tipe data yang berbeda. Struct digunakan untuk membentuk tipe data dengan anggota tertentu, yang dilakukan dengan menentukan anggota-anggotanya. Di dalam struct terdapat variabel sebagai anggota, setiap anggota struct memiliki nama dan data yang unik. Variabel memiliki dua jenis, yaitu variabel lokal yang dibuat didalam fungsi dan dapat dipanggil oleh fungsi yang mendeklarasikannya, dan variabel global yang dibuat diluar fungsi dan dapat dipanggil oleh semua fungsi yang ada dalam program tersebut.



## Referensi

[1] S. Anam, I. Yanti, Z. Fitria, U. Habibah, "Cara mudah belajar bahasa pemrograman C++," UB Press, 2021. 
[2] C. Ramadhani, S.T., M.Eng, "Algoritma Pemrograman dan Struktur Data Menggunakan C++," Andi Publisher, 2019.
[3] Josuttis, N. M. (2019). "C++17: The Complete Guide". Nicolai Josuttis.
[4] M. T. D. Putra, Munawir, and A. R. Yuniarti, "Belajar Pemrograman Lanjut dengan C++," Widina Media Utama, 2020.
[5] J. Carey, S. Doshi, and P. Rajan, "C++ Data Structures and Algorithm Design Principles," Packt, Oct. 2019.

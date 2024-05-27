# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### Rekursif
Rekursif adalah fungsi yang memanggil dirinya sendiri atau metode yang secara langsung atau tidak langsung memanggil dirinya sendiri [1]. Dalam rekursif biasanya mengandung prosedur dan fungsi, perbedaannya yaitu bahwa rekursif bisa memanggil ke dirinya sendiri, tetapi prosedur atau fungsi harus dipanggil lewat pemanggil prosedur atau fungsi [2]. Pemanggilan prosedur atau fungsi dari dirinya sendiri dapat berarti jika proses yang berulang tidak bisa diketahui kapan akan berakhir [1]. Fungsi rekursif harus memiliki dua bagian pernyataan rekursif dan kondisi terminasi. Perbedaan fungsi rekursif dan non rekursif yaitu fungsi rekursif mampu melakukan pemanggilan dirinya sendiri, sedangkan fungsi non rekursif hanya bisa memanggil fungsi lain [3]. 

Rekursif dibagi menjadi dua jenis yaitu:
- Rekursif langsung (Direct Recursion), fungsinya secara langsung memanggil dirinya sendiri [1]. Rekursi ini biasanya digunakan dalam pemrograman untuk menyelesaikan masalah yang dapat direduksi menjadi masalah serupa yang lebih kecil. Rekursi ini juga dapat membuat kode menjadi lebih ringkas dan simpel ketika digunakan dengan baik, namun perlu diingat untuk menghindari rekursi yang tak hingga yang dapat menyebabkan StackOverFlowError [4].
  
- Rekursif tidak langsung (Indirect Recursion), terjadi ketika fungsi A memanggil fungsi B, dan fungsi B memanggil kembali ke fungsi A maka itu melibatkan rekursi tidak langsung [1]. Rekursi ini merupakan fungsi yang memanggil fungsi lain dengan cara memanggil fungsi rekursif lain, bukan fungsi itu sendiri. Rekursi ini digunakan untuk menyelesaikan masalah yang lebih kompleks yang tidak dapat diselesaikan oleh rekursif langsung. 

## Kekurangan Rekursif 
Setiap program rekursif memiliki persyaratan ruang yang lebih besar daripada program iteratif karena semua fungsi akan tetap ada di tumpukan hingga base case tercapai. Program rekursif juga memiliki persyaratan waktu yang lebih besar karena pemanggilan fungsi dan pengembalian overhead [1].

## kelebihan Rekursif 
Rekursi menyediakan cara yang bersih dan sederhana dalam penulisan kode program. Beberapa masalah seperti Tree Traversal, Tower of Hanoi, dan lain-lain, untuk masalah seperti itu lebih dianjurkan untuk menulis kode rekursif. Meskipun permasalahan seperti itu juga dapat ditulis dalam bentuk kode secara iteratif dengan bantuan struktur data stack [1].

## Alokasi Memori untuk Rekursif
Saat sebuah fungsi apapun dipanggil dari fungsi `main()`, memori dialokasikan untuknya di stack. Sebuah fungsi rekursif memanggil dirinya sendiri, memori untuk fungsi yang dipanggil dialokasikan di atas memori yang dialokasikan untuk fungsi pemanggil dan salinan variabel lokal yang berbeda dibuat untuk setiap panggilan fungsi. Ketika base case tercapai, fungsi mengembalikan nilainya ke fungsi yang memamnggil, dilajutkan dengan melepaskan memori dan proses berlanjut [1].



## Guided 
### Rekursif Langsung (Direct Recursion)

```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }
    
    cout << n << " ";
    countdown(n - 1);
}

int main () {
    cout << "Rekursif Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/562437fb-e45a-414a-b14a-8167184810d8)

Kode di atas adalah kode program yang menampilkan sebuah penerapan fungsi rekursif langsung dalam menghitung mundur dari suatu bilangan positif `n` hingga `1`. Pertama, program akan menjalankan fungsi `main`, yang mencetak "Rekursif Langsung: " ke layar dan memanggil fungsi `countdown` dengan argumen `5`. Kemudian, fungsi `countdown` akan menerima argumen `n` yang bernilai `5` dan mulai melakukan perhitungan mundur dari angka `n` hingga 1 menggunakan rekursi, jika `n` sama dengan `0` maka fungsi berhenti memanggil dirinya sendiri dan rekursi berakhir. Setelah semua pemanggilan rekursif selesai, fungsi `main` akan melanjutkan dan mencetak newline (`endl`), lalu fungsi `main` akan mengembalikan nilai 0 yang menandakan bahwa program telah selesai dijalankan.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/6c8d941a-d09b-4cba-bbca-f23eea4b0ca0)


### Rekursif Tidak Langsung (Indirect Recursion)

```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung";
    functionA(num);
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/f76a6ab2-e595-4dfc-9ed0-e9f825d74243)

Kode di atas adalah kode program yang menampilkan sebuah penerapan fungsi rekursif tidak langsung untuk menghasilkan sebuah urutan angka. Pertama pada fungsi `main`, program akan mencetak "Rekursif Tidak Langsung: " ke layar. Selanjutnya, fungsi `main` memanggil fungsi `functionA` dengan argumen `5`. Fungsi `functionA` dijalankan dengan argumen `5` karena nilai `n` lebih besar dari 0, maka fungsi akan mencetak nilai `n` (yaitu 5) ke layar dan memanggil `functionB(4)` dilanjutkan dengan argumen lainnya hingga hasilnya argumen 0. Fungsi `functionA` dijalankan kembali dengan argumen `0`, karena nilai `n` (yaitu 0) tidak lebih besar dari 0, fungsi ini tidak melakukan apapun dan langsung kembali ke pemanggilannya. Jika semua pemanggilan rekursif selesai, program akan kembali ke fungsi `main` dan mengembalikan nilai 0 tanda bahwa program telah berjalan dengan sukses.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/c9058398-9f32-4151-85b3-b9457f7ac977)



## Unguided

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>

using namespace std;

int faktorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * faktorial(n - 1);
    }
}

int main()
{
    int num;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    }
    else
    {
        int hasil = faktorial(num);
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/425fadd2-daa9-424c-98b3-c1e1fe2fc6bc)

Kode di atas adalah kode program yang dapat menghitung faktorial dari suatu bilang bulan positif yang dimasukkan oleh pengguna menggunakan fungsi rekursif langsung. Pertama program dimulai dari dungsi `main` kemudian mencetak "Masukkan bilangan bulat positif: " ke layar. Lalu pengguna diminta untuk memasukkan bilangan bulat positif, jika bilangan yang dimasukkan kurang dari 0, program akan mencetak pesan kesalahan bahwa input tidak valid dan meminta pengguna untuk memasukkan bilangan bulat positif. Jika bilangan yang dimasukkan benar, maka program akan melanjutkan dengan memamnggil fungsi `faktorial` dengan argumen bilangan yang tadi sudah dimasukkan (`num`). Fungsi `faktorial` akan menerima bilangan bulat `n` dan memeriksa apakah `n` kurang dari atau sama dengan 1. Jika yam maka fungsi akan mengembalikan nilai 1, jika fungsi akan mengembalikan hasil perkalian antara `n` dengan faktorian dari `n-1`. Proses tersebut akan terus berjalan secara rekursif hingga mencapai kondisi saat nilai `n` sama dengan 1 atau kurang, di mana fungsi `faktorial` akan mulai mengembalikan nilai 1 dan berhenti memanggil dirinya sendiri. Hasil faktorial dari bilangan yang dimasukkan akan disimpan dalam variabel `hasil`, kemudian program akan mencetak hasil faktorial tersebut ke layar. Program akan mengembalikan nilai 0 bahwa program telah selesai berjalan.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/1f8d7513-c5cc-4447-9440-1ec517c97e5c)


### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>

using namespace std;

int faktorialA(int n);

int faktorialB(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * faktorialA(n - 1);
    }
}

int faktorialA(int n)
{
    return faktorialB(n);
}

int main()
{
    int num;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    }
    else
    {
        int hasil = faktorialB(num);
        cout << "Faktorial dari " << num << " adalah " << hasil << endl;
    }

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/6500838f-0d7c-47d0-985e-a747d27fbec9)

Kode di atas adalah kode program yang dapat menghitung faktorial dari suatu bilangan bulat positif yang dimasukkan oleh pengguna dengan menggunakan fungsi rekursif tidak langsung. Pertama program dimulai dengan meminta pengguna untuk memasukkan bilangan bulat positif, jika pengguna memasukkan nilai kurang dari 0 maka program akan mencetak pesan kesalahan dan program selesai, jika pengguna memasukkan bilangan bulat positif, maka program akan melanjutkan ke langkah berikutnya yaitu menghitung faktorian dari bilangan tersebut. Program akan memanggil fungsi `faktorialB` untuk menghitung faktorial dari bilangan yang dimasukkan, fungsi `faktorialB` menerima argumen `n` yang merupakan bilangan bulat yang akan dihitung faktorialnya. Jika `n` kurang dari atau sama dengan 1, fungsi mengembalikan nilai 1. Jika tidak, fungsi mengembalikan hasil perkalian `n` dengan faktorian dari `n - 1`, yang dihitung dengan memanggil fungsi `faktorialA`. Fungsi `faktorialA` akan memanggil kembali fungsi `faktorialB` untuk melakukan perhitungan faktorian dari `n - 1`. Proses rekursi akan terus berlanjut hingga mencapai nilai `n` sama dengan 1, di mana fungsi `faktorialB` akan mengembalikan nilai 1 dan berhenti memanggil dirinya sendiri. Hasil faktorian dari bilangan yang dimasukkan akan disimpan dalam variabel `hasil`. Kemudian, program akan mencetak hasil faktorian tersebut ke layar, program akan mengembalikan nilai 0 tanda program telah selesai berjalan. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/1b4fa59b-3281-4df5-ac46-58efdc7843cc)



## Kesimpulan

Kesimpulannya, Rekursif adalah proses sebuah fungsi yang memanggil dirinya sendiri dengan cara rekursif langsung atau rekursif tidak langsung. Rekursif langsung merupakan fungsi yang memanggil dirinya sendiri secara langsung atau tidak langsung memanggil dirinya sendiri, sedangkan rekursif tidak langsung merupakan fungsi yang memanggil fungsi lain dengan cara memanggil fungsi rekursif lain, bukan fungsi itu sendiri. Kekurangan dari rekursif adalah setiap programnya memiliki persyaratan ruang yang lebih besar, dan memiliki persyaratan yang lebih besar juga. Kelebihan dari rekursif adalah rekursi menyediakan cara yang bersih dan sederhaan dalam penulisan kode program, beberapa masalah dianjurkan untuk menggunakan rekursif dalam penyelesaiannya. Alokasi memori untuk rekursif adalah di atas memori yang dialokasikan untuk fungsi pemanggil dan salinan variabel lokal yang berbeda dibuat untuk setiap panggilan fungsi, ketika base case tercapai, fungsi mengembalikan nilainya ke fungsi yang memanggil, dilanjutkan dengan melepas memori dan proses pun berlanjut.



## Referensi

[1] S. H. S. Kom. MT and I. W. J. S. Kom. MCs, Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi, 2020.

[2] A. S. R. St. MTi, STRUKTUR DATA DAN ALGORITMA DENGAN C++. CV. AA. RIZKY, 2019.
 
[3] S. Anam, I. Yanti, Z. Fitriah, and U. Habibah, Cara mudah belajar bahasa pemrograman C++. Universitas Brawijaya Press, 2021.

[4] R. Firliana, R. Rina, dan P. Kasih, "Struktur Data yang Terorganisir," dalam Algoritma dan Pemrograman C++, Adjie Media Nusantara, 2019.

[5]  E. Lutfina, N. Inayati, and G. W. Saraswati, "Analisis Perbandingan Kinerja Metode Rekursif dan Metode Iteratif dalam Algoritma Linear Search", Komputika: Jaringan Sistem Komputer, 2022.

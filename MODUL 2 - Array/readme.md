# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Donna Nur Tamara</p>

## Dasar Teori

Array merupakan struktur data yang paling dasar dalam sebuah bahasa pemrograman. Array dapat mempermudah dalam menyimpan data karena array berisi komponen-komponen yang memiliki tipe data yang sama yang setiap anggota array dapat diakses melalui suatu indeks. Dalam bahasa pemrograman C++, ukuran dan tipe array tidak dapat diubah setelah deklarasinya[1]. Dibawah ini adalah beberapa jenis array yang umum diketahui:

### 1. Array Satu Dimensi
Array satu dimensi atau dapat disebut dengan vektor adalah tipe variabel yang berisi kumpulan data dengan tipe data yang sama dan disusun dalam satu baris atau satu dimensi. Array satu dimensi relatif sederhana untuk dipahami dan digunakan dan biasanya digunakan untuk menyimpan data yang tidak memiliki hubungan spasial, seperti daftar nama atau nilai. 

Elemen dalam array memiliki sebuah indeks yang berguna untuk mengakses elemen tersebut, indeksnya dimulai dari 0 dan berakhir pada jumlah semua elemen dikurangi satu. Array satu dimensi dapat divisualisasikan sebagai garis lurus.

### 2. Array Dua Dimensi
Array dua dimensi atau sering disebut dengan matriks adalah tipe variabel yang berisi kumpulan array satu dimensi dengan tipe data sama dan tersusun dalam bentuk tabel atau matriks, dimana baris dan kolom mewakili dimensi data. Array ini lebih kompleks daripada array satu dimensi, tetapi masih relatif mudah untuk dipahami dan digunakan.  

Array dua dimensi digunakan untuk menyimpan data yang memiliki hubungan spasial, seperti gambar, tabel, atau matriks. Setiap elemen dalam array ini diakses dengan dua indeks, yaitu indeks baris dan indeks kolom. Indeks baris menentukan posisi elemen di baris tertentu, dan indeks kolom menentukan posisi elemen di kolom tertentu[2]. 

### 3. Array Multidimensi
Array multidimensi adalah penggabungan antara array satu dimensi dan dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini dapat memiliki indeks lebih dari dua dimensi dan dapat divisualisasikan sebagai struktur berlapis yang mana setiap dimensi mewakili satu lapisan [3]. 

Array multidimensi digunakan untuk menyimpan data yang memiliki hubungan spasial dan temporal, seperti data simulasi atau data ilmiah. Dapat dideklarasikan dengan lebih dari tiga dimensi, tetapi array dengan lebih dari empat dimensi jarang digunakan.

### 4. Array Empat Dimensi
Array empat dimensi atau biasa disebut tensor adalah tipe variabel yang berisi array dengan empat dimensi saja dan memiliki tipe data yang sama, di mana setiap dimensi mewakili satu tingkatan struktur data serta dapat divisualisaikan sebagai struktur berlapis, di mana setiap dimensi mewakili satu lapisan. Array ini digunakan untuk menyimpan data spasial dan temporal, seperti data fisika atau data astronomi.

### 5. Array Lima Dimensi
Array lima dimensi adalah tipe variabel yang berisi array dengan lima dimensi dan memiliki tipe data yang sama, setiap dimensi mewakili satu tingkatan struktur data, dapat divisualisasikan sebagai struktur berlapis dengan lima tingkatan. 

Array ini memiliki kompleksitas yang sangat tinggi dan membutuhkan memori yang besar juga. Akses dalam array dengan dimensi tinggi seperti pada array ini dapat memakan waktu dan sumber daya. Array ini digunakan untuk menyimpan data spasial, temporal, dan spektral, seperti data citra medis atau data penginderaan jauh.

## Kekurangan dan Kelebihan Array
Berikut beberapa kekurangan dan kelebihan dari array pada bahasa pemrograman C++:

#### Kekurangan Array
  - Ukuran tetap, ukuran array tidak dapat dirubah setelahnya dan harus ditentukan saat pendeklarasian[4].
  - Memori terbuang, jika ada elemen array yang tidak digunakan, maka akan ada memori yang terbuang sia-sia[4].
  - Kompleksitas, mengelola array dengan banyak dimensi bisa menjadi kompleks dan sulit[4].
  - Keamanan memori, akses yang tidak terkontrol ke array dapat menyebabkan error dan crash pada program[4].
    
#### Kelebihan Array
  - Efesiensi memori, array menyimpan data yang bertipe sama secara berdekatan dalam memori, sehingga dapat meningkatkan efesiensi memori[4].
  - Akses data cepat, dalam mengakses elemen array dapat dilakukan dengan cepat karena alamat memori elemen-elemennya berurutan[4].
  - Sederhana, penggunaannya relatif sederhana dan mudah dipahami[4].
  - Fleksibel, array dapat digunakan untuk berbagai keperluan, seperti menyimpan data statistik, data sensor, dan data matriks[4].


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
Kode diatas merupakan kode program untuk menginput serta menampilkan elemen-elemen dalam sebuah array 3 dimensi dengan ukuran 2x3x3 (memiliki 2 blok, setiap blok berisi 3 baris dan 3 kolom). Menggunakan nested loop (loop bersarang) untuk menginputkan dan menampilkan elemen-elemen array dengan mengakses indeks array sesuai dimensinya. 

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
Kode diatas merupakan kode program untuk mencari nilai maksimum beserta lokasi indeksnya pada sebuah array yang telah diinputkan oleh pengguna. 

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

Kode diatas merupakan kode program yang meminta pengguna memasukkan jumlah data yang akan dimasukkan di dalam array dan menampilkan nomor ganjil dan genap pada array yang telah dimasukkan. 

Menggunakan loop `for` untuk menginputkan data sebanyak `n` kali, program akan meminta pengguna untuk memasukkan data ke-i dan menyimpannya di array `data`. Menggunakan loop `for` pada kode di atas juga untuk memisahkan data genap dan ganjil dari array `data` untuk ditampilkan secara terpisah, program akan mengecek setiap elemen pada array, jika genap maka akan ditampilkan dalam bagian `Nomor Genap`, dan jika ganjil maka akan ditampilkan dalam bagian `Nomor Ganjil`. Kemudian program akan mengembalikan nilai 0 yang menandakan bahwa program berjalan dengan sukses.

#### Full code Screenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/134fd3ba-fde5-4586-b3c0-720659a0c5b8">

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
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
```
#### Output:
<img width="278" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/c639471c-8bb7-4944-b0ac-bf5841617904">
<img width="260" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/eb5df816-7769-4077-859e-861e8e1d5ca0">


Kode diatas merupakan kode program yang memungkinkan pengguna untuk memasukkan nilai ke dalam array tiga dimensi yang kemudian ditampilkan nilainya, dengan memanfaatkan konsep array multidimensi. Menggunakan fungsi nested loop untuk mengisi elemen array dengan nilai yang dimasukkan oleh pengguna serta menampilkan nilai beserta indeksnya.

Menampilkan nilai-nilai array tanpa label indeks, hanya array saja. Menggunakan `ends` untuk memisahkan nilai array tanpa spasi tambahan di akhir.

#### Full code Screenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/e3e65c34-bdec-4cf5-b596-c30f05e3485e">

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata–rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>

using namespace std;

int main() {
    const int max_size = 100; // Ukuran maksimum array
    int arr[max_size];
    int a;

    // Input ukuran array dari pengguna
    cout << "Masukkan ukuran array: ";
    cin >> a;

    // Validasi ukuran array
    if (a <= 0 || a > max_size) {
        cout << "Ukuran array tidak valid.\n";
        return 1; // Menghentikan program dengan kode error
    }

    // Input elemen array dari pengguna
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < a; ++i) {
        cout << "Elemen " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Mencari nilai maksimum, minimum, dan rata-rata
    int max = arr[0], min = arr[0], sum = 0;
    for (int i = 0; i < a; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
    }

    // Menghitung nilai rata-rata
    double avg = static_cast<double>(sum) / a;

    // Menampilkan hasil
    cout << "Nilai Maksimum: " << max << endl;
    cout << "Nilai Minimum: " << min << endl;
    cout << "Nilai Rata-rata: " << avg << endl;

    return 0;
}
```
### Output:
<img width="214" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/4df486cb-80a1-4670-b7d0-a86d4e92114e">

Kode diatas merupakan kode program untuk menghitung nilai maksimum, minimum, dan rata-rata dari elemen-elemen array, dengan meminta pengguna memasukkan ukuran array yang di simpan pada variabel `a`. 

Kemudian program melakukan validasi untuk memastikan bahwa ukuran array yang dimasukkan oleh oengguna valid atau tidak, yaitu lebih besar dari 0 dan tidak melebihi `max_size`. Jika ukuran array yang dimasukkan tidak sesuai maka program akan mencetak pesan error dengan mengembalikan nilai 1.

Setelah itu, program meminta pengguna untuk memasukkan elemen-elemen sebanyak `a` kali. Menggunakan loop `for` untuk mengiterasi melalui elemen-elemen dan mencari nilai maksimum(`max`), nilai minimum(`min`), dan menjumlahkan semua elemen(`sum`) untuk menghitung rata-rata(`avg`). Program mengembalikan nilai 0 yang menandakan bahwa program telah berjalan dengan sukses.

### Full code Screenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/25491c83-b91c-4284-ae9e-a8e82a9b5804">

## Kesimpulan
Kesimpulannya, array adalah suatu struktur data yang digunakan untuk menyimpan data dengan cara yang efisien, ukuran dan tipe array tidak dapat diubah setelah deklarasinya serta berisi komponen-komponen yang memiliki tipe data yang sama yang dapat diakses melalui suatu indeks. Ada beberapa jenis array yang diketahui yaitu, array satu dimensi, array dua dimensi, array multidimensi, array empat dimensi, dan array lima dimensi. Array memiliki kekurangan dan kelebihan, kelebihan seperti efifiensi memori, akses data cepat, sederhana, fleksibel, sedangkan kekurangan dari array yaitu ukurannya yang tetap, memori terbuang, kompleksitas, dan keamanan memori.

## Referensi
[1]Putri, M. P. (Ed.). (2022). Algoritma dan Struktur Data. CV WIDINA MEDIA UTAMA.

[2]Siahaan, V., & Sianipar, R. H. (2023). THREE COOKBOOKS IN ONE: Visual C++, Visual Basic, Visual C#. New York, NY: Apress.

[3]Suryana, F., Arsyah, U. I., & Pratiwi, M. (2023). Algoritma dan Pemrograman dengan Bahasa C/C++. (1st ed.). CV MITRA CENDIKIA MEDIA.

[4]Huda, A., Ardi, N., & Muabi, A. (2023). Pengantar coding berbasis C/C++. UNP PRESS.

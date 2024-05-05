# <h1 align="center">Laporan Praktikum Modul Stack</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### Definisi _Stack_
_Stack_ adalah sebuah struktur data sederhana dalam bahasa pemrograman C++ yang digunakan sebagai penyimpanan data. _Stack_ adalah struktur data linier yang mengikuti prinsip _LIFO (Last in First Out)_. Dengan kata lain, kita dapat mengatakan bahwa jika prinsip _LIFO_ diimplementasikan dengan larik maka akan disebut sebagai _stack_ [1]. _Stack_ adalah kumpulan elemen yang hanya dapat ditambah dan atau dihapus dari satu ujung (gerbang) yang sama, seolah-olah bertumpuk [4]. 
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/be64829f-e557-4cbf-b03d-a2866dce1e47)

### Operasi pada _Stack_
Operasi-operasi/fungsi pada _stack_:
- **Push** (Masukkan), digunakan untuk menambah item pada _stack_ pada tumpukan paling atas. Operasi yang memasukkan data ke dalam _stack_. Operasi ini biasa dinyatakan dengan _push_(T,d), dengan T menyatakan _stack_ dan d menyatakan item data yang disisipkan ke dalam _stack_ T [2].
- **Pop** (Keluarkan), digunakan untuk mengambil item pada stack pada tumpukan paling atas [2]. Setiap kali operasi _pop_ dilakukan maka bagian yang paling atas akan berkurang satu, Operasi pop dilakukan jika _stack_ tidak kosong [4].
- **Clear** (Hapus Semua), digunakan untuk mengosongkan _stack_. Operasi ini biasa dinyatakan dengan pop(T). Dalam hal ini data teratas dari _stack_ T akan dikeluarkan dan menjadi nilai balik _pop_. _Pop_ biasanya dituangkan dalam bentuk pernyataan data = pop (T) [2].
- **IsEmpty** (Kosong), fungsi yang digunakan untuk mengecek apakah stack sudah kosong [2]. Jika stack kosong, maka operasi ini akan mengembalikan nilai `True`, dan jika tidak, maka nilai `False` [3].
- **IsFull** (Penuh), fungsi yang digunakan untuk mengecek apakah stack sudah penuh [2]. Jika stack penuh, maka operasi ini akan mengembalikan nilai `True`, dan jika belum, maka nilai `False` [3].
- **Top** (Atas), mendapatkan suatu nilai atau melihat elemen teratas pada tumpukan tanpa menghapusnya.
- **Size** (Ukuran), menghilangkan jumlah elemen yang atau tidak (terutama pada implementasi tumpukan dengan kapasitas terbatas).
- **Peek** (Lihat), memungkinkan pengguna untuk melihat elemen yang terletak di atas stack tanpa menghapusnya. Elemen ini tidak dihapus dan tetap berada di atas _stack_ [3].
- **Search** (Cari), untuk mencari keberadaan suatu elemen dalam sebuah tumpukan.

Operasi _push_ dikenal sebagai operasi _insert_ dan operasi _pop_ dikenal sebagai operasi _delete_. Selama operasi _push_ kita harus memeriksa kondisi _overflow_ dan selama operasi _pop_ kita harus memeriksa kondisi _underflow_ [1]. 
- _Overflow_, jika seseorang dapat mencoba menyisipkan sebuah elemen dengan struktur data (_stack_) yang sudah terisi. 
_Condition_ untuk _overflow_ adalah `Top = size - 1` (untuk stack dimulai dari 0), `Top = size` (untuk stack dimulai dari 1) [1].
- _Underflow_, jika seseorang dapat mencoba menghapus sebuah elemen dari sebuah struktur data (_stack_) kosong. _Condition_ untuk _underflow_ adalah `Top = -1` (untuk stack dimulai dari 0), `Top = 0` (untuk stack dimulai dari 1) [1].



## Guided

```C++
#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }

    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] == "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }

        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }

}

void destroyArrayBuku () {
    for (int i = top; i > 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang 70 dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh?" << isFull() << endl;
    cout << "Apakah data stack kosong?" << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus:" << top << endl;
    cetakArrayBuku();
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/91542043-5141-45d6-89f9-aba0b3a568cb)

Kode di atas adalah kode program yang menggunakan _array_ dari struktur data _stack_, program menyediakan fungsi-fungsi dasar untuk mengelola _stack_ buku, seperti menambahkan, menghapus, melihat, mengubah, dan menghitung buku. 

Pertama, program mendefinisikan _array_ `arrayBuku` untuk menampung 5 judul buku, variabel `maksimal` diset menjadi 5, menunjukkan kapasitas maksimum tumpukan. Lalu, program akan menambahkan buku baru ke tumpukan dengan fungsi `pushArrayBuku(string data)` fungsi akan memeriska tumpukan penuh dengan menggunakan `isFull()`, jika tumpukan penuh, pesan "Data telah penuh" dicetak dan buku baru tidak ditambahkan, jika tumpukan tidak kosong judul buku pada posisi `top - posisi` dicetak. Kemudian, program menghitung jumlah buku dalam tumpukan dengan menggunakan fungsi `countStack()`. Lalu, program mengubah judul buku pada posisi tertentu dalam tumpukan fungsi `changeArrayBuku(int posisi, string data)`. Kemudian, menggunakan fungsi `destroyArrayBuku()` untuk menghapus semua buku dari tumpukan. Lalu, mencetak daftar judul semua buku dalam tumpukan menggunakan fungsi `cetakArrayBuku()`. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/985db3e9-3594-4148-80ec-024ccf8bfbc8)



## Unguided

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program _stack_ adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya. 

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membersihkan string dari karakter selain huruf
string cleanString(const string &kalimat)
{
  string cleaned;
  for (char a : kalimat)
  {
    if (isalpha(a))
    {
      cleaned += tolower(a); // Mengubah huruf menjadi huruf kecil
    }
  }
  return cleaned;
}

bool isPalindrome(const string &kalimat)
{
  stack<char> huruf;

  // Membersihkan kalimat dari karakter selain huruf dan mengubah huruf menjadi huruf kecil
  string cleaned = cleanString(kalimat);

  // Memasukkan huruf ke dalam stack
  for (char a : cleaned)
  {
    huruf.push(a);
  }

  // Membandingkan huruf dari depan dan belakang menggunakan stack
  for (char a : cleaned)
  {
    char hurufStack = huruf.top();
    huruf.pop();
    if (a != hurufStack)
    {
      return false;
    }
  }

  return true; // Jika semua huruf cocok, kalimat merupakan palindrom
}

int main()
{
  string kalimat;
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  if (isPalindrome(kalimat))
  {
    cout << kalimat << " adalah : palindrom." << endl;
  }
  else
  {
    cout << kalimat << " adalah : bukan palindrom." << endl;
  }

  return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/d13b9514-1d71-4acc-a27e-d70ea4620a37)

Kode di atas adalah kode program untuk mengecek apakah kalimat tersebut merupakan kalimat palindrom atau bukan, dengan pengguna memasukkan kalimatnya sendiri. 

Pertama, program akan membersihkan kalimat dari karakter selain huruf dan diubah menjadi huruf kecil semua. Kemudian, program menggunakan _stack_ untuk menyimpan karakter dari kalimat yang sudah dibersihkan, dengan membandingkan karakter dari depan dan belakang kalimat menggunakan _stack_, program dapat menentukan apakah kalimat tersebut merupakan kalimat palindrom atau bukan. 

Program menggunakan fungsi-fungsi seperti, `clearString` yang didalamnya ada `string cleaned` dengan variabel string `cleaned` digunakan untuk menyimpan string yang telah dibersihkan, `if (isalpha(a))` digunakan untuk memeriksa apakah karakter a adalah huruf, `cleaned += tolower(a)` digunakan untuk menambahkan karakter a ke string `cleaned` setelah diubah menjadi huruf kecil menggunakan fungsi `tolower`. fungsi `isPalindrome` didalamnya ada `huruf.push(a)` digunakan untuk menambahkan karakter a ke stack `huruf`, `char hurufStack = huruf.top()` digunakan untuk mengambil karakter teratas dalam stack `huruf` dan menyimpannya di variabel `hurufStack`, `huruf.pop()` digunakan untuk menghapus karakter teratas dari stack `huruf`, `if (a != hurufStack)` digunakan untuk membandingkan karakter a dengan `hurufStack`, jika berbeda, maka kalimat bukan palindrom dan fungsi mengembalikan `false`, jika karakter cocok, maka kalimat merupakan palindrom dan fungsi mengembalikan `true`.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/2d9b8972-14bf-427f-9f14-ebba4fa9e34d)



### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan _stack_ dengan minimal 3 kata. Jelaskan output program yang _source code_-nya beserta operasi/fungsi yang dibuat?

```C++
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  // Deklarasi variabel
  string kalimat;
  stack<char> a;

  // Meminta input kalimat
  cout << "Masukkan Kata ";
  getline(cin, kalimat);

  // Memeriksa apakah kalimat memiliki minimal 3 kata
  if (kalimat.length() < 3)
  {
    cout << "Kalimat harus memiliki minimal 3 kata." << endl;
    return 0;
  }

  // Memasukkan kalimat ke dalam stack
  for (char b : kalimat)
  {
    a.push(b);
  }

  // Membalik kalimat
  kalimat = "";
  while (!a.empty())
  {
    kalimat += a.top();
    a.pop();
  }

  // Menampilkan kalimat yang dibalik
  cout << "Datastack Array : " << endl;
  cout << "Data : " << kalimat << endl;

  return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/90789817-a402-4a47-85f6-dd68811c92ef)

Kode di atas adalah kode program yang dapat membalikkan urutan kata dalam sebuah kalimat dengan minimal kalimat yang dapat diproses adalah 3 kata, dengan meminta pengguna untuk memasukkan sebuah kalimat. 

Pertama, program memeriksa apakah kalimat yang dimasukkan memiliki minimal 3 kata, jika tidak maka program akan menampilkan pesan bahwa kalimat minimal harus memiliki 3 kata dan program akan keluar. Jika kalimat memiliki minimal 3 kata, program akan memasukkan setiap karakter kalimat ke dalam sebuah _stack_. Kemudian, program akan mengambil karakter dari _stack_ satu persatu dan menambahkannya ke _string_ kosong yang baru, lalu membalikan kalimatnya. Terakhir, program akan membalikkan nilai 0 tanda bahwa program telah selesai, dan menampilkan kalimat yang telah di balik ke layar sebagai _output_. 

Program di atas menggunakan fungsi-fungsi seperti `stack<char> a` digunakan untuk membuat _stack_ bernama a yang dapat menampung karakter selama proses pembalikan, `a.push(b)` digunakan untuk memasukkan karakter b yang sedang dibaca ke dalam _stack_ a (proses membangun _stack_ dalam urutan terbalik), `while (!a.empty())` digunakan untuk melakukan perulangan selama _stack_ a tidak kosong, `kalimat += a.top()` digunakan untuk menambahkan karakter teratas dari _stack_ a ke _string_ kalimat, `a.pop()` digunakan untuk menghapus karakter teratas dari _stack_ a. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/2db1dd83-3d52-4dd9-b047-4a57c1b7952c)



## Kesimpulan

Kesimpulannya, _stack_ merupakan kumpulan beberapa elemen yang hanya dapat ditambah dan atau dihapus dari satu ujung (gerbang) yang sama, seolah-olah bertumpuk. Stack mengikuti prinsip _LIFO (Last in First Out)_ yang berarti elemen terakhir masuk akan pertama keluar yang direpresentasikan menggunakan _linked list_ dan _array_ yang disajikan dengan _stack_. Dalam _stack_ ada beberapa operasi yaitu _push_, _pop_, _clear_, _isEmpty_, _isFull_, _top_, _size_, _peek_, dan _search_. Dalam _stack_ ada istilah _overflow_ adalah jika menyisipkan sebuah elemen dengan _stack_ yang sudah terisi, sedangkan _underflow_ adalah jika mencoba menghapus sebuah elemen dari sebuah _stack_ kosong.

## Referensi

[1] S. N. Mohanty and P. K. Tripathy, "Data structure and algorithms using C++: A Practical Implementation". John Wiley & Sons, 2021.

[2] A. S. R. St. MTi, "STRUKTUR DATA DAN ALGORITMA DENGAN C++". CV. AA. RIZKY, 2019.

[3] M. F. Rohmah and R. E. Cahyono, "Teori dan Aplikasi Algoritma Pemrograman dengan Bahasa C dan C++". Penerbit NEM, 2022.

[4] E. Erkamim et al., "Buku Ajar Algoritma dan Struktur Data". PT. Sonpedia Publishing Indonesia, 2024.

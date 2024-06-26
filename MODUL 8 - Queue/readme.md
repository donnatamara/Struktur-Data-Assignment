# <h1 align="center">Laporan Praktikum Modul Queue</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### A. Queue
Queue atau antiran merupakan kumpulan elemen dengan penyisipan dan penghapusan elemen yang dilakukan dari sisi/gerbang yang berbeda. Penyisipan dilakukan dari gerbang belakang (rear) dan penghapusan dilakukan dari gerbang depan (front), sehingga Queue mempunyai sifat FIFO (First In First Out), yaitu elemen yang pertama masuk akan keluar pertama juga [1]. Antrian (Queue) merupakan suatu kumpulan data yang penambahan elemennya (masuk antrian) hanya bisa dilakukan pada suatu ujung (disebut dengan sisi belakang/rear) atau disebut juga enqueue yaitu apabila seseorang masuk ke dalam sebuah antrian, queue merupakan struktur data dinamis [2]. 

Jika seseorang keluar dari antrian/penghapusan (pengambilan elemen) dilakukan lewat ujung yang lain (disebut dengan sisi depan/fornt) atau disebut juga dequeue yaitu apabila seseorang keluar dari antrian. Jadi, dalam antrian menggunakan prinsip "masuk pertama keluar pertama" atau disebut dengan orinsip FIFO (first in first out). Dengan kata lain, urutan keluar akan sama dengan urutan masuknya. Contoh dalam kehidupan sehari-hari adalah antrian mobil saat membeli karcis di pintu jalan tol, antrian di bioskop dan sebagainya [2]. 

![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/7f5a388b-18a5-4d8f-af72-98b33ce35d34)

### B. Operasi-operasi standar pada Queue
- **Insialisasi**, adalah prosedur untuk membuat queue pada kondisi awal, queue yang masih kosong.
- **InQueue atau insert queue**, adalah prosedur untuk memasukkan sebuah elemen baru pada queue, jumlah elemen pada queue akan
  bertambah satu dan elemen tersebut merupakan elemen belakang [2].
- **Dequeue atau delete queue**, adalah prosedur untuk menghapus/mengambil sebuah elemen dari queue, elemen yang diambil adalah
  elemen depan dan jumlah elemen queue akan berkurang satu [2].
  Operasi-operasi yang berhubungan dengan jumlah elemen satu queue adalah:
  - **Size**, adalah operasi untuk mendapatkan banyaknya elemen queue [2].
  - **IsEmpty**, adalah operasi untuk mengetahui apakah queue dalam keadaan kosong atau tidak. Dengan status ini maka dapat
    dicegah dilakukannya operasi Dequeue dari suatu queue yang kosong [2].
  - **IsFull**, adalah operasi untuk mengetahui apakah queue penuh atau tidak. Prosedur ini hanya berlaku untuk queue yang
    jumlahnya terbatas [2].
  - **Front atau peek**, adalah operasi untuk mwngwmbalikan elemen yang paling depan di queue [3].
  - **Rear**, adalah operasi untuk mengembalikan elemen yang paling belakang di   queue [3], namun tidak menghapusnya.  
- **Enqueue** adalah operasi yang menambahkan elemen ke akhir antrian. Operasi dilakukan dengan cara mengecek apakah antrian sudah penuh. Jika tidak, pointer `rear` dinaikkan untuk menunjuk ke ruang kosong berikutnya, dan elemen baru ditambahkan ke antrian di lokasi yang dipoint oleh `rear` [4].

### C. Jenis-jenis Queue
**a. Queue Linear (Implementasi Queue dengan batasan linier)**
   Queue Liniear adalah implementasi Queue menggunakan struktur data linear seperti array atau linked list, yang mana 
   elemen-elemen ditambahkan di ujung belakang (rear) dan dihapus dari ujung depan (front) [5].
   
**b. Queue Circular (Implementasi Queue dengan memanfaatkan siklus)**
   Queue circular adalah implementasi Queue yang menggunakan struktur data linear seperti array dengan pemanfaatan 
   siklus, yang mana elemen-elemen tetap ditambahkan di ujung belakang (rear) dan dihapus dari ujun depan (front), 
   namun jika Queue mencapai batas maksimum, elemen baru akan ditempatkan di awal [5].
   
**c. Priority Queue (Implementasi Queue dengan prioritas pada setiap elemen)**
   Priority Queue adalah implementasi Queue di mana setiap elemen memeiliki prioritas tertentu. Queue jenis ini dapat 
   menggunakan struktur data seperti heap untuk memastikan elemen-elemen tetap terurut secara tepat [5].


## Guided

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/adf94611-c9ac-417b-b5c0-84d16a22d10f)

Kode di atas adalah kode program yang menampilkan antrian teller suatu bank dengan jumlah maksimal 5 orang, pengguna dapat menambahkan nama pelanggan ke antrian dengan fungsi `enqueueAntrian`, menghapus elemen pertama dari antrian menggunakan fungsi `dequeueAntrian()` dan memeriksa status antrian (isFull, isEmpty). Kode ini memungkinkan tampilan isi antrian dengan fungsi `viewQueue`, mengosongkan antrian dengan menggunakan fungsi `clearQueue`, menghitung jumlah elemen dalam antrian menggunakan fungsi `viewQueue`

Pertama, program akan menginisialisasi antrian dengan menggunakan fungsi `maksimalQueue` yang menentukan batas maksimum elemen dalam antrian (maksimal 5) dan mendeklarasikan variabel `front` dan `back` yang menunjukkan indeks depan dan belakang antrian. Kemudian pada fungsi `main()`, program akan menjalankan operasi-operasi tersebut untuk menambahkan data ke antrian, menghapus elemen pertama, menghitung jumlah elemen, mengosongkan antrian, dan menampilkan isi antrian setelah operasi-operasi tersebut dilakukan.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/6a9c2ae3-5985-48ac-8cba-34cc4152565a)



## Unguided

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list 

```C++
#include <iostream>

using namespace std;

struct Mahasiswa
{
    string data;
    Mahasiswa *next;
};

Mahasiswa *front = NULL;
Mahasiswa *back = NULL;

bool isEmpty()
{
    return front == NULL;
}

void enqueueAntrian(string data)
{
    Mahasiswa *newNode = new Mahasiswa;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Mahasiswa *temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue()
{
    int count = 0;
    Mahasiswa *current = front;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeueAntrian();
    }
}

void viewQueue()
{
    cout << "Data antrian teller: " << endl;
    Mahasiswa *current = front;
    int index = 1;
    while (current != NULL)
    {
        cout << index << ". " << current->data << endl;
        current = current->next;
        index++;
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/5e592ab1-5fd8-414b-a8f5-c77bca3ea17b)

Kode di atas merupakan kode program yang menerapkan konsep queue menggunakan linked list. Pertama, program akan mendeklarasikan struct bernama `Mahasiswa` yang memiliki dua atribut yaitu `data` dan `next`. Lalu, program akan mendekalrasikan dua pointer global yaitu `front` dan `back` untuk menandai elemen pertama dan terakhir dalam queue. Kemudian, pada fungsi `isEmpty()` akan mengembalikan nilai boolean `true` jika queue kosong dan `false` jika tidak. Fungsi `enqueueAntrian(string data)` untuk menambahkan elemen baru ke antrian, `dequeueAntrian()` untuk menghapus elemen dari depan antrian, `countQueue()` untuk menghitung jumlah elemen dari antrian, `clearQueue()` untuk mengosongkan antrian, dan `viewQueue()` untuk menampilkan isi pada antrian. 

Lalu, pada fungsi `main()` program akan menjalankan serta menampilkan sesuai instruksi yang telah dimasukkan yaitu menambah beberapa elemen ke antrian dengan fungsi `enqueueAntrian()`, menampilkan isi antrian dengan `viewQueue()` dan mencetak jumlah elemen dengan `countQueue()`, menghapus elemen pertama dari antrian dengan `dequeueAntrian()`, mengosongkan antrian dengan `clearQueue()` dan menampilkan kembali isi antrian serta jumlah elemennya. Program akan mengembalikan nilai 0 yang artinya program telah berjalan dengan sukses. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/14fdbf72-17d3-47fd-9fcf-4857b411db01)




### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>

using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    Mahasiswa *next;
};

Mahasiswa *front = NULL;
Mahasiswa *back = NULL;

bool isEmpty()
{
    return front == NULL;
}

void enqueueAntrian(string nama, string nim)
{
    Mahasiswa *newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Mahasiswa *temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue()
{
    int count = 0;
    Mahasiswa *current = front;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeueAntrian();
    }
}

void viewQueue()
{
    cout << "Data antrian mahasiswa: " << endl;
    Mahasiswa *current = front;
    int index = 1;
    while (current != NULL)
    {
        cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
        index++;
    }
}

int main()
{
    enqueueAntrian("Donna", "2311110014");
    enqueueAntrian("Dundun", "2311110114");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/06f8dc04-58e4-473a-92ac-9e4bef0b574e)

Kode di atas merupakan kode program yang menerapkan konsep queue menggunakan linked list. Seperti kode sebelumnya, hanya saja pada fungsi `main()` ditambahkan beberapa elemen.

Pertama, program akan mendeklarasikan struct bernama `Mahasiswa` yang memiliki dua atribut yaitu `data` dan `next`. Lalu, program akan mendekalrasikan dua pointer global yaitu `front` dan `back` untuk menandai elemen pertama dan terakhir dalam queue. Kemudian, pada fungsi `isEmpty()` akan mengembalikan nilai boolean `true` jika queue kosong dan `false` jika tidak. Fungsi `enqueueAntrian(string data)` untuk menambahkan elemen baru ke antrian, `dequeueAntrian()` untuk menghapus elemen dari depan antrian, `countQueue()` untuk menghitung jumlah elemen dari antrian, `clearQueue()` untuk mengosongkan antrian, dan `viewQueue()` untuk menampilkan isi pada antrian. 

Lalu, pada fungsi `main()` program akan menjalankan serta menampilkan sesuai instruksi yang telah dimasukkan yaitu menambah beberapa elemen ke antrian dengan fungsi `enqueueAntrian()`, menampilkan isi antrian dengan `viewQueue()` dan mencetak jumlah elemen dengan `countQueue()`, menghapus elemen pertama dari antrian dengan `dequeueAntrian()`, mengosongkan antrian dengan `clearQueue()` dan menampilkan kembali isi antrian serta jumlah elemennya. Program akan mengembalikan nilai 0 yang artinya program telah berjalan dengan sukses.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/91ed1b15-a76c-46f7-b14c-4a81ba19c2ae)




## Kesimpulan

Kesimpulannya, queue atau antrian adalah struktur data dinamis berupa kumpulan elemen yang memungkinkan penyisipan dan penghapusan elemen yang dilakukan dari sisi yang berbeda,. Penyisipan elemen dilakukan dari gerbang belakang (rear) dan penghapusan dilakukan dari gerbang depan (front). Karena cara ini, Queue memiliki sifat FIFO (First In First Out), yang berarti elemen yang pertama masuk akan keluar pertama juga. 

Queue memiliki beberapa operasi dasar diantaranya inisialisasi, Inqueue atau insert queue, dequeue atau delete queue, enqueue, size, isEmpty, isFull, front atau peek, dan rear. Queue juga memiliki jenis-jenis yaitu Queue linear adalah queue yang menggunakan struktur data linear seperti array atau linked list, queue circular adalah queue yang menggunakan struktur data linear seperti array dengan pemanfaatan siklus, dan priority queue adalah queue yang setiap elemennya memiliki prioritas tertentu.

## Referensi

[1] E. Erkamim et al., "Buku Ajar Algoritma dan Struktur Data" . PT. Sonpedia Publishing Indonesia, 2024.

[2] A. S. R. St. MTi, "STRUKTUR DATA DAN ALGORITMA DENGAN C++". CV. AA. RIZKY, 2019.

[3] J. Carey, S. Doshi, and P. Rajan, C++ Data structures and algorithm design principles: Leverage the power of modern C++ to build robust and scalable applications. Packt Publishing Ltd, 2019.

[4] S. N. Mohanty and P. K. Tripathy, Data structure and algorithms using C++: A Practical Implementation. John Wiley & Sons, 2021.

[5] R. Pratama, “Queue: Pengenalan, Implementasi, Operasi Dasar, dan Aplikasi,” Medium, May 24, 2023. [Online]. Available: https://medium.com/@furatamarizuki/queue-pengenalan-implementasi-operasi-dasar-dan-aplikasi-c5eed7e871a3

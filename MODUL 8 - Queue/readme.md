# <h1 align="center">Laporan Praktikum Modul Queue</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### 1. Queue
Queue atau antiran merupakan kumpulan elemen dengan penyisipan dan penghapusan elemen yang dilakukan dari sisi/gerbang yang berbeda. Penyisipan dilakukan dari gerbang belakang dan penghapusan dilakukan dari gerbang depan, sehingga Queue mempunyai sifat FIFO (First In First Out), yaitu elemen yang pertama masuk akan keluar pertama juga [1].

![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/7f5a388b-18a5-4d8f-af72-98b33ce35d34)







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

struct Node {
    string data;
    Node* next;
};

Node* front = NULL;
Node* back = NULL;

bool isEmpty() {
    return front == NULL;
}

void enqueueAntrian(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    Node* current = front;
    int index = 1;
    while (current != NULL) {
        cout << index << ". " << current->data << endl;
        current = current->next;
        index++;
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
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/5e592ab1-5fd8-414b-a8f5-c77bca3ea17b)

Kode di atas merupakan kode program yang menerapkan konsep queue menggunakan linked list. Pertama, program akan mendeklarasikan struct bernama `Node` yang memiliki dua atribut yaitu `data` dan `next`. Lalu, program akan mendekalrasikan dua pointer global yaitu `front` dan `back` untuk menandai elemen pertama dan terakhir dalam queue. Kemudian, pada fungsi `isEmpty()` akan mengembalikan nilai boolean `true` jika queue kosong dan `false` jika tidak. Fungsi `enqueueAntrian(string data)` untuk menambahkan elemen baru ke antrian, `dequeueAntrian()` untuk menghapus elemen dari depan antrian, `countQueue()` untuk menghitung jumlah elemen dari antrian, `clearQueue()` untuk mengosongkan antrian, dan `viewQueue()` untuk menampilkan isi pada antrian. 

Lalu, pada fungsi `main()` program akan menjalankan serta menampilkan sesuai instruksi yang telah dimasukkan yaitu menambah beberapa elemen ke antrian dengan fungsi `enqueueAntrian()`, menampilkan isi antrian dengan `viewQueue()` dan mencetak jumlah elemen dengan `countQueue()`, menghapus elemen pertama dari antrian dengan `dequeueAntrian()`, mengosongkan antrian dengan `clearQueue()` dan menampilkan kembali isi antrian serta jumlah elemennya. Program akan mengembalikan nilai 0 yang artinya program telah berjalan dengan sukses. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/bb0f21b9-f226-4b4f-b504-a64aa7283cbe)




### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

Mahasiswa* front = NULL;
Mahasiswa* back = NULL;

bool isEmpty() {
    return front == NULL;
}

void enqueueAntrian(string nama, string nim) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Mahasiswa* current = front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian();
    }
}

void viewQueue() {
    cout << "Data antrian mahasiswa: " << endl;
    Mahasiswa* current = front;
    int index = 1;
    while (current != NULL) {
        cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
        index++;
    }
}

int main() {
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
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/fdd76972-2692-4b7d-9e2e-513c8415b246)





## Kesimpulan

Kesimpulannya, queue adalah 

## Referensi

[1] E. Erkamim et al., "Buku Ajar Algoritma dan Struktur Data" . PT. Sonpedia Publishing Indonesia, 2024.

[2]

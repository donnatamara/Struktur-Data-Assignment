# <h1 align="center">Laporan Praktikum Modul Stack</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### 1. Stack
Stack adalah sebuah struktur data sederhana dalam bahasa pemrograman C++ yang digunakan sebagai penyimpanan data. Stack adalah struktur data linier yang mengikuti prinsip LIFO (Last in First Out). Dengan kata lain, kita dapat mengatakan bahwa jika prinsip LIFO diimplementasikan dengan larik maka akan disebut sebagai stack [1]. 
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/be64829f-e557-4cbf-b03d-a2866dce1e47)

Operasi-operasi/fungsi pada stack:
- Push, digunakan untuk menambah item pada stack pada tumpukan paling atas [2].
- Pop, digunakan untuk mengambill item pada stack pada tumpukan paling atas [2].
- Clear, digunakan untuk mengosongkan stack [2].
- IsEmpty, fungsi yang digunakan untuk mengecek apakah stack sudah kosong [2].
- IsFull, fungsi yang digunakan untuk mengecek apakah stack sudah penuh [2].
- 

Operasi dasar pada stack adalah push dan pop.
- Push adalah operasi yang memasukkan data ke dalam stack. Operasi ini biasa dinyatakan dengan oush(T,d), dengan T menyatakan stack dan d menyatakan item data yang disisipkan ke dalam stack T [2].
- Pop adalah operasi untuk mengambil data dari stack. Operasi ini biasa dinyatakan dengan pop(T). Dalam hal ini data teratas dari stack T akan dikeluarkan dan menjadi nilai balik pop. Pop biasanya dituangkan dalam bentuk pernyataan : data = pop (T) [2].

Operasi push dikenal sebagai operasi insert dan operasi pop dikenal sebagai operasi delete. Selama operasi push kita harus memeriksa kondisi overflow dan selama operasi pop kita harus memeriksa kondisi underflow [1]. 

- Overflow, jika seseorang dapat mencoba menyisipkan sebuah elemen dengan struktur data (stack) yang sudah terisi, maka situasi tersebut akan disebut sebagai overflow. Condition untuk overflow adalah Top = size - 1 (untuk stack dimulai dari 0), Top = size (untuk stack dimulai dari 1) [1].
- Underflow, jika seseorang dapat mencoba menghapus sebuah elemen dari sebuah struktur data (stack) kosong maka situasi tersebut akan disebut sebagai underflow. Condition untuk underflow adalah Top = -1 (untuk stack dimulai dari 0), Top = 0 (untuk stack dimulai dari 1) [2].


## Guided

### 1. 

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



#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/985db3e9-3594-4148-80ec-024ccf8bfbc8)



## Unguided

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya. 

```C++

```

#### Output:


#### Full code Screenshot:




### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program yang source codenya beserta operasi/fungsi yang dibuat?

```C++

```

#### Output:


#### Full code Screenshot:




## Kesimpulan

Kesimpulannya, 

## Referensi

[1] S. N. Mohanty and P. K. Tripathy, Data structure and algorithms using C++: A Practical Implementation. John Wiley & Sons, 2021.
[2] A. S. R. St. MTi, STRUKTUR DATA DAN ALGORITMA DENGAN C++. CV. AA. RIZKY, 2019.

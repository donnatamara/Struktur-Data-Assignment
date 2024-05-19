# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### Definisi Priority Queue

### Definisi Heaps




## Guided

```C++
 #include <iostream>
 #include <algorithm>

 int H[50];
 int heapSize = -1;

 int parent(int i) {
    return (i - 1) / 2;
 }

 int leftChild(int i) {
    return ((2 * i) + 1);
 }

 int rightChild(int i) {
    return ((2 * i) + 2);
 }

 void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
 }

 void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
 }

 void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
 }

 int extracMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
 }

 void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
 }

 int getMax() {
    return H[0];
 }

 void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extracMax();
 }

 int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extracMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
 }
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/7e2eda98-b3cb-41e4-b5be-8e8dbf4a28f0)z

Kode di atas adalah kode program menggunakan heap maksimum dengan menggunakan array statis. Pertama, program menginisialisasi heap `H[50]` yang merupakan array statis dengan kapasitas 50 elemen untuk menyimpan sebuah heap dengan variabel `heapSize` untuk melacak jumlah elemennya. Lalu, program akan menghitung indeks elemen dengan menggunakan fungsi `parent`, `leftChild`, dan `rightChild`. Kemudian, program akan memperbaiki heap dengan memindahkan elemen ke atas atau ke bawah sesuai kebutuhan dengan menggunakan fungsi `shiftUp` dan `shiftDown`. Operasi `insert` digunakan untuk menambah elemen baru ke dalam heap dan memperbaiki posisinya menggunakan fungsi `siftUp`. Fungsi `extractMax` untuk menghapus dan mengembalikan elemen maksimum dari heap, fungsi `changePriority` untuk mengubah prioritas elemen dan memperbaikinya dengan menggunakan fungsi `shiftUp` atau `shiftDown`. Lalu ada fungsi `getMax` yang dapat mengembalikan elemen maksimum tanpa menghapusnya, dan `remove` untuk menghapus elemen di indeks tertentu dengan mengatur nilai elemen tersebut lebih besar dari elemen di indeks tertentu dengan mengatur nilai elemen tersebut lebih besar dari elemen maksimum saat ini, lalu menghapusnya dengan `extractMax`.

Dalam fungsi `main`, program menambahkan beberapa elemen ke dalam heap menggunakan fungsi `insert`, lalu mengambil dan mencetak elemen maksimum dari heap menggunakan `extractMax`, mencetak isi heap setelah penghapusan elemen maksimum, mengubah prioritas elemen di indeks 2 menjadi 49 menggunakan `changePriority` dan heap diperbaiki, mencetak isi heap setelah perubahan prioritas, menghapus elemen di indeks 3 menggunakan `remove`, elemen di indeks 3 dihapus dan heap diperbaiki. Program akan mengembalikan nilai 0 yang artinya program telah selesai berjalan.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/d9a5cbcc-1cc4-4877-ac13-264f913c49f7)



## Unguided

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user

```C++

```

#### Output:


#### Full code Screenshot:




## Kesimpulan

Kesimpulannya, 

## Referensi

[1] 

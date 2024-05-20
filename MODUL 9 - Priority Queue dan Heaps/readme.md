# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### Priority Queue
Priority Queue adalah struktur data yang memungkinkan untuk menyimpan elemen-elemen dengan prioritas yang berbeda-beda. Elemen dengan prioritas yang lebih tinggi akan diproses terlebih dahulu dengan prioritas yang lebih tinggi akan diproses terlebih dahulu dibandingkan elemen dengan prioritas yang lebih rendah. Prinsip utama dari priority queue adalah "first in, highest priority out". 

Priority Queue adalah struktur data dasar yang terdiri dari satu set pasangan key-value di mana kunci menunjukkan prioritas (berdasarkan konvensi, kunci yang lebih kecil menunjukkan prioritas yang lebih tinggi. Struktur data ini banyak digunakan dalam algoritma, mulai dari aplikasi tingkat tinggi hingga kernel sistem tingkat rendah. Implementasi yang efisien dalam lingkungan multithreaded sangat penting untuk sistem multi-core modern dan masa depan. [1]. Ada beberapa cara untuk mengimplementasikan priority queue, termasuk menggunakan array, linked list, heap, atau binary serach tree. Priority queue sering digunakan dalam sistem real-time, di mana urutan pemrosesan elemen dapat memiliki konsekuensi yang signifikan.

Sebuah priority queue hanya mengimplementasikan dua operasi yaitu insert untuk menambahkan item dengan prioritas terkait ke dalam antrean, dan DeleteMin yang digunakan untuk menghapus item dengan prioritas tertinggi dari antrean [2]. Priority queue menawarkan pencarian waktu konstan dari elemen dengan prioritas tertinggi. Prioritas ditentukan dengan menggunakan operator kurang dari daripada elemen. Menyisipkan dan menghapus keduanya berjalan dalam waktu logaritmik[3].

### Heaps
Heap dalam struktur data adalah sebuah binary tree lengkap yang memenuhi properti heap, di mana setiap simpul yang diberikan adalah selalu lebih besar dari simpul-simpul turunannya dan kunci dari simpul akar adalah yang tersebar di antara simpul-simpul lainnya. Properti ini juga disebut properti heap maksimal. Dimana setiap simpul yang diberikan selalu lebih kecil dari simpul-simpul anaknya dan kunci dari simpul akar adalah yang terkecil di antara simpul-simpul lainnya. Properti ini juga disebut properti min heap [4].

Secara umum, pengertian dari heap adalah bagian dari memori yang terorganisasi untuk dapat melayani alokasi memori secara dinamis. Suatu heap tree adalah Complete Binary Tree (CBT) di mana harga-harga key pada node-nodenya sedemikian rupa sehingga harga-harga key pada node-node anaknya tidak ada yang lebih besar dari harga key pada node orang tuanya [5].

![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/ddced6d8-0619-478e-a90a-c3f708edb466)

Heap dibagi menjadi dua jenis yaitu:
- Heap maksimum (maxHeap) yaitu nilai di setiap node harus lebih besar (atau sama dengan) nilai di semua node di subtree kirinya, dan lebih kecil (atau sama dengan) nilai di semua node di subtree kanannya.
- Heap minimum (minHeap) yaitu nilai di setiap node harus lebih kecil (atau sama dengan) nilai di semua node di subtree kirinya, dan lebih besar (atau sama dengan) nilai di semua node di subtree kanannya. 

Operasi-operasi pada struktur data heap:
- Heapify, proses untuk mengatur ulang heap untuk mempertahankan properti heap [6].
- Find-max (atau Find-min), menemukan item maksimum dari max-heap, atau item minimum dari min-heap [6].
- Insertion, menambahkan item baru di heap [6].
- Deletion, menghapus item dari heap [6].
- Extract Min-Max, mengembalikan dan mengahpus elemen maksimum atau minimum masing-masing di max-heap dan min-heap [6].



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
#include <iostream>
#include <algorithm>

using namespace std;

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
        swap(H[parent(i)], H[i]);
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
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
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
    extractMax();
}

int main() {
    int a;
    cout << "Enter the number of elements in the heap : ";
    cin >> a;

    cout << "Enter the elements of the heap : ";
    for (int i = 0; i < a; ++i) {
        int element;
        cin >> element;
        insert(element);
    }

    cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority : " << extractMax() << "\n";

    cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    changePriority(2, 49);
    cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    remove(3);
    cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/c0f22aa6-26a0-4c93-8298-8ace03f32cdc)

Kode di atas adalah kode program yang menggunakan data max heap atau priority queue dengan menggunakan array. Pertama, program akan mendefinisikan array `H` dan variabel `heapSize` untuk menyimpan elemen-elemen heap dan jumlah elemen dalam heap. Selanjutnya, program memiliki fungsi-fungsi seperti `parent`, `leftChild`, dan `rightChild` untuk menentukan indeks parent, left child, dan right child dari suatu node dalam heap. Fungsi `shiftUp` dan `shiftDown` digunakan unruk mempertahankan properti heap setelah operasi-operasi seperti penambahan, penghapusan, atau perubahan prioritas elemen. 

Program di atas juga memiliki operasi-operasi dasar seperti `insert` untuk menambahkan elemen, `extractMax` untuk mengeluarkan elemen maksimum, `changePriority` untuk mengubah prioritas elemen, `getMax` untuk mendapatkan elemen maksimum tanpa mengeluarkannya, dan `remove` untuk menghapus elemen. Pada fungsi `main`, program meminta input pengguna dengan sejumlah elemen dan isi elemen-elemennya yang akan dimasukkan ke dalam heap, lalu menampilkan heap setelah setiap operasi seperti mengeluarkan elemen maksimum, mengubah prioritas elemen pada indeks 2 menjadi 49, serta menghapus elemen pada indeks 3. Kemudian, program akan mengembalikan nilai 0 tanda bahwa program telah sukses berjalan.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/92c16df6-8042-4166-aeaa-e8af2c933e74)



## Kesimpulan

Kesimpulannya, priority queue adalah struktur data yang memungkinkan untuk menyimpan elemen-elemen dengan prioritas tertentu, dengan prioritas yang lebih tinggi diproses terlebih dahulu dibandingkan dengan elemen yang lebih rendah. Ada beberapa cara untuk mengimplementasikan priority queue, termasuk menggunakan array, linked list, heap, atau binary serach tree. Heap adalah struktur data binary tree lengkap yang memenuhi properti heap, di mana setiap simpul yang diberikan selalu lebih besar dari simpul-simpul lainnya. Heap dibagi menjadi dua yaitu heap maksimum dan heap minimum. Ada beberapa operasi pada heap heapify, find-max, insertion, deletion, dan extract min-max.



## Referensi

[1] Goponenko, A., & Carroll, S. "A C++ implementation of a lock-free priority queue based on Multi-Dimensional Linked List". Link: https://www.researchgate.net/publication/337020321_A_C_Implementation_of_a_Lock-Free_Priority_Queue_Based_on_Multi-Dimensional_Linked_List. 2019.

[2] Carroll, S., & Goponenko, A. "A C++ implementation of a threadsafe priority queue based on multi-dimensional linked lists and MRLock". 2019.

[3] B. Andrist, V. Sehr, and B. Garney, "C++ High performance: Master the art of optimizing the functioning of your C++ code". Packt Publishing Ltd, 2020.

[4] Programiz. (n.d.). "Heap Data Structure". https://www.programiz.com/dsa/heap-data-structure. Diakses tanggal 20 Mei 2024.

[5]	E. Chalikdjen, H. Ong, dan S. P. Sajuthi, “Heap Tree dan Kegunaannya dalam Heap Sort.” 

[6] GeeksforGeeks, “Heap Sort Data Structures and Algorithms tutorials,” GeeksforGeeks, Mar. 29, 2024. https://www.geeksforgeeks.org/heap-sort/

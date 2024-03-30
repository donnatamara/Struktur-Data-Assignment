# <h1 align="center">Laporan Praktikum Modul Sorting</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori
### Konsep Dasar Sorting
Algoritma sorting merupakan algoritma yang digunakan untuk meletakkan elemen-elemen data ke dalam urutan tertentu, berdasarkan satu atau beberapa kunci pada tiap elemennya.
- Ascending adalah sistem pengurutan dari yang terkecil hingga yang terbesar. Contohnya 1, 2, 3, 4, 5, 6.
- Descending adalah sistem pengurutan dari yang terbesar hingga terkecil. Contohnya 6,5,4,3,2,1. 

## Insertion Sort
### Konsep Dasar Algoritma Insertion Sort
Insertion Sort merupakan cara pengurutan dengan pengecekan satu persatu dimulai dari elemen kedua sampai dengan elemen terakhir. Jika ditemukan data yang lebih kecil dari data sebelumnya, maka data tersebut ditempatkan pada posisi yang sesuai. 

### Pseudocode Algoritma Insertion Sort

```C++
for i = to n-1
        set j = i
        set t = a[j]
        repeat while j > 0 and a[j-1] > t
                move a [j-1] to right
        end repeat
        set a[j] = t
end for
```

## Bubble Sort
### Konsep Dasar Algoritma Bubble Sort
Bubble sort merupakan cara pengurutan dengan cara membandingkan satu elemen dengan elemen berikutnya. Jika elemen sekarang lebih besar dari elemen berikutnya maka harus ditukar.

### Pseudocode Algoritma Bubble Sort

```C++

```

## Selection Sort
### Konsep Dasar Algoritma Selection Sort
Selection Sort merupakan cara pengurutan dengan cara membandingkan elemen sekarang dengan elemen berikutnya hingga elemen terakhir. Jika ditemukan elemen paling kecil lalu akan ditukar dengan elemen sekarang.

### Pseudocode Algoritma Selection Sort
```C++

```


## Guided
### 1. Mengurutkan secara *ascending* untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>

using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of it
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};
    
    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```

#### Output:


### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>

using namespace std;

void insertion_sort(char arr[],  int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;
        while ((j > 0) && (arr[j] < arr[j - 1])) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }// end of while loop
    }// end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 6;
    char a [length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```

#### Output:

## Unguided

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort

```C++

```

#### Output:


### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++

```

#### Output:


### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! 
![alt text](image.png)

```C++

```

#### Output:


## Kesimpulan

Kesimpulannya, algortima sorting adalah cara pengurutan yang ada pada bahasa pemrograman. Ada beberapa jenis sorting, yaitu bubble sort, selection sort, dan insertion sort. Bubble sort adalah pengurutan dengan. Selection sort adalah pengurutan dengan. Selection sort adalah pengurutan dengan.

## Referensi

[1] 

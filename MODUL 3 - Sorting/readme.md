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
<img width="216" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/5b384e98-4e03-4aa3-9bb7-3aa02f8c4c85">



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
<img width="249" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/f321d36d-038b-48d3-af4d-c74892bfd0d7">


## Unguided

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort

```C++
#include <iostream>

using namespace std;

void selectionSort(double arr[], int a)
{
    for (int i = 0; i < a - 1; ++i)
    {
        int max = i;
        for (int j = i + 1; j < a; ++j)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }

        double temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int main()
{
    const int a = 5;
    double IPS[a] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS sebelum diurutkan:" << endl;
    for (int i = 0; i < a - 1; ++i)
    {
        cout << IPS[i] << ", ";
    }
    cout << IPS[a - 1] << endl;

    selectionSort(IPS, a);

    cout << "IPS setelah diurutkan secara descending:" << endl;
    for (int i = 0; i < a - 1; ++i)
    {
        cout << IPS[i] << ", "; /* code */
    }
    cout << IPS[a - 1] << endl;
    return 0;
}
```

#### Output:
<img width="246" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/2d4b6e2d-2938-42b4-9f0d-f64fa677f9e5">

Kode diatas merupakan program dengan algoritma pengurutan selection sort secara descending dengan array yang berisi bilangan desimal floating-point ganda. Looping luar berguna untuk pengurutan bertahap, jumlah iterasi adalah `a-1` karena elemen paling akhir sudah dianggap posisi akhir setelah iterasi sebelumnya. Looping dalam berguna untuk menemukan elemen maksimum dengan memeriksa apakah elemen `arr[j]` lebih besar daripada elemen pada indeks `maks`. Jika benar maka elemen yang lebih besar telah ditemukan, jadi `maks` diperbarui untuk menyimpan indeks `j` dari elemen yang lebih besar.

Setelah loop dalam selesai dijalankan, `maks` akan menyimpan indeks elemen terbesar di antara yang tersisa yang berguna untuk menukar elemen pada indeks `i` saat ini dengan elemen pada indeks `maks`.

#### Full code Screenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/009fec00-eb12-41c3-bfe3-9ffa935dbe77">



### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
using namespace std;

void bubble_sort(char arr[][10], int length)
{
    bool not_sorted = true;
    int j = 0;
    char tmp;

    while (not_sorted)
    {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++)
        {
            bool tukar = false;
            for (int k = 0; k < 10; k++)
            {
                if (arr[i][k] > arr[i + 1][k])
                {
                    tukar = true;
                    break;
                }
                else if (arr[i][k] < arr[i + 1][k])
                {
                    break;
                }
            }
            if (tukar)
            {
                // Menukar elemen
                char temp[10];
                for (int k = 0; k < 10; k++)
                {
                    temp[k] = arr[i][k];
                }
                for (int k = 0; k < 10; k++)
                {
                    arr[i][k] = arr[i + 1][k];
                }
                for (int k = 0; k < 10; k++)
                {
                    arr[i + 1][k] = temp[k];
                }
                not_sorted = true;
            } // end of it
        }     // end of for loop
    }         // end of while loop
} // end of bubble_sort
// Print array
void print_array(char a[][10], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{

    int length = 10;
    char nama_warga[][10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Urutan nama sebelum sorting: " << endl;
    print_array(nama_warga, length);

    bubble_sort(nama_warga, length);

    cout << "\nUrutan nama setelah sorting: " << endl;
    print_array(nama_warga, length);

    return 0;
}
```

#### Output:
<img width="300" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/e03b13a5-46c2-42e6-ab1f-d1454299cbd7">

Kode diatas merupakan program pengurutan dengan menggunakan bubble sort untuk mengurutkan array yang berisi nama orang. Array tersebut berupa array dua dimenensi dengan panjang array adalah `lenght`. Varibael `not_sorted` bertipe boolean digunakan untuk mengecek apakah array tersebut sudah terurut atau belum. Kemudian dicek apakah ada elemen yang perlu ditukar, jika ada maka lakukan penukaran dengan menggunakan variabel `temp` untuk menyimpan sementara. Program terus berjalan sampai terurut semuanya, cetak isi array, dan `return 0` menandakan bahwa program telah berjalan dengan sukses.

#### Full code Screenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/919b610c-f720-4733-a0fb-d5584801a507">



### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! 
<img width="199" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/285ba52f-d4d5-45a9-834e-3aaf0ca5e78c">

```C++
#include <iostream>
using namespace std;

void bubbleSort(char arr[], int a)
{
  int i, j;
  for (i = 0; i < a - 1; i++)
  {
    for (j = 0; j < a - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        char temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int a;
  cout << "input <n> = ";
  cin >> a;

  char karakter[a];

  // Meminta user untuk menginputkan karakter
  for (int i = 0; i < a; i++)
  {
    cout << "Karakter ke-" << i + 1 << ": ";
    cin >> karakter[i];
  }

  // Menampilkan karakter sebelum sorting
  cout << "\nUrutan karakter sebelum sorting:\n";
  for (int i = 0; i < a; i++)
  {
    cout << karakter[i] << " ";
  }

  // Sorting secara ascending dengan bubble sort
  bubbleSort(karakter, a);

  // Menampilkan karakter setelah ascending sort
  cout << "\n\nUrutan karakter setelah ascending sort:\n";
  for (int i = 0; i < a; i++)
  {
    cout << karakter[i] << " ";
  }

  // Sorting descending dengan bubble sort
  for (int i = 0; i < a / 2; i++)
  {
    char temp = karakter[i];
    karakter[i] = karakter[a - i - 1];
    karakter[a - i - 1] = temp;
  }

  // Menampilkan karakter setelah descending sort
  cout << "\n\nUrutan karakter setelah descending sort:\n";
  for (int i = 0; i < a; i++)
  {
    cout << karakter[i] << " ";
  }

  cout << endl;

  return 0;
}
```

#### Output:
<img width="248" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/a0ec03c5-afbf-4109-8073-270bb34f75bc">

Kode diatas merupakan kode program yang memungkinkan pengguna untuk memasukkan sejumlah n yang akan dirutkan secara ascending dan descending. 

Kodingan diatas 

### Full code Sreenshot:
<img width="960" alt="image" src="https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/40026f18-9bae-42de-9274-b8d544c1b8ad">




## Kesimpulan

Kesimpulannya, algortima sorting adalah cara pengurutan yang ada pada bahasa pemrograman. Ada beberapa jenis sorting, yaitu bubble sort, selection sort, dan insertion sort. Bubble sort adalah pengurutan dengan. Selection sort adalah pengurutan dengan. Selection sort adalah pengurutan dengan.

## Referensi

[1] 

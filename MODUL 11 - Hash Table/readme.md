# <h1 align="center">Laporan Praktikum Modul Hash Table </h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori


merepresentasikan setiap nilai dengan sebuah kunci yang mungkin unik dan, kemudian, menggunakan kunci yang sama untuk memeriksa keberadaan kunci tersebut atau untuk mengambil nilai yang sesuai, tergantung pada kasus penggunaannya. Fungsi yang mendapatkan kunci unik dari data yang diberikan disebut fungsi hash. Mari kita ambil satu contoh sederhana sebelum masuk ke dalam hashing. Katakanlah kita memiliki sebuah penampung yang menyimpan bilangan bulat, dan kita ingin mengetahui apakah sebuah bilangan bulat tertentu merupakan bagian dari penampung tersebut atau bukan secepat mungkin. Cara yang paling sederhana adalah dengan memiliki larik Boolean dengan setiap bit mewakili nilai yang sama dengan indeksnya. Ketika kita ingin menyisipkan sebuah elemen, kita akan mengatur nilai Boolean yang berhubungan dengan elemen tersebut menjadi 0. Untuk menyisipkan x, kita cukup mengatur data[x] = true. Memeriksa apakah sebuah bilangan bulat tertentu, x, ada di dalam penampung juga sama sederhananya - kita cukup memeriksa apakah data[x] bernilai benar [1]. Dengan demikian, fungsi penyisipan, penghapusan, dan pencarian menjadi O(1). Sebuah tabel hash sederhana untuk menyimpan bilangan-bilangan bulat bernomor dari 0 sampai 9 akan terlihat sebagai berikut: 



Tabel hash dibangun dari dua ide dasar: mengurangi kunci aplikasi menjadi kunci hash, sebuah angka dalam rentang dari 0 sampai N - 1, dan memetakan angka tersebut ke dalam rentang yang lebih kecil dari 0 hingga m - 1, m” N. Kita dapat menggunakan rentang kecil tersebut untuk mengindeks ke dalam larik dengan akses waktu yang tetap. Kedua ide ini sederhana, tetapi bagaimana mereka diimplementasikan dalam prakteknya mempengaruhi efisiensi tabel hash [2].

Tabel hash menyimpan elemen-elemennya dalam semacam larik ember. Ketika menambahkan sebuah elemen ke tabel hash, sebuah bilangan bulat dihitung untuk elemen tersebut menggunakan fungsi hash. Containers menggunakan hash table untuk menyimpan elemen-elemennya. Tabel ini mengharuskan elemen-elemennya dibandingkan dengan operator (==) dan ada cara untuk menghitung nilai hash berdasarkan elemen[3]. Setiap kunci dan setiap nilai dari tabel hash masing-masing adalah kumpulan fitur dan kumpulan contoh objek dalam kelompok maksimal [5]. 

### 



## Guided 
### 1. Guided 1

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```

#### Output:


#### Full code Screenshot:



### Guided 2

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}

```

#### Output:


#### Full code Screenshot:



## Unguided

### 1.	Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : 
a.	Setiap mahasiswa memiliki NIM dan nilai. 
b.	Program memiliki tampilan pilihan menu berisi poin C.
c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).


```C++

```

#### Output:


#### Full code Screenshot:



## Kesimpulan

Kesimpulannya, 



## Referensi

[1] J. Carey, S. Doshi, and P. Rajan, C++ Data structures and algorithm design principles: Leverage the power of modern C++ to build robust and scalable applications. Packt Publishing Ltd, 2019.

[2] T. Mailund, The Joys of Hashing: Hash Table Programming with C. Apress, 2019.

[3] B. Andrist, V. Sehr, and B. Garney, C++ High performance: Master the art of optimizing the functioning of your C++ code. Packt Publishing Ltd, 2020.

[4] V. Tran, L. Wang, H. Chen, and Q. Xiao, “MCHT: A maximal clique and hash table-based maximal prevalent co-location pattern mining algorithm,” Expert Systems With Applications, vol. 175, p. 114830, Aug. 2021, doi: 10.1016/j.eswa.2021.114830.
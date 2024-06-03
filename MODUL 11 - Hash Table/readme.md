# <h1 align="center">Laporan Praktikum Modul Hash Table </h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

Hash table adalah struktur data yang digunakan untuk menyimpan dan mengambil data menggunakan kunci unik. Fungsi hash mengambil kunci sebagai input dan menghasilkan indeks yang sesuai dengan array. Setiap kunci dan setiap nilai dari tabel hash masing-masing adalah kumpulan fitur dan kumpulan contoh objek dalam kelompok maksimal [1]. 

Hash table juga dapat diartikan sebagai fungsi yang merepresentasikan setiap nilai dengan sebuah kunci yang mungkin unik dan, kemudian, menggunakan kunci yang sama untuk memeriksa keberadaan kunci tersebut atau untuk mengambil nilai yang sesuai, tergantung pada kasus penggunaannya. Hash table adalah Fungsi yang mendapatkan kunci unik dari data yang diberikan[2]. 

Mari kita ambil satu contoh sederhana sebelum masuk ke dalam hashing. Katakanlah kita memiliki sebuah penampung yang menyimpan bilangan bulat, dan kita ingin mengetahui apakah sebuah bilangan bulat tertentu merupakan bagian dari penampung tersebut atau bukan secepat mungkin. Cara yang paling sederhana adalah dengan memiliki larik Boolean dengan setiap bit mewakili nilai yang sama dengan indeksnya. 

Ketika kita ingin menyisipkan sebuah elemen, kita akan mengatur nilai Boolean yang berhubungan dengan elemen tersebut menjadi 0. Untuk menyisipkan x, kita cukup mengatur data[x] = true. Memeriksa apakah sebuah bilangan bulat tertentu, x, ada di dalam penampung juga sama sederhananya - kita cukup memeriksa apakah data[x] bernilai benar [2]. Dengan demikian, fungsi penyisipan, penghapusan, dan pencarian menjadi O(1). Sebuah tabel hash sederhana untuk menyimpan bilangan-bilangan bulat bernomor dari 0 sampai 9 akan terlihat sebagai berikut: 

![Screenshot 2024-06-03 214503](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/91af5fda-db02-4786-b6f6-bd6a4acb1071)

Tabel hash dibangun dari dua ide dasar: mengurangi kunci aplikasi menjadi kunci hash, sebuah angka dalam rentang dari 0 sampai N - 1, dan memetakan angka tersebut ke dalam rentang yang lebih kecil dari 0 hingga m - 1, m” N. Kita dapat menggunakan rentang kecil tersebut untuk mengindeks ke dalam larik dengan akses waktu yang tetap. Kedua ide ini sederhana, tetapi bagaimana mereka diimplementasikan dalam prakteknya mempengaruhi efisiensi tabel hash [3].

Tabel hash menyimpan elemen-elemennya dalam semacam larik ember. Ketika menambahkan sebuah elemen ke tabel hash, sebuah bilangan bulat dihitung untuk elemen tersebut menggunakan fungsi hash. Containers menggunakan hash table untuk menyimpan elemen-elemennya. Tabel ini mengharuskan elemen-elemennya dibandingkan dengan operator (==) dan ada cara untuk menghitung nilai hash berdasarkan elemen[4]. 

### Operasi hash table
- Insertion, memasukkan data baru ke tabel hash.
- Deletion, menghapus data dari hash table.
- Searching, mencari data dalam hash table dan mencari data di dalam bucker yang sesuai.
- Update, memperbarui data dalam hash table lalu memperbarui data yang ditemukan.
- Traversal, melalui seluruh hush table untuk memproses semua data yang ada dalam tabel.

### Collision Resolution
Collision atau tabrakan terjadi ketika dua key yang berbeda dipetakan ke alamat dan bahkan kegagalan operasi tabel hash. Collusion ini dapat diatasi dengan beberapa jenis teknik yaitu:
- Chaining, yaitu setiap slot tabel hash dapat menampung pointer ke linked list yang berisi data-data yang dipetakan ke slot tersebut.
- Probing, slot-slot hash table diperiksa secara berurutan untuk mencari slot kosong terdekat dari slot yang dihitung dari fungsi hash. Ada beberapa cara stategi probing yaitu diantaranya:
  - Linear probing, slot diperika secara berurutan, dimulai dari slot yang dihitung dari fungsi hash, hingga ditemukan slot kosong.
  - Quadratic probing, slot diperiksa dengan pola kuadrat dari slot yang dihitung dari fungsi hash, hingga ditemukan slot kosong.
  - Double hashing, digunakan untuk menghitung offset dari slot yang dihitung dari fungsi hash pertama. Offset digunakan untuk mencari slot kosong dalam ola terentu.


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
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/65713825-5e39-45b7-9332-42c87ef0f79e)

Kode di atas adalah kode program yang menggunakan hash table dengan operasi insert, get, remove, dan traverse. Pertama, 'MAX_SIZE' ditetapkan sebagai 10 dan fungsi hash mengembalikan indeks berdasarkan 'key' menggunakan operasi modulus. Struktur 'Node' digunakan untuk menyimpan elemen dengan pasangan 'key' dan 'value', serta pointer 'next' untuk menghubungkan node dalam kasus collision. Class 'HasTable' memiliki array pointer ke 'Node' ('table'). Fungsi 'insert' menambahkan atau memperbarui pasangan 'key' dan 'value' di hash table, fungsi 'get' bertujuan untuk mengembalikan 'value' berdasarkan 'key', fungsi 'remove' yaitu untuk menghapus node dengan 'key' tertentu, dan fungsi objek 'HashTable' dibuat, beberapa pasangan 'key' dan 'value' ditambahkan, pencarian nilai berdasarkan 'key' dilakukan, node dengan 'key' tertentu dihapus, dan semua elemen dalam hash table dicetak. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/ef309c1b-e28d-4682-a851-4f5295ba77ee)



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
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/4d5f19e2-91d1-4b57-920f-9a9c85225659)

Kode di atas adalah kode program yang menggunakan struktur data hash table dengan ukuran 11 slot. Pertama, program akan membuat 'employee_map' dengan fungsi 'HashMap' dan memiliki array 'table' dengan ukuran 'TABLE_SIZE', lalu tiga data dari karyawan dimasukkan ke 'employee_Map' menggunakan fungsi 'insert', dengan data dihash menggunakan fungsi 'hashfunc' untuk menentukan indeks di 'table'. Metode 'searchByName' digunakan untuk mencari nomor telepon berdasarkan nama karyawan, sedangkan 'remove' digunakan untuk menghapus karyawan. Setelah operasi insert dan remove, isi 'employee_map' dicetak menggunakan fungsi 'print'. Saat terjadi kecocokan hash, data disimpan dalam bentuk linked list di slot yang sama. Operasi percarian menggunakan fungsi hash untuk indeks di mana data mungkin disimpan, dan jika data ditemukan, nomor telepon karyawan dicetak. Operasi penghapusan data dari hash table, dengan mencocokkan hash yang dilakukan melalui pencarian dalam linked list di slot yang sesuai. Seteleah operasi, isi hasah table ditampilkan, menunjukkan pasangan nama nomor telepon yang disimpan dalam setiap slot, termasuk penanganan tabrakan dengan linked list.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/41cb9e3c-6f45-4be2-bb54-33692f581605)



## Unguided

### 1.	Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : 
a.	Setiap mahasiswa memiliki NIM dan nilai. 
b.	Program memiliki tampilan pilihan menu berisi poin C.
c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).


```C++
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

const int TABLE_SIZE = 11;

class HashNode
{
public:
    string nim;
    int grade;

    HashNode(string nim, int grade)
    {
        this->nim = nim;
        this->grade = grade;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];
    list<string> inputOrder; // To keep track of the order of input

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string nim, int grade)
    {
        int hash_val = hashFunc(nim);

        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                node->grade = grade;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim, grade));
        inputOrder.push_back(nim); // Keep track of the order of input
    }

    void remove(string nim)
    {
        int hash_val = hashFunc(nim);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->nim == nim)
            {
                delete *it; // Free memory
                table[hash_val].erase(it);
                inputOrder.remove(nim); // Remove from input order list
                return;
            }
        }
    }

    string searchByNim(string nim)
    {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                return "NIM: " + node->nim + ", Nilai: " + to_string(node->grade);
            }
        }
        return "Mahasiswa tidak ditemukan";
    }

    vector<string> searchByGradeRange(int minGrade, int maxGrade)
    {
        vector<string> results;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            for (auto node : table[i])
            {
                if (node->grade >= minGrade && node->grade <= maxGrade)
                {
                    results.push_back("NIM: " + node->nim + ", Nilai: " + to_string(node->grade));
                }
            }
        }
        return results;
    }

    void print()
    {
        int count = 1;
        for (const auto &nim : inputOrder)
        {
            int hash_val = hashFunc(nim);
            for (auto node : table[hash_val])
            {
                if (node->nim == nim)
                {
                    cout << count << ". NIM: " << node->nim << ", Nilai: " << node->grade << endl;
                    count++;
                }
            }
        }
    }
};

void menu()
{
    cout << "Menu:\n";
    cout << "1. Tambah data mahasiswa\n";
    cout << "2. Hapus data mahasiswa\n";
    cout << "3. Cari data NIM mahasiswa\n";
    cout << "4. Cari data nilai mahasiswa (80-90)\n";
    cout << "5. Tampilkan semua data mahasiswa\n";
    cout << "6. Keluar\n";
    cout << "Pilih opsi: ";
}

int main()
{
    HashMap student_map;
    int choice;
    string nim;
    int grade;

    while (true)
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan nilai: ";
            cin >> grade;
            student_map.insert(nim, grade);
            break;
        case 2:
            cout << "Masukkan NIM yang akan dihapus: ";
            cin >> nim;
            student_map.remove(nim);
            break;
        case 3:
            cout << "Masukkan NIM yang akan dicari: ";
            cin >> nim;
            cout << student_map.searchByNim(nim) << endl;
            break;
        case 4:
        {
            vector<string> results = student_map.searchByGradeRange(80, 90);
            for (const auto &res : results)
            {
                cout << res << endl;
            }
            if (results.empty())
            {
                cout << "Data tidak ditemukan" << endl;
            }
            break;
        }
        case 5:
            student_map.print();
            break;
        case 6:
            cout << "Keluar dari program" << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
```

#### Output:


#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/ec156244-9f7e-479c-80d7-52db71aa014d)



## Kesimpulan

Kesimpulannya, 



## Referensi

[1]  V. Tran, L. Wang, H. Chen, and Q. Xiao, “MCHT: A maximal clique and hash table-based maximal prevalent co-location pattern mining algorithm,” Expert Systems With Applications, vol. 175, p. 114830, Aug. 2021, doi: 10.1016/j.eswa.2021.114830.

[2] J. Carey, S. Doshi, and P. Rajan, C++ Data structures and algorithm design principles: Leverage the power of modern C++ to build robust and scalable applications. Packt Publishing Ltd, 2019.

[3] T. Mailund, The Joys of Hashing: Hash Table Programming with C. Apress, 2019.

[4] B. Andrist, V. Sehr, and B. Garney, C++ High performance: Master the art of optimizing the functioning of your C++ code. Packt Publishing Ltd, 2020.

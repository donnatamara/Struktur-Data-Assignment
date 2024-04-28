# <h1 align="center">Laporan Praktikum Modul Linked List</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori
Linked list merupakan kumpulan node yang bersama-sama membentuk urutan linier, setiap node menyimpan sebuah pointer, yang biasanya menggunakan 'next' ke node berikutnya dalam daftar, setiap node juga menyimpan elemen terkaitnya [1]. 

### 1. Linked List Non Circular
Linked list non circular adalah struktur data dinamis yang terdiri dari node-node yang saling terhubung satu sama lain dengan bantuan sebuah pointer. Setiap node memiliki dua bagian utama yaitu data dan pinter yang menunjuk ke node berikutnya. Linked list efisien untuk menyimpan dan mengelola data dalam program C++ untuk pemula [2].

### 2. Linked List Circular
Linked list circular adalah jenis linked list yang terakhir mengarah ke node pertama, membuat struktur lingkaran, artinya pointer next dari node terakhir diatur ke alamat node pertama, membentuk sebuah loop. 

### 3. Single Linked List
Single linked list adalah struktur data yang terdiri dari node-node yang saling terhubung, dimana setiap node memiliki data dan referensi kek node berikutnya dalam urutan. Single linked list biasanya dimulai dengan deklarasi node pertama dan dapat digunakan untuk berbagai keperluan dalam pemrograman. 

### 4. Double Linked List
Double linked list adalah struktur data linear yang terdiri dari node yang saling terhubung satu sama lain, dimana setiap node memiliki tiga elemen yaitu data sebagai penyimpan nilai yang ingin direpresentasikan, pointer sebelumnya (prev) digunakan untuk menunjuk ke node sebelumnya dalam daftar dan pinter selanjutnya (next) digunakan untuk menunjuk ke node selanjutnya dalam daftar [3].

## Guided

### 1. Single and Doble Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/f441677a-95fc-443d-9bd9-eefb4422903e)


Kode di atas adalah program untuk 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/fa8f8096-252e-4f7a-a8e4-714784018227)


## 2. Single and Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/219ab408-eba0-4431-8ab1-8095cfd95bf6)

Kodingan di atas adalah program 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/cd82bdf2-93eb-41c0-85d6-8183a97790cf)


## 3. Circular and Non Circular Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; // true 
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan 
void insertDepan(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depab
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }
            
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transversing
        int nomor = 1;
        bantu = head;
        
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head-> next;

        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan list
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
#### Output:


Kodingan di atas adalah program 

#### Full code Screenshot:


## Unguided

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 

Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa, berikut contoh tampilan output dari nomor 1:
• Tampilan Menu: 
PROGRAM SINGLE LINKED LIST NON-CIRCULAR  
1. Tambah Depan  
2. Tambah Belakang  
3. Tambah Tengah  
4. Ubah Depan  
5. Ubah Belakang  
6. Ubah Tengah  
7. Hapus Depan  
8. Hapus Belakang  
9. Hapus Tengah  
10. Hapus List  
11. TAMPILKAN  
0. KELUAR  
Pilih Operasi :

• Tampilan Operasi Tambah:
-Tambah Depan 
Masukkan Nama : 
Masukkan NIM : 
Data telah ditambahkan

-Tambah Tengah 
Masukkan Nama : 
Masukkan NIM : 
Masukkan Posisi : 
Data telah ditambahkan

• Tampilan Operasi Hapus: 
-Hapus Belakang 
Data (nama mahasiswa yang dihapus) berhasil dihapus

-Hapus Tengah 
Masukkan posisi : 
Data (nama mahasiswa yang dihapus) berhasil dihapus

• Tampilan Operasi Ubah: 
-Ubah Belakang 
Masukkan nama : 
Masukkan NIM : 
Data (nama lama) telah diganti dengan data (nama baru)

-Ubah Belakang 
Masukkan nama : 
Masukkan NIM : 
Masukkan posisi : 
Data (nama lama) telah diganti dengan data (nama baru)

• Tampilan Operasi Tampil Data: 
DATA MAHASISWA 
NAMA NIM 
Nama1 NIM1 
Nama2 NIM2

*Buat tampilan output sebagus dan secantik mungkin sesuai kreatifitas anda  masing-masing, jangan terpaku pada contoh output yang diberikan*

```C++
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define Node structure
struct Node {
  string nama;
  string nim;
  Node *next;
};

Node *head;
Node *tail;

// Initialize the linked list
void init() {
  head = NULL;
  tail = NULL;
}

// Check if the linked list is empty
bool isEmpty() {
  return (head == NULL);
}

// Insert node at the front
void insertDepan(string nama, string nim) {
  Node *baru = new Node;
  baru->nama = nama;
  baru->nim = nim;
  baru->next = NULL;

  if (isEmpty()) {
    head = tail = baru;
  } else {
    baru->next = head;
    head = baru;
  }
    cout << "Data telah diperbarui" << endl;
}

// Insert node at the back
void insertBelakang(string nama, string nim) {
  Node *baru = new Node;
  baru->nama = nama;
  baru->nim = nim;
  baru->next = NULL;

  if (isEmpty()) {
    head = tail = baru;
  } else {
    tail->next = baru;
    tail = baru;
  }
    cout << "Data telah diperbarui" << endl;
}

// Count the number of nodes in the linked list
int hitungList() {
  Node *hitung = head;
  int jumlah = 0;
  while (hitung != NULL) {
    jumlah++;
    hitung = hitung->next;
  }
  return jumlah;
}

// Insert node in the middle
void insertTengah(string nama, string nim, int posisi) {
  if (posisi < 1 || posisi > hitungList()) {
    cout << "Posisi tidak valid. Posisi harus berada di antara 1 dan jumlah node." << endl;
    return;
  } else if (posisi == 1) {
    insertDepan(nama, nim);
    return;
  } else {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    Node *bantu = head;
    for (int i = 1; i < posisi - 1; i++) {
      bantu = bantu->next;
    }

    baru->next = bantu->next;
    bantu->next = baru;
  }
    cout << "Data telah diperbarui" << endl;
}

// Delete node at the front
void hapusDepan() {
  if (!isEmpty()) {
    Node *hapus = head;
    // Store name of deleted student
    string namaDihapus = hapus->nama;
    if (head->next != NULL) {
      head = head->next;
    } else {
      head = tail = NULL;
    }
    delete hapus;
    // Print success message with student name
    cout << "Data " << namaDihapus << " telah terhapus" << endl; 
  } else {
    cout << "Daftar tersebut kosong." << endl;
  }
}

// Delete node at the back
void hapusBelakang() {
  if (!isEmpty()) {
    Node *hapus = tail;
    // Store name of deleted student
    string namaDihapus = hapus->nama; 
    if (head != tail) {
      Node *bantu = head;
      while (bantu->next != tail) {
        bantu = bantu->next;
      }
      tail = bantu;
      tail->next = NULL;
    } else {
      head = tail = NULL;
    }
    delete hapus;
    // Print success message with student name
    cout << "Data " << namaDihapus << " telah terhapus" << endl; 
  } else {
    cout << "Daftar tersebut kosong." << endl;
  }
}

// Delete node in the middle
void hapusTengah(int posisi) {
  if (posisi < 1 || posisi > hitungList()) {
    cout << "Posisi tidak valid. Posisi harus berada di antara 1 dan jumlah node." << endl;
    return;
  } else if (posisi == 1) {
    hapusDepan();
    return;
  } else {
    Node *hapus;
    Node *bantu = head;
    for (int i = 1; i < posisi - 1; i++) {
      bantu = bantu->next;
    }
    hapus = bantu->next;
    // Store name of deleted student
    string namaDihapus = hapus->nama;
    bantu->next = hapus->next;
    delete hapus;
    // Print success message with student name
    cout << "Data " << namaDihapus << " telah terhapus" << endl; 
  }
}

// Update data in the front node
void ubahDepan(string nama, string nim) {
  if (!isEmpty()) {
    // Store old name
    string namaLama = head->nama;
    head->nama = nama;
    head->nim = nim;
    // Print success message with old and new names
    cout << "Data " << namaLama << " telah diubah menjadi data " << nama << endl; 
  } else {
    cout << "Daftar tersebut kosong." << endl;
  }
}

// Update data in the middle node
void ubahTengah(string nama, string nim, int posisi) {
  if (!isEmpty()) {
    if (posisi < 1 || posisi > hitungList()) {
      cout << "Posisi tidak valid. Posisi harus berada di antara 1 dan jumlah node." << endl;
      return;
    } else if (posisi == 1) {
      ubahDepan(nama, nim);
      return;
    } else {
      Node *bantu = head;
      for (int i = 1; i < posisi; i++) {
        bantu = bantu->next;
      }
      // Store old name
      string namaLama = bantu->nama;
      bantu->nama = nama;
      bantu->nim = nim;
      // Print success message with old and new names
      cout << "Data " << namaLama << " telah diubah menjadi data " << nama << endl; 
    }
  } else {
    cout << "Daftar tersebut kosong." << endl;
  }
}

// Update data in the back node
void ubahBelakang(string nama, string nim) {
  if (!isEmpty()) {
    // Store old name
    string namaLama = tail->nama;
    tail->nama = nama;
    tail->nim = nim;
    // Print success message with old and new names
    cout << "Data " << namaLama << " telah diubah menjadi data " << nama << endl; 
  } else {
    cout << "Daftar tersebut kosong." << endl;
  }
}

// Clear the linked list
void clearList() {
  Node *hapus;
  while (head != NULL) {
    hapus = head;
    head = head->next;
    delete hapus;
  }
  tail = NULL;
  cout << "Daftar telah dihapus" << endl;
}

// Display the linked list
void tampil() {
  Node *bantu = head;
  if (!isEmpty()) {
    cout << "------------------------------------------------" << endl;
    cout << "| No  |       Nama       |         NIM          |" << endl;
    cout << "------------------------------------------------" << endl;
    int i = 1;
    while (bantu != NULL) {
      cout << "| " << setw(3) << i << " | " << setw(15) << bantu->nama << "  | " << setw(15) << bantu->nim << "      |" << endl;
      bantu = bantu->next;
      i++;
    }
    cout << "------------------------------------------------" << endl;
  } else {
    cout << "Daftar tersebut kosong." << endl;
  }
}

// Main function
int main() {
  init();

  int pilihan;
  string nama, nim;
  int posisi;

  do {
    cout << "\n# MENU SINGLE LINKED LIST MAHASISWA #" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Tambah Data Awal" << endl;
    cout << "2. Tambah Data Akhir" << endl;
    cout << "3. Tambah Data Tengah" << endl;
    cout << "4. Ubah Data Awal" << endl;
    cout << "5. Ubah Data Akhir" << endl;
    cout << "6. Ubah Data Tengah" << endl;
    cout << "7. Hapus Data Awal" << endl;
    cout << "8. Hapus Data Akhir" << endl;
    cout << "9. Hapus Data Tengah" << endl;
    cout << "10. Tampilkan Data" << endl;
    cout << "11. Hapus Semua Data" << endl;
    cout << "0. Keluar" << endl;
    cout << "\nPilih Menu: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        insertDepan(nama, nim);
        tampil();
        break;
      case 2:
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        insertBelakang(nama, nim);
        tampil();
        break;
      case 3:
        cout << "Masukkan Nama : ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        cout << "Masukkan Posisi: ";
        cin >> posisi;
        insertTengah(nama, nim, posisi);
        tampil();
        break;
      case 4:
        cout << "Masukkan nama baru: ";
        cin >> nama;
        cout << "Masukkan NIM baru: ";
        cin >> nim;
        ubahDepan(nama, nim);
        tampil();
        break;
      case 5:
        cout << "Masukkan nama : ";
        cin >> nama;
        cout << "Masukkan NIM : ";
        cin >> nim;
        ubahBelakang(nama, nim);
        tampil();
        break;
      case 6:
        cout << "Masukkan posisi: ";
        cin >> posisi;
        cout << "Masukkan nama baru: ";
        cin >> nama;
        cout << "Masukkan NIM baru: ";
        cin >> nim;
        ubahTengah(nama, nim, posisi);
        tampil();
        break;
      case 7:
        hapusDepan();
        tampil();
        break;
      case 8:
        hapusBelakang();
        tampil();
        break;
      case 9:
        cout << "Masukkan posisi: ";
        cin >> posisi;
        hapusTengah(posisi);
        tampil();
        break;
      case 10:
        tampil();
        break;
      case 11:
        clearList();
        tampil();
        break;
      case 0:
        cout << "Selesai! Anda keluar dari program." << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 0);

  return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/09f8d88d-fdff-46e3-8cf6-1dc7ddf84f40)

Kode di atas adalah program yang mengelola dan menampilkan data mahasiswa dengan menggunakan single linked list, terdapat berbagai fungsi yaitu menambah, mengubah, menghapus, dan menampilkan data mahasiswa dalam daftar tersebut. Pengguna dapat memilih opsi yang ingin dijalankan dari menu yang telah disediakan.

Program mendefinisikan struktur `Node` untuk menyimpan data satu mahasiswa yang terdiri dari string nama, nim, serta node yang berguna untuk menyimpan pointer. Program memeriksa apakah linked list kosong, jika kosong kedua pointer akan sama-sama menunjuk ke node baru, jika tidak, pointer `next` dari node baru diarahkan ke node `head` yang ada saat ini. Kemudian pointer `head` diperbarui untuk menunjuk ke node baru, menjadikannya node terdepan yang baru. 

Algoritma yang ditampilkan dalam program tersebut adalah menambah data dengan menggunakan `insertDepan` dengan membuat node baru, dan menghubungkan `next` ke `head`, serta memperbarui `head` dan `tail` jika daftar kosong, `insertBelakang` digunakan dengan membuat node baru, menghubungkan `next` ke `NULL`, dan memperbarui `tail` jika daftar kosong.
`insertTengah` dengan menemukan node pada posisi sebelumnya, menghubungkan node baru di antara node sebelumnya dan node berikutnya, dan memperbarui `tail` jika posisinya adalah posisi terakhir. 

Algoritma penghapusan data, memiliki `hapusDepan` dengan menyimpan nama node yang dihapus, memperbarui `head` ke node berikutnya, dan menghapus node yang ingin dihapus. `hapusBelakang` untuk menyimpan nama node yang dihapus, memperbarui `tail` ke node sebelumnya, dan menghapus node yang ingin dihapus. `hapusTengah` dengan menemukan node sebelumnya, menghubungkan node sebelumnya ke node berikutnya, dan menghapus node yang ingin dihapus.

Algoritma perubahan data, memiliki `ubahDepan` dengan menyimpan nama lama dan mengganti nama dan NIM node pertama dengan yang baru. `ubahBelakang` dengan menyimpan nama lama dan mengganti nama dan NIM node terakhir dengan yang baru. `ubahTengah` dengan menemukan node pada posisi yang ditentukan, menyimpan nama lama, dan mengganti nama dan NIM node dengan yang baru.

Algoritma Penampilan data, memiliki `tampil`yang berguna untuk menampilkan header tabel, mengulangi setiap node, dan menampilkan nama, NIM, dan garis pembatas.



#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/e025d1b4-575a-436b-ab33-f18e663a6b11)


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/1e284aab-e2ce-41de-966d-4405d7c58fdf)

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/ba67a1b3-adc4-44ea-b2a1-ff1b15e5a7fb)

Diatas adalah hasil output dari instruksi yang telah diberikan menggunakan kode unguided 1. Dengan menggunakan insert depan, belakang, dan tengah sebagai perintah yang akan dijalankan. Hasil output ditambahkan dengan sebuah tabel agar dapat lebih jelas terbaca.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/bc3c9152-bd24-431a-a4f6-db42386639f9)


### 3. Lakukan perintah berikut: 
a) Tambahkan data berikut diantara Farrel dan Denis: 
Wati 2330004

b) Hapus data Denis

c) Tambahkan data berikut di awal:
Owi 2330000

d) Tambahkan data berikut di akhir: 
David 23300100

e) Ubah data Udin menjadi data berikut: 
Idin 23300045

f) Ubah data terkahir menjadi berikut: 
Lucy 23300101 

g) Hapus data awal 

h) Ubah data awal menjadi berikut: 
Bagas 2330002 

i) Hapus data akhir 

j) Tampilkan seluruh data

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/4c933c85-a2d4-4d29-9625-3d12a4c57aad)

Dengan memasukkan data sesuai instruksi yang telah diberikan, hasil akhir output terlihat seperti diatas. 

#### Full code Screenshot:
 ![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/a86901e2-c6f6-4042-945d-a9f459a7abaf)


## Kesimpulan

Kesimpulannya, 

## Referensi

[1] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2019). Data structures and algorithms in C++. John Wiley & Sons.

[2] A. Agus Priyono. Pemrograman C++ untuk Pemula. 2020.

[3] Tedi Suryadi. (2021). Struktur Data dan Algoritma dengan C++. Bandung: Informatika.

[4] 

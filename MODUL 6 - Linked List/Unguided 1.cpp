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
    cout << "Invalid position. Position must be between 1 and the number of nodes." << endl;
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
}

// Delete node at the front
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
    cout << "The list is empty." << endl;
  }
}

// Delete node at the back
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
    cout << "The list is empty." << endl;
  }
}

// Delete node in the middle
void hapusTengah(int posisi) {
  if (posisi < 1 || posisi > hitungList()) {
    cout << "Invalid position. Position must be between 1 and the number of nodes." << endl;
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
    bantu->next = hapus->next;
    delete hapus;
  }
}

// Update data in the front node
void ubahDepan(string nama, string nim) {
  if (!isEmpty()) {
    head->nama = nama;
    head->nim = nim;
  } else {
    cout << "The list is empty." << endl;
  }
}

// Update data in the middle node
void ubahTengah(string nama, string nim, int posisi) {
  if (!isEmpty()) {
    if (posisi < 1 || posisi > hitungList()) {
      cout << "Invalid position. Position must be between 1 and the number of nodes." << endl;
      return;
    } else if (posisi == 1) {
      ubahDepan(nama, nim);
      return;
    } else {
      Node *bantu = head;
      for (int i = 1; i < posisi; i++) {
        bantu = bantu->next;
      }
      bantu->nama = nama;
      bantu->nim = nim;
    }
  } else {
    cout << "The list is empty." << endl;
  }
}

// Update data in the back node
void ubahBelakang(string nama, string nim) {
  if (!isEmpty()) {
    tail->nama = nama;
    tail->nim = nim;
  } else {
    cout << "The list is empty." << endl;
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
  cout << "The list has been cleared." << endl;
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
      cout << "| " << setw(3) << i << " | " << setw(15) << bantu->nama << " | " << setw(15) << bantu->nim << " |" << endl;
      bantu = bantu->next;
      i++;
    }
    cout << "-----------------------------------------" << endl;
  } else {
    cout << "The list is empty." << endl;
  }
}

// Main function
int main() {
  init();

  int pilihan;
  string nama, nim;
  int posisi;

  do {
    cout << "\n# MENU LINKED LIST MAHASISWA #" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Tambah Data Depan" << endl;
    cout << "2. Tambah Data Belakang" << endl;
    cout << "3. Tambah Data Tengah" << endl;
    cout << "4. Hapus Data Depan" << endl;
    cout << "5. Hapus Data Belakang" << endl;
    cout << "6. Hapus Data Tengah" << endl;
    cout << "7. Ubah Data Depan" << endl;
    cout << "8. Ubah Data Tengah" << endl;
    cout << "9. Ubah Data Belakang" << endl;
    cout << "10. Tampilkan Data" << endl;
    cout << "11. Hapus Semua Data" << endl;
    cout << "0. Keluar" << endl;
    cout << "\nPilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        insertDepan(nama, nim);
        tampil();
        break;
      case 2:
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        insertBelakang(nama, nim);
        tampil();
        break;
      case 3:
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        cout << "Masukkan posisi (1-" << hitungList() << "): ";
        cin >> posisi;
        insertTengah(nama, nim, posisi);
        tampil();
        break;
      case 4:
        hapusDepan();
        tampil();
        break;
      case 5:
        hapusBelakang();
        tampil();
        break;
      case 6:
        cout << "Masukkan posisi (1-" << hitungList() << "): ";
        cin >> posisi;
        hapusTengah(posisi);
        tampil();
        break;
      case 7:
        cout << "Masukkan nama baru: ";
        cin >> nama;
        cout << "Masukkan NIM baru: ";
        cin >> nim;
        ubahDepan(nama, nim);
        tampil();
        break;
      case 8:
        cout << "Masukkan posisi (1-" << hitungList() << "): ";
        cin >> posisi;
        cout << "Masukkan nama baru: ";
        cin >> nama;
        cout << "Masukkan NIM baru: ";
        cin >> nim;
        ubahTengah(nama, nim, posisi);
        tampil();
        break;
      case 9:
        cout << "Masukkan nama baru: ";
        cin >> nama;
        cout << "Masukkan NIM baru: ";
        cin >> nim;
        ubahBelakang(nama, nim);
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
        cout << "Keluar dari program." << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 0);

  return 0;
}

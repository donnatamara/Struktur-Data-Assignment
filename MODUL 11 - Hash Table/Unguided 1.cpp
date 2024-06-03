#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int NIM;
    int nilai;
    Node* next;
    Node(int NIM, int nilai) : NIM(NIM), nilai(nilai), next(nullptr) {}
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
    void insert(int NIM, int nilai) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->NIM == NIM) {
                current->nilai = nilai;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(NIM, nilai);
        node->next = table[index];
        table[index] = node;
    }

    // Searching by NIM
    int get(int NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->NIM == NIM) {
                return current->nilai;
            }
            current = current->next;
        }
        return -1;
    }

    // Searching by nilai
    void get_by_range(int min_nilai, int max_nilai) {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                if (current->nilai >= min_nilai && current->nilai <= max_nilai) {
                    cout << "NIM: " << current->NIM << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }

    // delete
    void remove(int NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->NIM == NIM) {
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
                cout << "NIM: " << current->NIM << ", Nilai: " << current->nilai << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    int choice, NIM, nilai;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Cari data NIM mahasiswa\n";
        cout << "4. Cari data nilai mahasiswa\n";
        cout << "5. Tampilkan semua data mahasiswa\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                ht.insert(NIM, nilai);
                break;
            case 2:
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> NIM;
                ht.remove(NIM);
                break;
            case 3:
                cout << "Masukkan NIM yang akan dicari: ";
                cin >> NIM;
                nilai = ht.get(NIM);
                if (nilai != -1) {
                    cout << "NIM: " << NIM << ", Nilai: " << nilai << endl;
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            case 4:
                cout << "Data mahasiswa dengan nilai dalam rentang 80-90:\n";
                ht.get_by_range(80, 90);
                break;
            case 5:
                cout << "Semua data mahasiswa:\n";
                ht.traverse();
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 6);

    return 0;
}

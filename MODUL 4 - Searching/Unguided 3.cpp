#include <iostream>

using namespace std;

int sequentialSearch(int data[], int size, int target, int& index) {
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            index = i;
            return 1; // Kembalikan 1 jika angka ditemukan
        }
    }
    return 0; // Kembalikan 0 jika angka tidak ditemukan
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]); // Menghitung panjang array secara dinamis
    int target, index;

    cout << "Masukkan angka yang ingin Anda cari: ";
    cin >> target;

    if (sequentialSearch(data, size, target, index)) {
        cout << "Angka " << target << " ditemukan pada indeks ke-" << index << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam data" << endl;
    }

    return 0;
}

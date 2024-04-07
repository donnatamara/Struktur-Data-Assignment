#include <iostream>

using namespace std;

void sequentialSearch(const int data[], int size, int target, int indices[], int& count) {
    count = 0; 
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            indices[count] = i; // Simpan indeks jika angka ditemukan
            count++; 
        }
    }
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]); // Menghitung panjang array secara dinamis
    int target, count;
    const int max = 100; // Ukuran maksimum untuk array indeks
    int indices[max];

    cout << "Masukkan angka yang ingin Anda cari: ";
    cin >> target;

    sequentialSearch(data, size, target, indices, count);

    if (count > 0) {
        cout << "Angka " << target << " ditemukan sebanyak " << count << " kali, pada indeks:" << endl;
        for (int i = 0; i < count; i++) {
            cout << indices[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam data." << endl;
    }

    return 0;
}

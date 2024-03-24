#include <iostream>

using namespace std;

int main() {
    const int max_size = 100; // Ukuran maksimum array
    int arr[max_size];
    int a;

    // Input ukuran array dari pengguna
    cout << "Masukkan ukuran array: ";
    cin >> a;

    // Validasi ukuran array
    if (a <= 0 || a > max_size) {
        cout << "Ukuran array tidak valid.\n";
        return 1; // Menghentikan program dengan kode error
    }

    // Input elemen array dari pengguna
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < a; ++i) {
        cout << "Elemen " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Mencari nilai maksimum, minimum, dan rata-rata
    int max = arr[0], min = arr[0], sum = 0;
    for (int i = 0; i < a; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
    }

    // Menghitung nilai rata-rata
    double avg = static_cast<double>(sum) / a;

    // Menampilkan hasil
    cout << "Nilai Maksimum: " << max << endl;
    cout << "Nilai Minimum: " << min << endl;
    cout << "Nilai Rata-rata: " << avg << endl;

    return 0;
}

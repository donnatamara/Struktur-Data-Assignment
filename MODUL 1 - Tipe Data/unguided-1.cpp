#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas persegi
float hitungLuasPersegi(float sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung volume balok
float hitungVolumeBalok(float panjang, float lebar, float tinggi) {
    return panjang * lebar * tinggi;
}

int main() {
    char pilihanMenu; // Variabel yang digunakan untuk memproses menu pilihan user
    float ukuranSisi, panjang, lebar, tinggi; // Variabel untuk menampung data input dari user

    // Menampilkan menu pilihan
    cout << "1. Hitung Luas Persegi\n2. Hitung Volume Balok\nPilih Menu (1, 2): ";
    cin >> pilihanMenu;

    switch (pilihanMenu) {
    case '1':
        cout << "Masukkan panjang sisi persegi: ";
        cin >> ukuranSisi;
        // Menampilkan hasil perhitungan luas persegi
        cout << "Luas Persegi dengan sisi " << ukuranSisi << " adalah: " << hitungLuasPersegi(ukuranSisi) << endl;
        break;
    case '2':
        cout << "Masukkan panjang, lebar, dan tinggi balok: " << endl;
        cout << "Panjang: ";
        cin >> panjang;
        cout << "Lebar: ";
        cin >> lebar;
        cout << "Tinggi:";
        cin >> tinggi;
        // Menampilkan hasil perhitungan volume balok
        cout << "Volume Balok dengan panjang " << panjang << ", lebar " << lebar << ", dan tinggi " << tinggi << " adalah: "
             << hitungVolumeBalok(panjang, lebar, tinggi) << endl;
        break;
    default:
        cout << "Menu Tidak Ada";
    }

    return 0;
}
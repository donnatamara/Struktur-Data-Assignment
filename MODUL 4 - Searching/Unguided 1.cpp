#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mencetak semua posisi kemunculan huruf dalam string
void binarysearch(const string& str, char target) {
    bool found = false;
    cout << "Huruf \"" << target << "\" ditemukan pada indeks: ";
    for (int i = 0; i < str.length(); ++i) {
        if (tolower(str[i]) == tolower(target)) {
            found = true;
            cout << i << " ";
        }
    }
    if (!found) {
        cout << "tidak ditemukan";
    }
    cout << endl;
}

int main() {
    string kalimat = "Saya belajar algoritma dan struktur data.";
    char huruf;
    
    cout << "\nKalimat: " + kalimat << endl;
    cout << "\nMasukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Mengubah huruf menjadi huruf kecil untuk pencarian yang tidak case-sensitive
    huruf = tolower(huruf);

    // Memanggil fungsi binarysearch untuk mencari dan mencetak semua posisi kemunculan huruf
    binarysearch(kalimat, huruf);

    return 0;
}
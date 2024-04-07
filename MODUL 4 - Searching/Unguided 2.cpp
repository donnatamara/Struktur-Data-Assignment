#include <iostream>
#include <string>

using namespace std;

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int banyak = 0;
    const int max = 100; // Maksimum panjang kalimat
    int indeksVokal[max];
    int index = 0;

    for (int i = 0; i < kalimat.length(); i++) {
        char huruf = tolower(kalimat[i]); // Mengubah huruf menjadi huruf kecil
        if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u') {
            banyak++;
            indeksVokal[index++] = i;
        }
    }

    cout << "Banyak huruf vokal: " << banyak << endl;
    if (banyak > 0) {
        cout << "Indeks huruf vokal: ";
        for (int i = 0; i < index; i++) {
            cout << indeksVokal[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

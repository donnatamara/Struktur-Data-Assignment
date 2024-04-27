#include <iostream>
using namespace std;

// Mendefinisikan struktur buku
struct buku
{
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main()
{
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    for (int i = 0; i < 5; i++)
    {
        cout << "\nMasukkan data buku ke-" << i + 1 << ":" << endl;
        cout << "Judul Buku: ";
        cin.ignore(); // Bersihkan buffer input sebelumnya
        getline(cin, favorit.judulBuku[i]);

        cout << "Pengarang: ";
        getline(cin, favorit.pengarang[i]);

        cout << "Penerbit: ";
        getline(cin, favorit.penerbit[i]);

        cout << "Tebal Halaman: ";
        cin >> favorit.tebalHalaman[i];

        cout << "Harga Buku: ";
        cin >> favorit.hargaBuku[i];
    }

    // Menampilkan informasi buku favorit
    cout << "\n\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "\n\tData Buku ke-" << i + 1 << ":" << endl;
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
    }

    return 0;
}

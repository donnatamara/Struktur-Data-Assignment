#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan struktur buku
struct buku
{
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main()
{
    const int jumlah_buku = 3; // Jumlah buku yang ingin dimasukkan

    // Mendeklarasikan variabel favorit sebagai array dari struktur buku
    buku favorit[jumlah_buku];

    // Mengisi data ke dalam array favorit
    favorit[0].judulBuku = "The Alpha Girl's Guide";
    favorit[0].pengarang = "Henry Manampiring";
    favorit[0].penerbit = "Gagas Media";
    favorit[0].tebalHalaman = 253;
    favorit[0].hargaBuku = 79000;

    favorit[1].judulBuku = "Lukacita";
    favorit[1].pengarang = "Valerie Patkar";
    favorit[1].penerbit = "Bhuana Ilmu Populer";
    favorit[1].tebalHalaman = 448;
    favorit[1].hargaBuku = 93000;

    favorit[2].judulBuku = "Laut Bercerita";
    favorit[2].pengarang = "Leila S. Chudori";
    favorit[2].penerbit = "Kepustakaan Populer Gramedia";
    favorit[2].tebalHalaman = 394;
    favorit[2].hargaBuku = 92000;

    // Menampilkan informasi buku favorit
    for (int i = 0; i < jumlah_buku; i++)
    {
        cout << "\tBuku Favorit " << i + 1 << endl;
        cout << "\tJudul Buku : " << favorit[i].judulBuku << endl;
        cout << "\tPengarang : " << favorit[i].pengarang << endl;
        cout << "\tPenerbit : " << favorit[i].penerbit << endl;
        cout << "\tTebal Halaman: " << favorit[i].tebalHalaman << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit[i].hargaBuku << endl;
        cout << endl;
    }

    return 0;
}

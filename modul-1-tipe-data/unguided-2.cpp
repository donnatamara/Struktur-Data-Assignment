#include <iostream>
#include <string>
using namespace std;

//Class biasa yang belum publik akses
class Makanan_Daerah {
    string nama;
    string jenis;
    string asal;
};

//Class yang sudah menjadi publik akses
class Makanan_Daerah2 {
public:
    string nama;
    string jenis;
    string asal;
};

struct Makanan_Daerahh {
    string nama;
    string jenis;
    string asal;
};

int main() {
    Makanan_Daerahh md1;
    Makanan_Daerah2 md2;
    
    md1.nama = "Nasi Megono";
    md1.jenis = "Kering";
    md1.asal = "Pekalongan";
    cout << "==== Makanan 1 ===="
        << "\nNama Makanan: " << md1.nama
        << "\nJenis: Makanan " << md1.jenis
        << "\nAsal Daerah: " << md1.asal << endl;

    md2.nama = "Soto Tauto ";
    md2.jenis = "Basah";
    md2.asal = "Pekalongan";
    cout << "==== Makanan 2 ===="
        << "\nNama Makanan: " << md2.nama
        << "\nJenis: Makanan " << md2.jenis
        << "\nAsal Daerah: " << md2.asal << endl;

    return 0;
}
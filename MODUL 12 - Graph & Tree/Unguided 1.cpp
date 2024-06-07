#include <iostream>
#include <iomanip>

using namespace std;

const int max_simpul = 10;

int DonnaNurTamara_2311110014;

int main()
{
    int n;
    cout << "Silakan masukan jumlah simpul : ";
    cin >> n;

    char simpul_kota[max_simpul][50];
    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul_kota[i];
    }

    int bobot[max_simpul][max_simpul];
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << simpul_kota[i] << "--> " << simpul_kota[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << "\n\t";
    for (int i = 0; i < n; i++)
    {
        cout << setw(8) << simpul_kota[i];
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << simpul_kota[i] << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << setw(8) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}
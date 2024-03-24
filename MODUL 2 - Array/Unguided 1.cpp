#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Masukkan Data array: ";
    cin >> a;

    int array[a];
    cout << "Masukkan elemen array\n" << endl;
    for (i = 0; i < a; i++) {
        cin >> array[i];
    }

    cout << "Array ke-: ";
    for (i = 0; i < a; i++)
    {
        cout << "\n\nNomor Genap: ";
        for (int j = 0; j < a; j++) {
            if (array[j] % 2 == 0) {
                cout << array[j] << " "; 
            }
        }
        cout << "\n\nNomor Ganjil: ";
        for (int k = 0; k < a; k++); {
            if (array[k] % 2 != 0) {
                cout << array[k] << " "; 
            }
        }
    }
    return 0;
}
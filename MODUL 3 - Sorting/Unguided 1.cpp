#include <iostream>

using namespace std;

void selectionSort(double arr[], int a)
{   // Looping melalui setiap elemen array (kecuali paling akhir)
    for (int i = 0; i < a - 1; ++i)
    {   
        int max = i;
        // Looping dalam untuk mencari elemen terbesar
        for (int j = i + 1; j < a; ++j)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        // Tukar elemen sekarang (i) dengan elemen terbesar (maks)
        double temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int main()
{
    const int a = 5;
    double IPS[a] = {3.8, 2.9, 3.3, 4.0, 2.4}; // Array nilai IPS

    cout << "IPS sebelum diurutkan:" << endl;
    for (int i = 0; i < a - 1; ++i)
    {
        cout << IPS[i] << ", ";
    }
    cout << IPS[a - 1] << endl;
    // Mengurutkan array IPS
    selectionSort(IPS, a);

    cout << "IPS setelah diurutkan secara descending:" << endl;
    for (int i = 0; i < a - 1; ++i)
    {
        cout << IPS[i] << ", "; 
    }
    // Cetak elemen terakhir
    cout << IPS[a - 1] << endl; 
    return 0;
}
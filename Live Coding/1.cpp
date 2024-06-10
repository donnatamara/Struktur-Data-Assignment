#include <iostream>
using namespace std;

bool sequentialSearch(int data[], int n, int cari, int &index)
{
    for (int i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            index = i;
            return true;
        }
    }
    return false;
}

int main()
{
    int n = 5;
    int cari = 5;
    int data[n] = {1, 2, 3, 4, 5, 5};
    bool ketemu;
    int index;

    cout << "data: {1, 2, 3, 4, 5, 5}" << endl;

    ketemu = sequentialSearch(data, n, cari, index);

    if (ketemu)
    {
        cout << "angka " << cari << " telah ditemukan pada indeks ke-" << index << endl;
    }
    else
    {
        cout << cari << " tidak ditemukan pada data." << endl;
    }

    return 0;
}
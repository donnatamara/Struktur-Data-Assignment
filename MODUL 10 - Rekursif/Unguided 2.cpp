#include <iostream>

using namespace std;

int faktorialA(int n);

int faktorialB(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * faktorialA(n - 1);
    }
}

int faktorialA(int n)
{
    return faktorialB(n);
}

int main()
{
    int num;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    }
    else
    {
        int hasil = faktorialB(num);
        cout << "Faktorial dari " << num << " adalah " << hasil << endl;
    }

    return 0;
}
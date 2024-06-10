#include <iostream>
using namespace std;

void bubbleSort(int data, int n, int &index)
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            temp = index[j];
            index[j] = index[j + 1];
            index[j + 1] = temp;
        }
    }
}

void printArray(int data, int n, int &index)
{
    for (int i = 0; i < n; i++)
    {
    }
    return 0;
}

int main()
{
    int data = {5, 1, 4, 2, 8};
    int hasil;

    cout << "data sebelum terurut" << data << endl;
    cout << "data setelah terurut" << hasil << endl;

    return 0;
}

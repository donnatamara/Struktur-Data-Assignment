#include <iostream>
using namespace std;

void bubble_sort(char arr[][10], int length)
{
    bool not_sorted = true;
    int j = 0;
    char tmp;
    // looping sampai array terurut
    while (not_sorted)
    {
        not_sorted = false;
        j++;
        // Looping sepanjang array kecuali elemen terakhir
        for (int i = 0; i < length - j; i++)
        {
            bool tukar = false;
            for (int k = 0; k < 10; k++)
            {
                //membandingkan karakter pada indeks yang sama di string ini dan berikutnya
                if (arr[i][k] > arr[i + 1][k])
                {
                    tukar = true;
                    break;
                }
                else if (arr[i][k] < arr[i + 1][k])
                {
                    break;
                }
            }
            if (tukar)
            {
                // Menukar elemen
                char temp[10]; // Penyimpanan array sementara
                for (int k = 0; k < 10; k++)
                {
                    temp[k] = arr[i][k];
                }
                for (int k = 0; k < 10; k++)
                {
                    arr[i][k] = arr[i + 1][k];
                }
                for (int k = 0; k < 10; k++)
                {
                    arr[i + 1][k] = temp[k];
                }
                not_sorted = true;
            } // end of it
        }     // end of for loop
    }         // end of while loop
} // end of bubble_sort
// Print array
void print_array(char a[][10], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{

    int length = 10;
    char nama_warga[][10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Urutan nama sebelum sorting: " << endl;
    print_array(nama_warga, length);

    bubble_sort(nama_warga, length);

    cout << "\nUrutan nama setelah sorting: " << endl;
    print_array(nama_warga, length);

    return 0;
}
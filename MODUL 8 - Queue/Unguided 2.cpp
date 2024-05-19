#include <iostream>

using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    Mahasiswa *next;
};

Mahasiswa *front = NULL;
Mahasiswa *back = NULL;

bool isEmpty()
{
    return front == NULL;
}

void enqueueAntrian(string nama, string nim)
{
    Mahasiswa *newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Mahasiswa *temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue()
{
    int count = 0;
    Mahasiswa *current = front;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeueAntrian();
    }
}

void viewQueue()
{
    cout << "Data antrian mahasiswa: " << endl;
    Mahasiswa *current = front;
    int index = 1;
    while (current != NULL)
    {
        cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
        index++;
    }
}

int main()
{
    enqueueAntrian("Donna", "2311110014");
    enqueueAntrian("Dundun", "2311110114");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}

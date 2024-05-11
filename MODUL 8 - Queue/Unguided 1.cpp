#include <iostream>

using namespace std;

struct Mahasiswa
{
    string data;
    Mahasiswa *next;
};

Mahasiswa *front = NULL;
Mahasiswa *back = NULL;

bool isEmpty()
{
    return front == NULL;
}

void enqueueAntrian(string data)
{
    Mahasiswa *newNode = new Mahasiswa;
    newNode->data = data;
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
    cout << "Data antrian teller: " << endl;
    Mahasiswa *current = front;
    int index = 1;
    while (current != NULL)
    {
        cout << index << ". " << current->data << endl;
        current = current->next;
        index++;
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
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
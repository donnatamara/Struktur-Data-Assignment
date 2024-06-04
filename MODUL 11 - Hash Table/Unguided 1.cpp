#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

const int TABLE_SIZE = 11;

class HashNode
{
public:
    string nim;
    int grade;

    HashNode(string nim, int grade)
    {
        this->nim = nim;
        this->grade = grade;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];
    list<string> inputOrder; 

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string nim, int grade)
    {
        int hash_val = hashFunc(nim);

        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                node->grade = grade;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim, grade));
        inputOrder.push_back(nim); 
    }

    void remove(string nim)
    {
        int hash_val = hashFunc(nim);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->nim == nim)
            {
                delete *it; 
                table[hash_val].erase(it);
                inputOrder.remove(nim); 
                return;
            }
        }
    }

    string searchByNim(string nim)
    {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                return "NIM: " + node->nim + ", Nilai: " + to_string(node->grade);
            }
        }
        return "Mahasiswa tidak ditemukan";
    }

    vector<string> searchByGradeRange(int minGrade, int maxGrade)
    {
        vector<string> results;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            for (auto node : table[i])
            {
                if (node->grade >= minGrade && node->grade <= maxGrade)
                {
                    results.push_back("NIM: " + node->nim + ", Nilai: " + to_string(node->grade));
                }
            }
        }
        return results;
    }

    void print()
    {
        int count = 1;
        for (const auto &nim : inputOrder)
        {
            int hash_val = hashFunc(nim);
            for (auto node : table[hash_val])
            {
                if (node->nim == nim)
                {
                    cout << count << ". NIM: " << node->nim << ", Nilai: " << node->grade << endl;
                    count++;
                }
            }
        }
    }
};

void menu()
{
    cout << "Menu:\n";
    cout << "1. Tambah data mahasiswa\n";
    cout << "2. Hapus data mahasiswa\n";
    cout << "3. Cari data NIM mahasiswa\n";
    cout << "4. Cari data nilai mahasiswa (80-90)\n";
    cout << "5. Tampilkan semua data mahasiswa\n";
    cout << "6. Keluar\n";
    cout << "Pilih opsi: ";
}

int main()
{
    HashMap student_map;
    int choice;
    string nim;
    int grade;

    while (true)
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan nilai: ";
            cin >> grade;
            student_map.insert(nim, grade);
            break;
        case 2:
            cout << "Masukkan NIM yang akan dihapus: ";
            cin >> nim;
            student_map.remove(nim);
            break;
        case 3:
            cout << "Masukkan NIM yang akan dicari: ";
            cin >> nim;
            cout << student_map.searchByNim(nim) << endl;
            break;
        case 4:
        {
            vector<string> results = student_map.searchByGradeRange(80, 90);
            for (const auto &res : results)
            {
                cout << res << endl;
            }
            if (results.empty())
            {
                cout << "Data tidak ditemukan" << endl;
            }
            break;
        }
        case 5:
            student_map.print();
            break;
        case 6:
            cout << "Keluar dari program" << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}

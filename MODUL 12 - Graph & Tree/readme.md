# <h1 align="center">Laporan Praktikum Modul Graph dan Tree </h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### Graph


### Tree



## Guided 
### 1. Guided 1

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

#### Output:


#### Full code Screenshot:



### Guided 2

```C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one->right = five;
    // 7
    // /\
    // 1 9
    // 0 5

    nine->left = eight;
    // 7
    // /\
    // 1 9
    // / \ / \
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;


    return 0;
}
```

#### Output:


Kode di atas adalah kode program yang menggunakan struktur data binary tree. Pertama program akan mendeklarasikan sebuah struktur data bernama `TNode` yang didalamnya memiliki tiga anggota, yaitu `data` untuk menyimpan nilai integer, `left` untuk pointer ke simpul anak kiri, dan `right` untuk pointer ke simpul anak kanan. Selanjutnya, program mendefinisikan tiga fungsi (`preOrder`, `inOrder`, dan `postOrder`) untuk melakukan penelusuran (traversal) pada pohon biner untuk mencetak nilai-nilai simpul sesuai dengan urutan traversal yang akan dipilih. Pada fungsi `main`, program akan membuat simpul-simpul dengan nilai-nilai tertentu dan menghubungkannya untuk membentuk binary tree yang diinginkann, kemudian melakukan penulusuran pada binary tree menggunakan fungsi-fungsi penelusuran yang telah didefinisikan untuk mencetak nilai-nilai simpul sesuai dengan urutan penelusuran yang dipilih, yaitu pre-order, in-order, dan post-order. Lalu kembalikan nilai 0 yang mana progaram telah berhasil berjalan dengan sukses.

#### Full code Screenshot:



## Unguided

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.


```C++
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
```

#### Output:


#### Full code Screenshot:

### 2.	Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!


```C++
#include <iostream>
#include <queue>

using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(TNode *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node)
{
    if (node != nullptr)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node)
{
    if (node != nullptr)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void displayChildAndDescendant(TNode *node)
{
    if (node == nullptr)
        return;

    cout << "Children of " << node->data << ": ";
    if (node->left != nullptr)
        cout << node->left->data << " ";
    if (node->right != nullptr)
        cout << node->right->data << " ";
    cout << endl;

    cout << "Descendants of " << node->data << ": ";
    queue<TNode *> q;
    q.push(node->left);
    q.push(node->right);
    while (!q.empty())
    {
        TNode *current = q.front();
        q.pop();
        if (current != nullptr)
        {
            cout << current->data << " ";
            q.push(current->left);
            q.push(current->right);
        }
    }
    cout << endl;
}

void addNode(TNode *root)
{
    int parentData;
    cout << "Enter data for the parent node: ";
    cin >> parentData;

    int childData;
    cout << "Enter data for the child node: ";
    cin >> childData;

    TNode *parentNode = nullptr;
    queue<TNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TNode *current = q.front();
        q.pop();
        if (current->data == parentData)
        {
            parentNode = current;
            break;
        }
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }

    if (parentNode == nullptr)
    {
        cout << "Parent node not found. Please try again." << endl;
        return;
    }

    TNode *childNode = new TNode(childData);
    if (parentNode->left == nullptr)
        parentNode->left = childNode;
    else
        parentNode->right = childNode;
}

void showChildAndDescendant(TNode *root)
{
    cout << "Enter data for a node to display its children and descendants: ";
    int nodeData;
    cin >> nodeData;

    queue<TNode *> q;
    q.push(root);
    TNode *selectedNode = nullptr;
    while (!q.empty())
    {
        TNode *current = q.front();
        q.pop();
        if (current->data == nodeData)
        {
            selectedNode = current;
            break;
        }
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }

    if (selectedNode != nullptr)
    {
        displayChildAndDescendant(selectedNode);
    }
    else
    {
        cout << "Node not found." << endl;
    }
}

int main()
{
    cout << "Enter data for the root node: ";
    int rootData;
    int DonnaNurTamara_2311110014;
    cin >> rootData;

    TNode *root = new TNode(rootData);

    char choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add a new node\n";
        cout << "2. PreOrder traversal\n";
        cout << "3. InOrder traversal\n";
        cout << "4. PostOrder traversal\n";
        cout << "5. Display children and descendants of a node\n";
        cout << "6. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            addNode(root);
            break;
        case '2':
            cout << "PreOrder traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case '3':
            cout << "InOrder traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case '4':
            cout << "PostOrder traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case '5':
            showChildAndDescendant(root);
            break;
        case '6':
            cout << "Thank you, program terminated." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != '6');

    return 0;
}
```

#### Output:


#### Full code Screenshot:


## Kesimpulan

Kesimpulannya, 



## Referensi

[1] 
# <h1 align="center">Laporan Praktikum Modul Graph dan Tree </h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### Graph
Graph adalah struktur data yang terdiri dari set objek (simpul atau vertex) yang terhubung oleh satu set sambungan (sisi atau edge). Secara formal, graph G didefinisikan sebagai pasangan himpunan (V, E), di mana V adalah himpunan simpul dan E adlah himpunan sisi. Setiap sisi e di E menghubungkan dua simpul yang berbeda u dan v di V [3].

Ada beberapa jeni graph berdasarkan sifat-sifatnya, yaitu:
- Graph berarah (directed graph), setiap sisi memiliki arah sehingga sisi (u, v) berbesa dengan sisi (v, u) [3].
- Graph tak berarah (undirected graph), setiap sisi tidak memiliki arah, sehingga sisi (u, v) sama dengan sisi (v, u) [3].
- Graph berbobot (weighted graph), setiap sisi memiliki bobot atau nilai numerik yang menyatakan biaya atau jarak [3].

#### Graph Traversal
Menemukan lintasan atau rute dalam graf. Contoh algoritma yang digunakan adalah Depth First Search (DFS), Breadth-First Search (BFS), Dijkstra's
Algorithm, Search Algorithm, dan lain-lain [1].


### Tree
Tree merupakan struktur data hierarki yang terdiri dari node-node yang saling terhubung. Setiap tree memiliki satu node khusus yang disebut root node. Selain root node, tree juga memiliki node-node lain yang disebut shild node. Child node yang tidak memiliki child nodenya sendiri disebuh leaf node[4]. Tree dapat berguna untuk menyimpan dan memanipulasi data hierarki, setelah membuat pohon, hitung nilainya dalam urutan yang berbeda dan mencari nilai di dalam pohon [2]. 

Hubungan antara node-node dalam tree adalah seperti root node tidak memiliki parent node, setiap child node memiliki tapt satu parent node, setiap leaf node tidak memiliki child node [4].

Sebuah pohon terdiri dari simpul-simpul yang dihubungkan oleh cabang-cabang. Biasanya, simpul berisi beberapa jenis data. Setiap simpul dalam pohon memiliki satu simpul induk, kecuali satu simpul akar yang unik, yang tidak memiliki induk. Sebuah simpul yang tidak memiliki anak disebut simpul daun atau simpul eksternal. Sebuah simpul yang memiliki setidaknya satu anak disebut simpul internal [2].
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/d027cc59-06b3-4eaf-8bfd-dceb039b2c02) 

#### Binary Tree
Binary tree merupakan struktur data hierarki yang terdiri dari node-node yang saling terhubung [4].
Memiliki karakteristik maksimum child adalah 2 (left child dan right child). Complete binary tree apabila semua node kecuali leaf memiliki 0 atau 2 child. Subtree pada heap tree dapat memiliki 0 atau 2 child. Subtree pada pada Heap Tree dapat memiliki path length yang berbeda Skewed Binary Tree (Miring) : Bila semua node, kecuali Leaf memiliki hanya 1 child. Full Binary Tree : Bila semua node kecuali Leaf memiliki 2 Child dan semua subtree harus memiliki path yang sama [1].

Pembentukan Binary Tree berdasarkan Preorder,
Inorder atau Postorder Untuk membentuk suatu binary tree
berdasarkan preorder, inorder atau postorder dapat dilakukan
dengan syarat menggunakan 2 dari tiga penelusuran tersebut
dan salah satunya harus inorder [1]. 

#### Tree Tranversal
Melakukan pengolahan atau pencarian pada struktur data pohon. Contoh algoritma yang digunakan adalah Inorder Tranversal, Preorder Tranversal, Postorder Tranversal, dan lain-lain [1].


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
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/5c8a60a2-25ae-4762-b848-1b4e92d657ea)

Kode di atas adalah kode program yang mengimplementasikan struktur data graph. Program dimulai dengan deklarasi array `simpul` dengan panjang 7 yang berisi nama-nama kota dan matriks `busur` berukuran 7x7 yang menyimpan bobot busur antara simpul-simpul dalam graph. Fungsi `tampilGraph()` digunakan untuk menampilkan representasi adjacency list dari graph, di mana loop pertama mengiterasi setiap baris (simpul awal), menampilkan nama simpul awal dengan format rata kiri dan lebar 15 karakter, diikuti oleh loop kedua yang mengiterasi setiap kolom (simpul tujuan). Jika ada busur dari simpul awal ke simpul tujuan, nama simpul tujuan dan bobot busur ditampilkan dalam format `nama_simpul_tujuan (bobot)`, setelah semua kolom diperiksa, program akan pindah ke baris baru untuk ke simpul berikutnya, Pada fungsi `main` didalamnya akan memanggil `tampilGraph` untuk menampilkan graph ke layar dan mengakhiri program dengan nilai `0`, menunjukkan program berhasil berjalan tanpa error. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/40a1c08f-3fd2-4ff7-af1a-98d094a1bf47)


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
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/ed22fadc-e751-4361-bb43-9b055a7b98c8)

Kode di atas adalah kode program yang menggunakan struktur data binary tree. Pertama program akan mendeklarasikan sebuah struktur data bernama `TNode` yang didalamnya memiliki tiga anggota, yaitu `data` untuk menyimpan nilai integer, `left` untuk pointer ke simpul anak kiri, dan `right` untuk pointer ke simpul anak kanan. Selanjutnya, program mendefinisikan tiga fungsi (`preOrder`, `inOrder`, dan `postOrder`) untuk melakukan penelusuran (traversal) pada pohon biner untuk mencetak nilai-nilai simpul sesuai dengan urutan traversal yang akan dipilih. Pada fungsi `main`, program akan membuat simpul-simpul dengan nilai-nilai tertentu dan menghubungkannya untuk membentuk binary tree yang diinginkann, kemudian melakukan penulusuran pada binary tree menggunakan fungsi-fungsi penelusuran yang telah didefinisikan untuk mencetak nilai-nilai simpul sesuai dengan urutan penelusuran yang dipilih, yaitu pre-order, in-order, dan post-order. Lalu kembalikan nilai 0 yang mana progaram telah berhasil berjalan dengan sukses.

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/9ba83fb6-6df9-4e3c-abf0-8a21e3e896ce)



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
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/0db4bf91-4201-46d2-ba5d-2fc9597e08d8)

Kode di atas adalah kode program untuk membuat dan menampilkan matriks bobot dari beberapa simpul (kota) yang diinputkan oleh pengguna. Pertama, program meminta pengguna untuk memasukkan jumlah simpul dan menyimpan nilainya dalam variabel `n`. Selanjutnya, pengguna diminta untuk memasukkan nama setiap simpul, yang disimpan dalam array `simpul_kota`. Setelah itu, pengguna memasukkan bobot antara setiap pasangan simpul, yang disimpan dalam array dua dimensi `bobot`. Program kemudian menampilkan matriks bobot dalam bentuk tabel yang rapi, dengan menggunakan `setw(8)` untuk mengatur lebar kolom. Setiap baris tabel dimulai dengan nama simpul, diikuti oleh bobot antar simpul. Program mengakhiri eksekusinya dengan mengembalikan nilai 0 yang menandakan bahwa program telah sukses dijalankan. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/c4086d75-85b7-4759-b391-32741df7e3ac)


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

Kode di atas adalah kode program yang menggunakan sebuah binary tree dengan menampilkan menu-menu yang dapat pengguna akses untuk memilihnya. Pertama, program akan meminta pengguna untuk memasukkan data untuk node akar, yang kemudian digunakan untuk membuat pohon. Program menyediakan menu dengan opsi untuk menambahkan node baru, melakukan tranversal (PreOrder, InOrder, dan PostOrder), menampilkan anak dan keturunan dari node tertentu, atau keluar dari program. Saat pengguna memilih untuk menambahkan node baru, program akan meminta data untuk node induk dan anak, lalu menambahkan node anak sesuai dengan struktur pohon. Fungsi traversal digunakan untuk mencetak nilai node dalam urutan yang berbeda, sedangkan fungsi untuk menampilkan anak dan keturunanya menggunakan queue untuk menampilkan secra level-order. Program akan terus menampilkan menu hingga pengguna memilih untuk keluar dari prorgram untuk keluar, memberikan pengalaman yang interaktif dalamnya,, memberikan pengalaman interaktif dalam memanipulasi binary tree. 

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/b91dcc85-caf6-4f4a-86d5-7bb68ea07535)


## Kesimpulan

Kesimpulannya, 



## Referensi

[1] A. S. R. St. MTi, STRUKTUR DATA DAN ALGORITMA DENGAN C++. CV. AA. RIZKY, 2019.

[2] J. Carey, S. Doshi, and P. Rajan, C++ Data structures and algorithm design principles: Leverage the power of modern C++ to build robust and scalable applications. Packt Publishing Ltd, 2019.

[3] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to Algorithms, fourth edition. MIT Press, 2022.

[4] Y. Kanetkar, Data Structures through C++: Experience Data Structures C++ through animations. BPB Publications, 2019.

[5] 


# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>

<p align="center">Donna Nur Tamara</p>

## Dasar Teori

### Rekursif
Rekursif adalah fungsi yang memanggil dirinya sendiri atau metode yang secara langsung atau tidak langsung memanggil dirinya sendiri [1]. 

## Guided 
### Rekursif Langsung (Direct Recursion)

```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }
    
    cout << n << " ";
    countdown(n - 1);
}

int main () {
    cout << "Rekursif Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/562437fb-e45a-414a-b14a-8167184810d8)

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/72641bfd-6346-491a-9cbd-88b582b46228)


### Rekursif Tidak Langsung (Indirect Recursion)

```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung";
    functionA(num);
    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/f76a6ab2-e595-4dfc-9ed0-e9f825d74243)

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/cb5d6807-d28e-4c8a-907a-9490bc71faca)


## Unguided

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>

using namespace std;

int faktorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * faktorial(n - 1);
    }
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
        int hasil = faktorial(num);
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}
```

#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/425fadd2-daa9-424c-98b3-c1e1fe2fc6bc)


#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/a5cd11c6-39d7-4bcb-a716-c4a0ff2fbe0b)


### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
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
```


#### Output:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/6500838f-0d7c-47d0-985e-a747d27fbec9)

#### Full code Screenshot:
![image](https://github.com/donnatamara/Struktur-Data-Assignment/assets/161492059/69a5a9c5-4ca9-449c-9e7c-07dcb927ff13)




## Kesimpulan

Kesimpulannya, 


## Referensi

[1] S. H. S. Kom. MT and I. W. J. S. Kom. MCs, Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi, 2020.
 
[2] 

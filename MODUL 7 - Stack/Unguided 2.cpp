#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  // Deklarasi variabel
  string kalimat;
  stack<char> a;

  // Meminta input kalimat
  cout << "Masukkan Kata ";
  getline(cin, kalimat);

  // Memeriksa apakah kalimat memiliki minimal 3 kata
  if (kalimat.length() < 3)
  {
    cout << "Kalimat harus memiliki minimal 3 kata." << endl;
    return 0;
  }

  // Memasukkan kalimat ke dalam stack
  for (char b : kalimat)
  {
    a.push(b);
  }

  // Membalik kalimat
  kalimat = "";
  while (!a.empty())
  {
    kalimat += a.top();
    a.pop();
  }

  // Menampilkan kalimat yang dibalik
  cout << "Datastack Array : " << endl;
  cout << "Data : " << kalimat << endl;

  return 0;
}

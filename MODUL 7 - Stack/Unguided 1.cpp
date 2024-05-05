#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membersihkan string dari karakter selain huruf
string cleanString(const string &kalimat)
{
  string cleaned;
  for (char a : kalimat)
  {
    if (isalpha(a))
    {
      cleaned += tolower(a); // Mengubah huruf menjadi huruf kecil
    }
  }
  return cleaned;
}

bool isPalindrome(const string &kalimat)
{
  stack<char> huruf;

  // Membersihkan kalimat dari karakter selain huruf dan mengubah huruf menjadi huruf kecil
  string cleaned = cleanString(kalimat);

  // Memasukkan huruf ke dalam stack
  for (char a : cleaned)
  {
    huruf.push(a);
  }

  // Membandingkan huruf dari depan dan belakang menggunakan stack
  for (char a : cleaned)
  {
    char hurufStack = huruf.top();
    huruf.pop();
    if (a != hurufStack)
    {
      return false;
    }
  }

  return true; // Jika semua huruf cocok, kalimat merupakan palindrom
}

int main()
{
  string kalimat;
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  if (isPalindrome(kalimat))
  {
    cout << kalimat << " adalah : palindrom." << endl;
  }
  else
  {
    cout << kalimat << " adalah : bukan palindrom." << endl;
  }

  return 0;
}

#include <iostream>
using namespace std;

void bubbleSort(char arr[], int a) {
  int i, j;
  for (i = 0; i < a - 1; i++) {
    for (j = 0; j < a - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        char temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int a;
  cout << "input <n> = ";
  cin >> a;

  char karakter[a];

  // Meminta user untuk menginputkan karakter
  for (int i = 0; i < a; i++) {
    cout << "Karakter ke-" << i + 1 << ": ";
    cin >> karakter[i];
  }

  // Menampilkan karakter sebelum sorting
  cout << "\nUrutan karakter sebelum sorting:\n";
  for (int i = 0; i < a; i++) {
    cout << karakter[i] << " ";
  }

  // Sorting secara ascending dengan bubble sort
  bubbleSort(karakter, a);

  // Menampilkan karakter setelah ascending sort
  cout << "\n\nUrutan karakter setelah ascending sort:\n";
  for (int i = 0; i < a; i++) {
    cout << karakter[i] << " ";
  }

  // Sorting descending dengan bubble sort
  for (int i = 0; i < a / 2; i++) {
    char temp = karakter[i];
    karakter[i] = karakter[a - i - 1];
    karakter[a - i - 1] = temp;
  }

  // Menampilkan karakter setelah descending sort
  cout << "\n\nUrutan karakter setelah descending sort:\n";
  for (int i = 0; i < a; i++) {
    cout << karakter[i] << " ";
  }

  cout << endl;

  return 0;
}
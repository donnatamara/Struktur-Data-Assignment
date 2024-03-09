#include <iostream>
#include <map>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi map
    map<int, int> nilai;
    nilai[0] = 24;
    nilai[1] = 48;
    nilai[2] = 57;
    nilai[3] = 90;
    nilai[4] = 21;

    // Mencetak nilai dari map
    for (const auto& pair : nilai) {
        cout << "Element " << pair.first + 1 << " : " << pair.second << endl;
    }

    return 0;
}
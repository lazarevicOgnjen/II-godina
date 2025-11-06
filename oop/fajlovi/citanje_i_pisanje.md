```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("primer.txt", ios::in | ios::out | ios::app); 
    // ios::in - za čitanje, ios::out - za pisanje, ios::app - dodavanje na kraj fajla

    if (file.is_open()) {
        file << "Dodajem još jedan red.\n"; // upis
        file.seekg(0); // vraćanje na početak fajla za čitanje
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Nije moguće otvoriti fajl!" << endl;
    }
    return 0;
}
```

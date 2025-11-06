> **citanje liniju po liniju**
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("primer.txt"); // otvara fajl za čitanje
    string line;

    if (inFile.is_open()) {
        while (getline(inFile, line)) { // čitanje liniju po liniju
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Nije moguće otvoriti fajl za čitanje!" << endl;
    }
    return 0;
}
```
<br>

> **citanje rec po rec**
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("primer.txt");
    string rec;

    if (inFile.is_open()) {
        while (inFile >> rec) { // čitanje reč po reč
            cout << rec << endl; // svaka reč u novom redu
        }
        inFile.close();
    } else {
        cout << "Nije moguće otvoriti fajl za čitanje!" << endl;
    }

    return 0;
}
```

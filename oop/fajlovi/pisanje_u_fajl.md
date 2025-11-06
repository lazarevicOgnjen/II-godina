```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("primer.txt"); // otvara fajl za pisanje
    if (outFile.is_open()) {
        outFile << "Ovo je prvi red u fajlu.\n";
        outFile << "Ovo je drugi red.\n";
        outFile.close(); // obavezno zatvoriti fajl
        cout << "Podaci su upisani u fajl." << endl;
    } else {
        cout << "Nije moguće otvoriti fajl za pisanje!" << endl;
    }
    return 0;
}
```

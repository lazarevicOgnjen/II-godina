#include "IspitPriprema.h"
#include "IspitniMaterijal.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void zadatak1() {
    float vJedinicno = 10;
    
    try {
        // Testiranje pojedinačnih materijala
        IspitniMaterijal* p1 = new Lekcija(1001, 2.0, 1.5);
        cout << *p1 << endl;
        
        IspitniMaterijal* p2 = new Zadatak(1002, 2.4, 20);
        cout << *p2 << endl;
        
        // Testiranje kolekcije
        float tezine[] = { 1.5, 2.7, 0.8, 3.2, 1.8 };
        float duzina[] = { 1.2, 3.1, 2.5, 3.4, 4.1 };
        int kod[] = { 100, 20, 40, 50, 30 };
        
        IspitPriprema* pIspit = new IspitPriprema(20);
        
        for (int i = 0; i < 5; i++) {
            Lekcija* lekcija = new Lekcija(2 * i + 1, tezine[i], duzina[i]);
            pIspit->Dodaj(lekcija);
            Zadatak* zadatak = new Zadatak(2 * i + 2, tezine[i], kod[i]);
            pIspit->Dodaj(zadatak);
        }
        
        cout << *pIspit << endl;
        
        pIspit->Obrisi(3);
        cout << *pIspit << endl;
        
        pIspit->Savladaj(2);
        cout << *pIspit << endl;
        
        int sav = pIspit->UkupnoSavladanih();
        cout << sav << endl;
        
        float vreme = pIspit->UkupnoVreme(vJedinicno);
        cout << vreme << endl;
        
        IspitniMaterijal* matMin = nullptr, * matMax = nullptr;
        pIspit->VratiNaj(vJedinicno, &matMin, &matMax);
        cout << *matMin << endl << *matMax << endl;
        
        delete pIspit;
        delete p1;
        delete p2;
    }
    catch (const exception& e) {
        cout << "Greska: " << e.what() << endl;
    }
}

int main() {
    zadatak1();
    return 0;
}

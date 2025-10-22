#include "Ispit.h"
#include "Lesson.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void zadatak2() {
    int maxPodataka = 8, brojPodataka = 9;
    
    // Test za float (proste lekcije)
    try {
        float tezine[] = { 1.5, 2.7, 3.2, 0.8, 1.8, 4.1, 2.5, 2.3, 3.6 };
        Ispit<float> ispit(maxPodataka);
        
        for (int i = 0; i < brojPodataka; i++)
            ispit.Dodaj(tezine[i]);
        cout << ispit << endl;
        
        ispit.Izbaci(4, 3);
        cout << ispit << endl;
        
        float ukupno = ispit.Ukupno();
        cout << ukupno << endl;
        
        float vrednost = 2.0; 
        float ukupnaVrednost = 0;
        int broj = ispit.UkupniBrojVrednost(vrednost, ukupnaVrednost);
        cout << broj << " " << ukupnaVrednost << endl;
        
        float min = 0.0; 
        float max = 1000.0;
        ispit.minMax(1, 4, min, max);
        cout << min << " " << max << endl;
        
        ispit.Sacuvaj("IspProst.txt");
        
        Ispit<int> ispUc(maxPodataka);
        ispUc.Ucitaj("IspProst.txt");
        cout << ispUc << endl;
    }
    catch (const exception& e) {
        cout << "Greska: " << e.what() << endl;
    }

    // Test za NormalLesson
    try {
        char naziv[][8] = { "prva", "druga", "treca", "cetvrta", "peta",
                           "sesta", "sedma", "osma", "deveta" };
        float tezine[] = { 1.5, 2.7, 3.2, 0.8, 1.8, 4.1, 2.5, 2.3, 3.6 };
        float duzina[] = { 1.2, 3.1, 2.5, 3.4, 4.1, 1.7, 2.2, 3.7, 2.8 };
        Ispit<NormalLesson> ispNor(maxPodataka);
        
        for (int i = 0; i < brojPodataka; i++) {
            NormalLesson lekcija(naziv[i], tezine[i], duzina[i]);
            ispNor.Dodaj(lekcija);
        }
        
        cout << ispNor << endl;
        
        ispNor.Izbaci(4, 3);
        cout << ispNor << endl;
        
        float ukupno = ispNor.Ukupno();
        cout << ukupno << endl;
        
        float vrednost = 2.0; 
        float ukupnaVrednost = 0;
        int broj = ispNor.UkupniBrojVrednost(vrednost, ukupnaVrednost);
        cout << broj << " " << ukupnaVrednost << endl;

        NormalLesson min, max;
        ispNor.minMax(1, 4, min, max);
        cout << min << " " << max << endl;
        
        ispNor.Sacuvaj("IspNormal.txt");
        
        Ispit<NormalLesson> ispNorUc(maxPodataka);
        ispNorUc.Ucitaj("IspNormal.txt");
        cout << ispNorUc << endl;
    }
    catch (const exception& e) {
        cout << "Greska: " << e.what() << endl;
    }
}

int main() {
    zadatak2();
    return 0;
}

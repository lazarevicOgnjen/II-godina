#include <iostream>
#include "lezajki.h"
using namespace std;

int main() {
    Kafic kafic;

    // Iznajmljivanje lezajki
    kafic.iznajmiLezajke(new Lezajki(1, 5, 100, 50));
    kafic.iznajmiLezajke(new LezajkiSaDod(2, 3, 120, 60, 2));
    kafic.iznajmiLezajke(new Lezajki(3, 2, 90, 30));

    cout << "Spisak iznajmljenih lezajki:" << endl;
    kafic.ispisiLezajke();

    // Oslobadjanje lezajki
    kafic.oslobodiLezajke(2);
    cout << "\nNakon oslobadjanja lezajki sa rednim brojem 2:" << endl;
    kafic.ispisiLezajke();

    cout << "\nUkupno trenutno lezajki: " << kafic.ukupnoLezajki() << endl;
    cout << "Ukupno naplaceno: " << kafic.ukupnoNaplaceno() << endl;

    double provera = 150;
    cout << "Postoji li lezajki sa cenom vecom od " << provera << "? "
         << (kafic.postojiVecaOd(provera) ? "Da" : "Ne") << endl;

    kafic.maksimalniKupac();

    return 0;
}

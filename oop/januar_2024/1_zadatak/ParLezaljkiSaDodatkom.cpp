#include "ParLezaljkiSaDodatkom.h"
#include <iostream>
using namespace std;

ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(int r, int rd, double cl, double cn, int bd)
    : ParLezaljki(r, rd, cl, cn), brojDodatnih(bd) {}

ParLezaljkiSaDodatkom::~ParLezaljkiSaDodatkom() {}

double ParLezaljkiSaDodatkom::UkupnoZaNaplatu() const {
    double povecanje = 1 + 0.4 * brojDodatnih;
    double popust = (40 - 2 * red - 5 * brojDodatnih) / 100.0;
    return cenaLezaljki * povecanje + cenaNapicima * (1 - popust);
}

void ParLezaljkiSaDodatkom::Prikazi() const {
    cout << "Par lezaljki + dodatne [rbr=" << rbr
         << ", red=" << red
         << ", dodatne=" << brojDodatnih
         << ", cena lezaljki=" << cenaLezaljki
         << ", napici=" << cenaNapicima
         << ", ukupno=" << UkupnoZaNaplatu() << "]" << endl;
}

ostream& operator<<(ostream& os, const ParLezaljkiSaDodatkom& p) {
    os << "ParLezaljkiSaDodatkom(" << p.rbr << ", " << p.red << ", "
       << p.cenaLezaljki << ", " << p.cenaNapicima
       << ", dodatne=" << p.brojDodatnih << ")";
    return os;
}

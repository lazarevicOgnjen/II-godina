#include "ParLezaljki.h"

ParLezaljki::ParLezaljki(int r, int rd, double cl, double cn)
    : rbr(r), red(rd), cenaLezaljki(cl), cenaNapicima(cn) {}

ParLezaljki::~ParLezaljki() {}

double ParLezaljki::UkupnoZaNaplatu() const {
    double popust = (40 - 2 * red) / 100.0;
    return cenaLezaljki + cenaNapicima * (1 - popust);
}

void ParLezaljki::Prikazi() const {
    cout << "Par lezaljki [rbr=" << rbr
         << ", red=" << red
         << ", cena lezaljki=" << cenaLezaljki
         << ", napici=" << cenaNapicima
         << ", ukupno=" << UkupnoZaNaplatu() << "]" << endl;
}

ostream& operator<<(ostream& os, const ParLezaljki& p) {
    os << "ParLezaljki(" << p.rbr << ", " << p.red << ", "
       << p.cenaLezaljki << ", " << p.cenaNapicima << ")";
    return os;
}

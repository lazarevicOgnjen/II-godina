#include "Lezaljka.h"

Lezaljka::Lezaljka(int broj, double cena)
    : brojLezaljki(broj), cenaPica(cena) {}

double Lezaljka::Ukupno() const {
    return brojLezaljki * cenaPica;
}

void Lezaljka::Prikazi() const {
    cout << "[Broj: " << brojLezaljki << ", Cena pica: " << cenaPica << ", Ukupno: " << Ukupno() << "]";
}

ostream& operator<<(ostream& os, const Lezaljka& l) {
    os << "[Broj: " << l.brojLezaljki << ", Cena pica: " << l.cenaPica << ", Ukupno: " << l.Ukupno() << "]";
    return os;
}

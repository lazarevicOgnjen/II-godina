#include "IspitniMaterijal.h"

// IspitniMaterijal implementation
IspitniMaterijal::IspitniMaterijal(int oznaka, float tezina, bool savladao) 
    : _oznaka(oznaka), _tezina(tezina), _savladao(savladao) {}

std::ostream& operator<<(std::ostream& os, const IspitniMaterijal& materijal) {
    materijal.prikazi(os);
    return os;
}

// Lekcija implementation
Lekcija::Lekcija(int oznaka, float tezina, float duzina, bool savladao) 
    : IspitniMaterijal(oznaka, tezina, savladao), _duzina(duzina) {}

float Lekcija::vremePotrebno(float vremeJedinicno) const {
    return _duzina * _tezina * vremeJedinicno;
}

void Lekcija::prikazi(std::ostream& os) const {
    os << "Lekcija[Oznaka:" << _oznaka << ", Tezina:" << _tezina 
       << ", Duzina:" << _duzina << ", Savladao:" << (_savladao ? "DA" : "NE") << "]";
}

// Zadatak implementation
Zadatak::Zadatak(int oznaka, float tezina, int brojLinija, bool savladao) 
    : IspitniMaterijal(oznaka, tezina, savladao), _brojLinija(brojLinija) {}

float Zadatak::vremePotrebno(float vremeJedinicno) const {
    return _brojLinija * _tezina * vremeJedinicno * 0.05f;
}

void Zadatak::prikazi(std::ostream& os) const {
    os << "Zadatak[Oznaka:" << _oznaka << ", Tezina:" << _tezina 
       << ", Linije:" << _brojLinija << ", Savladao:" << (_savladao ? "DA" : "NE") << "]";
}

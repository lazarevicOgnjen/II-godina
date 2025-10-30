#include "LekcijaNormalna.h"
#include <cstring>

void LekcijaNormalna::kopiraj(const char* src, char*& dest) {
    if (dest != nullptr) {
        delete[] dest;
    }
    if (src != nullptr) {
        dest = new char[strlen(src) + 1];
        strcpy(dest, src);
    } else {
        dest = nullptr;
    }
}

LekcijaNormalna::LekcijaNormalna() : naziv(nullptr), tezina(0), duzina(0) {
    kopiraj("", naziv);
}

LekcijaNormalna::LekcijaNormalna(const char* n, float t, float d) 
    : naziv(nullptr), tezina(t), duzina(d) {
    kopiraj(n, naziv);
}

LekcijaNormalna::LekcijaNormalna(const LekcijaNormalna& l) 
    : naziv(nullptr), tezina(l.tezina), duzina(l.duzina) {
    kopiraj(l.naziv, naziv);
}

LekcijaNormalna::~LekcijaNormalna() {
    delete[] naziv;
}

LekcijaNormalna& LekcijaNormalna::operator=(const LekcijaNormalna& l) {
    if (this != &l) {
        kopiraj(l.naziv, naziv);
        tezina = l.tezina;
        duzina = l.duzina;
    }
    return *this;
}

bool LekcijaNormalna::operator>(const LekcijaNormalna& l) const {
    return tezina > l.tezina;
}

bool LekcijaNormalna::operator<(const LekcijaNormalna& l) const {
    return tezina < l.tezina;
}

bool LekcijaNormalna::operator>=(float vrednost) const {
    return tezina >= vrednost;
}

LekcijaNormalna::operator float() const {
    return tezina;
}

std::ostream& operator<<(std::ostream& os, const LekcijaNormalna& l) {
    os << l.naziv << " " << l.tezina << " " << l.duzina;
    return os;
}

std::istream& operator>>(std::istream& is, LekcijaNormalna& l) {
    char tempNaziv[100];
    is >> tempNaziv >> l.tezina >> l.duzina;
    l.setNaziv(tempNaziv);
    return is;
}

void LekcijaNormalna::setNaziv(const char* n) {
    kopiraj(n, naziv);
}

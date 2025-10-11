#include "lezajki.h"
#include <iostream>
using namespace std;

// ------------------- Lezajki -------------------
Lezajki::Lezajki(int rb, int r, double cl, double cn)
    : redniBroj(rb), red(r), cenaLezajki(cl), cenaNapica(cn) {}

Lezajki::~Lezajki() {}

int Lezajki::getRedniBroj() const { return redniBroj; }
int Lezajki::getRed() const { return red; }
double Lezajki::getCenaNapica() const { return cenaNapica; }

double Lezajki::ukupnaCena() const {
    double popust = (40 - 2 - red) / 100.0;
    return cenaLezajki + cenaNapica * (1 - popust);
}

void Lezajki::ispisi() const {
    cout << "Redni broj: " << redniBroj
         << ", Red: " << red
         << ", Cena lezajki: " << cenaLezajki
         << ", Cena napica: " << cenaNapica
         << ", Ukupno: " << ukupnaCena() << endl;
}

// ------------------- LezajkiSaDod -------------------
LezajkiSaDod::LezajkiSaDod(int rb, int r, double cl, double cn, int dl)
    : Lezajki(rb, r, cl, cn), dodatneLezajke(dl) {}

double LezajkiSaDod::ukupnaCena() const {
    int br = getRed();
    int bdl = dodatneLezajke;
    double popust = (40 - 2 - br - 5 - bdl) / 100.0;
    double baza = Lezajki::ukupnaCena() * (1 + 0.4 - bdl);
    return baza + getCenaNapica() * (1 - popust);
}

void LezajkiSaDod::ispisi() const {
    Lezajki::ispisi();
    cout << "Dodatne lezajke: " << dodatneLezajke << endl;
}

// ------------------- Kafic -------------------
Kafic::Kafic() : kolekcija(nullptr), brojLezajki(0), naplaceno(0) {}

Kafic::~Kafic() {
    for (int i = 0; i < brojLezajki; i++)
        delete kolekcija[i];
    delete[] kolekcija;
}

void Kafic::ukloniPoIndexu(int index) {
    delete kolekcija[index];
    for (int i = index; i < brojLezajki - 1; i++)
        kolekcija[i] = kolekcija[i + 1];
    brojLezajki--;
}

void Kafic::iznajmiLezajke(Lezajki* l) {
    Lezajki** novi = new Lezajki*[brojLezajki + 1];
    for (int i = 0; i < brojLezajki; i++)
        novi[i] = kolekcija[i];
    novi[brojLezajki] = l;
    delete[] kolekcija;
    kolekcija = novi;
    brojLezajki++;
}

void Kafic::oslobodiLezajke(int redniBroj) {
    for (int i = 0; i < brojLezajki; i++) {
        if (kolekcija[i]->getRedniBroj() == redniBroj) {
            naplaceno += kolekcija[i]->ukupnaCena();
            ukloniPoIndexu(i);
            break;
        }
    }
}

void Kafic::ispisiLezajke() const {
    if (brojLezajki == 0) {
        cout << "Trenutno nema iznajmljenih lezajki." << endl;
        return;
    }
    for (int i = 0; i < brojLezajki; i++)
        kolekcija[i]->ispisi();
}

int Kafic::ukupnoLezajki() const { return brojLezajki; }

double Kafic::ukupnoNaplaceno() const { return naplaceno; }

bool Kafic::postojiVecaOd(double vrednost) const {
    for (int i = 0; i < brojLezajki; i++)
        if (kolekcija[i]->ukupnaCena() > vrednost)
            return true;
    return false;
}

void Kafic::maksimalniKupac() const {
    if (brojLezajki == 0) return;
    int idxUkupno = 0, idxNapici = 0;
    double cenaNapiciMax = kolekcija[0]->getCenaNapica();

    for (int i = 1; i < brojLezajki; i++) {
        if (kolekcija[i]->ukupnaCena() > kolekcija[idxUkupno]->ukupnaCena())
            idxUkupno = i;
        if (kolekcija[i]->getCenaNapica() > cenaNapiciMax) {
            cenaNapiciMax = kolekcija[i]->getCenaNapica();
            idxNapici = i;
        }
    }

    cout << "Najveca ukupna cena:" << endl;
    kolekcija[idxUkupno]->ispisi();
    cout << "Najveca cena napica:" << endl;
    kolekcija[idxNapici]->ispisi();
}

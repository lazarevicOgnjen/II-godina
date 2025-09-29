#include "skladiste.h"
#include <iostream>

Skladiste::Skladiste(int k)
    : kapacitet(k), broj(0) {
    niz = new Pice * [kapacitet];
}

Skladiste::~Skladiste() {
    for (int i = 0; i < broj; ++i) delete niz[i];
    delete[] niz;
}

void Skladiste::prosiri() {
    int noviKap = kapacitet * 2;
    Pice** novi = new Pice * [noviKap];
    for (int i = 0; i < broj; ++i) novi[i] = niz[i];
    delete[] niz;
    niz = novi;
    kapacitet = noviKap;
}

void Skladiste::dodaj(Pice* p) {
    if (broj == kapacitet) prosiri();
    for (int i = 0; i < broj; ++i)
        if (niz[i]->jednako(*p)) {
            niz[i]->brojAmbalaza += p->brojAmbalaza;
            delete p;
            return;
        }
    niz[broj++] = p;
}

void Skladiste::izdvoji(const Pice& primer, int koliko) {
    for (int i = 0; i < broj; ++i) {
        if (niz[i]->jednako(primer)) {
            if (niz[i]->getBrojAmbalaza() <= koliko) {
                delete niz[i];
                for (int j = i; j < broj - 1; ++j) niz[j] = niz[j + 1];
                --broj;
            } else {
                niz[i]->brojAmbalaza -= koliko;
            }
            return;
        }
    }
}

void Skladiste::presipaj(const Voda& iz, const Voda& u) {
    int idxIz = -1, idxU = -1;
    for (int i = 0; i < broj; ++i) {
        if (niz[i]->jednako(iz)) idxIz = i;
        if (niz[i]->jednako(u))  idxU  = i;
    }
    if (idxIz == -1 || idxU == -1) return;

    int preliti = niz[idxIz]->getBrojAmbalaza();
    if (preliti > 5) preliti = 5;                 // primer ograničenja
    niz[idxIz]->brojAmbalaza -= preliti;
    niz[idxU ]->brojAmbalaza += preliti;

    if (niz[idxIz]->getBrojAmbalaza() == 0) {
        delete niz[idxIz];
        for (int j = idxIz; j < broj - 1; ++j) niz[j] = niz[j + 1];
        --broj;
    }
}

bool Skladiste::dovoljnaKolicina(float litara) const {
    float ukupno = 0;
    for (int i = 0; i < broj; ++i)
        ukupno += niz[i]->getZapremina() * niz[i]->getBrojAmbalaza();
    return ukupno >= litara;
}

void Skladiste::vratiNaj(Pice*& najjeftinije, Pice*& najskuplje) const {
    if (broj == 0) { najjeftinije = najskuplje = nullptr; return; }
    najjeftinije = najskuplje = niz[0];
    for (int i = 1; i < broj; ++i) {
        if (niz[i]->cena() < najjeftinije->cena()) najjeftinije = niz[i];
        if (niz[i]->cena() > najskuplje ->cena()) najskuplje  = niz[i];
    }
}

std::ostream& operator<<(std::ostream& os, const Skladiste& s) {
    for (int i = 0; i < s.broj; ++i) os << *s.niz[i] << '\n';
    return os;
}

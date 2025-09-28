#include "skladiste.h"
#include <algorithm>
#include <iostream>

Skladiste::Skladiste(int k) : kapacitet(k) {}
Skladiste::~Skladiste() { for (Pice* p : niz) delete p; }

void Skladiste::dodaj(Pice* p) {
    if (niz.size() >= static_cast<size_t>(kapacitet)) {
        delete p;
        return;
    }
    for (Pice* postojece : niz) {
        if (postojece->jednako(*p)) {
            postojece->brojAmbalaza += p->brojAmbalaza;
            delete p;
            return;
        }
    }
    niz.push_back(p);
}

void Skladiste::izdvoji(const Pice& primer, int koliko) {
    for (auto it = niz.begin(); it != niz.end(); ++it) {
        if ((*it)->jednako(primer)) {
            if ((*it)->getBrojAmbalaza() <= koliko) {
                delete *it;
                it = niz.erase(it);
            } else {
                (*it)->brojAmbalaza -= koliko;
            }
            return;
        }
    }
}

void Skladiste::presipaj(const Voda& iz, const Voda& u) {
    auto pronadji = [&](const Voda& vz) -> Pice* {
        for (Pice* p : niz)
            if (p->jednako(vz)) return p;
        return nullptr;
    };
    Pice* pIz = pronadji(iz);
    Pice* pU = pronadji(u);
    if (!pIz || !pU) return;

    int preliti = std::min(pIz->getBrojAmbalaza(), 5);
    pIz->brojAmbalaza -= preliti;
    pU->brojAmbalaza  += preliti;

    if (pIz->brojAmbalaza == 0) {
        niz.erase(std::remove(niz.begin(), niz.end(), pIz), niz.end());
        delete pIz;
    }
}

bool Skladiste::dovoljnaKolicina(float litara) const {
    float ukupno = 0;
    for (const Pice* p : niz)
        ukupno += p->getZapremina() * p->getBrojAmbalaza();
    return ukupno >= litara;
}

void Skladiste::vratiNaj(Pice*& min, Pice*& max) const {
    if (niz.empty()) { min = max = nullptr; return; }
    min = max = niz.front();
    for (const Pice* p : niz) {
        if (p->cena() < min->cena()) min = const_cast<Pice*>(p);
        if (p->cena() > max->cena()) max = const_cast<Pice*>(p);
    }
}

std::ostream& operator<<(std::ostream& os, const Skladiste& s) {
    for (const Pice* p : s.niz) os << *p << '\n';
    return os;
}

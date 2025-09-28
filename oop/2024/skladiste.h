#ifndef SKLADISTE_H
#define SKLADISTE_H

#include "pice.h"
#include <vector>

class Skladiste {
private:
    std::vector<Pice*> niz;
    int kapacitet;

public:
    explicit Skladiste(int k);
    ~Skladiste();

    void dodaj(Pice* p);
    void izdvoji(const Pice& primer, int koliko);
    void presipaj(const Voda& iz, const Voda& u);
    bool dovoljnaKolicina(float litara) const;
    void vratiNaj(Pice*& najjeftinije, Pice*& najskuplje) const;

    friend std::ostream& operator<<(std::ostream& os, const Skladiste& s);
};

#endif

#ifndef SKLADISTE_H
#define SKLADISTE_H

#include "pice.h"

class Skladiste {
private:
    Pice** niz;       // pokazivač na niz pokazivača
    int broj;         // trenutno pića
    int kapacitet;    // maksimalno pića

    void prosiri();   // povećava kapacitet

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

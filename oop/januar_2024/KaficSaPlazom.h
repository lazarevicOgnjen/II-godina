#ifndef KAFICSAPLAZOM_H
#define KAFICSAPLAZOM_H

#include "ParLezaljkiSaDodatkom.h"

class KaficSaPlazom {
    ParLezaljki** niz;
    int kapacitet;
    int brojTrenutnih;
    double naplaceno;

public:
    KaficSaPlazom(int kapacitet = 0);
    ~KaficSaPlazom();

    void Dodaj(ParLezaljki* p);
    void Oslobodi(int rbr);
    int UkupnoLezaljki() const;
    double UkupnaSvotaNovca() const;
    bool PostojiGdeTrebaPlatiti(double svota) const;
    void VratiNajskuplje(ParLezaljki** maxCena, ParLezaljki** maxNapici) const;

    friend ostream& operator<<(ostream& os, const KaficSaPlazom& k);
};

#endif

#ifndef PARLEZALJKISADODATKOM_H
#define PARLEZALJKISADODATKOM_H

#include "ParLezaljki.h"

class ParLezaljkiSaDodatkom : public ParLezaljki {
    int brojDodatnih;

public:
    ParLezaljkiSaDodatkom(int rbr = 0, int red = 0, double cenaLezaljki = 0,
                          double cenaNapicima = 0, int brojDodatnih = 0);
    ~ParLezaljkiSaDodatkom();

    double UkupnoZaNaplatu() const override;
    void Prikazi() const override;

    friend ostream& operator<<(ostream& os, const ParLezaljkiSaDodatkom& p);
};

#endif

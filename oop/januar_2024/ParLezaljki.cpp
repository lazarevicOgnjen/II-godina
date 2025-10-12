#ifndef PARLEZALJKI_H
#define PARLEZALJKI_H

#include <iostream>
using namespace std;

class ParLezaljki {
protected:
    int rbr;
    int red;
    double cenaLezaljki;
    double cenaNapicima;

public:
    ParLezaljki(int rbr = 0, int red = 0, double cenaLezaljki = 0, double cenaNapicima = 0);
    virtual ~ParLezaljki();

    int GetRbr() const { return rbr; }
    int GetRed() const { return red; }

    virtual double UkupnoZaNaplatu() const;
    virtual void Prikazi() const;

    friend ostream& operator<<(ostream& os, const ParLezaljki& p);
};

#endif

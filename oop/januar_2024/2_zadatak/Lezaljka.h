#ifndef LEZALJKA_H
#define LEZALJKA_H

#include <iostream>
using namespace std;

class Lezaljka {
    int brojLezaljki;
    double cenaPica;

public:
    Lezaljka(int broj = 0, double cena = 0);
    ~Lezaljka() = default;

    int GetBroj() const { return brojLezaljki; }
    double GetCena() const { return cenaPica; }

    double Ukupno() const;
    void Prikazi() const;

    friend ostream& operator<<(ostream& os, const Lezaljka& l);
};

#endif

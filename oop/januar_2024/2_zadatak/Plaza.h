#ifndef PLAZA_H
#define PLAZA_H

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Plaza {
    int redovi;
    int kolone;
    T** matrica;

public:
    Plaza(int r = 0, int k = 0);
    ~Plaza();

    void Dodaj(int red, int kol, const T& vrednost);
    void Oslobodi(int red, int kol);
    double Ukupno() const;
    int BrojMesta(int brojLez) const;
    int RedSaNajvise(int& brojLez) const;
    void Sacuvaj(const char* fajl) const;
    void Ucitaj(const char* fajl);

    void Ispisi(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Plaza<T>& p) {
        p.Ispisi(os);
        return os;
    }
};

#include "Plaza.cpp"
#endif

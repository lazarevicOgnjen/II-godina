#include "Plaza.h"
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
Plaza<T>::Plaza(int r, int k) : redovi(r), kolone(k) {
    matrica = new T*[redovi];
    for (int i = 0; i < redovi; i++) {
        matrica[i] = new T[kolone];
        for (int j = 0; j < kolone; j++) {
            matrica[i][j] = T(); // podrazumevana vrednost
        }
    }
}

template <typename T>
Plaza<T>::~Plaza() {
    for (int i = 0; i < redovi; i++)
        delete[] matrica[i];
    delete[] matrica;
}

template <typename T>
void Plaza<T>::Dodaj(int red, int kol, const T& vrednost) {
    if (red < 1 || red > redovi || kol < 1 || kol > kolone) {
        cerr << "Greska: Pogresna pozicija (" << red << ", " << kol << ")" << endl;
        return;
    }
    matrica[red - 1][kol - 1] = vrednost;
}

template <typename T>
void Plaza<T>::Oslobodi(int red, int kol) {
    if (red < 1 || red > redovi || kol < 1 || kol > kolone) {
        cerr << "Greska: Pogresna pozicija (" << red << ", " << kol << ")" << endl;
        return;
    }
    matrica[red - 1][kol - 1] = T();
}

template <typename T>
double Plaza<T>::Ukupno() const {
    double suma = 0;
    for (int i = 0; i < redovi; i++)
        for (int j = 0; j < kolone; j++) {
            // Za Lezaljka tip
            if constexpr (is_same<T, Lezaljka>::value)
                suma += matrica[i][j].Ukupno();
            else
                suma += matrica[i][j];
        }
    return suma;
}

template <typename T>
int Plaza<T>::BrojMesta(int brojLez) const {
    int count = 0;
    for (int i = 0; i < redovi; i++)
        for (int j = 0; j < kolone; j++) {
            if constexpr (is_same<T, Lezaljka>::value) {
                if (matrica[i][j].GetBroj() == brojLez)
                    count++;
            } else {
                if (matrica[i][j] == brojLez)
                    count++;
            }
        }
    return count;
}

template <typename T>
int Plaza<T>::RedSaNajvise(int& brojLez) const {
    int maxRed = -1;
    int maxBroj = -1;
    for (int i = 0; i < redovi; i++) {
        int suma = 0;
        for (int j = 0; j < kolone; j++) {
            if constexpr (is_same<T, Lezaljka>::value)
                suma += matrica[i][j].GetBroj();
            else
                suma += matrica[i][j];
        }
        if (suma > maxBroj) {
            maxBroj = suma;
            maxRed = i + 1;
        }
    }
    brojLez = maxBroj;
    return maxRed;
}

template <typename T>
void Plaza<T>::Sacuvaj(const char* fajl) const {
    ofstream out(fajl);
    if (!out) {
        cerr << "Greska prilikom cuvanja fajla: " << fajl << endl;
        return;
    }
    out << redovi << " " << kolone << endl;
    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            if constexpr (is_same<T, Lezaljka>::value)
                out << matrica[i][j].GetBroj() << " " << matrica[i][j].GetCena() << " ";
            else
                out << matrica[i][j] << " ";
        }
        out << endl;
    }
    out.close();
}

template <typename T>
void Plaza<T>::Ucitaj(const char* fajl) {
    ifstream in(fajl);
    if (!in) {
        cerr << "Greska prilikom ucitavanja fajla: " << fajl << endl;
        return;
    }
    int r, k;
    in >> r >> k;

    // oslobodi prethodnu matricu
    for (int i = 0; i < redovi; i++)
        delete[] matrica[i];
    delete[] matrica;

    redovi = r;
    kolone = k;
    matrica = new T*[redovi];
    for (int i = 0; i < redovi; i++) {
        matrica[i] = new T[kolone];
        for (int j = 0; j < kolone; j++) {
            if constexpr (is_same<T, Lezaljka>::value) {
                int broj; double cena;
                in >> broj >> cena;
                matrica[i][j] = Lezaljka(broj, cena);
            } else {
                in >> matrica[i][j];
            }
        }
    }
    in.close();
}

template <typename T>
void Plaza<T>::Ispisi(ostream& os) const {
    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            if constexpr (is_same<T, Lezaljka>::value)
                matrica[i][j].Prikazi();
            else
                os << matrica[i][j] << "\t";
        }
        os << endl;
    }
}

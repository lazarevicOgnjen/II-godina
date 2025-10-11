#ifndef LEZAJKI_H
#define LEZAJKI_H

class Lezajki {
private:
    int redniBroj;
    int red;
    double cenaLezajki;
    double cenaNapica;

public:
    Lezajki(int rb, int r, double cl, double cn);
    virtual ~Lezajki();

    int getRedniBroj() const;
    int getRed() const;
    double getCenaNapica() const;

    virtual double ukupnaCena() const;
    virtual void ispisi() const;
};

class LezajkiSaDod : public Lezajki {
private:
    int dodatneLezajke;

public:
    LezajkiSaDod(int rb, int r, double cl, double cn, int dl);
    double ukupnaCena() const override;
    void ispisi() const override;
};

class Kafic {
private:
    Lezajki** kolekcija;
    int brojLezajki;
    double naplaceno;

    void ukloniPoIndexu(int index);

public:
    Kafic();
    ~Kafic();

    void iznajmiLezajke(Lezajki* l);
    void oslobodiLezajke(int redniBroj);
    void ispisiLezajke() const;
    int ukupnoLezajki() const;
    double ukupnoNaplaceno() const;
    bool postojiVecaOd(double vrednost) const;
    void maksimalniKupac() const;
};

#endif

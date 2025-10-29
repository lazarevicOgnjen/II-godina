#ifndef ISPIT_PRIPREMA_H
#define ISPIT_PRIPREMA_H

#include <iostream>
using namespace std;
#include "IspitniMaterijal.h"

class IspitPriprema {
private:
    IspitniMaterijal** materijali; // динамички низ показивача
    int kapacitet;                 // максималан број елемената
    int broj;                      // тренутан број елемената

public:
    // Конструктор
    IspitPriprema(int kapacitet = 10);

    // Копи-конструктор
    IspitPriprema(const IspitPriprema& other);

    // Оператор доделе
    IspitPriprema& operator=(const IspitPriprema& other);

    // Деструктор
    ~IspitPriprema();

    // Додавање материјала
    void Dodaj(IspitniMaterijal* materijal);

    // Брисање по индексу (1-based у main-у)
    void Obrisi(int index);

    // Ознака савладаног материјала
    void Savladaj(int index);

    // Број савладаних
    int UkupnoSavladanih() const;

    // Укупно време
    float UkupnoVreme(float jedinicno) const;

    // Враћа најмањи и највећи по времену
    void VratiNaj(float jedinicno, IspitniMaterijal** min, IspitniMaterijal** max) const;

    // Пријатељски оператор <<
    friend ostream& operator<<(ostream& izlaz, const IspitPriprema& isp);
};

#endif

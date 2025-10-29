#ifndef ZADATAK_H
#define ZADATAK_H

#include <iostream>
using namespace std;
#include "IspitniMaterijal.h"

class Zadatak : public IspitniMaterijal {
private:
    int kod; // Јединствени код задатка

public:
    // Конструктор
    Zadatak(int id = 0, float tezina = 0.0, int kod = 0);

    // Копи-конструктор
    Zadatak(const Zadatak& other);

    // Оператор доделе
    Zadatak& operator=(const Zadatak& other);

    // Деструктор
    ~Zadatak();

    // Преоптерећена виртуелна метода за приказ
    void Prikazi() const override;

    // Преоптерећена виртуелна метода за израчунавање времена
    float Vreme(float jedinicno) const override;

    // Савладавање задатка
    void Savladaj();
};

#endif

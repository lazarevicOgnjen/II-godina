#ifndef LEKCIJA_H
#define LEKCIJA_H

#include <iostream>
using namespace std;
#include "IspitniMaterijal.h"

class Lekcija : public IspitniMaterijal {
private:
    float duzina; // Дужина лекције у часовима

public:
    // Конструктор
    Lekcija(int id = 0, float tezina = 0.0, float duzina = 0.0);

    // Копи-конструктор
    Lekcija(const Lekcija& other);

    // Оператор доделе
    Lekcija& operator=(const Lekcija& other);

    // Деструктор
    ~Lekcija();

    // Преоптерећена виртуелна метода за приказ
    void Prikazi() const override;

    // Преоптерећена виртуелна метода за израчунавање времена
    float Vreme(float jedinicno) const override;

    // Означава лекцију као савладану
    void Savladaj();
};

#endif

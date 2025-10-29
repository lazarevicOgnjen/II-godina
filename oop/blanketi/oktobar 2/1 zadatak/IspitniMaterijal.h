#ifndef ISPITNI_MATERIJAL_H
#define ISPITNI_MATERIJAL_H

#include <iostream>
using namespace std;

class IspitniMaterijal {
private:
    int id;           // Јединствени идентификатор материјала
    float tezina;     // Тежина материјала (колико је захтеван)
    bool savladan;    // Да ли је материјал савладан

public:
    // Конструктор
    IspitniMaterijal(int id = 0, float tezina = 0.0);

    // Копи-конструктор
    IspitniMaterijal(const IspitniMaterijal& other);

    // Оператор доделе
    IspitniMaterijal& operator=(const IspitniMaterijal& other);

    // Виртуелни деструктор (битно јер ће се брисати преко базног показивача)
    virtual ~IspitniMaterijal();

    // Гетери
    int GetID() const;
    float GetTezina() const;
    bool GetSavladan() const;

    // Сетери
    void SetSavladan(bool status);

    // Апстрактна функција за приказ
    virtual void Prikazi() const = 0;

    // Апстрактна функција која враћа трајање у зависности од јединичне вредности
    virtual float Vreme(float jedinicno) const = 0;

    // Помоћна функција за копирање заједничких атрибута
protected:
    void Kopiraj(const IspitniMaterijal& other);

    // Пријатељски оператор << (за испис свих типова материјала)
    friend ostream& operator<<(ostream& izlaz, const IspitniMaterijal& obj);
};

#endif

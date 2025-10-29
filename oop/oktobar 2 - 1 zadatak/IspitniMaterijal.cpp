#include "IspitniMaterijal.h"

// Конструктор
IspitniMaterijal::IspitniMaterijal(int id, float tezina) {
    this->id = id;
    this->tezina = tezina;
    this->savladan = false;
}

// Копи-конструктор
IspitniMaterijal::IspitniMaterijal(const IspitniMaterijal& other) {
    Kopiraj(other);
}

// Оператор доделе
IspitniMaterijal& IspitniMaterijal::operator=(const IspitniMaterijal& other) {
    if (this != &other)
        Kopiraj(other);
    return *this;
}

// Помоћна функција
void IspitniMaterijal::Kopiraj(const IspitniMaterijal& other) {
    id = other.id;
    tezina = other.tezina;
    savladan = other.savladan;
}

// Деструктор
IspitniMaterijal::~IspitniMaterijal() {
    // ништа посебно, али мора бити виртуелан
}

// Гетери
int IspitniMaterijal::GetID() const { return id; }
float IspitniMaterijal::GetTezina() const { return tezina; }
bool IspitniMaterijal::GetSavladan() const { return savladan; }

// Сетери
void IspitniMaterijal::SetSavladan(bool status) { savladan = status; }

// Пријатељски оператор <<
// Позива Prikazi() која ће бити дефинисана у изведеним класама
ostream& operator<<(ostream& izlaz, const IspitniMaterijal& obj) {
    obj.Prikazi();
    return izlaz;
}

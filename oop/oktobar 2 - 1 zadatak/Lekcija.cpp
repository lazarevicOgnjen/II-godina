#include "Lekcija.h"

// Конструктор
Lekcija::Lekcija(int id, float tezina, float duzina)
    : IspitniMaterijal(id, tezina) {
    this->duzina = duzina;
}

// Копи-конструктор
Lekcija::Lekcija(const Lekcija& other)
    : IspitniMaterijal(other) {
    this->duzina = other.duzina;
}

// Оператор доделе
Lekcija& Lekcija::operator=(const Lekcija& other) {
    if (this != &other) {
        IspitniMaterijal::operator=(other);
        duzina = other.duzina;
    }
    return *this;
}

// Деструктор
Lekcija::~Lekcija() {
    // ништа посебно, нема динамичке меморије
}

// Prikazi() — испис свих података
void Lekcija::Prikazi() const {
    cout << "[LEKCIJA] ID: " << GetID()
         << ", tezina: " << GetTezina()
         << ", duzina: " << duzina
         << ", savladana: " << (GetSavladan() ? "DA" : "NE");
}

// Враћа време савладавања лекције
float Lekcija::Vreme(float jedinicno) const {
    // нпр. време је tezina * duzina * jedinicno
    return GetTezina() * duzina * jedinicno;
}

// Савладавање лекције
void Lekcija::Savladaj() {
    SetSavladan(true);
}

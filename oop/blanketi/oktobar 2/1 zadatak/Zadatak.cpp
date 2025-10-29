#include "Zadatak.h"

// Конструктор
Zadatak::Zadatak(int id, float tezina, int kod)
    : IspitniMaterijal(id, tezina) {
    this->kod = kod;
}

// Копи-конструктор
Zadatak::Zadatak(const Zadatak& other)
    : IspitniMaterijal(other) {
    this->kod = other.kod;
}

// Оператор доделе
Zadatak& Zadatak::operator=(const Zadatak& other) {
    if (this != &other) {
        IspitniMaterijal::operator=(other);
        kod = other.kod;
    }
    return *this;
}

// Деструктор
Zadatak::~Zadatak() {
    // ништа посебно, нема динамичке меморије
}

// Prikazi() — испис свих података
void Zadatak::Prikazi() const {
    cout << "[ZADATAK] ID: " << GetID()
         << ", tezina: " << GetTezina()
         << ", kod: " << kod
         << ", savladan: " << (GetSavladan() ? "DA" : "NE");
}

// Враћа време за решавање задатка
float Zadatak::Vreme(float jedinicno) const {
    // Пример формуле: tezina * (kod % 10) * jedinicno
    // (логично — што већи код, то више времена треба)
    return GetTezina() * (kod % 10) * jedinicno;
}

// Савладавање задатка
void Zadatak::Savladaj() {
    SetSavladan(true);
}

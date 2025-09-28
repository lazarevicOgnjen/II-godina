#include "pice.h"
#include <iostream>

Pice::Pice(float z, int b) : zapremina(z), brojAmbalaza(b) {}
Pice::~Pice() {}

float Voda::cena() const {
    return zapremina * 50.0f;   // proizvoljna cena
}

bool Voda::jednako(const Pice& drugo) const {
    if (vrsta() != drugo.vrsta()) return false;
    return zapremina == drugo.getZapremina();
}

void Voda::prikazi() const {
    std::cout << "Voda: " << zapremina << " L, kom: " << brojAmbalaza;
}

Voda::Voda(float z, int b) : Pice(z, b) {}

Sok::Sok(float z, const char* u, int pv, float odnos, int b)
    : Pice(z, b), procenatVoca(pv), odnosCeneVodaVoc(odnos) {
    strncpy(ukus, u, sizeof(ukus) - 1);
    ukus[sizeof(ukus) - 1] = '\0';
}

float Sok::cena() const {
    float litVode = zapremina * (100 - procenatVoca) / 100.0f;
    float litVoca = zapremina * procenatVoca / 100.0f;
    return litVode * 50.0f + litVoca * 50.0f * odnosCeneVodaVoc;
}

bool Sok::jednako(const Pice& drugo) const {
    if (vrsta() != drugo.vrsta()) return false;
    return zapremina == drugo.getZapremina() &&
           strcmp(ukus, drugo.getUkus()) == 0 &&
           procenatVoca == drugo.getProcenatVoca();
}

void Sok::prikazi() const {
    std::cout << "Sok: " << zapremina << " L, ukus: " << ukus
              << ", vocе " << procenatVoca << "%, kom: " << brojAmbalaza;
}

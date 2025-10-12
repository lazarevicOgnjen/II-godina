#include "KaficSaPlazom.h"
#include <iostream>
using namespace std;

KaficSaPlazom::KaficSaPlazom(int kap)
    : kapacitet(kap), brojTrenutnih(0), naplaceno(0) {
    niz = new ParLezaljki*[kapacitet];
    for (int i = 0; i < kapacitet; i++)
        niz[i] = nullptr;
}

KaficSaPlazom::~KaficSaPlazom() {
    for (int i = 0; i < brojTrenutnih; i++)
        delete niz[i];
    delete[] niz;
}

void KaficSaPlazom::Dodaj(ParLezaljki* p) {
    if (brojTrenutnih < kapacitet) {
        niz[brojTrenutnih++] = p;
    }
}

void KaficSaPlazom::Oslobodi(int rbr) {
    for (int i = 0; i < brojTrenutnih; i++) {
        if (niz[i]->GetRbr() == rbr) {
            naplaceno += niz[i]->UkupnoZaNaplatu();
            delete niz[i];
            for (int j = i; j < brojTrenutnih - 1; j++)
                niz[j] = niz[j + 1];
            brojTrenutnih--;
            break;
        }
    }
}

int KaficSaPlazom::UkupnoLezaljki() const {
    return brojTrenutnih;
}

double KaficSaPlazom::UkupnaSvotaNovca() const {
    return naplaceno;
}

bool KaficSaPlazom::PostojiGdeTrebaPlatiti(double svota) const {
    for (int i = 0; i < brojTrenutnih; i++)
        if (niz[i]->UkupnoZaNaplatu() > svota)
            return true;
    return false;
}

void KaficSaPlazom::VratiNajskuplje(ParLezaljki** maxCena, ParLezaljki** maxNapici) const {
    double maxUkupno = -1;
    double maxNapicima = -1;
    *maxCena = nullptr;
    *maxNapici = nullptr;

    for (int i = 0; i < brojTrenutnih; i++) {
        double ukupno = niz[i]->UkupnoZaNaplatu();
        if (ukupno > maxUkupno) {
            maxUkupno = ukupno;
            *maxCena = niz[i];
        }

        // Napitke procenjujemo kao razлику: ukupno - cenaLezaljki (за основни тип)
        double napici = 0;
        const ParLezaljki* pl = niz[i];
        if (pl) {
            // Приближно израчунавање укупне цене пића без приватних атрибута
            napici = ukupno - (pl->UkupnoZaNaplatu() - 0);
        }
        if (napici > maxNapicima) {
            maxNapicima = napici;
            *maxNapici = niz[i];
        }
    }
}

ostream& operator<<(ostream& os, const KaficSaPlazom& k) {
    os << "--- KaficSaPlazom ---" << endl;
    for (int i = 0; i < k.brojTrenutnih; i++)
        k.niz[i]->Prikazi();
    os << "Ukupno naplaceno: " << k.naplaceno << endl;
    return os;
}

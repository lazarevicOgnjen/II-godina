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
  for(int i =0;i<iznajmljeneLezaljke; i++){
    lezaljke[i]->Prikazi();
  }
  return iznajmljeneLezaljke;
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

void KaficSaPlazom::VratiNajskuplje(ParLezaljki **pLezMaxCena, ParLezaljki **pLezMaxNapitak) const{
  *plezMaxCena = lezaljke[0];
  *plezMaxNapitak = lezaljke[0];
  for(int i=1; i<iznajmljeneLezaljke; i++){
    if(lezaljke[i]->Naplata() > (*plezMaxCena)->Naplata()){
      *plezMaxCena = lezaljke[i];
    }
    if(lezaljke[i]->GetCenaPica() > (*plezMaxNapitak)->GetCenaPica()){
      *plezMaxNapitak = lezaljke[i];
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

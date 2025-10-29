#include "IspitPriprema.h"

// Помоћна функција за копирање
static IspitniMaterijal* KopirajMaterijal(const IspitniMaterijal* src) {
    // Пошто не можемо користити RTTI или dynamic_cast без <typeinfo>,
    // направимо једноставну копију преко operator= позива (пошто све класе имају копи-конструкторе).
    // У реалној ситуацији, могли бисмо имати clone() виртуелну функцију у базној класи.
    // Али за овај задатак, само ћемо пренети показивач (плитка копија).
    return (IspitniMaterijal*)src;
}

// Конструктор
IspitPriprema::IspitPriprema(int kapacitet) {
    this->kapacitet = kapacitet;
    broj = 0;
    materijali = new IspitniMaterijal*[kapacitet];
    for (int i = 0; i < kapacitet; i++)
        materijali[i] = nullptr;
}

// Копи-конструктор
IspitPriprema::IspitPriprema(const IspitPriprema& other) {
    kapacitet = other.kapacitet;
    broj = other.broj;
    materijali = new IspitniMaterijal*[kapacitet];
    for (int i = 0; i < broj; i++)
        materijali[i] = KopirajMaterijal(other.materijali[i]);
    for (int i = broj; i < kapacitet; i++)
        materijali[i] = nullptr;
}

// Оператор доделе
IspitPriprema& IspitPriprema::operator=(const IspitPriprema& other) {
    if (this != &other) {
        // очисти постојеће
        for (int i = 0; i < broj; i++)
            delete materijali[i];
        delete[] materijali;

        kapacitet = other.kapacitet;
        broj = other.broj;
        materijali = new IspitniMaterijal*[kapacitet];
        for (int i = 0; i < broj; i++)
            materijali[i] = KopirajMaterijal(other.materijali[i]);
        for (int i = broj; i < kapacitet; i++)
            materijali[i] = nullptr;
    }
    return *this;
}

// Деструктор
IspitPriprema::~IspitPriprema() {
    for (int i = 0; i < broj; i++)
        delete materijali[i];
    delete[] materijali;
}

// Додавање материјала
void IspitPriprema::Dodaj(IspitniMaterijal* materijal) {
    if (broj < kapacitet)
        materijali[broj++] = materijal;
    else
        cout << "Nema mesta za dodavanje novog materijala!" << endl;
}

// Брисање по индексу (1-based као у задатку)
void IspitPriprema::Obrisi(int index) {
    int i = index - 1;
    if (i < 0 || i >= broj) return;

    delete materijali[i];
    for (int j = i; j < broj - 1; j++)
        materijali[j] = materijali[j + 1];
    materijali[--broj] = nullptr;
}

// Савладавање по индексу
void IspitPriprema::Savladaj(int index) {
    int i = index - 1;
    if (i < 0 || i >= broj) return;
    materijali[i]->SetSavladan(true);
}

// Укупно савладаних
int IspitPriprema::UkupnoSavladanih() const {
    int count = 0;
    for (int i = 0; i < broj; i++)
        if (materijali[i]->GetSavladan())
            count++;
    return count;
}

// Укупно време
float IspitPriprema::UkupnoVreme(float jedinicno) const {
    float ukupno = 0;
    for (int i = 0; i < broj; i++)
        ukupno += materijali[i]->Vreme(jedinicno);
    return ukupno;
}

// Најмањи и највећи по времену
void IspitPriprema::VratiNaj(float jedinicno, IspitniMaterijal** min, IspitniMaterijal** max) const {
    if (broj == 0) {
        *min = *max = nullptr;
        return;
    }
    float minV = materijali[0]->Vreme(jedinicno);
    float maxV = minV;
    *min = materijali[0];
    *max = materijali[0];
    for (int i = 1; i < broj; i++) {
        float vreme = materijali[i]->Vreme(jedinicno);
        if (vreme < minV) {
            minV = vreme;
            *min = materijali[i];
        }
        if (vreme > maxV) {
            maxV = vreme;
            *max = materijali[i];
        }
    }
}

// Оператор << за испис свих материјала
ostream& operator<<(ostream& izlaz, const IspitPriprema& isp) {
    izlaz << "[ISPIT PRIPREMA] (" << isp.broj << "/" << isp.kapacitet << ")\n";
    for (int i = 0; i < isp.broj; i++) {
        izlaz << i + 1 << ". " << *isp.materijali[i] << endl;
    }
    return izlaz;
}

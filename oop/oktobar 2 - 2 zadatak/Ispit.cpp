#include "Ispit.h"
#include "LekcijaNormalna.h"
#include <fstream>
#include <cstring>

template<typename T>
void Ispit<T>::prosiriNiz() {
    int noviKapacitet = maxPodataka * 2;
    T* noviNiz = new T[noviKapacitet];
    
    for (int i = 0; i < brojPodataka; i++) {
        noviNiz[i] = podaci[i];
    }
    
    delete[] podaci;
    podaci = noviNiz;
    maxPodataka = noviKapacitet;
}

template<typename T>
Ispit<T>::Ispit(int maxPod) : maxPodataka(maxPod), brojPodataka(0) {
    podaci = new T[maxPodataka];
}

template<typename T>
Ispit<T>::Ispit(const Ispit& i) : maxPodataka(i.maxPodataka), brojPodataka(i.brojPodataka) {
    podaci = new T[maxPodataka];
    for (int i = 0; i < brojPodataka; i++) {
        podaci[i] = i.podaci[i];
    }
}

template<typename T>
Ispit<T>::~Ispit() {
    delete[] podaci;
}

template<typename T>
Ispit<T>& Ispit<T>::operator=(const Ispit& i) {
    if (this != &i) {
        delete[] podaci;
        
        maxPodataka = i.maxPodataka;
        brojPodataka = i.brojPodataka;
        podaci = new T[maxPodataka];
        
        for (int j = 0; j < brojPodataka; j++) {
            podaci[j] = i.podaci[j];
        }
    }
    return *this;
}

template<typename T>
void Ispit<T>::Dodaj(const T& podatak) {
    if (brojPodataka >= maxPodataka) {
        prosiriNiz();
    }
    podaci[brojPodataka++] = podatak;
}

template<typename T>
void Ispit<T>::Izbaci(int pozicija, int broj) {
    if (pozicija < 0 || pozicija >= brojPodataka || broj <= 0) {
        return;
    }
    
    int brojZaBrisanje = (pozicija + broj > brojPodataka) ? 
                         brojPodataka - pozicija : broj;
    
    for (int i = pozicija; i < brojPodataka - brojZaBrisanje; i++) {
        podaci[i] = podaci[i + brojZaBrisanje];
    }
    
    brojPodataka -= brojZaBrisanje;
}

template<typename T>
float Ispit<T>::Ukupno() const {
    float ukupno = 0;
    for (int i = 0; i < brojPodataka; i++) {
        ukupno += static_cast<float>(podaci[i]);
    }
    return ukupno;
}

template<typename T>
int Ispit<T>::UkupniBrojVrednost(float vrednost, float& ukupnaVrednost) const {
    int broj = 0;
    ukupnaVrednost = 0;
    
    for (int i = 0; i < brojPodataka; i++) {
        if (podaci[i] >= vrednost) {
            broj++;
            ukupnaVrednost += static_cast<float>(podaci[i]);
        }
    }
    
    return broj;
}

template<typename T>
void Ispit<T>::minMax(int pozicija, int broj, T& min, T& max) const {
    if (pozicija < 0 || pozicija >= brojPodataka || broj <= 0) {
        return;
    }
    
    int kraj = (pozicija + broj > brojPodataka) ? brojPodataka : pozicija + broj;
    
    min = podaci[pozicija];
    max = podaci[pozicija];
    
    for (int i = pozicija + 1; i < kraj; i++) {
        if (podaci[i] < min) {
            min = podaci[i];
        }
        if (podaci[i] > max) {
            max = podaci[i];
        }
    }
}

template<typename T>
void Ispit<T>::Sacuvaj(const char* nazivFajla) const {
    std::ofstream fajl(nazivFajla);
    
    if (!fajl) {
        throw "Greska pri otvaranju fajla za pisanje!";
    }
    
    fajl << brojPodataka << std::endl;
    for (int i = 0; i < brojPodataka; i++) {
        fajl << podaci[i] << std::endl;
    }
    
    fajl.close();
}

template<typename T>
void Ispit<T>::Ucitaj(const char* nazivFajla) {
    std::ifstream fajl(nazivFajla);
    
    if (!fajl) {
        throw "Greska pri otvaranju fajla za citanje!";
    }
    
    int noviBrojPodataka;
    fajl >> noviBrojPodataka;
    
    if (noviBrojPodataka > maxPodataka) {
        delete[] podaci;
        maxPodataka = noviBrojPodataka;
        podaci = new T[maxPodataka];
    }
    
    brojPodataka = 0;
    for (int i = 0; i < noviBrojPodataka; i++) {
        T temp;
        fajl >> temp;
        podaci[brojPodataka++] = temp;
    }
    
    fajl.close();
}

// Eksplicitna instancija template klasa
template class Ispit<float>;
template class Ispit<int>;
template class Ispit<LekcijaNormalna>;

template std::ostream& operator<<(std::ostream& os, const Ispit<float>& i);
template std::ostream& operator<<(std::ostream& os, const Ispit<int>& i);
template std::ostream& operator<<(std::ostream& os, const Ispit<LekcijaNormalna>& i);

#ifndef ISPIT_H
#define ISPIT_H

#include <iostream>
#include <fstream>

template<typename T>
class Ispit {
private:
    T* podaci;
    int maxPodataka;
    int brojPodataka;
    
    void prosiriNiz();
    
public:
    Ispit(int maxPod = 10);
    Ispit(const Ispit& i);
    ~Ispit();
    
    Ispit& operator=(const Ispit& i);
    
    void Dodaj(const T& podatak);
    void Izbaci(int pozicija, int broj);
    float Ukupno() const;
    int UkupniBrojVrednost(float vrednost, float& ukupnaVrednost) const;
    void minMax(int pozicija, int broj, T& min, T& max) const;
    
    void Sacuvaj(const char* nazivFajla) const;
    void Ucitaj(const char* nazivFajla);
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Ispit<U>& i);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Ispit<T>& i) {
    for (int j = 0; j < i.brojPodataka; j++) {
        os << i.podaci[j] << " ";
    }
    return os;
}

#endif

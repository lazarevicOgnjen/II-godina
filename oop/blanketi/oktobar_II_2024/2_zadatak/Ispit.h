#ifndef ISPIT_H
#define ISPIT_H

#include <iostream>
#include <fstream>

template<typename T>
class Ispit {
private:
    T* _niz;
    int _trenutno;
    int _max;
    
    void kopiraj(const Ispit& other);
    void premesti(Ispit&& other);
    void brisi();
    
public:
    Ispit(int max);
    Ispit(const Ispit& other);
    Ispit(Ispit&& other);
    Ispit& operator=(const Ispit& other);
    Ispit& operator=(Ispit&& other);
    ~Ispit();
    
    void Dodaj(const T& element);
    void Izbaci(int start, int count);
    float Ukupno() const;
    int UkupniBrojVrednost(float vrednost, float& ukupnaVrednost) const;
    void minMax(int start, int end, T& min, T& max) const;
    void Sacuvaj(const char* filename) const;
    void Ucitaj(const char* filename);
    
    friend std::ostream& operator<<(std::ostream& os, const Ispit& ispit) {
        for (int i = 0; i < ispit._trenutno; i++) {
            os << ispit._niz[i];
            if (i < ispit._trenutno - 1) os << " ";
        }
        return os;
    }
};

// Eksplicitne instancije za podržane tipove
template class Ispit<float>;
template class Ispit<int>;
template class Ispit<NormalLesson>;

#endif

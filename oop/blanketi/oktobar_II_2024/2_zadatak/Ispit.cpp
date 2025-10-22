#include "Ispit.h"
#include "Lesson.h"
#include <fstream>
#include <stdexcept>

// Implementacija template metode mora biti u header-u, ali ovde ćemo koristiti eksplicitne instancije

template<typename T>
void Ispit<T>::kopiraj(const Ispit& other) {
    _max = other._max;
    _trenutno = other._trenutno;
    _niz = new T[_max];
    for (int i = 0; i < _trenutno; i++) {
        _niz[i] = other._niz[i];
    }
}

template<typename T>
void Ispit<T>::premesti(Ispit&& other) {
    _niz = other._niz;
    _trenutno = other._trenutno;
    _max = other._max;
    other._niz = nullptr;
    other._trenutno = 0;
    other._max = 0;
}

template<typename T>
void Ispit<T>::brisi() {
    delete[] _niz;
    _niz = nullptr;
}

template<typename T>
Ispit<T>::Ispit(int max) : _max(max), _trenutno(0) {
    _niz = new T[_max];
}

template<typename T>
Ispit<T>::Ispit(const Ispit& other) {
    kopiraj(other);
}

template<typename T>
Ispit<T>::Ispit(Ispit&& other) {
    premesti(std::move(other));
}

template<typename T>
Ispit<T>& Ispit<T>::operator=(const Ispit& other) {
    if (this != &other) {
        brisi();
        kopiraj(other);
    }
    return *this;
}

template<typename T>
Ispit<T>& Ispit<T>::operator=(Ispit&& other) {
    if (this != &other) {
        brisi();
        premesti(std::move(other));
    }
    return *this;
}

template<typename T>
Ispit<T>::~Ispit() {
    brisi();
}

template<typename T>
void Ispit<T>::Dodaj(const T& element) {
    if (_trenutno >= _max) {
        throw std::runtime_error("Kolekcija je puna");
    }
    _niz[_trenutno++] = element;
}

template<typename T>
void Ispit<T>::Izbaci(int start, int count) {
    if (start < 0 || start >= _trenutno || count < 0 || start + count > _trenutno) {
        throw std::runtime_error("Nevalidni indeksi za brisanje");
    }
    
    for (int i = start; i < _trenutno - count; i++) {
        _niz[i] = _niz[i + count];
    }
    _trenutno -= count;
}

// Specijalizacija za NormalLesson - koristi getTezina() metodu
template<>
float Ispit<NormalLesson>::Ukupno() const {
    float sum = 0;
    for (int i = 0; i < _trenutno; i++) {
        sum += _niz[i].getTezina();
    }
    return sum;
}

// Generička implementacija za ostale tipove
template<typename T>
float Ispit<T>::Ukupno() const {
    float sum = 0;
    for (int i = 0; i < _trenutno; i++) {
        sum += _niz[i];
    }
    return sum;
}

// Specijalizacija za NormalLesson
template<>
int Ispit<NormalLesson>::UkupniBrojVrednost(float vrednost, float& ukupnaVrednost) const {
    int count = 0;
    ukupnaVrednost = 0;
    for (int i = 0; i < _trenutno; i++) {
        float tezina = _niz[i].getTezina();
        if (tezina > vrednost) {
            count++;
            ukupnaVrednost += tezina;
        }
    }
    return count;
}

// Generička implementacija
template<typename T>
int Ispit<T>::UkupniBrojVrednost(float vrednost, float& ukupnaVrednost) const {
    int count = 0;
    ukupnaVrednost = 0;
    for (int i = 0; i < _trenutno; i++) {
        if (_niz[i] > vrednost) {
            count++;
            ukupnaVrednost += _niz[i];
        }
    }
    return count;
}

// Specijalizacija za NormalLesson
template<>
void Ispit<NormalLesson>::minMax(int start, int end, NormalLesson& min, NormalLesson& max) const {
    if (start < 0 || end >= _trenutno || start > end) {
        throw std::runtime_error("Nevalidni indeksi za minMax");
    }
    
    min = _niz[start];
    max = _niz[start];
    
    for (int i = start + 1; i <= end; i++) {
        if (_niz[i].getTezina() < min.getTezina()) {
            min = _niz[i];
        }
        if (_niz[i].getTezina() > max.getTezina()) {
            max = _niz[i];
        }
    }
}

// Generička implementacija
template<typename T>
void Ispit<T>::minMax(int start, int end, T& min, T& max) const {
    if (start < 0 || end >= _trenutno || start > end) {
        throw std::runtime_error("Nevalidni indeksi za minMax");
    }
    
    min = _niz[start];
    max = _niz[start];
    
    for (int i = start + 1; i <= end; i++) {
        if (_niz[i] < min) {
            min = _niz[i];
        }
        if (_niz[i] > max) {
            max = _niz[i];
        }
    }
}

template<typename T>
void Ispit<T>::Sacuvaj(const char* filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Greska pri otvaranju fajla za cuvanje");
    }
    
    file.write((char*)&_trenutno, sizeof(_trenutno));
    for (int i = 0; i < _trenutno; i++) {
        // Za tipove koji imaju sacuvaj metodu
        if constexpr (std::is_base_of_v<Lesson, T>) {
            _niz[i].sacuvaj(file);
        } else {
            file.write((char*)&_niz[i], sizeof(T));
        }
    }
}

template<typename T>
void Ispit<T>::Ucitaj(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Greska pri otvaranju fajla za citanje");
    }
    
    int trenutno;
    file.read((char*)&trenutno, sizeof(trenutno));
    
    if (trenutno > _max) {
        throw std::runtime_error("Nema dovoljno mesta u kolekciji");
    }
    
    _trenutno = trenutno;
    for (int i = 0; i < _trenutno; i++) {
        // Za tipove koji imaju ucitaj metodu
        if constexpr (std::is_base_of_v<Lesson, T>) {
            _niz[i].ucitaj(file);
        } else {
            file.read((char*)&_niz[i], sizeof(T));
        }
    }
}

// Eksplicitne instancije
template class Ispit<float>;
template class Ispit<int>;
template class Ispit<NormalLesson>;

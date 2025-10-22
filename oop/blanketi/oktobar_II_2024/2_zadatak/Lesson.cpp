#include "Lesson.h"
#include <fstream>
#include <cstring>

// Lesson implementation
Lesson::Lesson() : _tezina(0), _duzina(0) {
    _naziv[0] = '\0';
}

Lesson::Lesson(const char* naziv, float tezina, float duzina) : _tezina(tezina), _duzina(duzina) {
    strncpy(_naziv, naziv, 7);
    _naziv[7] = '\0';
}

std::ostream& operator<<(std::ostream& os, const Lesson& lesson) {
    lesson.print(os);
    return os;
}

// SimpleLesson implementation
SimpleLesson::SimpleLesson() : Lesson() {}

SimpleLesson::SimpleLesson(float tezina) : Lesson("", tezina, 0) {}

float SimpleLesson::getTezina() const {
    return _tezina;
}

void SimpleLesson::print(std::ostream& os) const {
    os << _tezina;
}

void SimpleLesson::sacuvaj(std::ostream& file) const {
    file.write((char*)&_tezina, sizeof(_tezina));
}

void SimpleLesson::ucitaj(std::istream& file) {
    file.read((char*)&_tezina, sizeof(_tezina));
    _duzina = 0;
    _naziv[0] = '\0';
}

// NormalLesson implementation
NormalLesson::NormalLesson() : Lesson() {}

NormalLesson::NormalLesson(const char* naziv, float procenjenaTezina, float duzina) 
    : Lesson(naziv, procenjenaTezina, duzina) {}

float NormalLesson::getTezina() const {
    return _tezina * _duzina;
}

void NormalLesson::print(std::ostream& os) const {
    os << _naziv << " " << getTezina();
}

void NormalLesson::sacuvaj(std::ostream& file) const {
    file.write(_naziv, 8);
    file.write((char*)&_tezina, sizeof(_tezina));
    file.write((char*)&_duzina, sizeof(_duzina));
}

void NormalLesson::ucitaj(std::istream& file) {
    file.read(_naziv, 8);
    file.read((char*)&_tezina, sizeof(_tezina));
    file.read((char*)&_duzina, sizeof(_duzina));
}

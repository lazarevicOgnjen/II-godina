#include "IspitPriprema.h"
#include <iostream>

IspitPriprema::IspitPriprema(int max) : _max(max), _trenutno(0) {
    _materijali = new IspitniMaterijal*[_max];
    for (int i = 0; i < _max; i++) {
        _materijali[i] = nullptr;
    }
}

IspitPriprema::IspitPriprema(const IspitPriprema& other) {
    _max = other._max;
    _trenutno = other._trenutno;
    _materijali = new IspitniMaterijal*[_max];
    
    for (int i = 0; i < _trenutno; i++) {
        const Lekcija* lekcija = dynamic_cast<const Lekcija*>(other._materijali[i]);
        const Zadatak* zadatak = dynamic_cast<const Zadatak*>(other._materijali[i]);
        
        if (lekcija) {
            _materijali[i] = new Lekcija(*lekcija);
        } else if (zadatak) {
            _materijali[i] = new Zadatak(*zadatak);
        }
    }
    
    for (int i = _trenutno; i < _max; i++) {
        _materijali[i] = nullptr;
    }
}

IspitPriprema& IspitPriprema::operator=(const IspitPriprema& other) {
    if (this != &other) {
        for (int i = 0; i < _trenutno; i++) {
            delete _materijali[i];
        }
        delete[] _materijali;
        
        _max = other._max;
        _trenutno = other._trenutno;
        _materijali = new IspitniMaterijal*[_max];
        
        for (int i = 0; i < _trenutno; i++) {
            const Lekcija* lekcija = dynamic_cast<const Lekcija*>(other._materijali[i]);
            const Zadatak* zadatak = dynamic_cast<const Zadatak*>(other._materijali[i]);
            
            if (lekcija) {
                _materijali[i] = new Lekcija(*lekcija);
            } else if (zadatak) {
                _materijali[i] = new Zadatak(*zadatak);
            }
        }
        
        for (int i = _trenutno; i < _max; i++) {
            _materijali[i] = nullptr;
        }
    }
    return *this;
}

IspitPriprema::~IspitPriprema() {
    for (int i = 0; i < _trenutno; i++) {
        delete _materijali[i];
    }
    delete[] _materijali;
}

void IspitPriprema::Dodaj(IspitniMaterijal* materijal) {
    if (_trenutno >= _max) {
        // Umesto std::runtime_error, koristimo cout i izlazak iz funkcije
        std::cout << "Greska: Kolekcija je puna" << std::endl;
        return;
    }
    _materijali[_trenutno++] = materijal;
}

void IspitPriprema::Obrisi(int oznaka) {
    for (int i = 0; i < _trenutno; i++) {
        if (_materijali[i]->getOznaka() == oznaka) {
            if (_materijali[i]->getSavladao()) {
                std::cout << "Greska: Ne moze se obrisati savladan materijal" << std::endl;
                return;
            }
            
            delete _materijali[i];
            
            for (int j = i; j < _trenutno - 1; j++) {
                _materijali[j] = _materijali[j + 1];
            }
            _materijali[--_trenutno] = nullptr;
            return;
        }
    }
    std::cout << "Greska: Materijal sa oznakom " << oznaka << " nije pronadjen" << std::endl;
}

void IspitPriprema::Savladaj(int oznaka) {
    for (int i = 0; i < _trenutno; i++) {
        if (_materijali[i]->getOznaka() == oznaka) {
            _materijali[i]->setSavladao(true);
            return;
        }
    }
    std::cout << "Greska: Materijal sa oznakom " << oznaka << " nije pronadjen" << std::endl;
}

int IspitPriprema::UkupnoSavladanih() const {
    int count = 0;
    for (int i = 0; i < _trenutno; i++) {
        if (_materijali[i]->getSavladao()) {
            count++;
        }
    }
    return count;
}

float IspitPriprema::UkupnoVreme(float vremeJedinicno) const {
    float total = 0;
    for (int i = 0; i < _trenutno; i++) {
        total += _materijali[i]->vremePotrebno(vremeJedinicno);
    }
    return total;
}

void IspitPriprema::VratiNaj(float vremeJedinicno, IspitniMaterijal** matMin, IspitniMaterijal** matMax) const {
    if (_trenutno == 0) {
        std::cout << "Greska: Kolekcija je prazna" << std::endl;
        return;
    }
    
    *matMin = _materijali[0];
    *matMax = _materijali[0];
    
    float minVreme = _materijali[0]->vremePotrebno(vremeJedinicno);
    float maxVreme = minVreme;
    
    for (int i = 1; i < _trenutno; i++) {
        float vreme = _materijali[i]->vremePotrebno(vremeJedinicno);
        if (vreme < minVreme) {
            minVreme = vreme;
            *matMin = _materijali[i];
        }
        if (vreme > maxVreme) {
            maxVreme = vreme;
            *matMax = _materijali[i];
        }
    }
}

std::ostream& operator<<(std::ostream& os, const IspitPriprema& priprema) {
    for (int i = 0; i < priprema._trenutno; i++) {
        os << *priprema._materijali[i];
        if (i < priprema._trenutno - 1) {
            os << std::endl;
        }
    }
    return os;
}

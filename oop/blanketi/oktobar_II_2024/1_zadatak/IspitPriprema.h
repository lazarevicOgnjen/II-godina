#ifndef ISPIT_PRIREMA_H
#define ISPIT_PRIREMA_H

#include "IspitniMaterijal.h"
#include <stdexcept>

class IspitPriprema {
private:
    IspitniMaterijal** _materijali;
    int _trenutno;
    int _max;
    
    void prosiriNiz();
    
public:
    IspitPriprema(int max);
    IspitPriprema(const IspitPriprema& other);
    IspitPriprema& operator=(const IspitPriprema& other);
    ~IspitPriprema();
    
    void Dodaj(IspitniMaterijal* materijal);
    void Obrisi(int oznaka);
    void Savladaj(int oznaka);
    int UkupnoSavladanih() const;
    float UkupnoVreme(float vremeJedinicno) const;
    void VratiNaj(float vremeJedinicno, IspitniMaterijal** matMin, IspitniMaterijal** matMax) const;
    
    friend std::ostream& operator<<(std::ostream& os, const IspitPriprema& priprema);
};

#endif

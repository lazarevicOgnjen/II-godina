#ifndef ISPITNI_MATERIJAL_H
#define ISPITNI_MATERIJAL_H

#include <iostream>

class IspitniMaterijal {
protected:
    int _oznaka;
    float _tezina;
    bool _savladao;
    
public:
    IspitniMaterijal(int oznaka, float tezina, bool savladao = false);
    virtual ~IspitniMaterijal() {}
    
    int getOznaka() const { return _oznaka; }
    float getTezina() const { return _tezina; }
    bool getSavladao() const { return _savladao; }
    void setSavladao(bool savladao) { _savladao = savladao; }
    
    virtual float vremePotrebno(float vremeJedinicno) const = 0;
    virtual void prikazi(std::ostream& os) const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const IspitniMaterijal& materijal);
};

class Lekcija : public IspitniMaterijal {
private:
    float _duzina;
    
public:
    Lekcija(int oznaka, float tezina, float duzina, bool savladao = false);
    float vremePotrebno(float vremeJedinicno) const override;
    void prikazi(std::ostream& os) const override;
};

class Zadatak : public IspitniMaterijal {
private:
    int _brojLinija;
    
public:
    Zadatak(int oznaka, float tezina, int brojLinija, bool savladao = false);
    float vremePotrebno(float vremeJedinicno) const override;
    void prikazi(std::ostream& os) const override;
};

#endif

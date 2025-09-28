#ifndef PICE_H
#define PICE_H

#include <iostream>

class Pice {
protected:
    float zapremina;
    int   brojAmbalaza;

public:
    Pice(float z, int b = 1);
    virtual ~Pice();

    float getZapremina()  const { return zapremina; }
    int   getBrojAmbalaza() const { return brojAmbalaza; }

    virtual const char* vrsta() const = 0;
    virtual float cena() const = 0;
    virtual bool jednako(const Pice& drugo) const = 0;
    virtual void prikazi() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Pice& p) {
        p.prikazi(); return os;
    }
};

class Voda : public Pice {
public:
    Voda(float z, int b = 1);
    const char* vrsta() const override { return "Voda"; }
    float cena() const override;
    bool jednako(const Pice& drugo) const override;
    void prikazi() const override;
};

class Sok : public Pice {
private:
    char ukus[50];
    int  procenatVoca;
    float odnosCeneVodaVoc;

public:
    Sok(float z, const char* u, int pv, float odnos, int b = 1);
    const char* vrsta() const override { return "Sok"; }
    float cena() const override;
    bool jednako(const Pice& drugo) const override;
    void prikazi() const override;

    const char* getUkus()        const { return ukus; }
    int         getProcenatVoca() const { return procenatVoca; }
};

#endif

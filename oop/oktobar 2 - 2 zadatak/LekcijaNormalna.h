#ifndef LEKCIJA_NORMALNA_H
#define LEKCIJA_NORMALNA_H

#include <iostream>

class LekcijaNormalna {
private:
    char* naziv;
    float tezina;
    float duzina;
    
    void kopiraj(const char* src, char*& dest);
    
public:
    LekcijaNormalna();
    LekcijaNormalna(const char* n, float t, float d);
    LekcijaNormalna(const LekcijaNormalna& l);
    ~LekcijaNormalna();
    
    LekcijaNormalna& operator=(const LekcijaNormalna& l);
    bool operator>(const LekcijaNormalna& l) const;
    bool operator<(const LekcijaNormalna& l) const;
    bool operator>=(float vrednost) const;
    operator float() const;
    
    friend std::ostream& operator<<(std::ostream& os, const LekcijaNormalna& l);
    friend std::istream& operator>>(std::istream& is, LekcijaNormalna& l);
    
    const char* getNaziv() const { return naziv; }
    float getTezina() const { return tezina; }
    float getDuzina() const { return duzina; }
    
    void setNaziv(const char* n);
    void setTezina(float t) { tezina = t; }
    void setDuzina(float d) { duzina = d; }
};

#endif

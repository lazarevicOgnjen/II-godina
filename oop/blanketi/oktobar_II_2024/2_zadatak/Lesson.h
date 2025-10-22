#ifndef LESSON_H
#define LESSON_H

#include <iostream>

class Lesson {
protected:
    float _tezina;
    float _duzina;
    char _naziv[8];
    
public:
    Lesson();
    Lesson(const char* naziv, float tezina, float duzina);
    virtual ~Lesson() {}
    
    virtual float getTezina() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void sacuvaj(std::ostream& file) const = 0;
    virtual void ucitaj(std::istream& file) = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Lesson& lesson);
};

class SimpleLesson : public Lesson {
public:
    SimpleLesson();
    SimpleLesson(float tezina);
    float getTezina() const override;
    void print(std::ostream& os) const override;
    void sacuvaj(std::ostream& file) const override;
    void ucitaj(std::istream& file) override;
};

class NormalLesson : public Lesson {
public:
    NormalLesson();
    NormalLesson(const char* naziv, float procenjenaTezina, float duzina);
    float getTezina() const override;
    void print(std::ostream& os) const override;
    void sacuvaj(std::ostream& file) const override;
    void ucitaj(std::istream& file) override;
};

#endif

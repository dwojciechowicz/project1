//plik naglowkowy klasy wielomian
#ifndef WIELOMIAN_H_
#define WIELOMIAN_H_
#include "jednomian.h"
class Wielomian
{
private:
    Jednomian *st2;
    Jednomian *st1;
    Jednomian *st0;
public:
    Wielomian();
    Wielomian(const Wielomian & w);
    Wielomian(Jednomian *a,Jednomian *b,Jednomian *c);
    Wielomian(int a,int b, int c);
    ~Wielomian();
    void pochodna();
    void pierwiastki();
    Wielomian & operator=(const Wielomian & j);
    Wielomian operator+(const Wielomian & w)const;
    Wielomian operator+=(const Wielomian & w);
    Wielomian operator-(const Wielomian & w)const;
    Wielomian operator-=(const Wielomian & w);
    friend std::ostream & operator<<(std::ostream & os, const Wielomian & w);
};
#endif

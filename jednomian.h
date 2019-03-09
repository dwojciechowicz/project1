//plik naglowkowy klasy jednomian
#ifndef JEDNOMIAN_H_
#define JEDNOMIAN_H_
#include <iostream>

class Jednomian
{
private:
  int *wspolczynnik;
    int *potega;
    friend class Wielomian;
public:

    Jednomian();
    Jednomian(const Jednomian & j);
    Jednomian(int ws,int pot);
    Jednomian pochodna()const;
    ~Jednomian();
    Jednomian & operator=(const Jednomian & j);
    Jednomian operator+(const Jednomian & j) const;
    Jednomian operator+=(const Jednomian & j);
    Jednomian operator-(const Jednomian & j) const;
    Jednomian operator-=(const Jednomian & j);
    int wiekszy()const;
    friend std::ostream & operator<<(std::ostream & os, const Jednomian & j);
};
#endif

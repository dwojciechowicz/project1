//implementacje matod klasy jednomian
#include "jednomian.h"

using namespace std;

Jednomian::Jednomian()//konstruktor domyslny
{
    cout<<"Wywolano konstruktor domyslny jednomianu"<<endl;
    wspolczynnik=new int;
    *wspolczynnik=0;
    potega=new int;
    *potega=0;
}
Jednomian::Jednomian(const Jednomian & j)
{
    cout<<"Wywolano konstruktor kopiujacy jednomianu"<<endl;
    wspolczynnik=new int;
    *wspolczynnik=*j.wspolczynnik;
    potega=new int;
    *potega=*j.potega;
}
Jednomian::Jednomian(int ws,int pot)
{
    cout<<"Wywolano konstruktor jednomianu z argumentami "<<ws<<" i "<<pot<<endl;
    wspolczynnik=new int;
    *wspolczynnik=ws;
    potega=new int;
    *potega=pot;
}
Jednomian::~Jednomian()//destruktor
{
    cout<<"Wywolano destruktor jednomianu "<<*this<<endl;
    delete wspolczynnik;
    delete potega;
}
Jednomian Jednomian::pochodna()const
{
    Jednomian rozniczka;
    *rozniczka.wspolczynnik=*wspolczynnik**potega;
    *rozniczka.potega=*potega-1;
    return rozniczka;
}
Jednomian & Jednomian::operator=(const Jednomian & j)
{
    if(this==&j)
        return *this;
    delete wspolczynnik;
    wspolczynnik=new int;
    *wspolczynnik=*j.wspolczynnik;
    delete potega;
    potega=new int;
    *potega=*j.potega;
    return *this;
}
Jednomian Jednomian::operator+(const Jednomian & j) const
{
    if(*potega==*j.potega)
    {
        Jednomian suma;
        *suma.wspolczynnik=*wspolczynnik+*j.wspolczynnik;
        *suma.potega=*potega;
        return suma;
        // return Jednomian(*wspolczynnik+*j.wspolczynnik, *potega);
    }
    else
    {
        cout<<"Potegi jednomianow sa rozne. Nie mozna wykonac dodawania"<<endl;
        return *this;
    }
}
Jednomian Jednomian::operator+=(const Jednomian & j)
{
    if(*potega==*j.potega)
    {
        *wspolczynnik=*wspolczynnik+*j.wspolczynnik;
        return *this;
    }
    else
    {
        cout<<"Potegi jednomianow sa rozne. Nie mozna wykonac dodawania"<<endl;
        return *this;
    }
}
Jednomian Jednomian::operator-(const Jednomian & j) const
{
    if(*potega==*j.potega)
    {
        Jednomian suma;
        *suma.wspolczynnik=*wspolczynnik-*j.wspolczynnik;
        *suma.potega=*potega;
        return suma;
    }
    else
    {
        cout<<"Potegi jednomianow sa rozne. Nie mozna wykonac odejmowania"<<endl;
        return *this;
    }
}
Jednomian Jednomian::operator-=(const Jednomian & j)
{
    if(*potega==*j.potega)
    {
        *wspolczynnik=*wspolczynnik-*j.wspolczynnik;
        return *this;
    }
    else
    {
        cout<<"Potegi jednomianow sa rozne. Nie mozna wykonac odejmowania"<<endl;
        return *this;
    }
}
int Jednomian::wiekszy()const//sprawdza czy wspolczynnik jednomianu jest wiekszy od zera
{
    if(*wspolczynnik>=0)
        return 1;
    else
        return 0;
}
ostream & operator<<(ostream & os, const Jednomian & j)
{
    if(*j.potega==0)
    {
        os<<*j.wspolczynnik;
    }
    else
    {
        os<<*j.wspolczynnik<<"x^"<<*j.potega;
    }

    return os;
}

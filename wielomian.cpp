//implementacje metod klasy wielomian
#include "wielomian.h"
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

Wielomian::Wielomian()//konstruktor domyslny
{
    cout<<"Wywolano konstruktor domyslny wielomianu"<<endl;
    st2=new Jednomian;
    st1=new Jednomian;
    st0=new Jednomian;
}
Wielomian::Wielomian(const Wielomian & w)
{
    cout<<"Wywolano konstruktor kopiujacy wielomianu"<<endl;
    st2=new Jednomian;
    *st2=*w.st2;
    st1=new Jednomian;
    *st1=*w.st1;
    st0=new Jednomian;
    *st0=*w.st0;
}
Wielomian::Wielomian(int a,int b,int c)
{
    st2=new Jednomian(a,2);
    st1=new Jednomian(b,1);
    st0=new Jednomian(c,0);
}
Wielomian::Wielomian(Jednomian *a,Jednomian *b,Jednomian *c)
{
    cout<<"Wywolano konstruktor wielomianu z argumentami:"<<*a<<" ,"<<*b<<" i "<<*c<<endl;
    if(*a->potega==2)
    {
        st2=a;
    }
    else
    {
        st2= new Jednomian(0,2);
    }
    if(*b->potega==1)
    {
        st1=b;
    }
    else
    {
        st1= new Jednomian(0,1);
    }
    if(*c->potega==0)
        st0=c;
    else
    {
        st0=new Jednomian;
    }
}
Wielomian::~Wielomian()//destruktor
{
    cout<<"Wywolano destruktor wielomianu "<<*this<<endl;
    delete st2;
    delete st1;
    delete st0;
}
void Wielomian::pochodna()
{
    cout<<"Pochodna wielomianu "<<*this<<" to: "<<st2->pochodna()<<" + "<<st1->pochodna()<<endl;
}
void Wielomian::pierwiastki()
{
    double a;
    double b;
    double c;
    a=*st2->wspolczynnik;
    b=*st1->wspolczynnik;
    c=*st0->wspolczynnik;
    if(a!=0)
    {
        double delta;
        delta=(b*b)-(4*a*c);
        if (delta>0)
        {
            double x1;
            double x2;
            x1=(-b-sqrt(delta))/(2*a);
            x2=(c/a)/x1;
            cout<<"Pierwiastki rownania kwadratowego "<<*this<<" wynosza: "<<x1<<" i "<<x2<<endl;
        }
        else
        {
            if (delta == 0)
            {
                double x0;
                x0=-b/(2*a);
                cout<<"Pierwiastek rownania kwadratowego "<<*this<<" wynosi "<<x0<<endl;
            }

            else
                cout<<"Rownanie "<<*this<<" nie ma pierwiastkow"<<endl;
        }
    }
    else if(b!=0)
    {
        double wynik;
        cout<<c<<endl;
        cout<<b<<endl;
        wynik=(double)(-c/b);
        cout<<"Pierwiastek wielomianu to: "<<wynik<<endl;
    }
    else
        cout<<"Wielomian nie ma pierwiastkow"<<endl;
}
Wielomian & Wielomian::operator=(const Wielomian & j)
{
    delete st2;
    st2= new Jednomian;
    *st2=*j.st2;
    delete st1;
    st1=new Jednomian;
    *st1=*j.st1;
    delete st0;
    st0=new Jednomian;
    *st0=*j.st0;
    return *this;
}
Wielomian Wielomian::operator+(const Wielomian & w)const
{
    Wielomian suma;
    *suma.st2=*st2+*w.st2;
    *suma.st1=*st1+*w.st1;
    *suma.st0=*st0+*w.st0;
    return suma;
}
Wielomian Wielomian::operator+=(const Wielomian & w)
{
    *st2=*st2+*w.st2;
    *st1=*st1+*w.st1;
    *st0=*st0+*w.st0;
    return *this;
}
Wielomian Wielomian::operator-(const Wielomian & w)const
{
    Wielomian suma;
    *suma.st2=*st2-*w.st2;
    *suma.st1=*st1-*w.st1;
    *suma.st0=*st0-*w.st0;
    return suma;
}
Wielomian Wielomian::operator-=(const Wielomian & w)
{
    *st2=*st2-*w.st2;
    *st1=*st1-*w.st1;
    *st0=*st0-*w.st0;
    return *this;
}
ostream & operator<<(ostream & os, const Wielomian & w)
{
    if((w.st1->wiekszy()) && (w.st0->wiekszy()))
        os<<*w.st2<<" +"<<*w.st1<<" +"<<*w.st0;
    else if((w.st1->wiekszy()) && !(w.st0->wiekszy()))
        os<<*w.st2<<" +"<<*w.st1<<" "<<*w.st0;
    else if(!(w.st1->wiekszy()) && !(w.st0->wiekszy()))
        os<<*w.st2<<" "<<*w.st1<<" "<<*w.st0;
    else if(!(w.st1->wiekszy()) && (w.st0->wiekszy()))
        os<<*w.st2<<" "<<*w.st1<<" +"<<*w.st0;
    return os;
}

//Klasa, ktorej obiekty reprezentuja wielomiany co najwyzej 2 stopnia
//Dorota Wojciechowicz
//prowadzaca: Aleksandra Pasnikowska
#include <iostream>
#include <limits>
#include "wielomian.h"

using namespace std;
const int ROZMIAR=4;
Wielomian *wsk[ROZMIAR];

void test(void);
void wypisz(void);
void dodawanie(Wielomian * wsk[]);
void odejmowanie(Wielomian * wsk[]);
void dodaj(Wielomian * wsk[]);
void odejmij(Wielomian * wsk[]);
void rozniczkowanie(Wielomian * wsk[]);
void pierwiastkowanie(Wielomian * wsk[]);
int menu(Wielomian * wsk[]);

int main()
{
    int i;
    cout<<"Na poczatku wpisz "<<ROZMIAR<<" wielomiany, na ktorych chcesz wykonywac obliczenia"<<endl;
    for(i=0; i<ROZMIAR; i++)
    {
        int a,b,c;
        cout<<"Wpisz wspolczynniki rownania kwadratowego poczynajac od 2 potegi"<<endl;
        if(!(cin>>a>>b>>c))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            wsk[i]=new Wielomian();
        }
        else
            wsk[i]=new Wielomian(a,b,c);
    }
    while (menu(wsk)!=0);
    for(i=0; i<ROZMIAR; i++)
    {
        delete wsk[i];
    }

    return 0;
}
void test()
{
    Jednomian *p=new Jednomian(1,2);
    Jednomian *r=new Jednomian(-2,1);
    Jednomian *s=new Jednomian(-3,0);
    Wielomian *pierwszy=new Wielomian(p,r,s);
    Wielomian *drugi=new Wielomian(8,6,4);
    Wielomian *trzeci=new Wielomian;
    cout<<"Test programu wykorzystujacy wielomiany:"<<*pierwszy<<", "<<*drugi<<" i "<<*trzeci<<endl;
    cout<<"Testowanie funkcji obliczjacej pierwiastki wielomianu"<<endl;
    pierwszy->pierwiastki();
    cout<<"Testowanie funkcji dodawania (+)"<<endl;
    *trzeci=*pierwszy+*drugi;
    cout<<*pierwszy<<" + "<<*drugi<<" = "<<*trzeci<<endl;
    cout<<"Testowanie funkcji odejmowania (-)"<<endl;
    *trzeci=*pierwszy-*drugi;
    cout<<*pierwszy<<" - ("<<*drugi<<") = "<<*trzeci<<endl;
    cout<<"Testowanie funkcji dodawania (+=)"<<endl;
    cout<<*pierwszy<<" += "<<*drugi<<" = ";
    *pierwszy+=*drugi;
    cout<<*pierwszy<<endl;
    cout<<"Testowanie funkcji odejmowania (-=)"<<endl;
    cout<<*pierwszy<<" -= "<<*trzeci<<" = ";
    *pierwszy-=*trzeci;
    cout<<*pierwszy<<endl;
    cout<<"Testowanie funkcji obliczajacej pochodna wielomianu"<<endl;
    pierwszy->pochodna();
    delete trzeci;
    delete drugi;
    delete pierwszy;
}
void wypisz(Wielomian * wsk[])
{
    int i;
    for(i=0; i<ROZMIAR; i++)
    {
        cout<<i<<"."<<*wsk[i]<<endl;
    }
}
void dodawanie(Wielomian * wsk[])
{
    int i,j;
    wypisz(wsk);
    cout<<"Podaj 2 cyfry odpowiadajace wielomianom, ktore chcesz dodac"<<endl;
    if(!(cin>>i>>j))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(i<ROZMIAR && j<ROZMIAR && i>=0 && j>=0)
        cout<<*wsk[i]<<" + "<<*wsk[j]<<" = "<<*wsk[i]+*wsk[j]<<endl;
}
void odejmowanie(Wielomian * wsk[])
{
    int i,j;
    wypisz(wsk);
    cout<<"Podaj 2 cyfry odpowiadajace wielomianom, ktore chcesz odjac"<<endl;
    if(!(cin>>i>>j))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(i<ROZMIAR && j<ROZMIAR && i>=0 && j>=0)
        cout<<*wsk[i]<<" - ("<<*wsk[j]<<") = "<<*wsk[i]-*wsk[j]<<endl;
}
void odejmij(Wielomian * wsk[])
{
    int i,j;
    wypisz(wsk);
    cout<<"Podaj 2 cyfry odpowiadajace wielomianom, ktore chcesz odjac"<<endl;
    if(!(cin>>i>>j))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(i<ROZMIAR && j<ROZMIAR && i>=0 && j>=0)
        cout<<*wsk[i]<<" -= "<<*wsk[j]<<" = ";
        cout<<(*wsk[i]-=*wsk[j])<<endl;

}
void dodaj(Wielomian * wsk[])
{
    int i,j;
    wypisz(wsk);
    cout<<"Podaj 2 cyfry odpowiadajace wielomianom, ktore chcesz dodac"<<endl;
    if(!(cin>>i>>j))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(i<ROZMIAR && j<ROZMIAR && i>=0 && j>=0)
        cout<<*wsk[i]<<" += "<<*wsk[j]<<" = ";
        cout<<(*wsk[i]+=*wsk[j])<<endl;

}
void pierwiastkowanie(Wielomian * wsk[])
{
    int i;
    wypisz(wsk);
    cout<<"Podaj cyfre, ktora odpowiada wielomianowi, ktorego pierwiastki chcesz znac"<<endl;
    if(!(cin>>i))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(i<ROZMIAR && i>=0)
        wsk[i]->pierwiastki();
}
void rozniczkowanie(Wielomian * wsk[])
{
    int i;
    wypisz(wsk);
    cout<<"Podaj cyfre, ktora odpowiada wielomianowi, ktory chcesz zrozniczkowac"<<endl;
    if(!(cin>>i))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if(i<ROZMIAR && i>=0)
        wsk[i]->pochodna();
}
int menu(Wielomian * wsk[])
{
    int num;
    cout<<"0 - zamknij program"<<endl<<"1 - test wbudowany"<<endl;
    cout<<"2 - dodawanie (+)"<<endl<<"3 - odejmowanie (-)"<<endl;
    cout<<"4 - dodawanie (+=)"<<endl<<"5 - odejmowanie (-=)"<<endl;
    cout<<"6 - rozniczkowanie"<<endl<<"7 - pierwiastkowanie"<<endl;
    cout<<"8 - wypisz"<<endl;
    cout<<"Wpisz cyfre odpowiadajaca funkcji ktora wybierasz"<<endl;
    while(!(cin>>num))
    {
        cout<<"Blad, wpisz ponownie"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (num)
    {
    case 0 :
        return 0;
    case 1 :
        test();
        break;
    case 2 :
        dodawanie(wsk);
        break;
    case 3 :
        odejmowanie(wsk);
        break;
    case 4 :
        dodaj(wsk);
        break;
    case 5 :
        odejmij(wsk);
        break;
    case 7 :
        pierwiastkowanie(wsk);
        break;
    case 6 :
        rozniczkowanie(wsk);
        break;
    case 8:
        wypisz(wsk);
        break;
    default :
        cout<<"Blad,wpisz ponownie";
    }
    return 1;
}

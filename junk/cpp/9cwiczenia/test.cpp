#include <iostream>
using namespace std;

class Foo
{
 public:
      int pierwsza;
      int druga;
 Foo();
 Foo(int,int);   

 friend ostream& operator<< (ostream&,Foo const&);
 friend istream& operator>> (istream&,Foo&);
 Foo operator+ (Foo const&);
};

Foo::Foo()
{
 pierwsza = druga = 0;
}

Foo::Foo(int a,int b)
{
 pierwsza = a;
 druga = b;
}

ostream& operator<< (ostream &wyjscie, Foo const& ex)
{
   wyjscie << "Pierwsza liczba: " << ex.pierwsza << " oraz druga: " << ex.druga << endl;
   return wyjscie;
}

istream& operator>> (istream &wejscie, Foo& ex)         
{
   wejscie >> ex.pierwsza >> ex.druga;
   return wejscie;
}

Foo Foo::operator+ (Foo const& ex)
{    
   Foo tmp(pierwsza + ex.pierwsza, druga + ex.druga);
   return tmp;    
}

int main()
{
    Foo ex1,ex2,ex3;

    cout << "Podaj 2 liczby dla:\n"
         << "Obiektu pierwszego: ";
    cin >> ex1;
    cout << "Oraz drugiego: ";
    cin >> ex2;

    cout << ex1 << ex2 << ex1+ex2;

    system("pause>nul");
}

#include<iostream>
#include<string>
using namespace std;


class Telefon {   
    int nr;
    string nazwa; 
    public:
       Telefon(int nr=0, string nz="") : nr(nr), nazwa(nz) {}
            friend istream& operator>> (istream &wejscie, Telefon &s);
       friend ostream & operator<< (ostream &wyjscie, const Telefon &s);


 };
 
 ostream & operator<< (ostream &wyjscie, const Telefon &s) {
   return wyjscie << "numer: " << s.nr << endl << "marka: " <<s.nazwa<<endl;
 }

  
istream& operator>> (istream &wejscie, Telefon &s)         
{   
    cout << "podaj nr";
   wejscie >> s.nr;
   cout << "podaj nazwe";
   wejscie >> s.nazwa;
   return wejscie;
}


  int main() {
 
   Telefon st, stu(10,"asd");
   cin >> st;
   cout << st; // wypisze nr indexu = 0, srednia ocen=0,
               // ponieważ są to wartosci domyślne konstruktora :)
  
   cout << stu; // wypisze nr indexu = 10, srednia ocen=5
   
   return 0;
 }
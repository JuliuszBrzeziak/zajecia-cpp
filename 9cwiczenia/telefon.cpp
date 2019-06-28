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

    void * operator new(size_t size ){
        cout << "tworzony nowy telefon" << endl;
        void * p = ::new Telefon();

        return p;
    }


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

    Telefon *t = new Telefon(12345,"tomek");

   cout << st; 
  
   cout << stu; 

   cout << *t;
   
   return 0;
 }
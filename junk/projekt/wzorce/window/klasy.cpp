#include <iostream>
using namespace std;

class KlasaThis {      
  int liczba;
public:
  void wczytaj(int liczba) {this->liczba=liczba;}


  
  void wypisz() {cout << liczba <<endl;}    
};

int main()
{
  KlasaThis ObiektThis;   
  ObiektThis.wczytaj(11);
  ObiektThis.wypisz(); 

  return 0;  
}
#include <iostream>

using namespace std;

class Zwierze{
    public:
    //Zwierze(); // po co to tutaj jest?
    void jedz2(); // i to?
//@up czy są to konstruktory?

    void jedz(){
        cout << "am am" << endl;
    }

};

class Ptak: public Zwierze{
    public:

    void lec(){
        cout << "fru fru" << endl;
    }
};

class Ryba: public Zwierze{
    public:

    void plyn(){
        cout << "hlup hlup" << endl;
    }
};





int main() {



    

   
    Zwierze zwierz1;

    zwierz1.jedz();

    Ptak ptak1;
    ptak1.jedz();
    ptak1.lec();
    // ptak1.plyn(); // nie mogę wywołać metody z innej podklasy w ten sposób

    Ryba *ryba = new Ryba();
    ryba->jedz();// -> to nie jest to samo co .
    ryba->plyn(); //co to jest ->??
    //a->b że wskaźnik a wskazuje na obiekt b


    //rzutowanie obiekty klasy ptak na zwierze
    Ptak *ptak = new Ptak();
    Zwierze *zwierze;
    zwierze = ptak;
    zwierze->jedz();

    //to też jest chyba jawne rzutowanie tylko w inny sposób
    Ryba ryba2;
    ((Zwierze)ryba2).jedz();

    //tutaj jest rzutowanie niejawne, kompilator sam to robi
    Zwierze zwierzeta[2];
    zwierzeta[0] = Ryba();
    zwierzeta[1] = Ptak();

    for (int i = 0; i<2;++i){
        zwierzeta[i].jedz();
    }





    return 0;
}
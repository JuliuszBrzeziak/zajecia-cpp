#include <iostream>

using namespace std;

class Pojazd
{
private:
    /* data */
public:
    int poj;

    Pojazd(int p);
    virtual ~Pojazd();
};

Pojazd::Pojazd(int p) :poj(p)
{
    
}

Pojazd::~Pojazd()
{
}

class Tram : public Pojazd
{
private:
    
public:
    Tram(int p);
   virtual ~Tram();
};

Tram::Tram(int p) : Pojazd(p)
{
    //poj = d;
}

Tram::~Tram()
{
}




int main(){
    //konstruktor odebrał nam możliwość kożystania z poniższych lini
    //Pojazd sam;
    //sam.poj = 1;

    Pojazd sam(2);
    Pojazd mot(1);
    Tram tra();


    cout << sam.poj << mot.poj << endl;

    


    return 0;
}
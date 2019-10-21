#include <iostream>

using namespace std;

class kociol
{
    private:

    int fuel;
    double temp;

};

class kontroler
{
    public:
    virtual void kont(int newtemp)=0;
};

class kaloryfer
{
    private:
    double tempk;
    void newtempk(int a){
        tempk = a;
    }
};

class termostat : private kontroler
{
    friend class kaloryfer;

    private:
    void newtempte(int a){
        tempt = a;
    }

};

class sterownik : private kontroler
{
    friend kociol;
    void wygas(){
        temp = 0;
    }

};

class serwisowe : 
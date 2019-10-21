#include <iostream>

using namespace std;


class B;//deklaracja zapowiadająca

class A{
    friend class B; //deklaracja przyjaźni
    //friend void F_friend(A &);
    public:
    int x;

};
/*
void F_friend(A & k){
    k.x=0;
}*/

class B{
    public:
    void wpisz(A& obiekt, const int wartosc){
        obiekt.x = wartosc;
        return;
    }
};

int main(){

    A a1;
    a1.x = 1;

    cout << "elo" << a1.x << endl;


    B b1;

    b1.wpisz(a1, 2);
    cout << "elo" << a1.x << endl;

    return 0;
}
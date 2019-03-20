#include<iostream>
#include<string>
using namespace std;

class myClass
{
    private:


    string imie, nazwisko, ulica, nr_domu, kod_pocztowy, miejscowosc;

    void getDataa(){
    cout << "podaj imie";
    getline(cin, imie);

    cout << "podaj nazwisko";
    getline(cin, nazwisko);

    cout << "podaj ulica";
    getline(cin, ulica);

    cout << "podaj nr_domu";
    getline(cin, nr_domu);

    cout << "podaj kod_pocztowy";
    getline(cin, kod_pocztowy);

    cout << "podaj miejscowosc";
    getline(cin, miejscowosc);
    }

    void printDataa(){
        cout << "--------------" << endl;
        cout << imie << " " << nazwisko << endl;
        cout << ulica << " " << nr_domu << endl;
        cout << kod_pocztowy << " " << miejscowosc << endl;
        cout << "--------------" << endl;
    }
};

int main(){
    myClass pas;

    cout << "he" << endl;
    pas.getDataa();
    pas.printDataa();
}
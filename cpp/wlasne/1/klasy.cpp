#include <iostream>

using namespace std;

class Zwrze
{
    public:
    //atrybuty
    string gtk;
    string ime;
    int wiek;

    //metody
    void dodaj_zwrze()
    {
        cout << "dodaj zwrz" << endl;
        cout << "podaj gtk" << endl;
        cin >> gtk;
        cout << "podaj ime" << endl;
        cin >> ime;
        cout << "podaj wiek" << endl;
        cin >> wiek;
    }

    void dj_gls(){
        cout << ime << wiek;
    }
};

int main(){
    Zwrze z1;

    z1.dodaj_zwrze();
    z1.dj_gls();

    return 0;
}
#include<string>
#include<iostream>
using namespace std;

int main(){
    //pierwszy sposób inicjalizacji stringa
    string napis1;
    napis1 = "text1";

    //przy użyciu konstruktora (!?)
    string napis2("text2");

    //chyba najlepszy
    string napis3="text3";

    cout << napis1 << napis2 << endl;
    cout << napis3 << endl;


    //wypełnia stringa 10`oma x`ami
    string napis4(10,'x');
    cout << napis4;
}
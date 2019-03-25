#include <iostream>


using namespace std;


int main(){

    int i;
//predefiniowanie wartości tablicy
    short tab[] = { 3, 6, 9};

    for (i=0; i<(sizeof(tab)/sizeof(short)); ++i){
        cout << tab[i];
    }

//deklaracja tablicy 2 wymiarowej
    char two_tab[3][5];

    char ch;
    ch = two_tab[2][4];
    //lub
    two_tab[0][0] = 'x';


    cout << two_tab[0][0] << endl;


    return 0;
}
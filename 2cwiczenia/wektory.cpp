#include <iostream>


using namespace std;


int main(){

    int i;
//predefiniowanie wartości tablicy
    short tab[] = { 3, 6, 9};

    for (i=0; i<(sizeof(tab)/sizeof(short)); ++i){
        cout << tab[i];
    }





    return 0;
}
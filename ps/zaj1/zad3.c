/*

Opracuj funkcję testującą czy przekazany jej bufor zawiera tylko i wyłącznie drukowalne znaki ASCII, 
tzn. bajty o wartościach z przedziału domkniętego [32, 126]. Funkcja ma mieć następującą sygnaturę: bool drukowalne(const void * buf, int len).

Pamiętaj o włączeniu nagłówka <stdbool.h>, bez niego kompilator nie rozpozna ani nazwy typu bool, ani nazw stałych true i false.

Zaimplementuj dwa warianty tej funkcji, w pierwszym wariancie funkcja ma pobierać kolejne bajty z bufora przy pomocy operacji indeksowania tablic, 
w drugim ma używać wskaźnika przesuwającego się z bajtu na bajt.
*/

#include <stdio.h>
#include <stdbool.h>

bool drukowalne(const void * buf, int len){

    char *wsk;

    for(int i = 0; i < len; i++){

    }

}

int main (){

}
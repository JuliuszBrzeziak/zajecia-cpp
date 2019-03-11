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

    //operator przypisania jak w C
    string a = "1"; string b = "2";
    a = b;
    cout << a;

    string aa, bb, cc;
    aa= "aa";
    bb= "bb";
    cc = "aa";

    //operator porównania ==
    if (aa==cc) cout << "aa i cc są równe \n";

    //operator różne !=
    if (aa!=bb) cout << "aa i bb są różne\n";

    //porządek leksygraficzny
    cout << "napis a ("<<aa<<") poprzedza napis b ("<<bb<<"): \n";
    if(aa<bb) cout << "tak a jest mniejsze leksygraficznie od a\n";
    else cout << "nieprawda\n";

    //łączenie łańcuchów
    aa = "mal" + aa;

    cout << "napis aa ("<<aa<<") poprzedza napis b("<<bb<<"): ";
    if (a<b) cout << "prawda\n";
    else cout << "nieprawda\n";

    //modyfikacja ?? dodaje znak 'x' w 0 miejscu
    bb[0] = '_';

    cout << "zmieniony wyraz b: "<<bb<<'\n';

    string v = "4321";
/* nie działa
    erase(v,4);
    
    cout << v;
*/

}
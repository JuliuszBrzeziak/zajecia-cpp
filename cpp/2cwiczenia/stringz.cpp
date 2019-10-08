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
    if (aa!=bb) cout << "aa i bb sa rozne\n";

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
 //erase usuwa znak od któregoś do któregoś
    v.erase(3,4);
    
    cout << v << endl;


//string który nie został zainicjalizowany zostaje pusty
    string pusty;

    cout << pusty << endl;
//empty sprawdza czy dany string jest pusty, jeśli tak to zwraca true
    if(pusty.empty()==true){
        cout << "pusty jest pusty" << endl;
    }

//size zwraca długość łancucha
    cout << v.size() <<endl;


//at oddaje to samo co v[1]
    cout << v.at(1) << endl;

    string w = "123456789";

//find zwraca cos dziwnego, nie rozumiem
 //   cout << w.find('4567')<<endl;




return 0;



}
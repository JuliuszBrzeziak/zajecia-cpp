#include <iostream>
#include <vector>

using namespace std;


//nadrzędna klasa
class Liczba{

    
    //klasa zawiera prywatną liczbę oraz tabele int
    private:
    //#############################################################
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //Ukradziono tab
    //Ukradziono i
    ////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //#############################################################
    
    


    //i publiczne metody
    public:

    //#############################################################
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //chwilowo umieszczono tutaj tab i l też
    int *tab;
    int l;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //#############################################################

    //bierze tablicę inta i wpisuje go w tabelę tab Liczby
    //DZIAŁA
    void Wczytaj_tab(int *tab){
        this->tab=tab;
    }


    //bierze inta i wpisuje go w l Liczby
    //DZIAŁA
    void Wczytaj_l(int a){
        l = a;
    }

    //wypisuje i`ty element tablicy
    //DZIAŁA
    void Wypisz_tabi(int i){
        cout << "element " <<i<<" to "<< tab[i] <<  endl;
    }
    
    //zwraca wielkość tablicy
    //NIEDZIAŁA
    template <typename T> int tab_Size(T tabw){
        cout << sizeof(tabw)/sizeof(*tabw) << endl;
        return sizeof(tabw)/sizeof(*tabw);
    }

    //wypisuje taba liczby
    //NIEDZIAŁA
    int tab_Size2(){
        return sizeof(tab)/sizeof(*tab);
    }

    //wypisuje tab
    //NIEDZIAŁA
    void Wypisz_tab(){
        for(int k=0;k<sizeof(tab)/sizeof(tab[0]);k++){
            cout << tab[k] << endl;
        }
    }

};

int main(){

    Liczba licz;
    int arr[3]={0,1,2};

    int *ar;
    ar = arr;
    vector <int> arv(3,2);

    licz.Wczytaj_tab(arr);

    

    cout << sizeof(arv)/sizeof(arv[1]) <<endl;



    cout << "zamykam się!"<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include "bitmap_image.hpp"


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
    vector<unsigned long long  int> tab;
    int l;
    vector<string> str;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //#############################################################

    //bierze tablicę inta i wpisuje go w tabelę tab Liczby
    //OK
    //void Wczytaj_tab(vector<unsigned long int> tab){
    //    this->tab=tab;
    //}


    //bierze inta i wpisuje go w l Liczby
    //OK
    void Wczytaj_l(int a){
        l = a;
    }

    //wypisuje i`ty element tablicy
    //OK
    void Wypisz_tabi(int i){
        cout << "element " <<i<<" to "<< tab[i] <<  endl;
    }
    
    //zwraca ilość elementów taba
    //OK
    int tab_Size(){
        return tab.size();
    }

    int str_Size(){
        return str.size();
    }    

    //wypisuje tab
    //OK
    void Wypisz_tab(){
        for(int k=0;k<tab_Size();k++){
            cout << tab[k] << ",";
        }
    }

    //sprawdza czy tab jest pusty, jeśli tak to wpisuje do niego fib
    //OK
    void fib_tab(int n){
        if(0 != tab_Size()){
            cout << "fib_tab error: niezerowa wielkośc tablicy" << endl;
            exit(1);
        } else{
            tab = {0,1,1};
            for(int i = 3; i<=n; i++){
                tab.push_back(tab[i-1] + tab[i - 2]);
            }
        }
    }

    //sprawdza czy tab jest pusty i wpisuje do niego silnie
    //OK
    void sil_tab(int n){
        
        int k;
        
        if(0 != tab_Size()){
            cout << "sil_tab error: niezerowa wielkośc tablicy" << endl;
            exit(2);
        } else{
            tab={1};
            for(int i =1;i<n;i++){
              
                tab.push_back( *(tab.end()-1) * i);
            }
        }
    }

    void nat_tab(int n){
        if(0 != tab_Size()){
            cout << "nat_tab error: niezerowa wielkośc tablicy" << endl;
            exit(3);
        } else {
            tab={0};
            for (int i = 1; i<n;i++){
                tab.push_back(i);
            }
        }
    }

    //spr czy tab i str jest pusty i wkleja odwrócony bit
    //OK
    void itrs(){

        if(0 == tab_Size()){
            cout << "itrs error: zerowa wielkośc tablicy liczb" << endl;
            exit(3); 
        }

        if(0 != str_Size()){
            cout << "itrs error: niezerowa wielkośc tablicy" << endl;
            exit(4);
        } else{
            string s;
            for(int i = 0; i <= tab_Size(); i++){
                s = bitset< 128 >(tab[i]).to_string();
                reverse(s.begin(),s.end());
                str.push_back(s);
            }
            
        }
    }

    //printuje mojego stringa bitów
    //OK
    void prtstr(){
        for(int i =0; i<str_Size();i++){
            cout << str[i] << endl;
        }
    }

    //printuje długość stringa
    //OK
    void nl(){
        cout << str[0].length() << endl;
        cout << str[0][2] << endl;
    }

    //rysuje bit po bicie daną liczbę
    //NIEDZIAŁA
    void rysuj(){
        struct point_t { double x,y; };

        const int canvas_width  = 200;//ustalenie szerokości mapy
        const int canvas_height = 200;//ustalenie wysokości

        cartesian_canvas canvas(canvas_width,canvas_height);

        point_t pnt = {0,0};
        for(int i = 0; i <= str_Size();i++){
            for(int j = 0; j< str[0].length(); j++ ){

                if('1'==str[i][j]){
                    canvas.plot_pixel(i,j);
                }

            }
        }

        canvas.image().save_image("plot.bmp");
    }

    //Funkcja testowa
    void test(int i,int talbica[],vector<int> vec){

        int tablica2[5]={0,1,2,3,4};
        int i2=884;
        vector<unsigned long long int> vec2(5,3);

        //vec2[0]=88;
        //vec2[1]=881;
        vec2[2]=882;
        //vec2[3]=883;
        

        //sprawdza fib_tab
        cout <<"fib_tab ";
        sil_tab(4);
        Wypisz_tab();
        cout<<"  jesli jest \"0,1,1,2,3,5\" to dobrze"<<endl;


        //sprawdza działanie wczytaj_tab wewnętrznego wektora
        //Wczytaj_tab(vec2);
        cout <<"wczytaj_tab wewnątrz:" <<tab[2] << "  jeżeli 882 to dobrze"<< endl;
        cout << "tab_size " << tab_Size() << " powinno być 5" << endl;

        //sprawdza wczytaj_tab wektorów zewnętrznych
        //Wczytaj_tab(vec);
        cout <<"wczytaj_tab zewnątrz:" <<tab[2] << "  jeżeli 883 to dobrze"<< endl;

        //sprawdza działanie wewnętrznego wczytaj_l
        Wczytaj_l(i2);
        cout <<"wczytaj_l wewnątrz:" <<i2 << "  jeżeli 884 to dobrze"<< endl;

        //sprawdza działanie zewnętrznego wczytaj_l
        Wczytaj_l(i);
        cout <<"wczytaj_tab wewnątrz:" <<l << "  jeżeli 885 to dobrze"<< endl;

        //sprawdza wypisz_tabi
        Wypisz_tabi(2);

        //sprawdza tab_size
        cout << "tab_size " << tab_Size() << " powinno być 4" << endl;

        //sprawdza wypisz_tab
        cout << "wypisz tab";
        Wypisz_tab();
        cout << "powinno być \"883,883,883,\" "<<endl;

        //sprawdza prtspr
        cout << "prtspr" <<endl;
        itrs();
        prtstr();

        nl();

        //nat_tab(20);

        //rysuj();
        cout << "koniec testu"<<endl;
    }

};


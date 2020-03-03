/*
TODO
generowanie randomowego OK
suma OK
część wspólna OK
różnica OK
sprawdzanie identycznościOK
wstawianie x OK
usuwanie x OK
sprawdzanie czy x należy OK
badanie czasów
*/
#include<iostream>
#include<string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <fstream> 
using namespace std;

#define NN 1000
class Sett
{
    public:

    int N ;
    int tab[NN];

    void setrnd(int n){

        N =n;
        
        for(int i = 0; i<N; i++){
            tab[i] = rand()%2;
            cout << tab[i];
        }
        cout << endl;
    }

    void prt(){
        for(int i = 0; i<N; i++){
            cout << tab[i];
        }
        cout << endl;
    }

    void wst(int a){
        tab[a] = 1;
    }

    void usu(int a){
        tab[a] = 0;
    }

    int spr(int a){
        if(tab[a]==1){
            return 1;
        } else {
            return 0;
        }
    }


    Sett sum(Sett a, Sett b){
        Sett c;
        c.N = a.N;
        cout << "suma";
        for(int i=0; i<N;i++){
            if(a.tab[i]==0 && b.tab[i]==0){
                c.tab[i]=0;
            } else {
                c.tab[i] =1;
            }
        }

        return c;
    }

    Sett czwsp(Sett a, Sett b){
        Sett c;
        cout << "część wspólna";
        for(int i=0; i<N;i++){
            if(a.tab[i]==1 && b.tab[i]==1){
                c.tab[i]=1;
            } else {
                c.tab[i] =0;
            }
        }
        return c;
    }

    Sett rca(Sett a, Sett b){
        Sett c;
        cout << "różnica";
        for(int i=0; i<N;i++){
            if(a.tab[i]==1 && b.tab[i]==1){
                c.tab[i]=0;
            } else {
                c.tab[i] = a.tab[i];
            }
        }
        return c;
    }

    bool idt(Sett a, Sett b){
        Sett c;
        for(int i=0; i<N;i++){
            if(a.tab[i]!=b.tab[i]){
                return false;
            } 
        }
        return true;
    }


};

int main(){
    clock_t t,y,u;
    t = clock();
    y= clock();
    u = clock();
    srand(time(NULL));
    Sett a,b,c;
    a.setrnd(9);
    b.setrnd(9);
    c.setrnd(9);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    cout << a.idt(a,b) << a.idt(a,a) << c.N<< endl;   
    c = a.sum(a,b);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    //c.prt();
    c = a.czwsp(a,b);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    //c.prt();
    c = a.rca(a,b);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    //c.prt();
    cout << a.idt(a,b) << a.idt(a,a) << c.N<< endl;
    y = clock() - y;
    printf ("It took me %d clicks (%f seconds).\n",y,((float)y)/CLOCKS_PER_SEC);
    u = clock() - u;
    printf ("It took me %d clicks (%f seconds).\n",u,((float)u)/CLOCKS_PER_SEC);
    
    ofstream outfile ("test.txt");

    outfile << "my text here!" << endl;

    outfile.close();

    return 0;

}
#include <iostream>
using namespace std;

class Liczby{
    public:
    int *fac;
    int li;
    int tab[100];
    int *tabs;
    int **tabs2;

    
    void wczytaj(int *tabs){
        this->tabs=tabs;
    }
    void wpisz_li(int a){
        li = a;
    }

    void wypisz(int i){
        cout << "czesc" << tabs[i] <<  endl;
    }

    void wypisz_tab(int *tab){
        for(int k=0;k<2;k++){
            cout << tab[k] << endl;
        }
    }
    

    void S(int a){
        int * sil = new int[a];
        sil[0]=1;
        for(int k=1;k<=a;k++){
            sil[k] = sil[k-1]*k;
            cout << "s"<<sil[k]<<endl;
        }

        tabs = sil;
        delete [] sil;
    }
    
};


int **  tab2(int a, int b){

    int** tabb = new int*[a];
    int i,j;
    a++;



    for( i=0;i<=4;i++){
        tabb[i] = new int[a];
        for ( j = 0; j <= 4; j++)
        {
            tabb[i][j] = j*i;
        }
        
    }

    return tabb;

}


int main(){

    int *tm;


    int **tb;
    int tn[] = {1,2,3};
    Liczby lim; 

    lim.S(5);

    lim.wpisz_li(30);

    //lim.wczytaj(tn);
    lim.wypisz(1);
    lim.wypisz_tab(lim.tabs);

    //tb = tab2(2,2);


    cout << "wychodze!" << lim.tabs[3] <<endl;
    return 0;
}

#include<iostream>
#include<string>
#include "liczby.h"
//#include "liczby.cpp"

using namespace std;




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

int main(int argc, char const *argv[])
{


    Liczby lim;
    
    int **arr;
    int *ar;

   // ar[1] = 2;

    arr = tab2(4,3);

    lim.tab2 = arr;
    cout <<  "hej"   << endl;
    //lim.tab = ar;
    //lim.Si(1);

    
    cout <<  "hej"   << "xxx"<< endl;
    
    return 0;
}


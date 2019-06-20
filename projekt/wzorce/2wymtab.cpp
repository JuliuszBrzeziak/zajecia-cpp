#include<iostream>
#include<string>

using namespace std;

int **  tab2(int a, int b){

    int** tab = new int*[a];
    int i,j;
    a++;

    for( i=0;i<=4;i++){
        tab[i] = new int[a];
        for ( j = 0; j <= 4; j++)
        {
            tab[i][j] = j*i;
        }
        
    }

    return tab;

}

int main(int argc, char const *argv[])
{

    int **arr;

    arr = tab2(4,3);

    cout << arr[4][4] << endl;
    
    return 0;
}


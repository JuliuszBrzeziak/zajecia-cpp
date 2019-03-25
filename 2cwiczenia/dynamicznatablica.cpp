#include <iostream>


using namespace std;

int main(){

    int* a = NULL; //wskaźnik na int równy null

    int n;
    cout << "podaj wielkość tablicy" << endl;
    cin >> n;
    
    a = new int[n]; // alokowanie tablicy o wielkości n

    //generowanie tablicy
    int j = 0;
    for(int i = 0; i<n;i++){
        a[i] = j;
        j +=1; // to to samo co j = j+1
    }

    //wypisywanie tablicy
    for(int i = 0; i<n; i++){
        cout << a[i] <<endl;
    }

    //uwalniamy dane
    //czy jest to niezbędne?
    delete[] a; // uwalnia dane pod wskaźnikiem "a"
    a = NULL; //ustawiamy wskaźnik na null, tak żeby nie było...
    //...dostępu do niezadeklarowanej pamięci

    cout << "koncze robote";


    return 0;
}
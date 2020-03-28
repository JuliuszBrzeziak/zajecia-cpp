#include <iostream>
using namespace std; 
  
// Zamienia elementy miejscami
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

//drukuje listę 
void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        cout << arr[i] << " ";
        cout << endl; 
} 

  
//ustala pivot a następnie zwraca jego miejce
int lomuto(int arr[], int l, int h) 
{ 
    int x = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++) { 
        if (arr[j] <= x) { 
            i++; 
            swap(&arr[i], &arr[j]); 
            //printArr(arr,h+1);
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 


void quickSortIterative(int arr[], int l, int h) 
{ 
    // tworzymy stos
    int stos[h - l + 1]={}; 
  
    // inicjalizujemy wierzchołek 
    int top = -1; 
  
    // wkładamy zmienne na stos
    stos[++top] = l; 
    stos[++top] = h; 


    // zdejmujemy do końca stosu
    while (top >= 0) { 
        // zdejmujemy zmienne
        h = stos[top--]; 
        l = stos[top--]; 

   
  
  
        // ustalamy pivot
        int p = lomuto(arr, l, h); 
  
        //jeżeli jest coś po lewej stronie pivota to wrzucamy ją na stos
        if (p - 1 > l) { 
            stos[++top] = l; 
            stos[++top] = p - 1; 
        } 
  

        //jeżeli coś jest po prawej stronie pivota to wrzucamy ją na stos
        if (p + 1 < h) { 
            stos[++top] = p + 1; 
            stos[++top] = h; 
        } 
    } 
} 
  

  
 
int main() 
{ 
    int arr[] = { 4, 3, 5, 2, 1,3,2,1 }; 
    int n = sizeof(arr) / sizeof(*arr); 
    quickSortIterative(arr, 0, n - 1); 
    printArr(arr, n); 
    return 0; 
} 

#include <bits/stdc++.h> 
using namespace std; 
  
//budowa maksymalnego kopca
void buildMaxHeap(int arr[], int n)  
{  
    for (int i = 1; i < n; i++)  
    { 
        // jeśli dziecko jest większe od rodzica
        if (arr[i] > arr[(i - 1) / 2])  
        { 
            int j = i; 
      
            // swap tak długo jak rodzic jest mniejszy
            while (arr[j] > arr[(j - 1) / 2])  
            { 
                swap(arr[j], arr[(j - 1) / 2]); 
                j = (j - 1) / 2; 
            } 
        } 
    } 
} 
  
void heapSort(int arr[], int n)  
{ 
    buildMaxHeap(arr, n); 
  
    for (int i = n - 1; i > 0; i--) 
    { 
        // swap wierzchołka i ostatniego
        swap(arr[0], arr[i]); 
      
        // ustalanie zmiennych
        int j = 0, index; 
          
        do
        { 
            //index na dziecko
            index = (2 * j + 1); 
              
            // jezeli lewe dziecko jest mniejsze to index na prawe
            if (arr[index] < arr[index + 1] && 
                                index < (i - 1)) 
                index++; 
          

            //jeżeli rodzic jest mniejszy niż dziecko to swap z większym dzieckiem
            if (arr[j] < arr[index] && index < i) 
                swap(arr[j], arr[index]); 
          
            j = index; 
          
        } while (index < i); 
    } 
} 
  

int main()  
{ 
    int arr[] = {10, 20, 15, 17, 9, 21,39,29,142,421,213,291,3291,2139,123,123,4,12,421,4,325,32,42342,123,23,321,341}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    printf("tablica: "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
          
    printf("\n\n");  
  
    heapSort(arr, n); 
  
    
    printf("posortowana tablica: "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
  
    return 0; 
} 

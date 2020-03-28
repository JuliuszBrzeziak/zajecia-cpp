#ifndef ARRAY_H_
#define ARRAY_H_

#define MIN_POJEMNOSC 10
#define GROWTH_FACTOR 2


#include <iostream>

using namespace std;

template <class T>
class SortedArrayList {

//template <class T>
public:
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}
//konstruktoty
//NEED: dopisać bebechy konstruktorów
SortedArrayList(){
    
};
SortedArrayList(int a){    pojemnosc = MIN_POJEMNOSC;
    wielkosc = a;
    element = (T*)malloc(pojemnosc * sizeof(*element));
    if (!element)
        throw std::bad_alloc();
};
SortedArrayList( SortedArrayList<T> &a){//kopiujący
    cout << "ale" << endl;
    //this->wielkosc = a.get();
    /*element = (T*)malloc(a.wielkosc * sizeof(*element));
    element = a.element;
    if (!element)
        throw std::bad_alloc();*/
        //cout << a.wielkosc << endl;
} 
SortedArrayList(SortedArrayList && ){}
~SortedArrayList(){
    free(element);
};
T get(){
    return wielkosc;
}
/*
//operatory
T &operator = (const T &t){ //kopiujący
    return *this;
}

T &operator = ( T &&t){ //przenoszący
    
    return *this;
}
*/


    void push(T value){// Wstawia element 'x'
        if (wielkosc >= pojemnosc)
            resize();
        *(element + wielkosc++) = value;
    }  

    T pop();               // Zwraca i usuwa pierwszy (najmniejszy) element
    size_t erase(size_t i); // Usuwa element na pozycji 'i'
    size_t find(T x);  // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size();            // Zwraca liczbę elementów w liście
    void remove(T x);      // Usuwa wszystkie elementy równe 'x'
    static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b);
                           // Scala dwie posortowane listy i zwraca posortowaną listę
    void unique();         // Usuwa sąsiadujące duplikaty
    void print();          // Wypisuje elementy listy (w porządku rosnącym)*/

    



    public:
        size_t wielkosc;
        size_t pojemnosc;
        T* element;
    void resize() {
    size_t capacity = pojemnosc*GROWTH_FACTOR;
    T *tmp = (T*)realloc(element, capacity * sizeof(*element));
    if (!tmp)
        throw std::bad_alloc();
    element = tmp;
    pojemnosc = capacity;
}

};
#endif /* ARRAY_H_ */
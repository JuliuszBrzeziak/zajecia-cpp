#ifndef ARRAY_H_
#define ARRAY_H_

#define MIN_POJEMNOSC 10
#define GROWTH_FACTOR 2


#include <iostream>

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
SortedArrayList(){
    
};
SortedArrayList(int a){    pojemnosc = MIN_POJEMNOSC;
    wielkosc = 0;
    element = (T*)malloc(pojemnosc * sizeof(*element));
    if (!element)
        throw std::bad_alloc();
};
SortedArrayList(const SortedArrayList<T> &a){} //kopiujący
SortedArrayList(SortedArrayList && ){}
~SortedArrayList(){};
/*
//operatory
T &operator = (const T &t){ //kopiujący
    return *this;
}

T &operator = ( T &&t){ //przenoszący
    
    return *this;
}
*/


    void push(T x);       // Wstawia element 'x'
    T pop();               // Zwraca i usuwa pierwszy (najmniejszy) element
    size_t erase(size_t i); // Usuwa element na pozycji 'i'
    size_t find(T x);  // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size();            // Zwraca liczbę elementów w liście
    void remove(T x);      // Usuwa wszystkie elementy równe 'x'
    static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b);
                           // Scala dwie posortowane listy i zwraca posortowaną listę
    void unique();         // Usuwa sąsiadujące duplikaty
    void print();          // Wypisuje elementy listy (w porządku rosnącym)*/

    private:
        size_t wielkosc;
        size_t pojemnosc;
        T* element;
        void resize();


};
#endif /* ARRAY_H_ */
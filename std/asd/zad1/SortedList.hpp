#ifndef ARRAY_H_
#define ARRAY_H_



#include <iostream>

template <class T>
class SortedList {

//template <class T>
public:
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}
//konstruktoty
SortedList(){};
SortedList(int a){};
SortedList(const SortedList<T> &a){} //kopiujący
SortedList(SortedList && ){}
~SortedList(){};
/*
//operatory
T &operator = (const T &t){ //kopiujący
    return *this;
}

T &operator = ( T &&t){ //przenoszący
    
    return *this;
}
*/


    void push(T x);        // Wstawia element 'x'
    T pop();               // Zwraca i usuwa pierwszy (najmniejszy) element
    size_t erase(size_t i); // Usuwa element na pozycji 'i'
    size_t find(T x);  // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size();            // Zwraca liczbę elementów w liście
    void remove(T x);      // Usuwa wszystkie elementy równe 'x'
    static SortedList merge(const SortedList& a, const SortedList& b);
                           // Scala dwie posortowane listy i zwraca posortowaną listę
    void unique();         // Usuwa sąsiadujące duplikaty
    void print();          // Wypisuje elementy listy (w porządku rosnącym)*/
};
#endif /* ARRAY_H_ */
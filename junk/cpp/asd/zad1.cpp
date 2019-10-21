
#include <stdio.h>
#include <stdlib.h>


using namespace std;


 using position_t = int;

template<typename T>
class SortedList {
    // using position_t = node<T>*; // Typ pozycji w liście dla implementacji wskaźnikowej
      // int dla implementacji tablicowej i kursorowej

    void push(T x);        // Wstawia element 'x'
    T pop();               // Zwraca i usuwa pierwszy (najmniejszy) element
    T erase(position_t i); // Usuwa element na pozycji 'i' i zwraca jego wartość
    position_t find(T x);  // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size();            // Zwraca liczbę elementów w liście
    void remove(T x);      // Usuwa wszystkie elementy równe 'x'
    static SortedList merge(const SortedList& a, const SortedList& b);
                           // Scala dwie posortowane listy i zwraca posortowaną listę
    void unique();         // Usuwa sąsiadujące duplikaty
    void print();          // Wypisuje elementy listy (w porządku rosnącym)
};

int main(int argc, char const *argv[])
{
    printf("hello0");
    return 0;
}

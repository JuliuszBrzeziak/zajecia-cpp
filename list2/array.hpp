
#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

template <class T>
class Array {
    public:
        Array();
        ~Array();

        void push_back(T value);// Wstawia element na koniec listy
        void push_front(T value);// Wstawia element na początek listy
        T pop_front(); //Usuwa element z początku listy i zwraca jego wartość
        T pop_back();// Usuwa element z końca listy  i zwraca jego wartość
        size_t erase(size_t index);// Usuwa element z pozycji pos i zwraca pozycję za usuwanym elementem
        size_t find(T value);// Wyszukuje element o wartości `x` i zwraca jego pozycję
        size_t insert(size_t pos, T x); // Wstawia element x przed pozycję pos i zwraca pozycję x


        void set(size_t index, T value); //Ustawiamy element index wartością value  
        T get(size_t index); //Zwraca wartość elementu 

        size_t size(); // Zwraca liczbę elementów w liście
        size_t capacity(); //Zwraca pojemność
        void print(); //wyświetla listę
        bool is_empty(); // Zwraca `true` gdy lista jest pusta

    private:
        size_t wielkosc;
        size_t pojemnosc;
        T* element;
        void resize();

};

#endif /* ARRAY_H_ */



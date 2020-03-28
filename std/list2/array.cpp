
#include "array.hpp"

#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MIN_POJEMNOSC 10
#define GROWTH_FACTOR 2


template <class T>
Array<T>::Array() {
    pojemnosc = MIN_POJEMNOSC;
    wielkosc = 0;
    element = (T*)malloc(pojemnosc * sizeof(*element));
    if (!element)
        throw std::bad_alloc();
}

template <class T>
Array<T>::~Array() {
    free(element);
}

template <class T>
void Array<T>::push_back(T value) {
    if (wielkosc >= pojemnosc)
        resize();
    *(element + wielkosc++) = value;
}

template <class T>
void Array<T>::push_front(T value) {
    if (wielkosc >= pojemnosc)
        resize();
    
    for(int i=0;i<=wielkosc;i++){
        *(element + wielkosc + 1 - i) = *(element + wielkosc -i);
    }

    *(element) = value;
}

template <class T>
T Array<T>::pop_front() {
    T pom = *element;
    this->erase(0);
    return pom;
}

template <class T>
size_t Array<T>::insert(size_t pos, T x) {
    if (wielkosc >= pojemnosc)
        resize();

    wielkosc++;
    for(size_t i = wielkosc;i>=pos;i--){
        *(element + 1 + i) = *(element + i);
    }
    *(element + pos) = x;
    return pos;
}


template <class T>
T Array<T>::pop_back() {
    T pom = *(element + wielkosc);
    this->erase(--wielkosc);

    return pom;
}

template <class T>
size_t Array<T>::erase(size_t index) {
    for(int i=index;i<=wielkosc;i++){
        *(element  + i) = *(element  +1 + i);
    }
    if(index==wielkosc){
        return index--;
    }
    wielkosc--;

    return index;
}

template <class T>
size_t Array<T>::find(T value) {
    for(size_t i = 0;i<wielkosc; i++){
        if(*(element + i)==value){
            return i;
        }
    }
    //return std::nullptr_t;
    return (size_t)NULL;
}

template <class T>
void Array<T>::set(size_t index, T value) {
    while (index >= wielkosc)
        this->push_back(0);
    *(element + index) = value;
}


template <class T>
T Array<T>::get(size_t index) {
    return *(element + index);
}

template <class T>
size_t Array<T>::size() {
    return wielkosc;
}

template <class T>
size_t Array<T>::capacity() {
    return pojemnosc;
}

template <class T>
void Array<T>::resize() {
    size_t capacity = pojemnosc*GROWTH_FACTOR;
    T *tmp = (T*)realloc(element, capacity * sizeof(*element));
    if (!tmp)
        throw std::bad_alloc();
    element = tmp;
    pojemnosc = capacity;
}

template <class T>
void Array<T>::print() {
    size_t i = 0;
    while (i < wielkosc) {
        std::cout << "Array[" << i << "] = " << this->get(i) << "\n";
        i++;
    }
}

template <class T>
bool Array<T>::is_empty() {
    if(wielkosc==0){
        return true;
    }
    else{
        return false;
    }
}

template class Array<int>;
template class Array<float>;
template class Array<std::string>;



#include "array.hpp"
#include <iostream>

int main () {
    Array<int> arr;
    Array<float> arr2;
    for (int i=0; i<20; i++)
        arr.push_back(20-i);


    arr.print();
    std::cout << arr.size() << std::endl;

    arr.pop_back();
    arr.insert(2,567);
    arr.insert(2,567);
    arr.print();
    std::cout << arr.size() << std::endl;
    std::cout << "szukam 9 : " << arr2.is_empty() <<std::endl;
    
    
    return 0;
}


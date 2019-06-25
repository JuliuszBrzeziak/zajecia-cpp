    //dodaje do siebie dwie binarne i wypluwa stringa binarnego
    //OK
    
    
    
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include "bitmap_image.hpp"  
    
    
    string addBinary(string a, string b) { 
        string result = ""; // Initialize result 
        int s = 0;          // Initialize digit sum 
        int i = a.size() - 1, j = b.size() - 1; 
        while (i >= 0 || j >= 0 || s == 1) 
        { 
        // Comput sum of last digits and carry 
        s += ((i >= 0)? a[i] - '0': 0); 
        s += ((j >= 0)? b[j] - '0': 0); 
  
        // If current digit sum is 1 or 3, add 1 to result 
        result = char(s % 2 + '0') + result; 
  
        // Compute carry 
        s /= 2; 
  
        // Move to next digits 
        i--; j--; 
        } 
        return result; 
    }
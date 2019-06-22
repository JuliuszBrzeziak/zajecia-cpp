#include <bitset>
#include <iostream>
#include <string>



using namespace std;


string reverse(string s){
    int n = s.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(s[i], s[n - i - 1]); 

        return s;

}

int main(){

    int a;
    a=3;

std::string s = std::bitset< 64 >( a ).to_string(); // string conversion

std::cout << std::bitset< 64 >( 54321 ) << ' '; // direct output

std::bitset< 64 > input;
//std::cin >> input;
//unsigned long ul = input.to_ulong();
//std::cout << ul << std::endl;
    int n = s.length(); 
  
s = reverse(s);

cout << s <<endl;
return 0;
}



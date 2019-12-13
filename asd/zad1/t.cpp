// function template
#include <iostream>
#include "SortedList.hpp"
using namespace std;



int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  SortedList<int> ar;
  
  k=ar.GetMax(i,j);
  //n=GetMax<long>(l,m);
  cout << k << endl;
  cout << n << endl;
  return 0;
}
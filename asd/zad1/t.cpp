// function template
#include <iostream>
#include "SortedList.hpp"
using namespace std;



int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  SortedList<int> ar(2);
  SortedList<int> arr(ar);
  SortedList<int> arrr(move(arr));
  
  k=arrr.GetMax(i,j);
  //n=GetMax<long>(l,m);
  cout << k << endl;
  cout << n << endl;
  return 0;
}
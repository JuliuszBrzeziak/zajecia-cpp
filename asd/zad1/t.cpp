// function template
#include <iostream>
#include "sortedArrayList.hpp"
using namespace std;



int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  SortedArrayList<int> ar(2);
  ar.push(3);
  SortedArrayList<int> arr(ar);
  /*
  SortedArrayList<int> arrr(move(arr));
  SortedArrayList<int> ab = SortedArrayList<int>(1);

   char *str;  
  
*/

  //k=arrr.GetMax(i,j);
  //n=GetMax<long>(l,m);
  cout << i << endl;
  //cout << n << endl;
  return 0;
}
#ifndef ARRAY_H_
#define ARRAY_H_



#include <iostream>

template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}

#endif /* ARRAY_H_ */
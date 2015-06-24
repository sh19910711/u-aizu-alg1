// Question 2
// 
// Write a program that searches by binary search and interpolation search. The program must fulfill the following conditions:
// 
//     A data object of searching must be displayed.
//     Input each key for binary search and interpolation search, and display the result.

#include <stdio.h>

#define FOUND 1
#define NOT_FOUND 0

int binary_search(int *a, int n, int key) {
  int i;
  int l;
  int r;
  int m;

  l = 0;
  r = n;
  for ( i = 0; i < 100; ++ i ) {
    m = (l + r) / 2;

    if ( a[m] == key ) {
      return FOUND;
    }

    if ( a[m] > key ) {
      r = m;
    } else if ( a[m] < key ) {
      l = m;
    }
  }

  return NOT_FOUND;
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  return 0;
}
#endif

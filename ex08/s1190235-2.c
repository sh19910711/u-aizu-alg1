/*
Question 2
http://web-ext.u-aizu.ac.jp/course/alg1/ex/uk/ex08/

Write a program that sorts by bubble sort, insertion sort and selection sort. The program must fulfill the following conditions:

A sequence is initialized when it is declared.
The program lets the user to choose the sorting method.
The program displays both the result and sorting process.
*/

#include <stdio.h>

void swap( int* a, int* b ) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubble( int* a, int n, void print(int*, int) ) {
  int i, j;
  for ( i = 0; i < n; ++ i ) {
    for ( j = n - 1; j > i; -- j ) {
      if ( a[j - 1] > a[j] ) {
        swap(a + j - 1, a + j);
      }
    }
    print(a, n);
  }
}

void insertion( int* a, int n, void print(int*, int) ) {
  int i, j, tmp;
  for ( i = 1; i < n; ++ i ) {
    tmp = a[i];
    j = i;
    while ( j - 1 >= 0 && a[j - 1] > tmp ) {
      a[j] = a[j - 1];
      j --;
    }
    a[j] = tmp;
    print(a, n);
  }
}

void selection( int* a, int n, void print(int*, int) ) {
  int i, j, good;
  for ( i = 0; i < n; ++ i ) {
    good = i;
    for ( j = i; j < n; ++ j ) {
      if ( a[good] > a[j] ) {
        good = j;
      }
    }
    swap(a + good, a + i);
    print(a, n);
  }
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  char buf[1024];
  int input[1024];
  printf("Before:  ");
  fgets(buf, 1024, stdin);
  return 0;
}
#endif

// Question 3
//
// Write a program that calculates the comparison time both for binary search and interpolation search, and display them. The program must fulfill the following conditions:
//
//     Number of a data is 100000 and data is constructed by random numbers.
//     Sort data by the sort functions which you have written in exercise 8 or 9.
//     Display data by each 30th because the data amount is too large.
//
// Additionally, fix interpolation function in question 2, because it have bugs which some data make it to be infinity loop or segmentation fault. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FOUND 1
#define NOT_FOUND 0

int binary_search(int *a, int n, int key) {
  int i;
  int l;
  int r;
  int m;

  l = 0;
  r = n;
  while ( l <  r ) {
    m = (l + r) / 2;

    if ( a[m] == key ) {
      return FOUND;
    }

    if ( a[m] > key ) {
      r = m;
    } else if ( a[m] < key ) {
      l = m + 1;
    }
  }

  return NOT_FOUND;
}

int interpolation_search(int *a, int n, int key) {
  int i;
  int l;
  int r;
  int m;

  l = 0;
  r = n;
  while ( l < r ) {
    if ( a[r] != a[l] ) {
      m = l + (double)(key - a[l]) / (double)(a[r] - a[l]) * (double)(r - l);
    } else {
      m = (l + r) / 2;
    }

    if ( m < l ) m = l;
    if ( m >= r ) m = r - 1;

    if ( a[m] == key ) {
      return FOUND;
    }

    if ( a[m] > key ) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return NOT_FOUND;
}

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void sort1(int *a, int n, int l, int r) {
  int i;
  int j;
  int x;
  int m;

  i = l;
  j = r;
  m = (l + r) / 2;
  x = a[m];
  for (;;) {
    while (a[i] < x) i ++;
    while (x < a[j]) j --;
    if ( i >= j ) break;
    swap(a + i, a + j);
    i ++;
    j --;
  }

  if (l < i - 1) sort1(a, n, l, i - 1);
  if (j + 1 < r) sort1(a, n, j + 1, r);
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  char buf[1000000];
  char *p;
  int a[1000000];
  int n;
  int i;
  int j;
  int tmp;
  int key;

  for ( n = 0; n < 100000; ++ n ) {
    a[n] = rand() % 100000 + 1;
  }

  sort1(a, n, 0, n - 1);

  puts("data:");
  for ( i = 0; i < 30; ) {
    for ( j = 0; j < 10; ++ j ) {
      printf("%d ", a[i]);
      i ++;
    }
    puts("");
  }

  printf("Input key for binary search: ");
  scanf("%d", &key);

  if ( binary_search(a, n, key) == FOUND ) {
    puts("found.");
  } else {
    puts("not found.");
  }

  printf("Input key for interpolation search: ");
  scanf("%d", &key);

  if ( interpolation_search(a, n, key) == FOUND ) {
    puts("found.");
  } else {
    puts("not found.");
  }

  return 0;
}
#endif

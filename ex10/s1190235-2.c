// Question 2
// 
// Write a program that searches by binary search and interpolation search. The program must fulfill the following conditions:
// 
//     A data object of searching must be displayed.
//     Input each key for binary search and interpolation search, and display the result.

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
  char buf[1000000];
  char *p;
  int a[1000000];
  int n;
  int i;
  int tmp;
  int key;

  printf("data: ");
  fgets(buf, 1000000, stdin);

  p = buf;
  n = 0;
  while (*p != '\0') {
    if (isdigit(*p)) {
      a[n ++] = strtol(p, &p, 10);
    } else {
      p ++;
    }
  }

  printf("Input key for binary search: ");
  scanf("%d", &key);

  if ( binary_search(a, n, key) == FOUND ) {
    puts("found.");
  } else {
    puts("not found.");
  }

  return 0;
}
#endif

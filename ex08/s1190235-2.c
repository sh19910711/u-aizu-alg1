/*
Question 2
http://web-ext.u-aizu.ac.jp/course/alg1/ex/uk/ex08/

Write a program that sorts by bubble sort, insertion sort and selection sort. The program must fulfill the following conditions:

A sequence is initialized when it is declared.
The program lets the user to choose the sorting method.
The program displays both the result and sorting process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void swap( int* a, int* b ) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubble( int* a, int n, void print(int*, int) ) {
  int i, j;
  for ( i = 0; i < n - 1; ++ i ) {
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
  for ( i = 0; i < n - 1; ++ i ) {
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
void print(int* a, int n) {
  int i;
  for ( i = 0; i < n; ++ i ) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  char buf1[1024]; // for input
  char buf2[1024]; // as tmp
  char *p1;
  char *p2;
  int input[1024];
  int n;
  int tmp;
  int sort_type;

  // input numbers
  printf("Before:  ");
  fgets(buf1, 1024, stdin);
  n = 0;
  p1 = buf1;
  while ( *p1 != '\0' ) {
    p2 = buf2;
    while ( isdigit(*p1) ) {
      *p2 = *p1;
      p1 ++;
      p2 ++;
      *p2 = '\0';
    }
    if ( isdigit(*buf2) ) {
      if ( sscanf(buf2, "%d", &tmp) != EOF ) {
        input[n ++] = tmp;
      }
    }
    p1 ++;
  }
  puts("");

  // input sort type
  printf("Select a method (1:buble, 2:insertion: 3: selection) > ");
  scanf("%d", &sort_type);
  switch(sort_type) {
    case 1:
      bubble(input, n, print);
      break;
    case 2:
      insertion(input, n, print);
      break;
    case 3:
      selection(input, n, print);
      break;
  }

  return 0;
}
#endif

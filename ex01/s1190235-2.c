#include <stdio.h>
#include <string.h>

#define LENGTH 256

int input(char* s) {
  char* p;
  printf("Input ISBN:  ");
  if ( fgets(s, LENGTH, stdin) == NULL ) {
    return 0;
  }
  p = s;
  while ( *p != '\0' ) {
    if ( *p == '\n' ) {
      *p = '\0';
    }
    p ++;
  }
  return 1;
}

char to_cd_char(int cd) {
  return cd == 10 ? 'X' : ('0' + cd);
}

int main() {
  char isbn[LENGTH];
  int s;
  int i;
  int k;
  int t;
  int cd;

  while ( input(isbn) ) {
    s = 0;
    k = 1;
    for ( i = 0; i < strlen(isbn); i ++ ) {
      if ( '0' <= isbn[i] && isbn[i] <= '9' ) {
        t = isbn[i] - '0';
        s += t * k;
        k ++;
      }
    }
    cd = s % 11;
    printf("ISBN => %s-%c\n", isbn, to_cd_char(cd));
    break;
  }
  return 0;
}

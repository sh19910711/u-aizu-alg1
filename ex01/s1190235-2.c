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

/* "4 0 8 8 7 3 1 0 4" => "4-08-873104" */
/* "4-08-873104" => "4-08-873104" */
void to_isbn_format(char* isbn) {
  char buf[256];
  char* p;
  char* t;
  int i;

  p = isbn;
  t = buf;
  i = 0;
  while ( *p != '\0' ) {
    if ( isdigit(*p) ) {
      if ( i == 1 || i == 3 ) {
        *t = '-';
        t ++;
      }
      *t = *p;
      t ++;
      i ++;
    }
    p ++;
  }
  *t = '\0';

  strcpy(isbn, buf);
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
    to_isbn_format(isbn);
    printf("ISBN => %s-%c\n", isbn, to_cd_char(cd));
    break;
  }
  return 0;
}

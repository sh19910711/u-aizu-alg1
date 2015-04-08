#include <stdio.h>
#include <string.h>

int input(char* s) {
  printf("Input ISBN:  ");
  if ( scanf("%s", s) != EOF ) {
    return 1;
  }
  return 0;
}

char to_cd_char(int cd) {
  return cd == 10 ? 'X' : ('0' + cd);
}

int main() {
  char isbn[256];
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

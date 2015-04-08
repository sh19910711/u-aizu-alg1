#include <stdio.h>
#include <string.h>

int main() {
  char buf[256];
  int s;
  int i;
  int k;
  int t;
  int res;

  while ( scanf("%s", buf) != EOF ) {
    printf("buf = %s\n", buf);
    s = 0;
    k = 1;
    for ( i = 0; i < strlen(buf); i ++ ) {
      if ( '0' <= buf[i] && buf[i] <= '9' ) {
        t = buf[i] - '0';
        printf("%d * %d + ", t, k);
        s += t * k;
        k ++;
      }
    }
    printf("s = %d\n", s);
    res = s % 11;
    printf("res = %d\n", s % 11);
  }
  return 0;
}

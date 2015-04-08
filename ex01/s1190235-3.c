#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NONE -1
#define N 3

int A[N*N];

/* random_digit() returns number of range 1-9 */
int random_digit() {
  return rand() % 10;
}

int check_table( int T[N][N] ) {
  int i;
  int j;
  int s;
  /* rows */
  for ( i = 0; i < N; i ++ ) {
    s = 0;
    for ( j = 0; j < N; j ++ ) {
      s += T[i][j];
    }
    if ( s * 2 != N * N * N + N ) {
      return 0;
    }
  }
  /* cols */
  for ( i = 0; i < N; i ++ ) {
    s = 0;
    for ( j = 0; j < N; j ++ ) {
      s += T[j][i];
    }
    if ( s * 2 != N * N * N + N ) {
      return 0;
    }
  }
  /* diags */
  for ( i = 0; i < N; i ++ ) {
    s = 0;
    s += T[i][i];
    if ( s * 2 != N * N * N + N ) {
      return 0;
    }
  }
  for ( i = 0; i < N; i ++ ) {
    s = 0;
    s += T[N - i - 1][N - i - 1];
    if ( s * 2 != N * N * N + N ) {
      return 0;
    }
  }
  return 1;
}

void print_table( int T[N][N] ) {
  int i;
  int j;
  for ( i = 0; i < N; i ++ ) {
    for ( j = 0; j < N; j ++ ) {
      printf("%4d", T[i][j]);
    }
    puts("");
  }
}

void init_table( int T[N][N] ) {
  int i;
  int j;
  for ( i = 0; i < N; i ++ ) {
    for ( j = 0; j < N; j ++ ) {
      T[i][j] = NONE;
    }
  }
}

void swap(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void shuffle_list() {
  int i;
  int s;
  int t;
  for ( i = 0; i < 2; i ++ ) {
    s = rand() % (N * N);
    t = rand() % (N * N);
    swap(&A[s], &A[t]);
  }
}

void generate_table_from_list( int T[N][N] ) {
  int i;
  int r;
  int c;
  i = 0;
  for ( r = 0; r < N; r ++ ) {
    for ( c = 0; c < N; c ++ ) {
      T[r][c] = A[i];
      i ++;
    }
  }
}

void init_list() {
  int i;
  for ( i = 0; i < N * N; i ++ ) {
    A[i] = i + 1;
  }
}

int main() {
  int T[N][N];
  init_list(); /* A = {1, 2, ...} */
  init_table(T);
  srand((unsigned)time(NULL));
  do {
    shuffle_list();
    generate_table_from_list(T);
  } while ( ! check_table(T) );
  print_table(T);
  return 0;
}

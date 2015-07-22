#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* new_array(int n) {
  return (int*)malloc(sizeof(int) * n);
}

int** new_table(int r, int c) {
  int** self;
  int i;
  
  self = (int**)malloc(sizeof(int*)*r);
  for (i=0;i<r;++i) {
    self[i] = new_array(c);
  }

  return self;
}

void free_table(int** t, int r) {
  int i;
  for (i=0;i<r;++i) {
    free(t[i]);
  }
  free(t);
}

void print_table(int** t, int r, int c) {
  int i;
  int j;
  for (i=0;i<r;++i) {
    for (j=0;j<c;++j) {
      printf("%3d ", t[i][j]);
    }
    puts("");
  }
  puts("");
}

int max(int a, int b) {
  return a > b ? a : b;
}

int lcs(char* sa, char* sb) {
  int** dp;
  int la;
  int lb;
  int r;
  int c;
  int i;
  int j;
  int res;

  la = strlen(sa);
  lb = strlen(sb);
  r = la + 1;
  c = lb + 1;

  dp = new_table(r, c);

  for (i=0;i<r;++i) {
    for(j=0;j<c;++j) {
      dp[i][j] = 0;
    }
  }

  for (i=1;i<r;++i) {
    for (j=1;j<c;++j) {
      if (sa[i-1] == sb[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  res = dp[r-1][c-1];
  free_table(dp, r);

  return res;
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
void trim(char* p) {
  while (*p) {
    if (*p == '\n') *p = '\0';
    p ++;
  }
}

int main() {
  char sa[1024];
  char sb[1024];
  fgets(sa, 1024, stdin);
  fgets(sb, 1024, stdin);
  trim(sa);
  trim(sb);
  printf("the length of LCS = %d\n", lcs(sa, sb));
  return 0;
}
#endif

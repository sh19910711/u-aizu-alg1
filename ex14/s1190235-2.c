#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long Int;

Int* new_array(int n) {
  return (Int*)malloc(sizeof(Int) * n);
}

Int** new_table(Int r, Int c) {
  Int** self;
  Int i;
  
  self = (Int**)malloc(sizeof(Int*)*r);
  for (i=0;i<r;++i) {
    self[i] = new_array(c);
  }

  return self;
}

void free_table(Int** t, Int r) {
  Int i;
  for (i=0;i<r;++i) {
    free(t[i]);
  }
  free(t);
}

void print_table(Int** t, Int r, Int c) {
  Int i;
  Int j;
  for (i=0;i<r;++i) {
    for (j=0;j<c;++j) {
      if (t[i][j] >= LONG_MAX / 10) {
        printf("   - ");
      } else {
        printf("%4lld ", t[i][j]);
      }
    }
    puts("");
  }
}

Int least_count(int n, Int* a) {
  Int** dp;
  Int i;
  Int j;
  Int k;
  Int c;
  Int inf;
  Int res;

  inf = LONG_MAX / 10;
  dp = new_table(n+1, n+1);

  for (i=0;i<n;++i) {
    for (j=0;j<n;++j) {
      dp[i][j] = inf;
    }
  }
  for (i=0;i<n;++i) {
    dp[i][i] = 0;
  }

  for (j=1;j<n;++j) {
    for (i=0;i+j<n;++i) {
      for(k=i;k<i+j;++k) {
        c = dp[i][k] + dp[k+1][i+j] + a[i]*a[k+1]*a[i+j+1];
        if (c < dp[i][i+j]) {
          dp[i][i+j] = c;
        }
      }
    }
  }

  res = dp[0][n-1];
  free_table(dp, n);
  return res;
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  int n;
  Int a[1024];
  int i;
  scanf("%d", &n);
  for (i=0; i<n; ++i) {
    scanf("%lld", a+i);
  }

  printf("the least cost = %lld\n");

  return 0;
}
#endif

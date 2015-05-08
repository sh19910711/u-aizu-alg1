#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 問題２
// また、main() 関数でそれらの関数を呼び出し、 以下の値を計算させて表示させなさい。
// 
//    10!
//    初項 1、等比 2 の等比数列の第 10 項までの等比級数
//    フィボナッチ数列の第 20 項目
//    x = 2 のときの 4 次多項式 f(x) = 1x4 + 2x3 + 3x2 + 4x + 5

// 階乗
int fact( int n ) {
  if ( n <= 1 ) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

// 2^n
int pow2(int n) {
  int res = 1;
  int i;
  for ( i = 0; i + 1 < n; ++ i ) {
    res *= 2;
  }
  return res;
}

// 等比級数
int geom( int n ) {
  if ( n == 1 ) {
    return 1;
  } else {
    return pow2(n) + geom(n - 1);
  }
}

// フィボナッチ数
int fib( int n ) {
  if ( n <= 2 ) {
    return 1;
  } else {
    return fib(n - 2) + fib(n - 1);
  }
}

// 4 次多項式 f(x) = 1x^4 + 2x^3 + 3x^2 + 4^x + 5
int func( int x, int n ) {
  if ( n == 1 ) {
    return n;
  } else {
    return n + x * func(x, n - 1);
  }
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  return 0;
}
#endif

#include <stdio.h>

/* 問題２ */
/* スタックを作るのには配列を用いる */ 
/* データはキーボードから入力 */
/* 文字処理するごとにスタックの内容を表示 */
/* 入力データ中の数字はすべて 1 桁の数として処理して良い */

#define SIZE (10000 + 11)

char stack[SIZE];
int stack_pointer;

int stack_empty() {
  return stack_pointer == 0;
}

void stack_init() {
  stack_pointer = 0;
}

void stack_push(char c) {
  stack[stack_pointer ++] = c;
}

char stack_pop() {
  return stack[-- stack_pointer];
}

void stack_print() {
  int i;
  for ( i = 0; i < stack_pointer; ++ i ) {
    printf("%d", stack[i]);
    if ( i + 1 < stack_pointer ) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
  printf("\n");
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  return 0;
}
#endif


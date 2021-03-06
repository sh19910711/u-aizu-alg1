#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

void stack_finalize() {
}

void stack_push(char c) {
  stack[stack_pointer ++] = c;
}

char stack_pop() {
  assert(stack_pointer > 0);
  return stack[-- stack_pointer];
}

void stack_print() {
  int i;
  for ( i = 0; i < stack_pointer; ++ i ) {
    printf("%d", stack[i]);
    if ( i + 1 < stack_pointer ) {
      printf(" ");
    }
  }
  printf("\n");
}

void eval_print() {
#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
  stack_print();
#endif
}

int to_int(char c) {
  assert(isdigit(c));
  return c - '0';
}

int eval(char* s) {
  int res;
  int i;
  int len;
  int a;
  int b;

  stack_init();
  len = strlen(s);

  for ( i = 0; i < len; ++ i ) {
    if ( isdigit(s[i]) ) {
      stack_push(to_int(s[i]));
    } else {
      a = stack_pop();
      b = stack_pop();
      if ( s[i] == '+' ) {
        stack_push(a + b);
      } else if ( s[i] == '-' ) {
        stack_push(a - b);
      } else if ( s[i] == '*' ) {
        stack_push(a * b);
      }
    }
    eval_print();
  }

  res = stack_pop();
  stack_finalize();
  return res;
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  char buf[1024];
  printf("Input data by Reverse Polish Notation: ");
  scanf("%s", buf);
  printf("Answer: %d\n", eval(buf));
  return 0;
}
#endif


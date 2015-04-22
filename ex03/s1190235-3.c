#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* 問題３ */
/* ただし、スタックを作るのにはリストを用いること。 */
/* 他の条件については、問題２と同じ */

int stack_empty() {
}

void stack_init() {
}

void stack_push(char c) {
}

char stack_pop() {
}

void stack_print() {
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
  int i;
  int len;
  int a;
  int b;

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
  return stack_pop();
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


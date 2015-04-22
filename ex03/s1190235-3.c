#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* 問題３ */
/* ただし、スタックを作るのにはリストを用いること。 */
/* 他の条件については、問題２と同じ */

typedef int NodeValue;
struct Node {
  NodeValue value;
  struct Node* next;
};

struct Node* head;
struct Node* tail;

struct Node* create_node() {
  return (struct Node*)malloc(sizeof(struct Node));
}

void push_front(NodeValue value) {
  struct Node* new_node = create_node();
  new_node->value = value;
  new_node->next = head->next;
  head->next = new_node;
}

NodeValue pop_front() {
  NodeValue res;
  struct Node* new_head_next;

  assert(head->next != tail);

  new_head_next = head->next->next;
  res = head->next->value;
  free(head->next);
  head->next = new_head_next;

  return res;
}

int stack_empty() {
  return head->next == tail;
}

void stack_init() {
  head = create_node();
  tail = create_node();
  head->next = tail;
  tail->next = tail;
}

void stack_finalize() {
  free(head);
  free(tail);
}

void stack_push(int x) {
  push_front(x);
}

char stack_pop() {
  return pop_front();
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


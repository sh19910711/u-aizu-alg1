/*
問題３
http://web-int.u-aizu.ac.jp/course/alg1/ex/jp/ex06/

後置記法から解析木を作成するプログラムを書きなさい。 必要であれば、演習第３回 で使用した関数などを 用いても良い。

実行例：
% ./a.out
Input data by Reverse Polish Notation: 123*+
preorder:  + 1 * 2 3 
inorder:   1 + 2 * 3 
postorder: 1 2 3 * + 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE (100000 + 11)

struct node {
  struct node* left;
  struct node* right;
  char key;
};
typedef struct node Node;
typedef Node* NodePointer;

NodePointer stack_data[SIZE];
int stack_num;

void stack_init() {
  stack_num = 0;
}

void stack_push(NodePointer c) {
  stack_data[stack_num ++] = c;
}

NodePointer stack_pop() {
  return stack_data[-- stack_num];
}

int stack_empty() {
  return stack_num == 0;
}

NodePointer new_node(char c) {
  NodePointer res;
  res = (NodePointer)malloc((int)sizeof(Node));
  res->key = c;
  res->left = NULL;
  res->right = NULL;
  return res;
}

void tree_free(NodePointer p) {
  if ( p->left ) {
    tree_free(p->left);
  }
  if ( p->right ) {
    tree_free(p->right);
  }
  free(p);
}

NodePointer tree_by_revpol(char* s) {
  NodePointer cur;
  char* p;
  p = s;
  stack_init();
  while ( *p ) {
    if ( isdigit(*p) ) {
      stack_push(new_node(*p));
    } else {
      cur = new_node(*p);
      cur->right = stack_pop();
      cur->left = stack_pop();
      stack_push(cur);
    }
    p ++;
  }
  return cur;
}

void preorder(NodePointer cur, char* s, int* ns) {
  s[*ns] = cur->key;
  (*ns) ++;
  if ( cur->left ) {
    preorder(cur->left, s, ns);
  }
  if ( cur->right ) {
    preorder(cur->right, s, ns);
  }
}

void inorder(NodePointer cur, char* s, int* ns) {
  if ( cur->left ) {
    inorder(cur->left, s, ns);
  }
  s[*ns] = cur->key;
  (*ns) ++;
  if ( cur->right ) {
    inorder(cur->right, s, ns);
  }
}

void postorder(NodePointer cur, char* s, int* ns) {
  if ( cur->left ) {
    postorder(cur->left, s, ns);
  }
  if ( cur->right ) {
    postorder(cur->right, s, ns);
  }
  s[*ns] = cur->key;
  (*ns) ++;
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  return 0;
}
#endif


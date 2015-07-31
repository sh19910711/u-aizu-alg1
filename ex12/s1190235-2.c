// Problem 2
// http://web-ext.u-aizu.ac.jp/course/alg1/ex/uk/ex12/
//
// Write a program which hashes by using separate chaining method and uses the following function. Input data from keyboard, a hash table is displayed finally. The length of the hash table M is 5.
//
// int hash(char c){
//   return (int)(c-64)%M;
// }
//
// Example:
// % ./a.out
// Input data: CHOCOLATE
//  0: E T O O 
//  1: A 
//  2: L 
//  3: C H C 
//  4: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char value;
  struct node* next;
} Node;

int hash(char c, int mod) {
  return (int)(c - 64) % mod;
}

Node* new_node(char c, Node* next) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = c;
  node->next = next;
  return node;
}

Node** new_heads(int size) {
  int i;
  Node** heads;
  
  heads = (Node**)malloc(size * sizeof(Node*));
  for ( i = 0; i < size; ++ i ) {
    heads[i] = new_node('-', NULL);
  }

  return heads;
}

int get_length(Node* head) {
  int len = 0;
  Node* p = head;
  while ( p->next ) {
    len ++;
    p = p->next;
  }
  return len;
}

void append_child(Node* head, char c) {
  Node* child = (Node*)malloc(sizeof(Node));
  child->value = c;
  child->next = head->next;
  head->next = child;
}

Node** bunnsa_rennketsu(char* s, int mod) {
  Node** heads;
  int len;
  int i;
  int h;

  len = strlen(s);
  heads = new_heads(mod);

  for ( i = 0; i < len; ++ i ) {
    h = hash(s[i], mod);
    append_child(heads[h], s[i]);
  }

  return heads;
}

void free_head(Node* head) {
  Node* p = head;
  while ( p->next ) {
    free(p);
    p = p->next;
  }
}

void free_heads(Node** heads, int mod) {
  int i;
  for ( i = 0; i < mod; ++ i ) {
    free_head(heads[i]);
  }
  free(heads);
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  char input[1024];
  int mod;
  int i;
  Node* p;

  mod = 5;

  printf("Input data: ");
  scanf("%s", input);

  Node** heads = bunnsa_rennketsu(input, mod);

  for ( i = 0; i < mod; ++ i ) {
    printf("%2d: ", i);
    p = heads[i];
    while ( p->next ) {
      printf("%c ", p->next->value);
      p = p->next;
    }
    printf("\n");
  }

  free_heads(heads, mod);
}
#endif

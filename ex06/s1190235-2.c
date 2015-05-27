/*
問題２
http://web-int.u-aizu.ac.jp/course/alg1/ex/jp/ex06/

ノードの中身を表示しながらトラバースする関数

void preorder(NodePointer node);
void inorder(NodePointer node);
void postorder(NodePointer node);

を再帰を使って書きなさい。ファイルは ex06-2-skel.c を使用すること。

実行例：
% ./a.out
preorder:  + 1 * 2 3 
inorder:   1 + 2 * 3 
postorder: 1 2 3 * + 
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *right;
  char key;
  struct node *left;
};
typedef struct node * NodePointer;

void treeinitialize(void);
NodePointer makenode(char c);
void preorder(NodePointer node);
void inorder(NodePointer node);
void postorder(NodePointer node);

NodePointer head, tail;

int main(){
  treeinitialize();

  /* テスト用の木を作成 */
  head->right=makenode('+');
  head->right->left=makenode('1');
  head->right->right=makenode('*');
  head->right->right->left=makenode('2');
  head->right->right->right=makenode('3');


  /* トラバース */
  printf("preorder:  ");
  preorder(head->right);
  printf("\n");

  printf("inorder:   ");
  inorder(head->right);
  printf("\n");

  printf("postorder: ");
  postorder(head->right);
  printf("\n");

  return 0;
}

void treeinitialize(void){
  head=makenode(-1);
  tail=makenode(-1);
  head->right=tail;
  head->left=tail;
}

/*
 * ノードを作成し、そのノードへのポインタを返す。
 */
NodePointer makenode(char c){
  NodePointer x;

  x=malloc(sizeof(struct node));
  x->key=c;
  x->right=tail;
  x->left=tail;

  return x;
}

void preorder(NodePointer node){
  if (node == head) {
    return preorder(node->right);
  }
  if (node == tail) {
    return;
  }
  printf("%c", node->key);
  if ( node->left ) {
    preorder(node->left);
  }
  if ( node->right ) {
    preorder(node->right);
  }
}

void inorder(NodePointer node){
  if (node == head) {
    return inorder(node->right);
  }
  if (node == tail) {
    return;
  }
  if ( node->left ) {
    inorder(node->left);
  }
  printf("%c", node->key);
  if ( node->right ) {
    inorder(node->right);
  }
}

void postorder(NodePointer node){
  if (node == head) {
    return postorder(node->right);
  }
  if (node == tail) {
    return;
  }
  if ( node->left ) {
    postorder(node->left);
  }
  if ( node->right ) {
    postorder(node->right);
  }
  printf("%c", node->key);
}

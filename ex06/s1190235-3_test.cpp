#include <gtest/gtest.h>
#include <string.h>

namespace {

#include "./s1190235-3.c"

  TEST(Node, NewNode) {
    NodePointer ret = new_node('c');
    ASSERT_EQ(ret->key, 'c');
    free(ret);
  }

  TEST(Tree, ByRevPol) {
    char* in = "123*+";
    NodePointer root = tree_by_revpol(in);
    ASSERT_EQ(root->key, '+');
    ASSERT_EQ(root->left->key, '1');
    ASSERT_EQ(root->right->key, '*');
    ASSERT_EQ(root->right->left->key, '2');
    ASSERT_EQ(root->right->right->key, '3');
    tree_free(root);
  }

  TEST(Tree, PreOrder) {
    char* in = "123*+";
    NodePointer root = tree_by_revpol(in);
    char s[1024];
    int ns = 0;
    preorder(root, s, &ns);
    char* expect = "+1*23";
    for ( int i = 0; i < 5; ++ i ) {
      ASSERT_EQ(s[i], expect[i]);
    }
    tree_free(root);
  }

  TEST(Tree, InOrder) {
    char* in = "123*+";
    NodePointer root = tree_by_revpol(in);
    char s[1024];
    int ns = 0;
    inorder(root, s, &ns);
    char* expect = "1+2*3";
    for ( int i = 0; i < 5; ++ i ) {
      ASSERT_EQ(s[i], expect[i]);
    }
    tree_free(root);
  }

  TEST(Tree, PostOrder) {
    char* in = "123*+";
    NodePointer root = tree_by_revpol(in);
    char s[1024];
    int ns = 0;
    postorder(root, s, &ns);
    char* expect = "123*+";
    for ( int i = 0; i < 5; ++ i ) {
      ASSERT_EQ(s[i], expect[i]);
    }
    tree_free(root);
  }

  TEST(Stack, PushAndPop) {
    stack_init();
    NodePointer tmp[3];
    tmp[0] = new_node('1');
    tmp[1] = new_node('+');
    tmp[2] = new_node('2');
    for ( int i = 0; i < 3; ++ i ) {
      stack_push(tmp[i]);;
    }
    ASSERT_EQ(stack_pop()->key, '2');
    ASSERT_EQ(stack_pop()->key, '+');
    ASSERT_EQ(stack_pop()->key, '1');
    for ( int i = 0; i < 3; ++ i ) {
      free(tmp[i]);
    }
  }

  TEST(Stack, CheckEmpty) {
    stack_init();
    ASSERT_EQ(stack_empty(), 1);
    NodePointer p = new_node('1');
    stack_push(p);
    ASSERT_EQ(stack_empty(), 0);
    free(p);
  }

}

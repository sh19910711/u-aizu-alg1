#include <gtest/gtest.h>

namespace {

#include "./s1190235-1.c"

  void dummy_print(int* a, int n) {
    // dummy
    for ( int i = 0; i < n; ++ i ) {
      // printf("%d, ", a[i]);
    }
    // printf("\n");
  }

  TEST(Bubble, Reversed) {
    int n = 5;
    int a[] = {5, 4, 3, 2, 1};
    bubble(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

  TEST(Bubble, Sorted) {
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    bubble(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

  TEST(Bubble, Random) {
    int n = 5;
    int a[] = {5, 3, 2, 1, 4};
    bubble(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

  TEST(Insertion, Reversed) {
    int n = 5;
    int a[] = {5, 4, 3, 2, 1};
    insertion(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

  TEST(Insertion, Sorted) {
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    insertion(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

  TEST(Insertion, Random) {
    int n = 5;
    int a[] = {5, 3, 2, 1, 4};
    insertion(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

  TEST(Selection, Reversed) {
    int n = 5;
    int a[] = {5, 4, 3, 2, 1};
    selection(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

  TEST(Selection, Sorted) {
    int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    selection(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

  TEST(Selection, Random) {
    int n = 5;
    int a[] = {5, 3, 2, 1, 4};
    selection(a, n, dummy_print);
    int expected[] = {1, 2, 3, 4, 5};
    for ( int i = 0; i < n; ++ i ) {
      ASSERT_EQ(a[i], expected[i]);
    }
  }

}

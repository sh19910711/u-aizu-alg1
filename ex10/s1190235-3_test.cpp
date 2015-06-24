#include <gtest/gtest.h>

namespace {

#include "./s1190235-3.c"

  TEST(Sort, Data1) {
    const int n = 5;
    int a[] = {5, 4, 3, 2, 1};
    int exp[] = {1, 2, 3, 4, 5};
    sort1(a, n, 0, n - 1);
    int i = 0;
    for ( i = 0; i < 5; ++ i ) {
      ASSERT_EQ(a[i], exp[i]);
    }
  }

  TEST(BinarySearch, Found) {
    const int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(binary_search(a, n, 1), FOUND);
    ASSERT_EQ(binary_search(a, n, 2), FOUND);
    ASSERT_EQ(binary_search(a, n, 3), FOUND);
    ASSERT_EQ(binary_search(a, n, 4), FOUND);
    ASSERT_EQ(binary_search(a, n, 5), FOUND);
  }

  TEST(BinarySearch, NotFound) {
    const int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(binary_search(a, n, 0), NOT_FOUND);
    ASSERT_EQ(binary_search(a, n, 6), NOT_FOUND);
    ASSERT_EQ(binary_search(a, n, -1), NOT_FOUND);
  }

  TEST(BinarySearch, ExampleInput) {
    const int n = 10;
    int a[n]={ 1, 4, 6, 9, 10, 13, 19, 23, 25, 30 };
    ASSERT_EQ(binary_search(a, n, 9), FOUND);
    ASSERT_EQ(binary_search(a, n, 8), NOT_FOUND);
  }

  TEST(InterpolationSearch, Found) {
    const int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(interpolation_search(a, n, 1), FOUND);
    ASSERT_EQ(interpolation_search(a, n, 2), FOUND);
    ASSERT_EQ(interpolation_search(a, n, 3), FOUND);
    ASSERT_EQ(interpolation_search(a, n, 4), FOUND);
    ASSERT_EQ(interpolation_search(a, n, 5), FOUND);
  }

  TEST(InterpolationSearch, NotFound) {
    const int n = 5;
    int a[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(interpolation_search(a, n, 0), NOT_FOUND);
    ASSERT_EQ(interpolation_search(a, n, 6), NOT_FOUND);
    ASSERT_EQ(interpolation_search(a, n, -1), NOT_FOUND);
  }

  TEST(InterpolationSearch, ExampleInput) {
    const int n = 10;
    int a[n]={ 1, 4, 6, 9, 10, 13, 19, 23, 25, 30 };
    ASSERT_EQ(interpolation_search(a, n, 9), FOUND);
    ASSERT_EQ(interpolation_search(a, n, 8), NOT_FOUND);
  }

}

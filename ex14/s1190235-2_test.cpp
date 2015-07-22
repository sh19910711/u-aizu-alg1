#include <gtest/gtest.h>

namespace {

#include "./s1190235-2.c"

  TEST(LeastCount, ExampleInput) {
    int n = 4;
    long long a[5] = {5, 2, 6, 4, 3};
    ASSERT_EQ(least_count(n, a), 102);
  }

  TEST(LeastCount, Input1) {
    int n = 4;
    long long a[5] = {5, 10, 3, 12, 5};
    ASSERT_EQ(least_count(n, a), 405);
  }

}

#include <gtest/gtest.h>

namespace {

#include "./s1190235-2.c"

  TEST(FactTest, ResultOfOne) {
    ASSERT_EQ(1, fact(1));
  }

  TEST(FactTest, ResultOfThree) {
    ASSERT_EQ(6, fact(3));
  }

  TEST(FactTest, ResultOfFour) {
    ASSERT_EQ(24, fact(4));
  }

  TEST(FactTest, Example) {
    ASSERT_EQ(3628800, fact(10));
  }

  TEST(GeomTest, ResultOfOne) {
    ASSERT_EQ(1, geom(1));
  }

  TEST(GeomTest, Example) {
    ASSERT_EQ(1023, geom(10));
  }

  TEST(FibTest, Example) {
    ASSERT_EQ(6765, fib(20));
  }

  TEST(FuncTest, Example) {
    ASSERT_EQ(57, func(2, 5));
  }

}

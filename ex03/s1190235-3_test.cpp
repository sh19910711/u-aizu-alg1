#include <gtest/gtest.h>

namespace {

#include "./s1190235-3.c"

  TEST(ProblemThree, PushAndPop) {
    stack_init();
    stack_push(1);
    stack_push(2);
    stack_push(3);
    ASSERT_EQ(stack_pop(), 3);
    ASSERT_EQ(stack_pop(), 2);
    ASSERT_EQ(stack_pop(), 1);
    stack_finalize();
  }

  TEST(ProblemThree, OnePlusTwo) {
    ASSERT_EQ(eval("12+"), 3);
  }

  TEST(ProblemThree, OneTimesTwo) {
    ASSERT_EQ(eval("12*"), 2);
  }

  TEST(ProblemThree, ExampleInput) {
    ASSERT_EQ(eval("12+34+*"), 21);
  }

}

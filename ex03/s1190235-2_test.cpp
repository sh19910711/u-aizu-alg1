#include <gtest/gtest.h>

namespace {

#include "./s1190235-2.c"

TEST(StackTest, PushAndPop) {
  stack_init();
  stack_push('1');
  stack_push('2');
  stack_push('+');
  ASSERT_EQ(stack_pop(), '+');
  ASSERT_EQ(stack_pop(), '2');
  ASSERT_EQ(stack_pop(), '1');
}

TEST(EvalTest, OnePlusTwo) {
  ASSERT_EQ(eval("12+"), 3);
}

TEST(EvalTest, OneTimesTwo) {
  ASSERT_EQ(eval("12*"), 2);
}

TEST(EvalTest, ExampleInput) {
  ASSERT_EQ(eval("12+34+*"), 21);
}

}


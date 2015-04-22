#include <gtest/gtest.h>
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

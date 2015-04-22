#include <gtest/gtest.h>
#include "./s1190235-0.c"

TEST(HelloTest, CallFunction) {
  EXPECT_STREQ("hello, world", get_hello());
}

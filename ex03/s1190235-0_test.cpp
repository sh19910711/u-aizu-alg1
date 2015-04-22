#include <gtest/gtest.h>

namespace {

#include "./s1190235-0.c"

  TEST(HelloTest, CallFunction) {
    ASSERT_STREQ("hello, world", get_hello());
  }

}

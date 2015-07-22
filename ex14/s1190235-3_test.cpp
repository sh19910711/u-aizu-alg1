#include <gtest/gtest.h>

namespace {

#include "./s1190235-3.c"

  TEST(LCS, ExampleInput) {
    char* a = "abcbdab";
    char* b = "bdcaba";
    ASSERT_EQ(lcs(a, b), 4);
  }

  TEST(LCS, Input1) {
    char* a = "10010101";
    char* b = "010110110";
    ASSERT_EQ(lcs(a, b), 6);
  }

}

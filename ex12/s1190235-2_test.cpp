#include <gtest/gtest.h>

namespace {

#include "./s1190235-2.c"

  TEST(Hash, Example) {
    ASSERT_EQ(hash('C', 5), 3);
    ASSERT_EQ(hash('H', 5), 3);
    ASSERT_EQ(hash('O', 5), 0);
    ASSERT_EQ(hash('L', 5), 2);
    ASSERT_EQ(hash('A', 5), 1);
  }

  TEST(BunnsaRennketsu, CheckLength) {
    int mod = 5;
    Node** heads = bunnsa_rennketsu("CHOCOLATE", mod);
    ASSERT_EQ(get_length(heads[0]), 4);
    ASSERT_EQ(get_length(heads[1]), 1);
    ASSERT_EQ(get_length(heads[2]), 1);
    ASSERT_EQ(get_length(heads[3]), 3);
    ASSERT_EQ(get_length(heads[4]), 0);
    free_heads(heads, mod);
  }

  TEST(BunnsaRennketsu, CheckFirstChar) {
    int mod = 5;
    Node** heads = bunnsa_rennketsu("CHOCOLATE", mod);
    ASSERT_EQ(heads[0]->next->value, 'E');
    ASSERT_EQ(heads[1]->next->value, 'A');
    ASSERT_EQ(heads[2]->next->value, 'L');
    ASSERT_EQ(heads[3]->next->value, 'C');
    free_heads(heads, mod);
  }

}

#include <gtest/gtest.h>

namespace {

#include "./s1190235-3.c"

  TEST(InputGraph, ExampleInput) {
    FILE* fp = fopen("s1190235-3_input.txt", "r");
    AdjacentList* adj_list = input_adj_list(fp);
    fclose(fp);

    ASSERT_EQ(adj_list->num_vertices, 4);
    ASSERT_EQ(adj_list->num_edges[0], 2);
    ASSERT_EQ(adj_list->edges[0][0], 2);
    ASSERT_EQ(adj_list->edges[0][1], 3);
    ASSERT_EQ(adj_list->num_edges[1], 0);
    ASSERT_EQ(adj_list->num_edges[2], 2);;
    ASSERT_EQ(adj_list->edges[2][0], 1);
    ASSERT_EQ(adj_list->edges[2][1], 3);
    ASSERT_EQ(adj_list->num_edges[3], 1);
    ASSERT_EQ(adj_list->edges[3][0], 1);

    free_adj_list(adj_list);
  }

  TEST(Dfs, ExampleInput) {
    FILE* fp = fopen("s1190235-3_input.txt", "r");
    AdjacentList* adj_list = input_adj_list(fp);
    fclose(fp);

    int t = 1;
    int* d = new_array_with_value(adj_list->num_vertices, 0);
    int* f = new_array_with_value(adj_list->num_vertices, 0);

    dfs(0, &t, adj_list, d, f);

    ASSERT_EQ(d[0], 1);
    ASSERT_EQ(d[1], 3);
    ASSERT_EQ(d[2], 2);
    ASSERT_EQ(d[3], 5);

    free_adj_list(adj_list);
  }

}

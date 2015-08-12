#include <gtest/gtest.h>

namespace {

#include "./s1190235-2.c"

  TEST(InputGraph, ExampleInput) {
    FILE* fp = fopen("s1190235-2_input.txt", "r");
    AdjacentList* adj_list = input_adj_list(fp);
    fclose(fp);

    ASSERT_EQ(adj_list->num_vertices, 4);
    ASSERT_EQ(adj_list->num_edges[0], 2);
    ASSERT_EQ(adj_list->edges[0][0], 3);
    ASSERT_EQ(adj_list->edges[0][1], 2);
    ASSERT_EQ(adj_list->num_edges[1], 0);
    ASSERT_EQ(adj_list->num_edges[2], 2);;
    ASSERT_EQ(adj_list->edges[2][0], 3);
    ASSERT_EQ(adj_list->edges[2][1], 1);
    ASSERT_EQ(adj_list->num_edges[3], 1);
    ASSERT_EQ(adj_list->edges[3][0], 1);

    free_adj_list(adj_list);
  }

  TEST(ConvertGraph, ExampleInput) {
    FILE* fp = fopen("s1190235-2_input.txt", "r");
    AdjacentList* adj_list = input_adj_list(fp);
    fclose(fp);

    AdjacentMatrix* adj_mat = convert_from_adj_list(adj_list);

    int expected[4][4] = {
      { 0, 0, 1, 1 },
      { 0, 0, 0, 0 },
      { 0, 1, 0, 1 },
      { 0, 1, 0, 0 },
    };

    ASSERT_EQ(adj_mat->num_vertices, 4);
    for (int i = 0; i < 4; ++ i) {
      for (int j = 0; j < 4; ++ j) {
        ASSERT_EQ(adj_mat->matrix[i][j], expected[i][j]);
      }
    }

    free_adj_list(adj_list);
    free_adj_matrix(adj_mat);
  }


}

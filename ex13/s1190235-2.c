// 問題２
// 有向グラフの隣接リスト法による表現が与えられたとき、
// その隣接行列法による表現を出力するプログラムを作成しなさい。
//  プログラムは以下の条件を満たすこと。 (ex13-2-skel.c)
//
// 入力として与えられた有向グラフの情報を読み、隣接リスト法によるデータ構造を作る。
// 有向グラフの情報は隣接リスト法の表現に沿って与えられる。
// グラフのノード数を n としたとき、各ノードには1からnまでの番号がふられている。
// ノードの最大数は100とする
// プログラムが作った隣接リスト法によるデータ構造から、隣接行列法によるデータ構造を作る。
// 作成した隣接行列の内容を出力する。
// 注： 隣接リスト法に沿った表現が入力として与えられたとき、 
// 実際には隣接リスト法によるデータ構造を作らずに、 
// 隣接行列法によるデータ構造を直接作ることは可能です。 
// この問題では、隣接リスト法と隣接行列によるデータ構造の作り方を学ぶために、 
// いったん隣接リスト法によるデータ構造を作ってから 隣接行列法によるデータ構造を作っています。

#include <stdio.h>
#include <stdlib.h>

typedef struct adjacent_list_graph {
  int num_verticles;
  int** edges;
  int* num_edges;
} AdjacentList;

typedef struct adjacent_matrix_graph {
  int num_verticles;
  int** matrix;
} AdjacentMatrix;

int* new_array(int size) {
  return (int*)malloc(sizeof(int)*size);
}

int* new_array_with_value(int size, int value) {
  int i;
  int* self;

  self = (int*)malloc(sizeof(int)*size);
  for (i=0; i<size; ++i) {
    self[i] = value;
  }

  return self;
}

int** new_table(int rows, int cols, int value) {
  int r;
  int** table;

  table = (int**)malloc(sizeof(int*)*rows);
  for (r = 0; r < rows; ++r) {
    table[r] = new_array_with_value(cols, value);
  }

  return table;
}

int** new_list(int size) {
  int i;
  int** self;

  self = (int**)malloc(sizeof(int*)*size);
  for (i = 0; i < size; ++i) {
    self[i] = NULL;
  }

  return self;
}

AdjacentMatrix* new_adj_matrix(int num_verticles) {
  AdjacentMatrix* self = (AdjacentMatrix*)malloc(sizeof(AdjacentMatrix));

  self->num_verticles = num_verticles;
  self->matrix = new_table(num_verticles, num_verticles, 0);

  return self;
}

AdjacentList* new_adj_list(int num_verticles) {
  AdjacentList* self = (AdjacentList*)malloc(sizeof(AdjacentList));

  self->num_verticles = num_verticles;
  self->edges = new_list(self->num_verticles);
  self->num_edges = new_array(self->num_verticles);

  return self;
}

void free_table(int** table, int rows) {
  int i;
  for (i=0; i<rows; ++i) {
    free(table[i]);
  }
  free(table);
}

void free_adj_matrix(AdjacentMatrix* adj_mat) {
  free_table(adj_mat->matrix, adj_mat->num_verticles);
  free(adj_mat);
}

void free_adj_list(AdjacentList* adj_list) {
  int i;

  if (! adj_list) {
    return;
  }

  for (i=0; i<adj_list->num_verticles; ++i) {
    if (adj_list->edges[i]) {
      free(adj_list->edges[i]);
    }
  }

  free(adj_list->num_edges);
  free(adj_list);
}

AdjacentList* input_adj_list(FILE* fp) {
  AdjacentList* adj_list;
  int num_verticles;
  int i;
  int j;
  int num_edges;
  int tmp;

  if (fscanf(fp, "%d", &num_verticles)) {
    adj_list = new_adj_list(num_verticles);

    for (i = 0; i < adj_list->num_verticles; ++ i) {
      if (fscanf(fp, "%d", adj_list->num_edges + i)) {
        adj_list->edges[i] = new_array(adj_list->num_edges[i]);
        for (j = 0; j < adj_list->num_edges[i]; ++j) {
          if (!fscanf(fp, "%d", &tmp)) {
            abort();
          }
          adj_list->edges[i][j] = tmp - 1;
        }
        continue;
      }

      abort();
    }

    return adj_list;
  }

  abort();
}

AdjacentMatrix* convert_from_adj_list(AdjacentList* adj_list) {
  AdjacentMatrix* adj_mat;
  int i;
  int j;
  int dest;
  
  adj_mat = new_adj_matrix(adj_list->num_verticles);
  for (i=0; i<adj_list->num_verticles; ++i) {
    for (j=0; j<adj_list->num_edges[i]; ++j) {
      dest = adj_list->edges[i][j];
      adj_mat->matrix[i][dest] = 1;
    }
  }

  return adj_mat;
}

void print_adj_matrix(AdjacentMatrix* adj_mat) {
  int i;
  int j;

  printf("matrix\n");
  for (i=0; i<adj_mat->num_verticles; ++i) {
    for (j=0; j<adj_mat->num_verticles; ++j) {
      printf("%d ", adj_mat->matrix[i][j]);
    }
    printf("\n");
  }
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  AdjacentList* adj_list = input_adj_list(stdin);
  AdjacentMatrix* adj_mat = convert_from_adj_list(adj_list);
  print_adj_matrix(adj_mat);
  free_adj_list(adj_list);
  free_adj_matrix(adj_mat);
  return 0;
}
#endif

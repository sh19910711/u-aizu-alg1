// 問題３
// 与えられた有向グラフに対して深さ優先探索を行うプログラムを作成しなさい。 プログラムは以下の条件を満たすこと。 (ex13-3-skel.c)
//
// 入力として与えられた有向グラフの情報を読み、隣接リストのデータ構造を作る。
// 有向グラフの情報は隣接リスト法の表現に沿って与えられる。 グラフのノード数を n としたとき、各ノードには1からnまでの番号がふられている。
// ノードの最大数は100とする
// プログラムは各ノードの発見時刻と終了時刻を報告する。 ただし、最初に訪問するノードの開始時刻を1とする。
// 問題１の例で示したグラフに対する実行例を示します(緑がプログラムへの入力、 赤がプログラムの出力)
//     % ./a.out
//     4
//     2 4 3
//     0
//     2 4 2
//     1 2
//     timestamps
//     1: 1 8
//     2: 3 4
//     3: 2 7
//     4: 5 6

#include <stdio.h>
#include <stdlib.h>

typedef struct adjacent_list_graph {
  int num_vertices;
  int** edges;
  int* num_edges;
} AdjacentList;

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

AdjacentList* new_adj_list(int num_vertices) {
  AdjacentList* self = (AdjacentList*)malloc(sizeof(AdjacentList));

  self->num_vertices = num_vertices;
  self->edges = new_list(self->num_vertices);
  self->num_edges = new_array(self->num_vertices);

  return self;
}

void free_table(int** table, int rows) {
  int i;
  for (i=0; i<rows; ++i) {
    free(table[i]);
  }
  free(table);
}

void free_adj_list(AdjacentList* adj_list) {
  int i;

  if (! adj_list) {
    return;
  }

  for (i=0; i<adj_list->num_vertices; ++i) {
    if (adj_list->edges[i]) {
      free(adj_list->edges[i]);
    }
  }

  free(adj_list->num_edges);
  free(adj_list);
}

void swap(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}

void sort1(int* a, int n) {
  int i;
  int j;

  for (i = 0; i < n; ++ i) {
    for (j = i; j < n; ++ j) {
      if (a[i] > a[j]) {
        swap(a + i, a + j);
      }
    }
  }
}

AdjacentList* input_adj_list(FILE* fp) {
  AdjacentList* adj_list;
  int num_vertices;
  int i;
  int j;
  int num_edges;
  int tmp;

  if (fscanf(fp, "%d", &num_vertices)) {
    adj_list = new_adj_list(num_vertices);

    for (i = 0; i < adj_list->num_vertices; ++ i) {
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

    for (i = 0; i < adj_list->num_vertices; ++ i) {
      sort1(adj_list->edges[i], adj_list->num_edges[i]);
    }

    return adj_list;
  }

  abort();
}

void inc(int* x) {
  (*x) += 1;
}

void dfs(int cur, int* t, AdjacentList* adj_list, int* d, int* f) {
  int i;
  int dest;

  d[cur] = *t;

  for (i = 0; i < adj_list->num_edges[cur]; ++ i) {
    int dest = adj_list->edges[cur][i];
    if (d[dest]) continue;
    inc(t);
    dfs(dest, t, adj_list, d, f);
  }

  inc(t);
  f[cur] = *t;
}

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main() {
  AdjacentList* adj_list;
  int* d;
  int* f;
  int t;
  
  t = 1;
  adj_list = input_adj_list(stdin);
  d = new_array_with_value(adj_list->num_vertices, 0);
  f = new_array_with_value(adj_list->num_vertices, 0);

  dfs(0, &t, adj_list, d, f);

  free_adj_list(adj_list);
  return 0;
}
#endif

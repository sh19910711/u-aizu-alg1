#!/bin/sh

# 問題２の 4 の結果をグラフ作成ツール（xmgrace）で読み込める形式で出力しなさい。
# 形式は次の通りである。 
for x in `seq 500 500 10000`; do
  printf "$x "
  echo $x | ~/docs/gethrtime | awk -F' ' '{print $3}'
done

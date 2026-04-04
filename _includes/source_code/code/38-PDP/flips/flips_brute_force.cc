#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  long N, K, Q;
  scanf("%ld%ld%ld", &N, &K, &Q);
  
  std::vector<std::vector<bool>> arr(N + 1, std::vector<bool>(N + 1, false));
  for (long i = 0; i < K; ++i) {
    long x, y;
    scanf("%ld%ld", &x, &y);
    arr[x][y] = 1;
  }
  
  int total_solutions = 0;
  for (int mask1 = 0; mask1 < (1 << N); ++mask1) {
    for (int mask2 = 0; mask2 < (1 << N); ++mask2) {
      auto tmp = arr;
      for (int r = 1; r <= N; ++r) {
        if (!(mask1 & (1 << (r-1)))) continue;
        for (int c = 1; c <= N; ++c) tmp[r][c] = !tmp[r][c];
      }
      for (int c = 1; c <= N; ++c) {
        if (!(mask2 & (1 << (c-1)))) continue;
        for (int r = 1; r <= N; ++r) tmp[r][c] = !tmp[r][c];
      }
      int cnt = 0;
      for (int r = 1; r <= N; ++r)
        for (int c = 1; c <= N; ++c)
          cnt += tmp[r][c];
      if (cnt == 0) ++total_solutions;
    }
  }
  printf("%ld\n", total_solutions);
  return 0;
}


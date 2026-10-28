#include <cstdio>
#include <set>
#include <unordered_map>
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
  
  std::vector<std::pair<long, long>> pts;
  std::vector<long> row_count(N+1, 0);
  for (long i = 0; i < Q; ++i) {
    long a, b, c, d;
    scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
    pts.push_back({a, c});
    ++row_count[a];
  }
  // Διαλέγουμε την γραμμή που γίνονται τα λιγότερα 
  // updates ως γραμμή αναφοράς.
  long mn_row = 1;
  for (long i = 1; i <= N; ++i) {
    if (row_count[i] < row_count[mn_row]) 
      mn_row = i;
  }
  
  std::vector<long> diff(N + 1, 0);
  long total_valid_rows = 0;
  for (long r = 1; r <= N; ++r) {
    for (long c = 1; c <= N; ++c) {
      diff[r] += (arr[r][c] == arr[mn_row][c]);
    }
    total_valid_rows += (diff[r] == 0 || diff[r] == N);
  }
  if (total_valid_rows == N) printf("2\n");
  else printf("0\n");
  
  auto update_cell = [&](long r, long c) {
    if (diff[r] == 0 || diff[r] == N) --total_valid_rows;
    if (arr[r][c] == arr[mn_row][c]) --diff[r];
    else ++diff[r];
    total_valid_rows += (diff[r] == 0 || diff[r] == N);
  };
  for (auto [x, y] : pts) {
    if (mn_row != x) {
      update_cell(x, y);
      arr[x][y] = !arr[x][y];
    } else {
      arr[x][y] = !arr[x][y];
      for (long r = 1; r <= N; ++r) {
        if (r == mn_row) continue;
        update_cell(r, y);
      }
    }
    if (total_valid_rows == N) printf("2\n");
    else printf("0\n");
  }
  
  return 0;
}


#include <algorithm>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>

int main() {
  long N, K, Q;
  scanf("%ld%ld%ld", &N, &K, &Q);
  
  std::unordered_map<long, std::unordered_set<long>> ones;
  
  auto toggle = [&](long r, long c) {
    if (ones[r].find(c) == ones[r].end()) ones[r].insert(c);
    else ones[r].erase(c);
  };
  
  std::unordered_map<long, long> row_count;
  for (long i = 0; i < K; ++i) {
    long x, y;
    scanf("%ld%ld", &x, &y);
    toggle(x, y);
    ++row_count[x];
  }
  
  std::vector<std::pair<long, long>> pts;
  for (long i = 0; i < Q; ++i) {
    long a, b, c, d;
    scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
    pts.push_back({a, c});
    ++row_count[a];
    ones[a];
  }
  // Διαλέγουμε την γραμμή που γίνονται τα λιγότερα 
  // updates ως γραμμή αναφοράς.
  long mn_row = 1;
  row_count[mn_row];
  for (auto [i, cnt] : row_count) {
    if (cnt < row_count[mn_row]) 
      mn_row = i;
  }
  for (auto [i, _] : row_count) {
    if (i + 1 < N && row_count.find(i + 1) == row_count.end()) {
      mn_row = i + 1;
      break;
    }
  }
  // Επιβεβαιώνουμε ότι το mn_row είναι στα ones.
  ones[mn_row];
  
  auto get_arr = [&](long r, long c) {
    return ones.at(r).find(c) != ones.at(r).end();
  };
  
  long all_same = 0;
  long all_diff = 0;
  std::unordered_map<long, long> diff;
  long total_valid_rows = 0;
  for (auto& [r, row] : ones) {
    long agreeing_ones = 0;
    for (auto c : row) {
      bool arr_mnr_c = get_arr(mn_row, c);
      agreeing_ones += arr_mnr_c;
    }
    diff[r] = (ones.at(mn_row).size() - agreeing_ones) + (ones.at(r).size() - agreeing_ones); 
    all_same += diff[r] == 0;
    all_diff += diff[r] == N;
  }
  bool is_large_instance = (K + Q) < N;
  auto is_valid = [&](){
    if (is_large_instance && !ones[mn_row].empty()) {
      return ones[mn_row].size() == N && all_diff == ones.size() - 1;
    }
    return (all_same + all_diff == N) || ((ones[mn_row].empty() || ones[mn_row].size() == N) && all_same + all_diff == ones.size());
  };
  if (is_valid()) printf("2\n");
  else printf("0\n");
  
  auto update_cell = [&](long r, long c) {
    if (diff[r] == 0) --all_same;
    if (diff[r] == N) --all_diff;
    if (get_arr(r, c) == get_arr(mn_row, c)) --diff[r];
    else ++diff[r];
    if (diff[r] == 0) ++all_same;
    if (diff[r] == N) ++all_diff;
  };

  int i = 0;
  for (auto [x, y] : pts) {
    if (mn_row != x) {
      toggle(x, y);
      update_cell(x, y);
    } else {
      toggle(x, y);
      for (const auto& [r, _] : ones) {
        if (r == mn_row) continue;
        update_cell(r, y);
      }
    }
    if (is_valid()) printf("2\n");
    else printf("0\n");
  }
  
  return 0;
}


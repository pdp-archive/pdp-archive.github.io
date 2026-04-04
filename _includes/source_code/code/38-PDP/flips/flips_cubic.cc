#include <algorithm>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <unordered_map>

int main() {
  long N, K, Q;
  scanf("%ld%ld%ld", &N, &K, &Q);
  
  std::vector<std::vector<bool>> arr(N + 1, std::vector<bool>(N + 1, false));
  for (long i = 0; i < K; ++i) {
    long x, y;
    scanf("%ld%ld", &x, &y);
    arr[x][y] = 1;
  }
  
  // Ελέγχουμε ότι κάθε γραμμή είναι ίση ή αντίστροφη της επόμενης.
  bool all_equal_or_reverse = true;
  for (long r = 2; r <= N; ++r) {
    bool are_equal = true;
    for (long c = 1; c <= N; ++c)
      are_equal &= (arr[r-1][c] == arr[r][c]);
    bool are_reverse = true;
    for (long c = 1; c <= N; ++c)
      are_reverse &= (arr[r-1][c] != arr[r][c]);
    all_equal_or_reverse &= (are_equal || are_reverse);
  }
  if (all_equal_or_reverse) printf("2\n");
  else printf("0\n");
  
  return 0;
}


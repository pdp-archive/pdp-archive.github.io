#include <cstdio>
#include <vector>
#include <unordered_map>

typedef long long ll;

int main() {
  FILE *fi = fopen("twoends.in", "r");
  long N;
  fscanf(fi, "%ld", &N);
  std::unordered_map<ll, long> value_to_pos;
  std::vector<ll> A(N);
  ll sm = 0;
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%lld", &A[i]);
    sm += A[i];
    if (value_to_pos.find(sm) != value_to_pos.end()) continue;
    value_to_pos[sm] = i;
  }
  sm = 0;
  ll mx = 0;
  for (long i = N - 1; i >= 0; --i) {
    sm += A[i];
    if (value_to_pos.find(sm) != value_to_pos.end()) {
      if (value_to_pos[sm] + (N - i) <= N) {
        if (mx < sm) mx = sm;
      }
    }
  }
  FILE *fo = fopen("twoends.out", "w");
  fprintf(fo, "%lld\n", mx);
  
  return 0;
}


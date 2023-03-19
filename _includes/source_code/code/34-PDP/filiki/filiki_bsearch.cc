#include <cstdio>
#include <vector>

using namespace std;

vector<long> d, w;
vector<vector<long>> e;

long MinK(long u, long D) {
  long ans = 0;
  d[u] = 0;
  for (long i = 0; i < e[u].size(); ++i) {
    long neib = e[u][i];
    long weight = w[neib];
    ans += MinK(neib, D);
    if (d[neib] + weight > D) ans += 1;
    else d[u] = max(d[u], d[neib] + weight);
  }
  return ans;
}

int main() {
  FILE *fi = fopen("filiki.in", "r");
  FILE *fo = fopen("filiki.out", "w");  
  long N, K, lo = 0, hi = 0, mid, par, weight;

  fscanf(fi, "%ld %ld", &N, &K);
  d.resize(N + 1);
  e.resize(N + 1);
  w.resize(N + 1);
  d[1] = 0;
  for (long i = 2; i <= N; ++i) {
    fscanf(fi, "%ld %ld", &par, &weight);
    e[par].push_back(i);
    w[i] = weight;
    d[i] = d[par] + weight;
    hi += weight;
  }

  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (MinK(1, mid) + 1 <= K) hi = mid;
    else lo = mid + 1;
  }

  fprintf(fo, "%ld\n", lo);
  fclose(fi), fclose(fo);
}

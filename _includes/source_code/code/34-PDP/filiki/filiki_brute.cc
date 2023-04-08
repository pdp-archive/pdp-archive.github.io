#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> d;
vector<vector<long>> e;
long mark[30];

long Solve(long u, long ancestor) {
  long ans = mark[u] ? 0 : d[u] - d[ancestor];
  for (auto neigh : e[u])
    ans = max(ans, Solve(neigh, mark[u] ? u : ancestor));  
  return ans;  
}

int main() {
  FILE *fi = fopen("filiki.in", "r");
  FILE *fo = fopen("filiki.out", "w");  
  long N, K, par, weight, ans=0;

  fscanf(fi, "%ld %ld", &N, &K);
  d.resize(N + 1);
  e.resize(N + 1);
  d[1] = 0;
  for (long i = 2; i <= N; ++i) {
    fscanf(fi, "%ld %ld", &par, &weight);
    e[par].push_back(i);
    d[i] = d[par] + weight;
    ans += weight; //upper bounding ans
  }

  mark[1] = 1;
  //this code generates all ways to mark K-1 elements
  for(long i=1; i<K; ++i) mark[N-i+1] = 1;
  do {
    ans = min(ans, Solve(1,1));
  } while(next_permutation(mark+2, mark+N+1));

  fprintf(fo, "%ld\n", ans);
  fclose(fi), fclose(fo);
}

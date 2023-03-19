#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f
#define MAXN 150
#define MAXK 150

using namespace std;

vector<long> e[MAXN+5];
long d[MAXN+5], dp[MAXN+5][MAXN+5][MAXK+5];
bool computed[MAXN+5][MAXN+5][MAXK+5];

long Solve(long u, long y, long k) {
  if (computed[u][y][k]) return dp[u][y][k];
  computed[u][y][k] = true;
  
  if (e[u].size()==0) dp[u][y][k] = k==0 ? d[u]-d[y] : 0;
  else {
    dp[u][y][k] = INF;
    //If we don't mark u
    for(long kt=0; kt <= k; ++kt)
      dp[u][y][k] = min(dp[u][y][k], max(max(d[u]-d[y], Solve(e[u][0], y, kt)), (e[u].size()>1 ? Solve(e[u][1], y, k-kt) : 0)));
    //If we mark u
    if (k>0)
      for(long kt=0; kt < k; ++kt)
	dp[u][y][k] = min(dp[u][y][k], max(Solve(e[u][0], u, kt), (e[u].size()>1 ? Solve(e[u][1], u, k-kt-1) : 0)));
  }
  return dp[u][y][k];
}

int main() {
  FILE *fi = fopen("filiki.in", "r");
  FILE *fo = fopen("filiki.out", "w");  
  long N, K, par, weight;

  fscanf(fi, "%ld %ld", &N, &K);
  d[1] = 0, d[0] = -INF; //to force 1 to be marked
  for (long i = 2; i <= N; ++i) {
    fscanf(fi, "%ld %ld", &par, &weight);
    e[par].push_back(i);
    d[i] = d[par] + weight;
  }

  fprintf(fo, "%ld\n", Solve(1,0,K));
  fclose(fi), fclose(fo);
}

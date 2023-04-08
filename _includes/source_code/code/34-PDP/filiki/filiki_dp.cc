#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f
#define MAXN 150
#define MAXK 150

using namespace std;

vector<long> eOld[MAXN+1], e[2*MAXN+1];
long d[2*MAXN+1], dp[2*MAXN+1][2*MAXN+1][MAXK+1], currNode;
bool computed[2*MAXN+1][2*MAXN+1][MAXK+1];

void Convert(long uOld, long neibIndex, long uNew) {
  //if at most 2 neighbors left, append them and recurse
  if(eOld[uOld].size() - neibIndex <= 2) {
    for(long i=neibIndex; i<eOld[uOld].size(); ++i) {
      e[uNew].push_back(eOld[uOld][i]);
      Convert(eOld[uOld][i], 0, eOld[uOld][i]);
    }
    return;
  }

  //else, append the first node and recurse
  e[uNew].push_back(eOld[uOld][neibIndex]);
  Convert(eOld[uOld][neibIndex], 0, eOld[uOld][neibIndex]);

  //and then create a fake node to recurse
  e[uNew].push_back(++currNode);
  d[currNode] = d[uOld];
  Convert(uOld, neibIndex+1, currNode);
}

long Solve(long u, long y, long k) {
  if (computed[u][y][k]) return dp[u][y][k];
  computed[u][y][k] = true;
  
  if (e[u].size()==0) dp[u][y][k] = k==0 ? d[u]-d[y] : 0;
  else {
    dp[u][y][k] = INF;
    //If we mark u
    if (k>0)
      for(long kt=0; kt < k; ++kt)
	dp[u][y][k] = min(dp[u][y][k], max(Solve(e[u][0], u, kt),
					   (e[u].size()>1 ? Solve(e[u][1], u, k-kt-1) : 0)));
    //If we don't mark u
    for(long kt=0; kt <= k; ++kt)
      dp[u][y][k] = min(dp[u][y][k], max(max(d[u]-d[y], Solve(e[u][0], y, kt)),
					 (e[u].size()>1 ? Solve(e[u][1], y, k-kt) : 0)));    
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
    eOld[par].push_back(i);
    d[i] = d[par] + weight;
  }

  currNode = N;
  Convert(1,0,1);
  
  fprintf(fo, "%ld\n", Solve(1,0,K));
  fclose(fi), fclose(fo);
}

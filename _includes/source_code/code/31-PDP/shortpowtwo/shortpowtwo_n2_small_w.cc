#include <bits/stdc++.h>
using namespace std;
const long MAXN = 1000;
const long MAXM = 1000;
const long INF = 0x3f3f3f3f;
const long MOD = 1e9+7;

long N, M, dist[MAXN+5], visited[MAXN+5];
vector<long> e[MAXN+5], w[MAXN+5];

void Dijkstra(long S, long T) {
  for(long i=1; i<=N; ++i) {
    dist[i] = INF;
    visited[i] = 0;
  }
  dist[S] = 0;
  
  for(long i=1; i<N; ++i) {
    long minDist = INF, minNode = 0;
    for(long j=1; j<=N; ++j) {
      if (!visited[j] && dist[j] < minDist) {
	minDist = dist[j];
	minNode = j;
      }
    }

    if ( minDist != INF ) {
      visited[minNode] = 1;
      for(long j=0; j<e[minNode].size(); ++j) {
	long to=e[minNode][j], d=w[minNode][j];
	if(dist[to] > dist[minNode] + d )
	  dist[to] = dist[minNode] + d;
      }
    }
  }
  
  printf("%ld\n", dist[T]==INF?-1:dist[T]);
}

int main() {
  freopen("shortpowtwo.in","r",stdin);
  freopen("shortpowtwo.out","w",stdout);
  long a, b, c, S, T;
  scanf("%ld %ld", &N, &M);
  for(long i=1; i<=M; ++i) {
    scanf("%ld %ld %ld", &a, &b, &c);
    e[a].push_back(b);
    w[a].push_back(1<<c);
  }
  scanf("%ld %ld", &S, &T);

  Dijkstra(S,T);
  return 0;
}

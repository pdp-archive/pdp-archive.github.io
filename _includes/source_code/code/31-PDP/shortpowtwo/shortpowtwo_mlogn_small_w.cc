#include <bits/stdc++.h>
using namespace std;
const long MAXN = 100000;
const long MAXM = 100000;
const long INF = 0x3f3f3f3f;
const long MOD = 1e9+7;

long N, M, dist[MAXN+5];
vector<long> e[MAXN+5], w[MAXN+5];

void Dijkstra(long S, long T) {
  set< pair<long,long> > Set;
  for(long i=1; i<=N; ++i)
    dist[i] = INF;
  dist[S] = 0;
  Set.insert( {0,S} );
  while(!Set.empty()) {
    long curr = (*Set.begin()).second;
    Set.erase ( Set.begin() );
    if (curr==T) {
      printf("%ld\n", dist[T] % MOD);
      return;
    }

    for(long i=0; i<e[curr].size(); ++i) {
      long to = e[curr][i], d=w[curr][i];
      if ( dist[to] > dist[curr]+d ) {
	if ( dist[to] != INF )
	  Set.erase ( Set.find ( {dist[to],to} ));
	dist[to] = dist[curr]+d;
	Set.insert( {dist[to],to} );
      }
    }
  }

  printf("-1\n");
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

#include <bits/stdc++.h>
using namespace std;
const long MAXN = 60000;
const long INF = 0x3f3f3f3f; //Huge number not overflowing, written in hexadecimal. Easy to remember.

long N, M, dDij[MAXN+2];
vector<long> e[MAXN+2], d[MAXN+2];
set< pair<long,long> > S;

void Dijkstra(long s, long ignore) {
  for(long i=1; i<=N; ++i) dDij[i] = INF;
  dDij[s] = 0;
  S.insert( {0,s} );
  while (!S.empty()) {
    long curr = S.begin()->second;
    S.erase(S.begin());
    
    for(long i=0; i<e[curr].size(); ++i) {
      long neib = e[curr][i];
      if (neib==ignore) continue;
      if ( dDij[neib] > dDij[curr] + d[curr][i] ) {
        if ( dDij[neib] < INF ) {
          S.erase( S.find( {dDij[neib], neib} ) );
        }
        dDij[neib] = dDij[curr] + d[curr][i];
        S.insert( {dDij[neib], neib} );
      }
    }
  }
}

int main () {
  freopen("supgame.in","r",stdin);
  freopen("supgame.out","w",stdout);  
  long s, t, p, q, ans;
  scanf("%ld %ld %ld %ld %ld %ld", &N, &M, &s, &t, &p, &q);
  for(long i=1; i<=M; ++i) {
    long a, b, c;
    scanf("%ld %ld %ld", &a, &b, &c);
    e[a].push_back(b);
    d[a].push_back(c);
  }
  Dijkstra(s, q);
  ans = dDij[t];
  long tmp = dDij[p];
  Dijkstra(p, -1);
  ans = min(ans, tmp + dDij[t]);
  
  printf("%ld\n", ans);
}

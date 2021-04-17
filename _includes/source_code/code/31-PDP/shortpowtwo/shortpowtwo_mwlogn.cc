#include <bits/stdc++.h>
using namespace std;
const long MAXN = 100000;
const long MAXM = 100000;
const long INF = 0x3f3f3f3f;
const long MAXW = 500;
const long MOD = 1e9+7;

struct BigNum {
  bool isInf;
  bool digit[MAXW+20];
  bool operator < (const BigNum &A) const { //compares current struct with A
    if (isInf) return false; //if the current number is Infinite, then it is not smaller
    if (A.isInf) return true;
    for(long i=MAXW+20-1; i>=0; --i) {
      if (digit[i] < A.digit[i]) return true;
      else if (digit[i] > A.digit[i]) return false;
    }
    return false; //the numbers were equal, so the current is not smaller than A
  }
} dist[MAXN+5];

//Add x and 2^exp
//Notice that since 2^exp is a power of 2, it is zero everywhere, except for the exp-th digit
//This makes the addition extremely simple
BigNum Add(BigNum x, long exp) {
  for(long i=exp; i<MAXW+20; ++i) {
    x.digit[i] ^= 1; //flip this digit
    if (x.digit[i] == 1) break;
  }
  return x;
}

long N, M, pow2[MAXW], parent[MAXN+5];
vector<long> e[MAXN+5], w[MAXN+5];

void Dijkstra(long S, long T) {
  set< pair<BigNum,long> > Set;
  for(long i=1; i<=N; ++i)
    dist[i].isInf = true;
  dist[S].isInf = false;
  parent[S] = 0;
  Set.insert( {dist[S],S} );
  while(!Set.empty()) {
    long curr = (*Set.begin()).second;
    if (curr==T) {
      break;
    }
    Set.erase ( Set.begin() );

    for(long i=0; i<e[curr].size(); ++i) {
      long to = e[curr][i], d=w[curr][i];
      BigNum tmp = Add(dist[curr],d);
      if ( tmp < dist[to] ) {
	if ( !dist[to].isInf )
	  Set.erase ( Set.find ( {dist[to],to} ));
	dist[to] = tmp;
	parent[to] = curr;
	Set.insert( {dist[to],to} );
      }
    }
  }

  if (Set.empty())
    printf("-1\n");
  else {
    long ans = 0, curr = T, i;
    while (curr != S) {
      for(i=0; e[parent[curr]][i] != curr; ++i);
      ans = (ans + pow2[ w[parent[curr]][i] ]) % MOD;
      curr = parent[curr];
    }
    printf("%ld\n", ans);
  }
}

int main() {
  freopen("shortpowtwo.in","r",stdin);
  freopen("shortpowtwo.out","w",stdout);
  long a, b, c, S, T;
  scanf("%ld %ld", &N, &M);
  for(long i=1; i<=M; ++i) {
    scanf("%ld %ld %ld", &a, &b, &c);
    e[a].push_back(b);
    w[a].push_back(c);
  }
  scanf("%ld %ld", &S, &T);

  pow2[0] = 1;
  for(long i=1; i<MAXW; ++i)
    pow2[i] = (2*pow2[i-1]) % MOD;

  Dijkstra(S,T);
  return 0;
}

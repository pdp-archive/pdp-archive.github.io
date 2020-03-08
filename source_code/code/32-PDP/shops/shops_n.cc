#include <bits/stdc++.h>
const long MAXN = 2000000;
using namespace std;

long N, K, ans, A[MAXN+5], s[MAXN+5], maxUpTo[MAXN+5];

int main() {
  freopen("shops.in","r",stdin);
  freopen("shops.out","w",stdout);
  scanf("%ld %ld", &N, &K);
  for(long i=1; i<=N; ++i) {
    scanf("%ld", &A[i]);
    s[i] = s[i-1] + A[i];
    if(i-K>=0) maxUpTo[i] = max(maxUpTo[i-1], s[i] - s[i-K]);
  }
  if(N<=2*K) {
    printf("%ld\n", s[N]);
    return(0);
  }

  for(long i=2*K; i<=N; ++i)
    ans = max (s[i]-s[i-K]+maxUpTo[i-K], ans);

  printf("%ld\n", ans);
}


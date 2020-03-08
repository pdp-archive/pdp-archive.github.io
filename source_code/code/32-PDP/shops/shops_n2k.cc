#include <bits/stdc++.h>
const long MAXN = 2000000;
using namespace std;

long N, K, ans, s, sum, A[MAXN+5];

int main() {
  freopen("shops.in","r",stdin);
  freopen("shops.out","w",stdout);
  scanf("%ld %ld", &N, &K);
  for(long i=1; i<=N; ++i) scanf("%ld", &A[i]), s+=A[i];
  if(N<=2*K) {
    printf("%ld\n", s);
    return(0);
  }

  for(long i=2*K; i<=N; ++i)
    for(long j=K; j<=i-K; ++j) {
      long sum = 0;
      for(long k=1; k<=K; ++k) sum += A[i-k+1] + A[j-k+1];
      ans = max (sum, ans);
    }

  printf("%ld\n", ans);
}

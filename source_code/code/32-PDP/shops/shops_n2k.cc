#include <bits/stdc++.h>
const long MAXN = 2000000;
using namespace std;

long N, K, ans, s, sum, A[MAXN+5];

int main() {
  freopen("shops.in","r",stdin);
  freopen("shops.out","w",stdout);
  scanf("%ld %ld", &N, &K);
  for(long i=1; i<=N; ++i)
    scanf("%ld", &A[i]);
  for(long right2=2*K; right2<=N; ++right2)
    for(long right1=K; right1<=right2-K; ++right1) {
      long sum = 0;
      for(long k=1; k<=K; ++k) sum += A[right2-k+1] + A[right1-k+1];
      ans = max (sum, ans);
    }

  printf("%ld\n", ans);
  return 0;
}

#include <bits/stdc++.h>
const long MAXN = 1000000;
using namespace std;

long N, K, ans, A[MAXN+5], s[MAXN+5];

int main() {
  freopen("longsumk.in","r",stdin);
  freopen("longsumk.out","w",stdout);
  scanf("%ld %ld", &N, &K);
  for(long i=1; i<=N; ++i) {
    scanf("%ld", &A[i]);
    s[i] = s[i-1]+A[i];
  }
  for(long i=1; i<=N; ++i)
    for(long j=1; j<=i; ++j)
      if(s[i]-s[j-1]==K && ans < i-j+1)
	ans = i-j+1;

  printf("%ld\n", ans);
  return 0;
}

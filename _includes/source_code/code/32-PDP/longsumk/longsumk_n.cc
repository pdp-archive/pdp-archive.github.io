#include <bits/stdc++.h>
const long MAXN = 1000000;
using namespace std;

long N, K, ans, A[MAXN+5], s[MAXN+5];
unordered_map<long,long> positionOfValue;

int main() {
  freopen("longsumk.in","r",stdin);
  freopen("longsumk.out","w",stdout);
  scanf("%ld %ld", &N, &K);
  for(long i=1; i<=N; ++i) {
    scanf("%ld", &A[i]);
    s[i] = s[i-1]+A[i];
  }
  for(long i=N; i>=1; --i) positionOfValue[s[i]]=i;
  for(long i=1; i<=N; ++i)
    if (positionOfValue.find(s[i] - K) != positionOfValue.end()) //s[i]-K exists
      ans = max(ans,i-positionOfValue[s[i]-K]);

  printf("%ld\n", ans);
  return 0;
}


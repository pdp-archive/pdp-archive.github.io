#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const long MAXX = 1'000;

long dp[MAXX + 1];
long par[MAXX + 1];

int main() {  
  par[0] = -1;
  for (long i = 1; i <= MAXX; ++i) {
    par[i] = -1;
    dp[i] = -2;
    for (long j = 1; j <= i; ++j) {
      if (2 * j <= i) continue;
      if (par[i] == -1 || dp[i - j] + 1 > dp[i]) {
        par[i] = i - j;
        dp[i] = dp[i - j] + 1;
      }
    }
  }
  
  long T;
  scanf("%ld", &T);
  
  while (T--) {
    ll x;
    scanf("%lld", &x);
    printf("%ld\n", dp[x]);
    while (par[x] != -1) {
      printf("%lld ", x - par[x]);
      x = par[x];
    }
    printf("\n");
  }
  
  return 0;
}


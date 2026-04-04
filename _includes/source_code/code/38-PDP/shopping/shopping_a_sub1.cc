#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const long MAXN = 500'000;

ll V[MAXN];

int main() {
  long N, Q;
  scanf("%ld%ld", &N, &Q);
  
  for (long i = 0; i < N; ++i) {
    scanf("%lld", &V[i]);
  }
  
  while (Q--) {
    ll x;
    scanf("%lld", &x);
    while (true) {
      ll mx = -1;
      for (long i = 0; i < N; ++i)
        if (V[i] <= x)
          mx = std::max(mx, V[i]);
      if (mx == -1) break;
      x -= mx;
    }
    printf("%lld\n", x);
  }
  
  return 0;
}


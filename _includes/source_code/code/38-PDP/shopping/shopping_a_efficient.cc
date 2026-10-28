#include <algorithm>
#include <cstdio>
#include <set>
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
  
  std::sort(V, V + N);
  
  while (Q--) {
    ll x;
    scanf("%lld", &x);
    while (V[0] <= x) {
      // Βρίσκει το πρώτο στοιχείο με V[i] >= x + 1, 
      // δηλαδή με V[i] > x, δηλαδή με V[i-1] <= x.
      auto it = std::lower_bound(V, V + N, x + 1);
      --it;
      x = x % *it;
    }
    printf("%lld\n", x);
  }
  
  return 0;
}


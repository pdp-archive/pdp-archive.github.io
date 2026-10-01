#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

int main() {
  long N, Q;
  scanf("%ld%ld", &N, &Q);
  
  ll v;
  scanf("%lld", &v);
  
  while (Q--) {
    ll x;
    scanf("%lld", &x);
    printf("%lld\n", x % v);
  }
  
  return 0;
}


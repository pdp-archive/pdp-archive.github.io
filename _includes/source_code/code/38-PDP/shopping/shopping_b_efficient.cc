#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

int main() {
  long T;
  scanf("%ld", &T);
  
  std::vector<ll> ans;
  while (T--) {
    ll x;
    scanf("%lld", &x);
    long cur_pow = 1; 
    ans.clear();
    while (x) {
      if (2 * cur_pow >= x) ans.push_back(x);
      else ans.push_back(cur_pow);
      cur_pow *= 2;
      x -= ans.back();
    }
    printf("%d\n", ans.size());
    printf("%lld", ans[0]);
    for (int i = 1; i < ans.size(); ++i) 
      printf(" %lld", ans[i]);
    printf("\n");
  }
  
  return 0;
}


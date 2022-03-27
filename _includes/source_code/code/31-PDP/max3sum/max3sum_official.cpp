#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  freopen("max3sum.in", "r", stdin);
  scanf("%d", &N);
  vector<int> a(N), b(N), c(N);
  for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < N; ++i) scanf("%d", &b[i]);
  for (int i = 0; i < N; ++i) scanf("%d", &c[i]);
  int best = -1, best_a = -1, best_ab = -1;
  for (int i = 0; i < N-2; ++i) {
    best_a = max(best_a, a[i]);
    best_ab = max(best_ab, best_a + b[i+1]);
    best = max(best, best_ab + c[i+2]);
  }
  freopen("max3sum.out", "w", stdout);
  printf("%d\n", best);
}

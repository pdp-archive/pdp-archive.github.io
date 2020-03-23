#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  freopen("maketime.in", "rt", stdin);
  freopen("maketime.out", "wt", stdout);
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  vector<int> x(M+2);
  x[0] = 0;
  for (int i = 1; i <= M; ++i)
    scanf("%d", &(x[i]));
  x[M+1] = N+1;
  sort(x.begin(), x.end());
  if (M <= K) {
    printf("%d\n", N);
  } else {
    int best = 0;
    for (int i = 1; i + K <= M+1; i++)
      best = max(best, x[i+K] - x[i-1] - 1);
    printf("%d\n", best);
  }
}

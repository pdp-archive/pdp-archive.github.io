#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
#ifdef CONTEST
  freopen("listgame.in", "rt", stdin);
  freopen("listgame.out", "wt", stdout);
#endif
  int N;
  scanf("%d", &N);
  vector<int> x(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &x[i]);
  // s[k] : the sum of the first k elements
  vector<int> s(N+1);
  s[0] = 0;
  for (int i = 0; i < N; i++) s[i+1] = s[i] + x[i];
  // dp[k][i] : the best the player that plays first can do for the
  //            list of integers of length k starting at element i.
  vector<int> dp[2];
  dp[0].resize(N+1);
  dp[1].resize(N+1);
  for (int i = 0; i <= N; ++i) dp[0][i] = 0;
  for (int k = 1; k <= N; ++k)
    for (int i = 0; i <= N-k; ++i)
      dp[k%2][i] = s[k+i] - s[i] - min(dp[(k-1)%2][i+1], dp[(k-1)%2][i]);
  printf("%d\n", dp[N%2][0]);
}

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
#ifdef CONTEST
  freopen("metoxes.in", "rt", stdin);
  freopen("metoxes.out", "wt", stdout);
#endif
  int N, K, money;
  scanf("%d %d", &N, &K);
  scanf("%d", &money);
  int dp[2][K+1][2];
  for (int j=0; j<=K; ++j) {
    dp[1][j][0] = 0;
    dp[1][j][1] = -money;
  }
  for (int i=2; i<=N; ++i) {
    scanf ("%d", &money);
    dp[i%2][0][0] = 0;
    dp[i%2][0][1] = max(dp[(i-1)%2][0][1], -money);
    for (int j=1; j<=K; ++j ) {
      dp[i%2][j][0] = max(dp[(i-1)%2][j][0], dp[(i-1)%2][j-1][1] + money);
      dp[i%2][j][1] = max(dp[(i-1)%2][j][1], dp[(i-1)%2][j][0] - money);
    }
  }
  printf("%d\n", dp[N%2][K][0]);
}

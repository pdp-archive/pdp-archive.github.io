#include <cstdio>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define mp make_pair

#define MAXN 100100

using namespace std;

typedef pair< int, int > pii;

int dp[MAXN + 1][2];
pii rect[MAXN + 1];

int main() {
  int N, u, v;
  freopen("parallel.in", "r", stdin);
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d%d", &u, &v);
    rect[i] = mp(u, v);
  }
  dp[1][0] = rect[1].X;
  dp[1][1] = rect[1].Y;
  for(int i = 2; i <= N; i++) {
    dp[i][0] = rect[i].X + max(
        dp[i - 1][0] + abs(rect[i].Y - rect[i - 1].Y),
        dp[i - 1][1] + abs(rect[i - 1].X - rect[i].Y)
    );
    dp[i][1] = rect[i].Y + max(
        dp[i - 1][0] + abs(rect[i - 1].Y - rect[i].X),
        dp[i - 1][1] + abs(rect[i - 1].X - rect[i].X)
    );
  }
  freopen("parallel.out", "w", stdout);
  printf("%d\n", max(dp[N][0], dp[N][1]));
}

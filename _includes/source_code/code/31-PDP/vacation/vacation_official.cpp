#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define MAXN 5100
#define INF 1234567890
#define INFLL 12345678901234567LL

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, B, S, R, dist[MAXN + 1][2];

vector<pii> G[MAXN + 1][2];

ll A[MAXN + 1], dp[MAXN + 1][2];

void dijkstra(int s, int id) {
  set<pii> S;
  for (int i = 1; i <= N; i++) dist[i][id] = INF;
  dist[s][id] = 0;
  S.insert(mp(0, s));
  while (!S.empty()) {
    pii A = *S.begin();
    S.erase(S.begin());
    int u = A.Y, d = A.X;
    for (int i = 0; i < G[u][id].size(); i++) {
      int v = G[u][id][i].Y, w = G[u][id][i].X;
      if (d + w < dist[v][id]) {
        dist[v][id] = d + w;
        S.insert(mp(d + w, v));
      }
    }
  }
}


int main() {
  int u, v, w;
  ll sum = 0;
  freopen("vacation.in", "r", stdin);
  scanf("%d%d%d%d", &N, &S, &B, &R);
  for (int i = 0; i < R; i++) {
    scanf("%d%d%d", &u, &v, &w);
    G[u][0].pb(mp(w, v));
    G[v][1].pb(mp(w, u));
  }
  dijkstra(B + 1, 0);
  dijkstra(B + 1, 1);
  for (int i = 1; i <= B; i++) A[i] = (ll)(dist[i][0] + dist[i][1]);
  sort(A + 1, A + B + 1);
  for (int i = 1; i <= B; i++) {
    sum += A[i];
    dp[i][1] = (ll)(i - 1) * sum;
  }
  for (int k = 2; k <= S; k++) {
    for (int i = 1; i <= B; i++) {
      sum = A[i];
      dp[i][k % 2] = INFLL;
      for (int j = i - 1; j >= 0; j--) {
        if ((i - j) * k > i) break;
        dp[i][k % 2] = min(dp[i][k % 2],
                           (ll)(i - j - 1) * sum + dp[j][(k - 1) % 2]);
        sum += A[j];
      }
    }
  }
  freopen("vacation.out", "w", stdout);
  printf("%lld\n", dp[B][S % 2]);
}

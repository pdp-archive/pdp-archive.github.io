#include <cstdio>
#include <algorithm>
#include <vector>

#define MAXN 501000
#define INF 123456789012345LL

#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, label[MAXN + 1], sub_black[MAXN + 1], black;

vector<pii> T[MAXN + 1];

ll total, ans = INF;

void dfs_precomp(int u, int p, ll dist) {
  if (label[u]) total += dist;
  sub_black[u] = label[u];
  for (auto e : T[u]) {
    int v = e.X, w = e.Y;
    if (v == p) continue;
    dfs_precomp(v, u, dist + (ll) w);
    sub_black[u] += sub_black[v];
  }
}

void dfs_solve(int u, int p, ll cur_dist) {
  ans = min(ans, cur_dist);
  for (auto e : T[u]) {
    int v = e.X;
    ll w = e.Y;
    if (v == p) continue;
    int down_count = sub_black[v], up_count = black - sub_black[v];
    ll new_dist = cur_dist - (ll) down_count * w + (ll) up_count * w;
    dfs_solve(v, u, new_dist);
  }
}

int main() {
  freopen("treecity.in", "r", stdin);
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &label[i]);
    black += label[i];
  }
  for (int i = 1; i < N; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    T[u].pb(mp(v, w));
    T[v].pb(mp(u , w));
  }
  dfs_precomp(1, -1, 0);
  dfs_solve(1, -1, total);
  freopen("treecity.out", "w", stdout);
  printf("%lld\n", ans);
}

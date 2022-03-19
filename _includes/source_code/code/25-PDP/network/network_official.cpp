#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

#define MAXN 10000

typedef set<int> adjlist;
typedef vector<adjlist> graph;
typedef vector<int> veci;
typedef vector<bool> vecb;

void dfs (const graph &g,
          veci &level, veci &low, veci &children, vecb &critical,
          int u)
{
  low[u] = level[u];
  for (adjlist::iterator i = g[u].begin(); i != g[u].end(); i++)
    if (level[*i] == -1) {
      level[*i] = level[u] + 1;
      children[u]++;
      dfs(g, level, low, children, critical, *i);
      low[u] = min(low[u], low[*i]);
      if (level[u] > 0 && low[*i] >= level[u]) {
        // u is a non-root node and there's no way from *i
        // to any upper level of u
        critical[u] = true;
      }
    }
    else if (level[*i] < level[u] - 1) {
      // *i's depth is lower than y's parent....so it's a back edge
      low[u] = min(low[u], level[*i]);
    }
  if (level[u] == 0) {
    // root node
    if (children[u] >= 2) critical[u] = true;
  }
}

int critical (int N, const graph &g)
{
  vector<bool> critical(N);
  vector<int> level(N), low(N), children(N);
  for (int i=0; i<N; i++) {
    critical[i] = false;
    level[i] = low[i] = -1;
    children[i] = 0;
  }
  level[0] = 0;
  dfs(g, level, low, children, critical, 0);
  int count = 0;
  for (int i=0; i<N; i++) if (critical[i]) count++;
  return count;  
}

int main ()
{
#ifdef CONTEST
  freopen("network.in", "rt", stdin);
  freopen("network.out", "wt", stdout);
#endif
  // input
  int N, K;
  scanf("%d %d", &N, &K);
  graph g(N);
  for (int i=0; i<K; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  // calculate
  int count = critical(N, g);
  // output
  printf("%d\n", count);
  return 0;
}

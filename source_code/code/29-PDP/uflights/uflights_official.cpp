#include <cstdio>
#include <set>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> edge;
#define mkedge(v, k) make_pair(k, v)
#define cost(e) ((e).first)
#define target(e) ((e).second)

int main() {
  freopen("uflights.in", "rt", stdin);
  freopen("uflights.out", "wt", stdout);
  int N, M;
  scanf("%d %d", &N, &M);
  vector< vector<edge> > G(N);
  for (int i = 0; i < M; ++i) {
    int A, B, K;
    scanf("%d %d %d", &A, &B, &K);
    G[A-1].push_back(mkedge(B-1, K));
    G[B-1].push_back(mkedge(A-1, K));
  }
  priority_queue< edge, vector<edge>, greater<edge> > Q;
  set<int> visited;
  int u = 0, total = 0;
  do {
    visited.insert(u);
    for (vector<edge>::iterator i = G[u].begin(); i != G[u].end(); ++i)
      Q.push(*i);
    while (!Q.empty()) {
      edge e = Q.top();
      Q.pop();
      u = target(e);
      if (visited.find(u) != visited.end()) continue;
      total += cost(e);
      break;
    }
  } while (visited.size() < N);
  printf("%d\n", total);
  return 0;
}

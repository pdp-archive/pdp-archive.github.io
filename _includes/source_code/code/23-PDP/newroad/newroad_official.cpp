#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

#define INFINITE 0x42424242

typedef vector< pair<int, int> > neighbours;

void dijkstra (int N, neighbours g[], int s, int d[])
{
  set< pair<int, int> > Q;
  for (int v=0; v<N; v++)
    d[v] = INFINITE;
  d[s] = 0;
  Q.insert(make_pair(d[s], s));
  while (!Q.empty()) {
    int u = Q.begin()->second;
    Q.erase(Q.begin());
    for (neighbours::iterator v = g[u].begin(); v != g[u].end(); v++) {
      int dv = d[u] + v->second;
      if (dv < d[v->first]) {
        if (d[v->first] != INFINITE)
          Q.erase(Q.find(make_pair(d[v->first], v->first)));
        d[v->first] = dv;
        Q.insert(make_pair(d[v->first], v->first));
      }
    }
  }
}

int main ()
{
  FILE * f;
  int N, M, K, s, t;

  f = fopen("newroad.in", "rt");
  fscanf(f, "%d %d %d %d %d\n", &N, &M, &K, &s, &t);
  s--; t--;
  neighbours fwd[N], rev[N];
  
  for (int i=0; i<M; i++) {
    int u, v, l;
    fscanf(f, "%d %d %d\n", &u, &v, &l);
    u--; v--;
    fwd[u].push_back(make_pair(v, l));
    rev[v].push_back(make_pair(u, l));
  }

  int ds[N], dt[N];
  dijkstra(N, fwd, s, ds);
  dijkstra(N, rev, t, dt);

  int min = ds[t];
  for (int i=0; i<K; i++) {
    int u, v, l;
    fscanf(f, "%d %d %d\n", &u, &v, &l);
    u--; v--;
    if (ds[u] == INFINITE || dt[v] == INFINITE) continue;
    int d = ds[u] + l + dt[v];
    if (d < min) min = d;
  }
  fclose(f);

  f = fopen("newroad.out", "wt");
  fprintf(f, "%d\n", min);
  fclose(f);

  return 0;
}

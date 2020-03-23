#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class UnionFind {
public:
  // Nodes are numbered from 1 to N.
  UnionFind(long N) : parent(N+1), rank(N+1) {}

  long find(long x) {
    if (parent[x] == 0) return x;
    parent[x] = find(parent[x]);
    return parent[x];
  }

  void do_union(long x, long y) {
    long xRoot = find(x), yRoot = find(y);
    if (xRoot == yRoot) return;
    if (rank[xRoot] < rank[yRoot])
      parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
      parent[yRoot] = xRoot;
    else {
      parent[yRoot] = xRoot;
      rank[xRoot]++;
    }
  }

private:
  vector<int> parent, rank;
};

int main() {
  freopen("villages.in", "rt", stdin);
  freopen("villages.out", "wt", stdout);
  long N, M, K;
  scanf("%ld %ld %ld", &N, &M, &K);
  UnionFind UF(N);
  for (long i = 0; i < M; ++i) {
    long u, v;
    scanf("%ld %ld", &u, &v);
    UF.do_union(u, v);
  }
  vector<bool> leader(N+1);
  long groups = 0;
  for (long u = 1; u <= N; ++u) {
    long p = UF.find(u);
    if (!leader[p]) { leader[p] = true; ++groups; }
  }
  printf("%ld\n", groups > K ? groups - K : 1);
  return 0;
}

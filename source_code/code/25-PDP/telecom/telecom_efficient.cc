#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 500000;

struct Edge {
   long u;
   long v;
   long weight;
   
   Edge(long u, long v, long weight) : u(u), v(v), weight(weight) {}
   
   bool operator<(const Edge& e) const {
      if (weight != e.weight) return weight < e.weight;
      if (u != e.u) return u < e.u;
      return v < e.v;
   }
};

long N;

long parent[MAXN + 1];
long rank[MAXN + 1];
ll count[MAXN + 1];

void init() {
   for (long i = 1; i <= N; ++i) {
      parent[i] = i;
      rank[i] = 1;
      count[i] = 1;
   }
}

long findParent(long n) {
   if (n == parent[n]) return n;
   return parent[n] = findParent(parent[n]);
}

void unite(long u, long v) {
   if (rank[u] < rank[v]) std::swap(u, v);
   parent[v] = u;
   count[u] += count[v];
   if (rank[u] == rank[v]) ++rank[u];
}

int main() {
   FILE *fi = fopen("telecom.in", "r");
   fscanf(fi, "%ld", &N);
   std::vector<Edge> edges;
   
   for (long i = 1; i < N; ++i) {
      long u, v, weight;
      fscanf(fi, "%ld%ld%ld", &u, &v, &weight);
      edges.push_back(Edge(u, v, weight));
   }
   fclose(fi);
   std::sort(edges.begin(), edges.end());
   init();
   ll total = 0;
   for (const Edge& e : edges) {
      long parent_u = findParent(e.u);
      long parent_v = findParent(e.v);
      total += e.weight;
      if (parent_u != parent_v) {
         total += (count[parent_u] * count[parent_v] - 1) * (e.weight + 1);
         unite(parent_u, parent_v);
      }
   }
   
   FILE *fo = fopen("telecom.out", "w");
   fprintf(fo, "%lld\n", total);
   fclose(fo);
   return 0;
}

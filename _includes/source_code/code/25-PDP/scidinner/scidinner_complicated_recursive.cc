#include <stdio.h>
#include <vector>

const size_t MAXN = 1'000'000;

std::vector<long> v[MAXN+1];

std::vector<long> topo_sort;
bool visited[MAXN + 1];
long max_path[MAXN + 1];

void dfs(long u) {
   for (const auto& neigh : v[u]) {
      if (!visited[neigh]) {
         visited[neigh] = true;
         dfs(neigh);
      }
   }
   topo_sort.push_back(u);
}

int main() {
   long N, M;
   FILE *fi = fopen("scidinner.in", "r");
   fscanf(fi, "%ld%ld", &N, &M);
   for (long i = 0; i < M; ++i) {
      long a, b;
      fscanf(fi, "%ld%ld", &a, &b);
      v[a].push_back(b);
   }
   fclose(fi);
   
   for (long i = 1; i <= N; ++i) {
      if (!visited[i]) {
         visited[i] = true;
         dfs(i);
      }
   }
   
   long max_max_path = 0;
   for (long i = 0; i < topo_sort.size(); ++i) {
      long u = topo_sort[i];
      for (const auto& neigh : v[u]) {
         max_path[u] = std::max(max_path[u], max_path[neigh] + 1);
      }
      max_max_path = std::max(max_max_path, max_path[u]);
   }
   
   FILE *fo = fopen("scidinner.out", "w");
   fprintf(fo, "%ld\n", max_max_path + 1);
   fclose(fo);
   
   return 0;
}

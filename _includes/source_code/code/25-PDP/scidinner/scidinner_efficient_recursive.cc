#include <stdio.h>
#include <vector>

const size_t MAXN = 1'000'000;

std::vector<long> v[MAXN+1];

bool has_parent[MAXN + 1];
long max_path_len;

void dfs(long u, long path_len) {
   if (path_len > max_path_len) 
       max_path_len = path_len;
   for (const auto& neigh : v[u]) {
      dfs(neigh, path_len + 1);
   }
   
}

int main() {
   long N, M;
   FILE *fi = fopen("scidinner.in", "r");
   fscanf(fi, "%ld%ld", &N, &M);
   for (long i = 0; i < M; ++i) {
      long a, b;
      fscanf(fi, "%ld%ld", &a, &b);
      v[a].push_back(b);
      has_parent[b] = true;
   }
   fclose(fi);
   
   for (long i = 1; i <= N; ++i) {
      if (!has_parent[i]) {
         dfs(i, 1);
      }
   }
   
   FILE *fo = fopen("scidinner.out", "w");
   fprintf(fo, "%ld\n", max_path_len);
   fclose(fo);
   
   return 0;
}

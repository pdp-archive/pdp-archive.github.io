#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 500000;

std::vector<std::pair<long, long>> v[MAXN + 1];

void findMax(long current, long target, long par, long cur_max, long& ans) {
   if (current == target) {
      ans = cur_max;
      return;
   }
   for (const auto& edge : v[current]) {
      if (edge.first == par) continue;
      findMax(edge.first, target, current, std::max(cur_max, edge.second), ans);
   }
}
      

long findMaxEdgeInPath(long u, long v) {
   long ans = -1;
   findMax(u, v, -1, -1, ans);
   return ans;
}

int main() {
   long N;
   FILE *fi = fopen("telecom.in", "r");
   fscanf(fi, "%ld", &N);
   
   for (long i = 1; i < N; ++i) {
      long a, b, weight;
      fscanf(fi, "%ld%ld%ld", &a, &b, &weight);
      v[a].push_back(std::make_pair(b, weight));
      v[b].push_back(std::make_pair(a, weight));
   }
   fclose(fi);
   
   ll total = 0;
   for (long u = 1; u <= N; ++u) {
      for (long v = u + 1; v <= N; ++v) {
         total += findMaxEdgeInPath(u, v) + 1;
      }
   }
   total -= N - 1;
   
   FILE *fo = fopen("telecom.out", "w");
   fprintf(fo, "%lld\n", total);
   fclose(fo);
   return 0;
}

#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 500000;

std::vector<std::pair<long, long>> v[MAXN + 1];

void findSumMax(long current, long par, long cur_max, ll& ans) {
   ans += cur_max + 1;
   for (const auto& edge : v[current]) {
      if (edge.first == par) continue;
      findSumMax(edge.first, current, std::max(cur_max, edge.second), ans);
   }
}

ll findSumMax(long u) {
   ll ans = 0;
   findSumMax(u, -1, -1, ans);
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
      total += findSumMax(u);
   }
   total = (total)/2 - (N - 1);
   
   FILE *fo = fopen("telecom.out", "w");
   fprintf(fo, "%lld\n", total);
   fclose(fo);
   return 0;
}

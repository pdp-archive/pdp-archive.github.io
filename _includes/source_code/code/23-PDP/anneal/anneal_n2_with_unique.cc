#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const long MAXN = 50'000;
const ll MAXV = 10'000'000LL * 2 * (MAXN + 1);
long a[MAXN], idx[MAXN];
ll dp[MAXN];

std::vector<std::pair<long, long>> b;

int main() {
   long N;
   FILE *fi = fopen("anneal.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
      b.push_back({ a[i], i });
   }
   fclose(fi);
   sort(b.begin(), b.end());
   long prev = -1, cur_idx = -1;
   for (long i = 0; i < N; ++i) {
      if (b[i].first != prev) {
         prev = b[i].first;
         ++cur_idx;
         b[cur_idx].first = b[i].first;
      }
      idx[b[i].second] = cur_idx;
   }
   for (long i = 0; i < N; ++i) {
      ll mn = MAXV;
      for (long j = 0; j < idx[i]; ++j) {
         dp[j] += a[i] - b[j].first;
      }
      for (long j = idx[i]; j <= cur_idx; ++j) {
         mn = std::min(mn, dp[j]);
         dp[j] += 2 * a[i];
      }
      dp[idx[i]] = mn;
   }
   ll mn = dp[0];
   for (long i = 0; i <= cur_idx; ++i) {
      mn = std::min(mn, dp[i]);
   }
   FILE *fo = fopen("anneal.out", "w");
   fprintf(fo, "%lld\n", mn);
   fclose(fo);
   return 0;
}

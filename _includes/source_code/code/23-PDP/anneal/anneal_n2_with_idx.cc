#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 50'000;
const ll MAXV = 10'000'000LL * 2 * (MAXN + 1);
long a[MAXN];

int main() {
   long N;
   FILE *fi = fopen("anneal.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
   }
   fclose(fi);
   std::vector<std::vector<ll>> dp(N, std::vector<ll>(N, 0LL));
   for (long i = 0; i < N; ++i) {
      ll mn = MAXV;
      for (long j = 0; j < N; ++j) {
         ll prev = (i > 0) ? dp[i-1][j] : 0;
         if (a[i] > a[j]) dp[i][j] = prev + a[i] - a[j];
         else {
            mn = std::min(mn, prev);
            dp[i][j] = prev + 2 * a[i];
         }
      }
      dp[i][i] = mn;
   }
   ll mn = dp[N-1][0];
   for (long i = 0; i < N; ++i) {
      mn = std::min(mn, dp[N-1][i]);
   }
   FILE *fo = fopen("anneal.out", "w");
   fprintf(fo, "%lld\n", mn);
   fclose(fo);
   return 0;
}

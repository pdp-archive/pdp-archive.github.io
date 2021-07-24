#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const int MAXN = 50'000;
const ll MAXV = 10'000'000LL * (MAXN + 1);
long a[MAXN];

int main() {
   int N;
   FILE *fi = fopen("anneal.in", "r");
   fscanf(fi, "%d", &N);
   long max_a = 0;
   for (int i = 0; i < N; ++i) {
      fscanf(fi, "%d", &a[i]);
      max_a = std::max(max_a, a[i]);
   }
   fclose(fi);
   
   std::vector<std::vector<ll>> dp(N, std::vector<ll>(max_a + 1, 0));
   for (int i = 0; i < N; ++i) {
      ll mn = MAXV;
      for (long j = 0; j <= max_a; ++j) {
         ll prev = (i > 0 ? dp[i-1][j] : 0);
         if (a[i] > j) dp[i][j] = prev + a[i] - j;
         else {
            mn = std::min(mn, prev);
            dp[i][j] = prev + 2 * a[i];
         }
      }
      dp[i][a[i]] = mn;
   }
   ll mn = dp[N-1][0];
   for (long i = 0; i <= max_a; ++i) {
      mn = std::min(mn, dp[N-1][i]);
   }
   FILE *fo = fopen("anneal.out", "w");
   fprintf(fo, "%lld\n", mn);
   fclose(fo);
   return 0;
}

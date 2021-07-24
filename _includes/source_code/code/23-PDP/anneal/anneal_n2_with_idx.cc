#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 50'000;
const ll MAXV = 10'000'000LL * (MAXN + 1);
int a[MAXN];

int main() {
   int N;
   FILE *fi = fopen("anneal.in", "r");
   fscanf(fi, "%d", &N);
   for (int i = 0; i < N; ++i) {
      fscanf(fi, "%d", &a[i]);
   }
   fclose(fi);
   std::vector<std::vector<ll>> dp(N, std::vector<ll>(N, 0LL));
   for (int i = 0; i < N; ++i) {
      ll mn = MAXV;
      for (int j = 0; j < N; ++j) {
         ll prev = (i > 0 ? dp[i-1][j] : 0);
         if (a[i] > a[j]) dp[i][j] = prev + a[i] - a[j];
         else {
            mn = std::min(mn, prev);
            dp[i][j] = prev + 2 * a[i];
         }
      }
      dp[i][i] = mn;
   }
   ll mn = dp[N-1][0];
   for (int i = 0; i < N; ++i) {
      mn = std::min(mn, dp[N-1][i]);
   }
   FILE *fo = fopen("anneal.out", "w");
   fprintf(fo, "%lld\n", mn);
   fclose(fo);
   return 0;
}

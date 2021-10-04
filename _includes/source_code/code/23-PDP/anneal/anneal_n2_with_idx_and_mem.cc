#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const long MAXN = 50'000;
const ll MAXV = 10'000'000LL * 2 * (MAXN + 1);
long a[MAXN];
ll dp[MAXN];

int main() {
   long N;
   FILE *fi = fopen("anneal.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
   }
   fclose(fi);
   for (long i = 0; i < N; ++i) {
      ll mn = MAXV;
      for (long j = 0; j < N; ++j) {
         if (a[i] > a[j]) dp[j] += a[i] - a[j];
         else {
            mn = std::min(mn, dp[j]);
            dp[j] += 2 * a[i];
         }
      }
      dp[i] = mn;
   }
   ll mn = dp[0];
   for (long i = 0; i < N; ++i) {
      mn = std::min(mn, dp[i]);
   }
   FILE *fo = fopen("anneal.out", "w");
   fprintf(fo, "%lld\n", mn);
   fclose(fo);
   return 0;
}

#include <algorithm>
#include <cstdio>

const size_t MAXN = 10000;

long a[MAXN];

// Δύο σειρές που αντιστοιχούν στις διαφορές d και d + 1.
long dp[MAXN][2];

int main() {
   long N;
   FILE *fi = fopen("listgame.in", "r");
   fscanf(fi, "%ld", &N);
   long total = 0;
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
      total += a[i];
   }
   fclose(fi);
   // dp[i][j] = best from j to i + j
   for (long i = 0; i < N; ++i) {
      long cur = i % 2; // Διαφορά d + 1
      long prev = (i + 1) % 2; // Διαφορά d
      for (long j = 0; j + i < N; ++j) {
        if (i == 0) dp[j][cur] = a[j];
        else if (i % 2 == 0) {
           dp[j][cur] = std::max(a[j] + dp[j + 1][prev], a[i + j] + dp[j][prev]);
        } else dp[j][cur] = std::min(-a[j] + dp[j + 1][prev], -a[i + j] + dp[j][prev]);
      }
   }
   FILE *fo = fopen("listgame.out", "w");
   if (N % 2 == 1) fprintf(fo, "%ld\n", (dp[0][0] + total)/2);
   else fprintf(fo, "%ld\n", (total - dp[0][1])/2);
   fclose(fo);
   return 0;
}

#include <algorithm>
#include <cstdio>

const size_t MAXN = 10000;

long a[MAXN];
long dp[MAXN][MAXN]; // dp[i][j] = καλύτερο από το j στο i + j

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
   
   for (long i = 0; i < N; ++i) {
      for (long j = 0; j + i < N; ++j) {
        if (i == 0) dp[j][j] = a[j];
        else if (i % 2 == 0) {
           dp[j][j + i] = std::max(a[j] + dp[j + 1][j + i], a[i + j] + dp[j][j + i - 1]);
        } else dp[j][j + i] = std::min(-a[j] + dp[j + 1][j + i], -a[i + j] + dp[j][j + i - 1]);
      }
   }
   
   FILE *fo = fopen("listgame.out", "w");
   if (N % 2 == 1) fprintf(fo, "%ld\n", (dp[0][N-1] + total)/2);
   else fprintf(fo, "%ld\n", (total - dp[0][N-1])/2);
   fclose(fo);
   return 0;
}
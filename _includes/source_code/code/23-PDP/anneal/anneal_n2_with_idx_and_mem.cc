#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const int MAXN = 50'000;
const ll MAXV = 10'000'000LL * (MAXN + 1);
int a[MAXN];
ll dp[MAXN];

int main() {
   int N;
   FILE *fi = fopen("anneal.in", "r");
   fscanf(fi, "%d", &N);
   for (int i = 0; i < N; ++i) {
      fscanf(fi, "%d", &a[i]);
   }
   fclose(fi);
   for (int i = 0; i < N; ++i) {
      ll mn = MAXV;
      for (int j = 0; j < N; ++j) {
         if (a[i] > a[j]) dp[j] += a[i] - a[j];
         else {
            mn = std::min(mn, dp[j]);
            dp[j] += 2 * a[i];
         }
      }
      dp[i] = mn;
   }
   ll mn = dp[0];
   for (int i = 0; i < N; ++i) {
      mn = std::min(mn, dp[i]);
   }
   FILE *fo = fopen("anneal.out", "w");
   fprintf(fo, "%lld\n", mn);
   fclose(fo);
   return 0;
}

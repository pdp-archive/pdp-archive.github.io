#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const int MAXN = 300;
const ll INF = 10'000LL * MAXN * MAXN;

ll dp[MAXN][MAXN][2];

int main() {
   FILE *fi = fopen("fishboats.in", "r");
   ll M; 
   int N;
   fscanf(fi, "%d%lld", &N, &M);
   std::vector<int> left, right;
   left.push_back(0);
   right.push_back(0);
   for (int i = 0; i < N; ++i) {
      int tmp;
      fscanf(fi, "%d", &tmp);
      if (tmp < 0) left.push_back(-tmp);
      else right.push_back(tmp);
   }
   fclose(fi);
   std::sort(left.begin(), left.end());
   std::sort(right.begin(), right.end());
   
   ll cur_best = 0;
   // Δοκιμάζουμε όλα τα δυνατά πλήθη ψαρόβαρκων στη βέλτιση λύση.
   for (int total_boats = 1; total_boats <= N; ++total_boats) {
      for (int i = 0; i < left.size(); ++i) {
         int mx_j = std::min(total_boats - i + 1, (int) right.size());
         for (int j = 0; j < mx_j; ++j) {
            if (i == 0 && j == 0) continue;
            int remaining_boats = total_boats - (i + j) + 1;
            dp[i][j][0] = dp[i][j][1] = -INF;
            if (i >= 1) dp[i][j][0] = M + std::max(
               dp[i-1][j][0] - remaining_boats * (left[i] - left[i-1]),
               dp[i-1][j][1] - remaining_boats * (left[i] + right[j]));
            if (j >= 1) dp[i][j][1] = M + std::max(
               dp[i][j-1][1] - remaining_boats * (right[j] - right[j-1]),
               dp[i][j-1][0] - remaining_boats * (left[i] + right[j]));
            // Η λύση είναι πιθανή μόνο όταν i+j == total_boats.
            if (i + j == total_boats) cur_best = std::max(
               cur_best, 
               std::max(dp[i][j][0], dp[i][j][1]));
         }
      }
   }
   
   FILE *fo = fopen("fishboats.out", "w");
   fprintf(fo, "%lld\n", cur_best);
   fclose(fo);
   return 0;
}

#include <stdio.h>
#define MAXN 100005
#define MAXM 505
#define INF (-1000000000)

int dp[MAXN][MAXM];
int N, M, K;
int use;
int a[MAXN];

int main() {
   freopen("supermarket.in", "r", stdin);
   freopen("supermarket.out", "w", stdout);
   scanf("%d %d %d", &N, &M, &K);
   for(int i=0; i<N; ++i) scanf("%d", a+i);
   int best = 0;
   for(use=0; use<=M; ++use) {
      for(int i=0; i<=N; ++i)
         for(int j=0; j<=use; ++j)
            dp[i][j] = 0;
      for(int i=N-1; i>=0; --i) {
         for(int before=use; before>=0; --before) {
            int keep, move, idx;
            // Case keep
            keep = INF;
            if(N-i-1 >= use-before) {
               keep = dp[i+1][before];
               idx = i-before+1;
               if(idx % K == 0)
                  keep += a[i];
            }
            // Case move
            move = INF;
            if((i != N-1 || before != 0) && before+1 <= use) {
               move = dp[i+1][before+1];
               idx = N-use+before+1;
               if(idx % K == 0)
                  move += a[i];
            }
            if(keep < 0 && move < 0) dp[i][before] = INF;
            else {
               if(keep > move) dp[i][before] = keep;
               else dp[i][before] = move;
            }
         }
      }
      int current = dp[0][0];
      if(current > best)
         best = current;
   }
   printf("%d\n", best);
   return 0;
}

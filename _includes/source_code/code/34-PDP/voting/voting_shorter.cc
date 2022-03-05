#include <stdio.h>

const long MAXM = 1000;

long cnt[MAXM + 1];

int main() {
   long N, M, K;
   FILE *fi = fopen("voting.in", "r");
   fscanf(fi, "%ld%ld%ld", &N, &M, &K);
   
   int max_val = -1, max_cnt = 0;
   for (long i = 0; i < K; ++i) {
      long cur;
      fscanf(fi, "%ld", &cur);
      ++cnt[cur];
      max_cnt += (cnt[cur] == max_val);
      if (cnt[cur] > max_val) {
         max_val = cnt[cur];
         max_cnt = 1;
      }
   }
   fclose(fi);
   
   long possible_winners = 0;
   for (long i = 1; i <= M; ++i) {
      possible_winners += ((max_val == cnt[i] && max_cnt == 1)
         || (cnt[i] + N - K > max_val));
   }
   
   FILE *fo = fopen("voting.out", "w");
   fprintf(fo, "%ld\n", possible_winners);
   fclose(fo);
   
   return 0;
}

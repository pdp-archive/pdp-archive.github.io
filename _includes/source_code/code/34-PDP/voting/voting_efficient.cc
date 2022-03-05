#include <stdio.h>

const long MAXM = 1000;

long cnt[MAXM + 1];

int main() {
   long N, M, K;
   FILE *fi = fopen("voting.in", "r");
   fscanf(fi, "%ld%ld%ld", &N, &M, &K);
   
   // Μετράμε τις ψήφους για κάθε υποψήφιο.
   for (long i = 0; i < K; ++i) {
      long cur;
      fscanf(fi, "%ld", &cur);
      ++cnt[cur];
   }
   fclose(fi);
   
   long max_val = -1, max_cnt = 0;
   for (long i = 1; i <= M; ++i) {
      if (cnt[i] == max_val) ++max_cnt;
      else if (cnt[i] > max_val) {
         max_val = cnt[i];
         // Βρήκαμε καινούργια μέγιστη τιμή, άρα
         // πρέπει να ξαναρχίσουμε τον μετρητή.
         max_cnt = 1;
      }
   }
   
   
   // Μετράμε τους υποψήφιους που μπορούν να κερδίσουν.
   long possible_winners = 0;
   for (long i = 1; i <= M; ++i) {
      if (max_val == cnt[i] && max_cnt == 1) ++possible_winners;
      else if (cnt[i] + N - K > max_val) ++possible_winners;
   }
   
   FILE *fo = fopen("voting.out", "w");
   fprintf(fo, "%ld\n", possible_winners);
   fclose(fo);
   
   return 0;
}

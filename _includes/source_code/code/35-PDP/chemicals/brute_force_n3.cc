#include <algorithm>
#include <cstdio>

const size_t MAXN = 1'000'000;
long A[MAXN];

int main() {
   FILE *fi = fopen("chemicals.in", "r");
   long N, K;
   fscanf(fi, "%ld%ld", &N, &K);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &A[i]);
   }
   fclose(fi);
   
   long max_range = 0;
   // Δοκιμάζουμε όλα τα δυνατά διαστήματα [i, j].
   for (long i = 0; i < N; ++i) {
      for (long j = i; j < N; ++j) {
         // Δοκιμάζουμε όλα τα δυνατά ζεύγη (k, j) στο [i, j].
         bool found_pair = false;
         for (long k = i; k < j && !found_pair; ++k) {
            if ((A[k] + A[j]) % K == 0) found_pair = true;
         }
         if (!found_pair) {
            max_range = std::max(max_range, j - i + 1);
         } else {
            // Αν βρούμε ζευγάρι που δεν είναι καλό, τότε βγαίνουμε από το loop.
            break;
         }
      }
   }
   
   FILE *fo = fopen("chemicals.out", "w");
   fprintf(fo, "%ld\n", max_range);
   fclose(fo);
   
   return 0;
}

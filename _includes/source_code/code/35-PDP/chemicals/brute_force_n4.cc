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
         // Δοκιμάζουμε όλα τα δυνατά ζεύγη (k1, k2) στο [i, j].
         bool found_pair = false;
         for (long k1 = i; k1 <= j && !found_pair; ++k1) {
            for (long k2 = k1 + 1; k2 <= j && !found_pair; ++k2) {
               if ((A[k1] + A[k2]) % K == 0) found_pair = true;
            }
         }
         if (!found_pair) {
            max_range = std::max(max_range, j - i + 1);
         }
      }
   }
   
   FILE *fo = fopen("chemicals.out", "w");
   fprintf(fo, "%ld\n", max_range);
   fclose(fo);
   
   return 0;
}

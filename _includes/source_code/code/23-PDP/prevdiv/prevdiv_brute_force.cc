#include <cstdio>

const size_t MAXN = 3'000'000;

long A[MAXN];

int main() {
   long n;
   FILE *fi = fopen("prevdiv.in", "r");
   fscanf(fi, "%ld", &n);
   for (long i = 0; i < n; ++i) {
      fscanf(fi, "%ld", &A[i]);
   }
   fclose(fi);
   long cur_max = A[0];
   for (long i = 1; i < n; ++i) {
      if (A[i] > cur_max) {
         bool found_counterexample = false;
         for (long j = 0; j <= i - 1; ++j){
            if (A[i] % A[j] != 0) {
               found_counterexample = true;
               break;
            }
         }
         if (!found_counterexample) {
            cur_max = A[i];
         }
      }
   }
   FILE *fo = fopen("prevdiv.out", "w");
   fprintf(fo, "%ld\n", cur_max);
   fclose(fo);
   return 0;
}

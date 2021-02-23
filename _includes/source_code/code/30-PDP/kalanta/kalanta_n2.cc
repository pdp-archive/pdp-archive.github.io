#include <algorithm>
#include <stdio.h>

const size_t MAXN = 1'000'000;

long A[MAXN * 2];

int main() {
   long N;
   FILE *fi = fopen("kalanta.in", "r");
   fscanf(fi, "%ld", &N);
   long total = 0;
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &A[i]);
      A[i+N] = A[i];
      total += A[i];
   }
   fclose(fi);
   long min_diff = total;
   for (long i = 0; i < N; ++i) {
      long sum = 0;
      for (long j = i; j < N; ++j) {
         sum += A[j];
         long other_sum = total - sum;
         min_diff = std::min(min_diff, std::abs(sum - other_sum));
      }
   }
   FILE *fo = fopen("kalanta.out", "w");
   fprintf(fo, "%ld\n", min_diff);
   fclose(fo);
   return 0;
}

#include <algorithm>
#include <cstdio>

const long MAXN = 1'000'000;

long A[MAXN];
bool seen[MAXN];

int main() {
   FILE *fi = fopen("efimerides.in", "r");
   long N, K;
   fscanf(fi, "%ld%ld", &N, &K);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &A[i]);
   }
   fclose(fi);
   
   long max_sum = 0;
   for (long i = 0; i < N; ++i) {
      // Ξεκινάμε μία διαδρομή από το i, αν δεν το έχουμε ξαναεπισκεφτεί.
      if (seen[i]) continue;
      long sum = 0, j = i;
      do {
         sum += A[j];
         j = (j + K) % N;
         seen[j] = true;
      } while(j != i);
      max_sum = std::max(max_sum, sum);
   }
   
   FILE *fo = fopen("efimerides.out", "w");
   fprintf(fo, "%ld\n", max_sum);
   fclose(fo);
   return 0;
}

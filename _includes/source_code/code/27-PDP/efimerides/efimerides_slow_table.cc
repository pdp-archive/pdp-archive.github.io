#include <algorithm>
#include <cstdio>
#include <unordered_set>

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
      long sum = 0, j = i;
      while (!seen[j]) {
         seen[j] = true;
         sum += A[j];
         j = (j + K) % N;
      }
      // Καθαρίζουμε τον πίνακα seen.
      j = i;
      while (seen[j]) {
         seen[j] = false;
         j = (j + K) % N;
      }
      max_sum = std::max(max_sum, sum);
   }
   
   FILE *fo = fopen("efimerides.out", "w");
   fprintf(fo, "%ld\n", max_sum);
   fclose(fo);
   return 0;
}

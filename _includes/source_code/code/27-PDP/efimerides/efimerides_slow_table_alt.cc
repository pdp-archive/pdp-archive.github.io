#include <algorithm>
#include <cstdio>
#include <unordered_set>

const long MAXN = 1'000'000;

long A[MAXN];
long last_seen_with[MAXN];

int main() {
   FILE *fi = fopen("efimerides.in", "r");
   long N, K;
   fscanf(fi, "%ld%ld", &N, &K);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &A[i]);
   }
   fclose(fi);
   
   std::fill(last_seen_with, last_seen_with + N, -1);
   long max_sum = 0;
   for (long i = 0; i < N; ++i) {
      long sum = 0, j = i;
      while (last_seen_with[j] != i) {
         last_seen_with[j] = i;
         sum += A[j];
         j = (j + K) % N;
      }
      max_sum = std::max(max_sum, sum);
   }
   
   FILE *fo = fopen("efimerides.out", "w");
   fprintf(fo, "%ld\n", max_sum);
   fclose(fo);
   return 0;
}

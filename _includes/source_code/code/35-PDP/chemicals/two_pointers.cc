#include <algorithm>
#include <cstdio>
#include <unordered_map>

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
   std::unordered_map<long, long> modula;
   long left = 0;
   for (long i = 0; i < N; ++i) {
      long target = (K - (A[i] % K) ) % K;
      while (modula[target] > 0) {
         --modula[A[left] % K];
         ++left;
      }
      ++modula[A[i] % K];
      max_range = std::max(max_range, i - left + 1);
   }
   
   FILE *fo = fopen("chemicals.out", "w");
   fprintf(fo, "%ld\n", max_range);
   fclose(fo);
   
   return 0;
}

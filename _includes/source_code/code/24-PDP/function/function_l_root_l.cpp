#include <algorithm>
#include <stdio.h>

bool isPrime(long k) {
   if (k == 1 || k == 2) return false;
   for (long i = 2; i * i <= k; ++i) {
      if (k % i == 0) return false;
   }
   return true;
}

int main() {
   long N, M;
   FILE *fi = fopen("function.in", "r");
   fscanf(fi, "%ld%ld\n", &N, &M);
   fclose(fi);
   
   if (N > M) std::swap(N, M);
   
   FILE *fo = fopen("function.out", "w");
   bool is_first = true;
   for (long k = N + 1; k < M; ++k) {
      if (isPrime(k)) {
         if (!is_first) fprintf(fo, " ");
         fprintf(fo, "%ld", k);
         is_first = false;
      }
   }
   if (!is_first) {
      fprintf(fo, "\n");
   }
   fclose(fo);
   return 0;
}

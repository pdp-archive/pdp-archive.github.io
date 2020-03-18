#include <algorithm>
#include <stdio.h>

const size_t MAXM = 10000;

bool isNotPrime[MAXM];

int main() {
   long N, M;
   FILE *fi = fopen("function.in", "r");
   fscanf(fi, "%ld%ld\n", &N, &M);
   fclose(fi);
   
   if (N > M) std::swap(N, M);

   isNotPrime[0] = isNotPrime[1] = true;
   for (long k = 2; k < M; ++k) {
      if (isNotPrime[k]) continue; 
      for (long i = 2; i * k <= M; ++i) {
         isNotPrime[i * k] = true;
      }
   }
   isNotPrime[2] = true;
   
   FILE *fo = fopen("function.out", "w");
   bool is_first = true;
   for (long k = N + 1; k < M; ++k) {
      if (!isNotPrime[k]) {
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

#include <algorithm>
#include <stdio.h> 
#include <stdlib.h>

const size_t MAXN = 1000000;

long a[MAXN];
long N, M, C;

long findMaxDiffInInterval(long st, long en) {
   long max_val = a[st], min_val = a[st];
   for (long i = st; i < en; ++i) {
      max_val = std::max(max_val, a[i]);
      min_val = std::min(min_val, a[i]);
   }
   return max_val - min_val;
}


int main() { 
   FILE *fi = fopen("sound.in", "r");
   fscanf(fi, "%ld%ld%ld", &N, &M, &C);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
   }
   fclose(fi);
   
   FILE *fo = fopen("sound.out", "w");
   bool found = false;
   for (long i = 0; i + M <= N; ++i) {
      long diff = findMaxDiffInInterval(i, i + M);
      if (diff <= C) {
         fprintf(fo, "%ld\n", i + 1);
         found = true;
      }
   }
   if (!found) {
      fprintf(fo, "NULL\n");
   }

   fclose(fo);
   return 0;
}

#include <stdio.h>

const size_t MAXL = 1000;

long M[MAXL];
long K[5];

int main() {
   long L, N; 
   FILE *fi = fopen("astrolavos.in", "r");
   fscanf(fi, "%ld", &L);
   for (long i = 0; i < L; ++i) {
      fscanf(fi, "%ld", &M[i]);
   }
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < 5; ++i) {
      fscanf(fi, "%ld", &K[i]);
   }
   fclose(fi);
   
   FILE *fo = fopen("astrolavos.out", "w");
   for (long i = 0; i < 5; ++i) {
      double ans = N * double(M[0]) /double(M[K[i]-1]);
      if (i > 0) fprintf(fo, " ");
      fprintf(fo, "%.3lf", ans);
   }
   fprintf(fo, "\n");
   fclose(fo);
   return 0;
}
 

#include <cstdio>

typedef long long ll;

int main() {
   long n;
   FILE *fi1 = fopen("prevdiv.in", "r");
   FILE *fi2 = fopen("prevdiv.in", "r");
   fscanf(fi1, "%ld", &n);
   fscanf(fi2, "%ld", &n);
   long cur_max;
   fscanf(fi1, "%ld", &cur_max);
   long A_tested_up_to;
   fscanf(fi2, "%ld", &A_tested_up_to);
   long tested_up_to = 0;
   for (long i = 1; i < n; ++i) {
      long A_i;
      fscanf(fi1, "%ld", &A_i);
      if (A_i > cur_max) {
         while (tested_up_to < i) {
            if (A_i % A_tested_up_to != 0) break;
            fscanf(fi2, "%ld", &A_tested_up_to);
            ++tested_up_to;
         }
         if (tested_up_to == i) cur_max = A_i;
      }
   }
   fclose(fi1);
   fclose(fi2);
   FILE *fo = fopen("prevdiv.out", "w");
   fprintf(fo, "%ld\n", cur_max);
   fclose(fo);
   return 0;
}

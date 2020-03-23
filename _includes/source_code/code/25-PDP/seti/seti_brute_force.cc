#include <stdio.h>

const size_t MAXN = 10000;
typedef long long ll;

long A[MAXN];
bool forms_triplet[MAXN];

int main() {
   long N;
   FILE *fi = fopen("seti.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &A[i]);
   }
   fclose(fi);
   
   ll total = 0;
   for (long center = 0; center < N; ++center) {
      long x = 1;
      while (center - x >= 0 && center + x < N) {
         if (A[center - x] == A[center + x] && A[center - x] * 2 < A[center]) {
            ++total;
            forms_triplet[center] = true;
            break;
         }
         ++x;
      }
   }
   
   FILE *fo = fopen("seti.out", "w");
   fprintf(fo, "%lld\n", total);
   for (long i = 0; i < N; ++i) {
      if (forms_triplet[i]) {
         fprintf(fo, "%ld\n", i + 1); 
      }
   }
   fclose(fo);
   
   return 0;
}
      

#include <algorithm>
#include <cstdio>

const long MAXN = 100'000;

double A[MAXN];

int main() {
   FILE *fi = fopen("ensemble.in", "r");
   long N, K;
   fscanf(fi, "%ld %ld", &N, &K);
  
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%lf", &A[i]);
   }
  
   std::sort(A, A+N);
  
   double sum1 = 0.0;
   double sum2 = 0.0;
  
   for (long i = 0; i < N; ++i) {
      if (i < K) {
         sum2 += A[K];
      } else if (i > N - K -1) {
         sum2 += A[N-K-1];
      } else {
         sum1 += A[i];
         sum2 += A[i];
      }
   }
   fclose(fi);
  
   FILE *fo = fopen("ensemble.out", "w");
   double av1 = sum1 / double(N - 2 * K);
   double av2 = sum2 / double(N);
   fprintf(fo, "%.2lf %.2lf\n", av1, av2);
   fclose(fo);
   return 0;
}

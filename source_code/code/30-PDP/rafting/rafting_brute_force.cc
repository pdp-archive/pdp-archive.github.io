#include <cstdio>

const size_t MAXN = 500000;

long A[MAXN];

int main() {
   long N;
   FILE *fi = fopen("rafting.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      long rank;
      fscanf(fi, "%ld", &rank);
	  --rank;
	  for (long j = i; j > rank; --j) {
	     A[j] = A[j - 1];
	  }
	  A[rank] = i + 1;
   }
   fclose(fi);
   
   FILE *fo = fopen("rafting.out", "w");
   for (long i = 0; i < N; ++i) {
      fprintf(fo, "%ld", A[i]);
	  if (i < N - 1) fprintf(fo, " ");
   }
   fprintf(fo, "\n");
   fclose(fo);
   return 0;
}

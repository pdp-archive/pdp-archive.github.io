#include <cstdio>

const size_t MAXN = 1024;
const size_t MAXM = 65536;

char A[MAXN];
char B[MAXM];

int main() {
   long N, M;
   FILE *fi = fopen("matrix.in", "r");
   fscanf(fi, "%ld\n", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%c", &A[i]);
   }
   fscanf(fi, "\n");
   fscanf(fi, "%ld\n", &M);
   for (long i = 0; i < M; ++i) {
      fscanf(fi, "%c", &B[i]);
   }
   long found_pos = -1;
   for (long i = 0; i <= M - N; ++i) {
      bool found_different = false;
      for (long j = 0; j < N; ++j) {
         if (B[i + j] != A[j]) {
            found_different = true;
            break;
         }
      }
      if (!found_different) {
         found_pos = i + 1;
         break;
      }
   }
   FILE *fo = fopen("matrix.out", "w");
   if (found_pos == -1) fprintf(fo, "F\n");
   else fprintf(fo, "%ld\n", found_pos);
   return 0;
}

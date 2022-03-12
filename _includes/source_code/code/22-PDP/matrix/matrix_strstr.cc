#include <cstdio>
#include <cstring>

const size_t MAXN = 1024;
const size_t MAXM = 65536;

char A[MAXN];
char B[MAXM];

int main() {
   long N, M;
   FILE *fi = fopen("matrix.in", "r");
   fscanf(fi, "%ld\n", &N);
   for (long i = 0; i < N; ++i) {
      A[i] = fgetc(fi);
   }
   
   fscanf(fi, "%ld\n", &M);
   for (long i = 0; i < M; ++i) {
      B[i] = fgetc(fi);
   }
   char* ptr = strstr(B, A);
   
   FILE *fo = fopen("matrix.out", "w");
   if (ptr == NULL) fprintf(fo, "F\n");
   else fprintf(fo, "%ld\n", long(ptr - B + 1));
   return 0;
}

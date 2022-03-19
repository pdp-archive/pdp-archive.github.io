#include <algorithm>
#include <cstdio>

const size_t MAXN = 1024;
const size_t MAXM = 65536;

typedef long long ll;

char A[MAXN+1];
char B[MAXM+1];
// Η failure function του αλγόριθμου KMP.
long F[MAXN+1];

int main() {
   long N, M;
   FILE *fi = fopen("matrix.in", "r");
   fscanf(fi, "%ld\n", &N);
   for (long i = 1; i <= N; ++i) {
      A[i] = fgetc(fi);
   }
   
   fscanf(fi, "%ld\n", &M);
   for (long i = 1; i <= M; ++i) {
      B[i] = fgetc(fi);
   }
   
   // Υπολογισμός της failure function.
   F[0] = -1;
   long k = -1;
   for(long i = 1; i <= N; i++) {
      while(k >= 0 && A[k+1] != A[i]) k = F[k];
      F[i] = ++k;
   }
   
   // Εύρεση συμβολοσειράς.
   long found_pos = -1;
   k = 0;
   for(long i = 1; i <= M; i++) {
      while(k >= 0 && A[k+1] != B[i]) k = F[k];
      k++;
      if(k == N) {
         found_pos = i - N + 1;
         break;
      }
   }

   FILE *fo = fopen("matrix.out", "w");
   if (found_pos == -1) fprintf(fo, "F\n");
   else fprintf(fo, "%ld\n", found_pos);
   return 0;
}

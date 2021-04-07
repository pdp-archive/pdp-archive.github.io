#include <algorithm>
#include <cstdio>

const size_t MAXN = 1000000;

char A[MAXN + 2];
char B[MAXN + 2];

long N;

bool checkEqualPrefix(long L) {
   for (long i = 1; i < L; ++i) {
      if (A[i] != B[i]) return false;
   }
   return true;
}

bool checkEqualSuffix(long M) {
   for (long i = M + 1; i <= N; ++i) {
      if (A[i] != B[i]) return false;
   }
   return true;
}

bool checkReversedMiddleStrings(long L, long M) {
   for (long i = L; i <= M; ++i) {
      if (A[i] != B[M+L-i]) return false;
   }
   return true;
}

int main() {
   FILE *fi = fopen("dnaseq.in", "r");
   fscanf(fi, "%ld\n", &N);
   fgets(A + 1, N + 2, fi);
   fgets(B + 1, N + 2, fi);

   long min_diff = N + 1;
   for (long L = 1; L <= N; ++L) {
      for (long M = L; M <= N; ++M) {
         if (checkEqualPrefix(L) && checkEqualSuffix(M)
           && checkReversedMiddleStrings(L, M)) {
            min_diff = std::min(min_diff, M - L);
         }
      }
   }
   fclose(fi);
  
   FILE *fo = fopen("dnaseq.out", "w");
   if (min_diff == N + 1) fprintf(fo, "no\n");
   else fprintf(fo, "%ld\n", min_diff);
   fclose(fo);
   return 0;
}

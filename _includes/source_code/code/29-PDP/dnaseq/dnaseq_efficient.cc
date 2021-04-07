#include <algorithm>
#include <cstdio>

const size_t MAXN = 1000000;

char A[MAXN + 2];
char B[MAXN + 2];

long N;

long findLongestCommonPrefix() { 
   long L = 1;
   while (L <= N) {
      if (A[L] != B[L]) return L;
      ++L;
   }
   return N+1;
}

long findLongestCommonSuffix() {
   long M = N;
   while (M >= 1) {
      if (A[M] != B[M]) return M;
      --M;
   }
   return 1;
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
   fclose(fi);
  
   long L = findLongestCommonPrefix();
   long M = findLongestCommonSuffix();

   FILE *fo = fopen("dnaseq.out", "w");
   if (L > M) fprintf(fo, "0\n");
   else if (checkReversedMiddleStrings(L, M)) fprintf(fo, "%ld\n", M - L);
   else fprintf(fo, "no\n");
   fclose(fo);
   return 0;
}

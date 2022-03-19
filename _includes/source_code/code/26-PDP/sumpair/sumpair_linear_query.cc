#include <algorithm>
#include <cstdio>

const size_t MAXN = 1'000'000;

long A[MAXN];
long N, Q;

bool doesPairExist(long target) {
   long lo = 0, hi = N - 1;
   while (lo < hi) {
      long sum = A[lo] + A[hi];
      if (sum == target) return true;
      else if (sum > target) --hi;
      else ++lo;
   }
   return false;
}

int main() {
   FILE *fi = fopen("sumpair.in", "r");
   fscanf(fi, "%ld %ld", &N, &Q);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &A[i]);
   }
   std::sort(A, A+N);
   FILE *fo = fopen("sumpair.out", "w");
   for (long j = 0; j < Q; ++j) {
      long target;
      fscanf(fi, "%ld", &target);
      fprintf(fo, "%s\n", doesPairExist(target) ? "true" : "false");
   }
   return 0;
}

#include <cstdio>

typedef long long ll;

/* Ελέγχουμε αν η αναπαράσταση του M στη βάση K έχει μόνο ένα ψηφίο. */
bool checkRepresentationHasSingleDigit(ll M, ll k) {
   ll prev_digit = -1;
   while (M > 0) {
      ll current_digit = M % k;
      if (prev_digit != -1 && prev_digit != current_digit) {
         return false;
      }
      prev_digit = current_digit;
      M /= k;
   }
   return true;
}

ll solve(ll M) {
   for (ll k = 2; k < M; ++k) {
      if (checkRepresentationHasSingleDigit(M, k)) {
         return k;
      }
   }
   return M + 1;
}

int main() {
   FILE *fi = fopen("numbase.in", "r");
   long N;
   fscanf(fi, "%ld", &N);
   FILE *fo = fopen("numbase.out", "w");
   for (long test_case = 0; test_case < N; ++test_case) {
      ll M;
      fscanf(fi, "%lld", &M);
      fprintf(fo, "%lld\n", solve(M));
   }
   fclose(fi);
   fclose(fo);
   return 0;
}

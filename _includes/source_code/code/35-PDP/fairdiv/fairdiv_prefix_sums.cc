#include <cstdio>
#include <vector>

long N;
std::vector<int> A;
// S[0] = 0
// S[i] = a0 + ... + a_{i-1}
std::vector<long> S;

// Υπολογίζουμε το άθροισμα a_i + ... + a_j.
long compute_sum(long i, long j) {
   if (j < i) return 0;
   return S[j+1] - S[i];
}

int main() {
   FILE *fi = fopen("fairdiv.in", "r");
   fscanf(fi, "%ld", &N);
   A = std::vector<int>(N);
   S = std::vector<long>(N+1);
   S[0] = 0;
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%d", &A[i]);
      S[i+1] = S[i] + A[i];
   }
   fclose(fi);
   
   // Δοκιμάζουμε όλες τις δυνατές μοιρασιές.
   long opt_A = 0, opt_B = 0, opt_C = 0;
   for (long iA = 0; iA < N; ++iA) {
      for (long iB = iA; iB < N; ++iB) {
         long sum_A = compute_sum(0, iA); 
         long sum_B = compute_sum(iA + 1, iB);
         long sum_C = compute_sum(iB + 1, N - 1);
         if (sum_A >= sum_B && sum_B >= sum_C) {
            if (sum_C > opt_C || (sum_C == opt_C && sum_B >= opt_B)) {
               opt_A = sum_A;
               opt_B = sum_B;
               opt_C = sum_C;
            }
         }
      }
   }
   
   FILE *fo = fopen("fairdiv.out", "w");
   fprintf(fo, "%ld %ld %ld\n", opt_A, opt_B, opt_C);
   fclose(fo);
   return 0;
}

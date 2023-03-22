#include <cstdio>
#include <vector>

long N;
std::vector<int> A;
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
   A = std::vector<int>(N+1);
   A[N] = 0;
   S = std::vector<long>(N+1);
   long sum = 0;
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%d", &A[i]);
      sum += A[i];
   }
   fclose(fi);
   
   long iB = N, sum_A = sum, sum_B = 0, sum_C = 0;
   long opt_A = sum, opt_B = 0, opt_C = 0;
   
   // Βρίσκουμε την καλύτερη μοιρασιά αν έχουμε δώσει 
   // τα στοχεία a_0, ... , a_{iA} στον A. 
   for (long iA = N - 2; iA >= 0; --iA) {
      sum_A -= A[iA + 1];
      sum_B += A[iA + 1];
      while (iB > iA + 1 && sum_B - A[iB]  >= sum_C + A[iB]) {
         sum_B -= A[iB];
         sum_C += A[iB];
         --iB;
      }
      
      // Ελέγχουμε αν η τωρινή λύση είναι η καλύτερη.
      if (sum_A >= sum_B && sum_B >= sum_C) {
         if (sum_C > opt_C || (sum_C == opt_C && sum_B >= opt_B)) {
            opt_A = sum_A;
            opt_B = sum_B;
            opt_C = sum_C;
         }
      }
   }
   
   FILE *fo = fopen("fairdiv.out", "w");
   fprintf(fo, "%ld %ld %ld\n", opt_A, opt_B, opt_C);
   fclose(fo);
   return 0;
}

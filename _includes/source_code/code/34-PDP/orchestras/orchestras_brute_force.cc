#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

const size_t MAXK = 20;
const size_t MAXN = 20;

long N, K;
long v[MAXK][MAXN]; // Οι αμοιβές των μουσικών.

// Τα ελάχιστα/μεγιστα κάθε ορχήστρας μέχρι στιγμής.
long cur_min[MAXK][MAXN], cur_max[MAXK][MAXN];
long best = -1; // Η καλύτερη απόκλιση μέχρι στιγμής.

std::vector<long> initial_permutation; // Τα στοιχεία 0,1,...,Ν-1.

void discover(int k) {
   std::vector<long> cur_permutation = initial_permutation;
   do {
      long mx_diff = -1;
      for (long i = 0; i < N; ++i) {
         // Υπολογίζουμε την ελάχιστη και μέγιστη αμοιβή για κάθε ορχήστρα.
         long group = cur_permutation[i];
         cur_min[k][group] = std::min(cur_min[k-1][group], v[k][i]);
         cur_max[k][group] = std::max(cur_max[k-1][group], v[k][i]);
         
         // Υπολογίζουμε την απόκλιση για την ορχήστρα.
         long group_diff = cur_max[k][group] - cur_min[k][group];
         if (mx_diff == -1 || group_diff > mx_diff) mx_diff = group_diff;
      }
      // Αν η τωρινή απόκλιση είναι μεγαλύτερη από την καλύτερη, 
      // τότε σταματάμε (γιατί δεν πρόκειται να μικρύνει).
      if (mx_diff < best || best == -1) {
         // Αν είμαστε στο τελευταίο όργανο ανανεώνουμε το καλύτερο.
         if (k == K - 1) best = mx_diff;
         else discover(k + 1);
      }
   } while (next_permutation(cur_permutation.begin(), cur_permutation.end()));
}

int main() {
   FILE *fi = fopen("orchestras.in", "r");
   fscanf(fi, "%ld %ld\n", &N, &K);
   
   for (long i = 0; i < K; ++i) {
      for (long j = 0; j < N; ++j) {
         fscanf(fi, "%ld", &v[i][j]);
      }
   }
   fclose(fi);

   // Το πρώτο μέλος κάθε ορχήστρας έχετε από την πρώτη
   // ομάδα οργάνων.
   for (long i = 0; i < N; ++i) {
      initial_permutation.push_back(i);
      cur_min[0][i] = cur_max[0][i] = v[0][i];
   }
   discover(1);
   
   FILE *fo = fopen("orchestras.out", "w");
   fprintf(fo, "%ld\n", best);
   fclose(fo);
   return 0;
}

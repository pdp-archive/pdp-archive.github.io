#include <algorithm>
#include <stdio.h>

const size_t MAXN = 1'000'000;

long A[MAXN * 2 + 2];
long prefix_sum[MAXN * 2 + 2];

int main() {
   long N;
   FILE *fi = fopen("kalanta.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 1; i <= N; ++i) {
      fscanf(fi, "%ld", &A[i]);
      A[i+N] = A[i];
   }
   fclose(fi);
   
   // Υπολογισμός των prefix sums.
   for (long i = 1; i <= 2 * N; ++i) {
      prefix_sum[i] = A[i] + prefix_sum[i - 1];
   }
   
   long total = prefix_sum[N];
   long min_diff = total;
   long target = total / 2;
   // Βρίσκουμε το μεγαλύτερο άθροισμα (μικρότερο ή ίσο από total/2)
   // για κάθε δυνατή αρχή i.
   for (long i = 1; i <= N; ++i) {
      // Δυαδική αναζήτηση στην απάντηση.
      long st = i, en = i + N -1;
      while (st < en) {
         long md = (st + en + 1) / 2;
         long sum = prefix_sum[md] - prefix_sum[i - 1];
         if (sum > target) en = md - 1;
         else st = md;
      }
      // Υπολογίζουμε τη διαφορά.
      long sum = prefix_sum[st] - prefix_sum[i - 1];
      long other_sum = total - sum;
      min_diff = std::min(min_diff, std::abs(sum - other_sum));
   }
   
   FILE *fo = fopen("kalanta.out", "w");
   fprintf(fo, "%ld\n", min_diff);
   fclose(fo);
   return 0;
}

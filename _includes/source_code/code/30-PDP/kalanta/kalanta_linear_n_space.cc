#include <algorithm>
#include <stdio.h>

const size_t MAXN = 1'000'000;

long a[MAXN + 1];
long N;

long A(long i) {
   if (i <= N) return a[i];
   return a[i - N];
}   

int main() {
   FILE *fi = fopen("kalanta.in", "r");
   fscanf(fi, "%ld", &N);
   long total = 0;
   for (long i = 1; i <= N; ++i) {
      fscanf(fi, "%ld", &a[i]);
      total += a[i];
   }
   fclose(fi);
   
   long min_diff = total;
   long target = total / 2;
   long j = 1;
   long sum = 0;
   // Βρίσκουμε το μεγαλύτερο άθροισμα (μικρότερο ή ίσο από total/2)
   // για κάθε δυνατή αρχή i.
   for (long i = 1; i <= N; ++i) {
      sum -= A(i - 1);
      // Το j μπορεί να αυξηθεί το πολύ 2N φορές.
      while (j < i + N && sum + A(j) <= target) {
         sum += A(j);
         ++j;
      }         
      long other_sum = total - sum;
      min_diff = std::min(min_diff, std::abs(sum - other_sum));
   }
   
   FILE *fo = fopen("kalanta.out", "w");
   fprintf(fo, "%ld\n", min_diff);
   fclose(fo);
   return 0;
}

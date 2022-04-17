#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
   long N, K, tmp;
   FILE *fi = fopen("orchestras.in", "r");
   fscanf(fi, "%ld %ld\n", &N, &K);
   std::vector<long> a, b;
   for (long j = 0; j < N; ++j) {
      fscanf(fi, "%ld", &tmp);
      a.push_back(tmp);
   }
   for (long j = 0; j < N; ++j) {
      fscanf(fi, "%ld", &tmp);
      b.push_back(tmp);
   }
   fclose(fi);
   
   // Ταξινομούμε τους παίχτες κάθε οργάνου.
   std::sort(a.begin(), a.end());
   std::sort(b.begin(), b.end());
   
   // Βρίσκουμε τη μέγιστη απόκλιση από τις ορχήστρες
   // που δημιουργήσαμε.
   long ans = std::abs(a[0] - b[0]);
   for (long j = 0; j < N; ++j) {
      ans = std::max(ans, std::abs(a[j] - b[j]));
   }
   
   FILE *fo = fopen("orchestras.out", "w");
   fprintf(fo, "%ld\n", ans);
   fclose(fo);
   return 0;
}

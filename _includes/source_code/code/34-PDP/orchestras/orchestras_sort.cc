#include <algorithm>
#include <cstdio>
#include <vector>

const size_t MAXA = 1'000'000;

int main() {
   long N, K;
   FILE *fi = fopen("orchestras.in", "r");
   fscanf(fi, "%ld %ld\n", &N, &K);
   std::vector<long> v[K];
   for (long i = 0; i < K; ++i) {
      for (long j = 0; j < N; ++j) {
         long tmp;
         fscanf(fi, "%ld", &tmp);
         v[i].push_back(tmp);
      }
      // Ταξινομούμε τους παίχτες του ίδιου οργάνου.
      std::sort(v[i].begin(), v[i].end());
   }
   fclose(fi);
   
   long ans = -1;
   for (long j = 0; j < N; ++j) {
      // Βρίσκουμε για κάθε ορχήστρα την απόκλιση.
      long cur_min = MAXA, cur_max = -1;
      for (long i = 0; i < K; ++i) {
         if (v[i][j] < cur_min) cur_min = v[i][j];
         if (v[i][j] > cur_max) cur_max = v[i][j];
      }
      long diff = cur_max - cur_min;
      if (ans < diff) ans = diff;
   }
   
   FILE *fo = fopen("orchestras.out", "w");
   fprintf(fo, "%ld\n", ans);
   fclose(fo);
   return 0;
}

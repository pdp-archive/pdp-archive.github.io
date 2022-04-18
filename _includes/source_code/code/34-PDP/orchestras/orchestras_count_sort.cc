#include <algorithm>
#include <cstdio>
#include <list>
#include <vector>

const size_t MAXA = 1'000'001;

std::list<int> cnt_arr[MAXA];

int main() {
   long N, K;
   FILE *fi = fopen("orchestras.in", "r");
   fscanf(fi, "%ld %ld\n", &N, &K);
   for (long i = 0; i < K; ++i) {
      for (long j = 0; j < N; ++j) {
         long tmp;
         fscanf(fi, "%ld", &tmp);
         // Κρατάμε για κάθε αμοιβή το όργανο i. 
         cnt_arr[tmp].push_back(i);
      }
   }
   fclose(fi);
   
   // Κάνουμε την ταξινόμηση με counting sort.
   // Ταξινομούμε όλους τους K πίνακες ταυτόχρονα
   // και έτσι χρειάζεται O(NK + Α) χρόνος αντί για
   // O(NKA).
   std::vector<long> v[K];
   for (long i = 0; i < MAXA; ++i) {
      for (auto val : cnt_arr[i]) {
         v[val].push_back(i);
      }
   }
   
   long ans = -1;
   for (long j = 0; j < N; ++j) {
      // Βρίσκουμε την απόκλιση για κάθε ορχήστρα.
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

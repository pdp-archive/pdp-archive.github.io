#include <algorithm>
#include <cstdio>

typedef long long ll;

const size_t MAXN = 1000000;

// Οι κορυφές των βουνών, το ύψος και η θέση στον πίνακα.
struct Peak {
   long idx;
   ll v;

   // Υλοποίηση της σύγκρισης κατά ύψος και αν είναι ίσα τα ύψη, 
   // τότε κατά index.
   bool operator<(const Peak& other) const {
      if (v == other.v) return idx < other.idx;
      return v < other.v;
   }

} a[MAXN];

int main () {
   long N;
   FILE *fi = fopen("skitrip.in", "r");
   fscanf(fi, "%ld", &N);
   ll val;
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%lld", &val);
      a[i] = {i, val};
   }
   fclose(fi);
   
   std::sort(a, a + N);
   
   long min_idx = a[0].idx;
   long max_length = 0;
   for (long i = 1; i < N; ++i) {
      max_length = std::max(max_length, a[i].idx - min_idx);
      min_idx = std::min(min_idx, a[i].idx);
   }
   
   FILE *fo = fopen("skitrip.out", "w");
   fprintf(fo, "%ld\n", max_length);
   return 0;
}


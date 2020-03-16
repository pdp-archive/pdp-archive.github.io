#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 2 * 1000000;

struct Peak {
   long idx;
   ll v;
};

ll a[MAXN];

int main () {
   long N;
   FILE *fi = fopen("skitrip.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
   }
   fclose(fi);
   
   // Βρίσκουμε όλα τα πιθανά δεξιά τέλη του μέγιστου
   // διαστήματος.
   std::vector<Peak> right;
   right.push_back({ N-1, a[N-1] });
   for (long i = N-2; i >= 0; --i) {
      if (right.back().v < a[i]) {
         right.push_back({ i, a[i] });
      }
   }
   
   ll min_value = a[0] + 1;
   long max_length = 0;
   long right_idx = right.size() - 1;
   for (long i = 0; i < N; ++i) {
      // Για κάθε πιθανό αριστερό τέλος, βρίσκουμε το μικρότερο
      // δεξί τέλος που είναι μεγαλύτερο.
      if (min_value > a[i]) {
         while (right_idx > 0 && right[right_idx - 1].v >= a[i]) --right_idx;
         max_length = std::max(max_length, right[right_idx].idx - i);
         min_value = a[i];
      }
   }
   FILE *fo = fopen("skitrip.out", "w");
   fprintf(fo, "%ld\n",max_length);
   fclose(fo);
   
   return 0;
}

#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

const int MAXM = 10'000;

long count[MAXM];

int main() {
   int M, N, K;
   FILE *fi = fopen("servers.in", "r");
   fscanf(fi, "%d%d%d", &M, &N, &K);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         int x, y;
         fscanf(fi, "%d%d", &x, &y);
         count[x] += y;
      }
   }
   std::vector<std::pair<long, int>> vec;
   for (int i = 0; i < M; ++i) {
      vec.push_back({ count[i], i });
   }
   // Ταξινομούμε τα ζευγάρια κατά το count τους και τυπώνουμε
   // τα Κ μεγαλύτερα.
   std::sort(vec.begin(), vec.end(), std::greater<std::pair<long, int>>());
   
   FILE *fo = fopen("servers.out", "w");
   for (int i = 0; i < K; ++i) {
      fprintf(fo, "%d %ld\n", vec[i].second, vec[i].first);
   }
   fclose(fo);
   
   return 0;
}

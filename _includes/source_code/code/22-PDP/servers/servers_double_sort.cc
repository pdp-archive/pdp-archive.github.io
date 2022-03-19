#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>


int main() {
   int M, N, K;
   FILE *fi = fopen("servers.in", "r");
   fscanf(fi, "%d%d%d", &M, &N, &K);
   std::vector<std::pair<int, int>> pairs;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         int x, y;
         fscanf(fi, "%d%d", &x, &y);
         pairs.push_back({ x, y });
      }
   }
   fclose(fi);
   
   // Ταξινομούμε τα ζευγάρια, ώστε αυτά που αναφέρονται στην
   // ίδια σελίδα να είναι το ένα δίπλα στο άλλο.
   std::sort(pairs.begin(), pairs.end());
   
   std::vector<std::pair<long, int>> vec;
   // Ενώμουμε τους μετρητές που αφορούν την ίδια σελίδα.
   int prev_id = -1;
   long cur_sum = 0;
   for (auto [cur_id, cur_count] : pairs) {
      if (cur_id == prev_id) { 
         cur_sum += cur_count;
      } else {
         // Τελειώσαμε με το μέτρημα του prev_id και ξεκινάμε
         // να μετράμε για το cur_sum.
         if (prev_id != -1) {
            vec.push_back({ cur_sum, prev_id });
         }
         cur_sum = cur_count;
         prev_id = cur_id;
      }
   }
   vec.push_back({ cur_sum, prev_id });
   
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

#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

std::vector<int> left, right;

ll M; 
ll cur_best = 0;

void find_best() {
   ll cur_dist = 0;
   ll cur_fish = 0;
   ll prev = 0;
   for (int i = 0; i < right.size(); ++i) {
      cur_dist += right[i] - prev;
      prev = right[i];
      cur_fish += i > 0 ? (M - cur_dist) : 0;
      cur_best = std::max(cur_best, cur_fish);
      
      // Δοκιμάζουμε να κάνουμε στροφή εδώ προς τα αριστερά.
      ll new_cur_dist = cur_dist, new_cur_fish = cur_fish, 
         new_prev = -right[i];
      for (int j = 1; j < left.size(); ++j) {
         new_cur_dist += left[j] - new_prev;
         new_prev = left[j];
         new_cur_fish += (M - new_cur_dist);
         cur_best = std::max(cur_best, new_cur_fish);
      }
   }
}

int main() {
   FILE *fi = fopen("fishboats.in", "r");
   int N;
   fscanf(fi, "%d%lld", &N, &M);
   
   right.push_back(0);
   left.push_back(0);
   for (int i = 0; i < N; ++i) {
      int tmp;
      fscanf(fi, "%d", &tmp);
      if (tmp < 0) left.push_back(-tmp);
      else right.push_back(tmp);
   }
   fclose(fi);
   std::sort(left.begin(), left.end());
   std::sort(right.begin(), right.end());

   find_best();
   // Δοκιμάζουμε και από την άλλη κατεύθυνση.
   std::swap(right, left);
   find_best();

   FILE *fo = fopen("fishboats.out", "w");
   fprintf(fo, "%lld\n", cur_best);
   fclose(fo);
   return 0;
}

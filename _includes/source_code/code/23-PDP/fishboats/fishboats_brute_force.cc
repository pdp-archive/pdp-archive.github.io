#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

std::vector<int> left, right;

ll M; 
ll cur_best = 0; // Η καλύτερη λύση μέχρι στιγμής.

/* Ψάχνουμε για την καλύτερη λύση όταν έχουμε ήδη επισκεφθεί τις i αριστερές βάρκες
   και τις j δεξιές. 
   Αν is_left==true, τότε είμαστε στην i διαφορετικά είμαστε στην j. 
   Η dist είναι ο χρόνος που έχει περάσει μέχρι τώρα και total_fish είναι τα ψάρια που 
   έχουμε μαζέψει μέχρι στιγμής.*/
void explore(int i, int j, bool is_left, ll dist, ll total_fish) {
   cur_best = std::max(cur_best, total_fish);
   // Περίπτωση 1η: Πηγαίνουμε στην αριστερή βάρκα i+1.
   if (i+1 < left.size()) {
      ll new_dist = dist + (is_left ? (left[i+1]-left[i]) : (left[i+1]+right[j]));
      explore(i + 1, j, true, new_dist, total_fish + (M - new_dist));
   }
   // Περίπτωση 2η: Πηγαίνουμε στη δεξιά βάρκα j+1.
   if (j+1 < right.size()) {
      ll new_dist = dist + (!is_left ? (right[j+1]-right[j]) : (right[j+1]+left[i]));
      explore(i, j + 1, false, new_dist, total_fish + (M - new_dist));
   }
}
 

int main() {
   FILE *fi = fopen("fishboats.in", "r");
   int N;
   fscanf(fi, "%d%lld", &N, &M);
   
   // Χωρίζουμε τις συντεταγμένες σε αρνητικές και θετικές.
   left.push_back(0);
   right.push_back(0);
   for (int i = 0; i < N; ++i) {
      int tmp;
      fscanf(fi, "%d", &tmp);
      if (tmp < 0) left.push_back(-tmp);
      else right.push_back(tmp);
   }
   fclose(fi);
   
   std::sort(left.begin(), left.end());
   std::sort(right.begin(), right.end());

   explore(0, 0, true, 0, 0);

   FILE *fo = fopen("fishboats.out", "w");
   fprintf(fo, "%lld\n", cur_best);
   fclose(fo);
   
   return 0;
}

#include <algorithm>
#include <set>
#include <stdio.h> 
#include <stdlib.h>

const size_t MAXN = 1000000;

long a[MAXN];
long N, M, C;

struct Item {
   long idx;
   long value;
   Item(long idx, long value) : idx(idx), value(value) { }
   
   bool operator<(const Item& other) const {
      if (value == other.value) return idx < other.idx;
      return value < other.value;
   }
};

std::set<Item> min_set;
std::set<Item> max_set;

long extractMax(long idx) {
   while (max_set.rbegin()->idx < idx - M + 1) max_set.erase(std::prev(max_set.end()));
   return max_set.rbegin()->value;
}

long extractMin(long idx) {
   while (min_set.begin()->idx < idx - M + 1) min_set.erase(min_set.begin());
   return min_set.begin()->value;
}

int main() { 
   FILE *fi = fopen("sound.in", "r");
   fscanf(fi, "%ld%ld%ld", &N, &M, &C);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld", &a[i]);
   }
   fclose(fi);
   
   // Initialise the deques for the first m-1 elements.
   for (long i = 0; i < M - 1; ++i) {
      min_set.insert(Item(i, a[i]));
      max_set.insert(Item(i, a[i]));
   }
   
   FILE *fo = fopen("sound.out", "w");
   bool found = false;
   for (long i = M - 1; i < N; ++i) {
      min_set.insert(Item(i, a[i]));
      max_set.insert(Item(i, a[i]));
      
      if (extractMax(i) - extractMin(i) <= C) {
         found = true;
         fprintf(fo, "%ld\n", i - M + 2);
      }
   }
   
   if (!found) {
      fprintf(fo, "NULL\n");
   }

   fclose(fo);
   return 0;
}

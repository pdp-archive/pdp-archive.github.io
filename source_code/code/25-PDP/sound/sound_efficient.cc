#include <algorithm>
#include <deque>
#include <stdio.h> 
#include <stdlib.h>

const size_t MAXN = 1000000;

long a[MAXN];
long N, M, C;

struct Item {
   long idx;
   long value;
   Item(long idx, long value) : idx(idx), value(value) { }
};

std::deque<Item> min_deque;
std::deque<Item> max_deque;

void insertToDeques(long i, long value) {
   Item item(i, value);
   while (!min_deque.empty() && value <= min_deque.front().value) min_deque.pop_front();
   min_deque.push_front(item);
   while (!max_deque.empty() && value >= max_deque.front().value) max_deque.pop_front();
   max_deque.push_front(item);
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
      insertToDeques(i, a[i]);
   }
   
   FILE *fo = fopen("sound.out", "w");
   bool found = false;
   for (long i = M - 1; i < N; ++i) {
      // Remove old items.
      if (min_deque.back().idx < i - M + 1) min_deque.pop_back();
      if (max_deque.back().idx < i - M + 1) max_deque.pop_back();
      
      insertToDeques(i, a[i]);
      if (max_deque.back().value - min_deque.back().value <= C) {
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

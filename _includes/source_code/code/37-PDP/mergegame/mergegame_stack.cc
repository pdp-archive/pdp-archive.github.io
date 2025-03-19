#include <cstdio>
#include <vector>

int main() {
   FILE *fi = fopen("mergegame.in", "r");
   long S, N;
   fscanf(fi, "%ld%ld", &S, &N);
         
   std::vector<long> st;
   for (long i = 0; i < N; ++i) {
      long cur;
      fscanf(fi, "%ld", &cur);
      while (!st.empty() && st.back() <= cur) {
         if (st.back() == cur)  ++cur;
         st.pop_back();
      }
      st.push_back(cur);
   }
   
   FILE *fo = fopen("mergegame.out", "w");
   fprintf(fo, "%ld\n", st[0]);
   fclose(fo);
   
   return 0;
}


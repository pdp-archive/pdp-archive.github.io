#include <algorithm>
#include <cstdio>

typedef long long ll;

const size_t MAXN = 1000000;

ll a[MAXN];

int main () {
   long N;
   FILE *fi = fopen("skitrip.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%lld", &a[i]);
   }
   fclose(fi);
   
   long mx = 0;
   for (long i = 0; i < N; ++i) {
      for (long j = i + 1; j < N; ++j) {
         if (a[i] <= a[j]) {
            mx = std::max(mx, j - i);
         }
      }
   }
   
   FILE *fo = fopen("skitrip.out", "w");
   fprintf(fo, "%ld\n", mx);
   fclose(fo);
   
   return 0;
}


#include <cstdio>

typedef unsigned long long ull;

const size_t MAXN = 1000000;

ull x[MAXN + 2];
ull lcm_prefix[MAXN + 2];
ull lcm_suffix[MAXN + 2];

ull gcd(ull a, ull b) {
   while (a != 0) {
      ull tmp = a;
      a = b % a;
      b = tmp;
   }
   return b;
}

ull lcm(ull a, ull b) {
   ull g = gcd(a, b);
   return (a/g) * b;
}

int main() {
   long N; 
   FILE *fi = fopen("agora.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 1; i <= N; ++i) {
      fscanf(fi, "%llu", &x[i]);
   }
   fclose(fi);
   
   lcm_prefix[0] = 1;
   for (long i = 1; i <= N; ++i) {
      lcm_prefix[i] = lcm(lcm_prefix[i-1], x[i]);
   }
   
   lcm_suffix[N+1] = 1;
   for (long i = N; i > 0; --i) {
      lcm_suffix[i] = lcm(lcm_suffix[i+1], x[i]);
   }
   
   ull best_value = lcm_suffix[1];
   long best_idx = 0;
   for (long i = 1; i <= N; ++i) {
      ull candidate = lcm(lcm_prefix[i-1], lcm_suffix[i+1]);
      if (candidate < best_value) {
         best_value = candidate;
         best_idx = i;
      }
   }
   
   FILE *fo = fopen("agora.out", "w");
   fprintf(fo, "%llu %ld\n", best_value, best_idx);
   fclose(fo);
   
   return 0;
}

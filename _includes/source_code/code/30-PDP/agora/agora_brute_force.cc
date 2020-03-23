#include <cstdio>

typedef unsigned long long ull;

const size_t MAXN = 1000000;

long N;

ull x[MAXN + 1];

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

ull lcmWithout(long idx) {
   ull temp = 1;
   for (long i = 1; i <= N; ++i) {
      if (i == idx) continue;
      temp = lcm(temp, x[i]);
   }
   return temp;
}

int main() { 
   FILE *fi = fopen("agora.in", "r");
   fscanf(fi, "%ld", &N);
   for (long i = 1; i <= N; ++i) {
      fscanf(fi, "%llu", &x[i]);
   }
   fclose(fi);
   
   ull best_value = lcmWithout(0);
   long best_idx = 0;
   for (long i = 1; i <= N; ++i) {
      ull candidate = lcmWithout(i);
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

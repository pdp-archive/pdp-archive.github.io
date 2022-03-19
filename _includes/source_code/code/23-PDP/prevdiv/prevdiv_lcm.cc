#include <algorithm>
#include <cstdio>

long gcd(long a, long b) {
   if (a == 0) return b;
   return gcd(b % a, a);
}

long lcm(long a, long b) {
   return (a / gcd(a, b)) * b;
}

int main() {
   long n;
   FILE *fi = fopen("prevdiv.in", "r");
   fscanf(fi, "%ld", &n);
   long A_0;
   fscanf(fi, "%ld", &A_0);
   long cur_max = A_0;
   long cur_lcm = A_0;
   long A_i;
   for (long i = 0; i < n; ++i) {
      fscanf(fi, "%ld", &A_i);
      if (A_i % cur_lcm == 0) cur_max = A_i;
      cur_lcm = lcm(cur_lcm, A_i);
   }
   fclose(fi);
   FILE *fo = fopen("prevdiv.out", "w");
   fprintf(fo, "%ld\n", cur_max);
   fclose(fo);
   return 0;
}

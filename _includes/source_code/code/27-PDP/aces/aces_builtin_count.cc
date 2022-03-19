#include <bitset>
#include <cstdio>

int count_bits(long x) {
   return std::bitset<32>(x).count();
}

long cnt[32];

int main() {
   FILE *fi = fopen("aces.in", "r");
   
   long n;
   fscanf(fi, "%ld", &n);
   for (long i = 0; i < n; ++i) {
      long tmp;
      fscanf(fi, "%ld", &tmp);
      ++cnt[count_bits(tmp)];
   }
   
   int max_count = 0;
   for (int i = 0; i < 32; ++i) {
      if (max_count < cnt[i]) max_count = cnt[i];
   }
   fclose(fi);
   
   FILE *fo = fopen("aces.out", "w");
   fprintf(fo, "%ld\n", max_count);
   fclose(fo);
   
   return 0;
}

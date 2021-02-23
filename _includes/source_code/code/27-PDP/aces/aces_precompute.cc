#include <bitset>
#include <cstdio>

int count_bits_slow(long x) {
   int total = 0;
   while (x > 0) {
      total += x & 1;
      x >>= 1;
   }
   return total;
}

int byte_count[256];

void precompute() {
   for (int i = 0; i < 256; ++i) {
      byte_count[i] = count_bits_slow(i);
   }
}

int count_bits(long x) {
   // Το x & 0xFF επιστρέφει το χαμηλότερο byte από τον x. 
   // Τα x >> 8, x >> 16, x >> 24, μετακινούν τον αριθμό
   // ώστε το 2ο, 3ο και 4ο byte να είναι μεταξύ 0..255.
   return byte_count[x & 0xFF] + byte_count[(x >> 8) & 0xFF] 
      + byte_count[(x >> 16) & 0xFF] + byte_count[(x >> 24) & 0xFF];
}

long cnt[32];

int main() {
   precompute();
   
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

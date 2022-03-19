#include <cstdio>

const size_t MAXN = 100'000;

long count[MAXN];

int main() {
   FILE *fi = fopen("domes.in", "r");
   long N, M;
   fscanf(fi, "%ld %ld", &N, &M);
   long answer = N;
   for (long i = 0; i < M; ++i) {
      long A, B;
      fscanf(fi, "%ld %ld", &A, &B);
      ++count[A];
      ++count[B];
      if (count[A] == 2) --answer;
      if (count[B] == 2) --answer;
   }
   fclose(fi);
  
   FILE *fo = fopen("domes.out", "w");
   fprintf(fo, "%ld", answer);
   fclose(fo);
   return 0;
}
  
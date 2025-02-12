#include <algorithm>
#include <cstdio>
#include <vector>

int main(){
   FILE *in = fopen("samepizzas.in", "r");
   FILE *out= fopen("samepizzas.out", "w");
   long P,N,K;
   fscanf(in, "%ld", &P);
   fscanf(in, "%ld%ld", &N, &K);
   
   std::vector<long> A(N);
   long mn, mx;
   for(long i = 0; i < N; i++) {
      fscanf(in, "%ld", &A[i]);
      if (i == 0 || A[i] < mn) mn = A[i];
      if (i == 0 || A[i] > mx) mx = A[i];
   }
    
   long st = mn, en = mx;
   while (st < en) {
      long md = (st + en + 1) / 2;
      long cnt = 0;
      for (auto v : A) cnt += (v >= md);
      if (cnt >= K) st = md;
      else en = md - 1;
   }
    
   fprintf(out, "%ld\n", st);
   fclose(out);
   fclose(in);
   return 0;
}

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

typedef long long ll;

int main(){
   long P,N,X,Y,Z;
   ll ans = 0;
   
   FILE *in = fopen("hiring.in", "r");
   fscanf(in, "%ld\n", &P);
   fscanf(in, "%ld %ld %ld %ld\n", &N, &X, &Y, &Z);
   
   for(long i = 0; i < N; ++i) {
      long A, B, C;
      fscanf(in, "%ld%ld%ld", &A, &B, &C);
      if (i < Z) ans += C;
      else if (i >= N - Y) ans += B;
      else ans += A;
   }
   fclose(in);
   
   FILE *out= fopen("hiring.out", "w");
   fprintf(out, "%lld\n", ans);
   fclose(out);
   
   return 0;
}

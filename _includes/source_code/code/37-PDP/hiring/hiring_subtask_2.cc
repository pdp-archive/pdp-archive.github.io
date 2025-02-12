#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

typedef long long ll;

struct Score {
   long A, B, C; 
};

int main(){
   long P, N, X, Y, Z;
   
   FILE *in = fopen("hiring.in", "r");
   fscanf(in, "%ld\n", &P);
   fscanf(in, "%ld %ld %ld %ld\n", &N, &X, &Y, &Z);
   
   std::vector<Score> scores(N);
   for(long i = 0; i < N; ++i) {
      fscanf(in, "%ld%ld%ld", &scores[i].A, &scores[i].B, &scores[i].C);
   }
   fclose(in);
   
   // Ταξινόμηση με βάση την διαφορά Bi - Ai.
   std::sort(scores.begin(), scores.end(), [](const Score& one, const Score& two) {
      return one.B - one.A > two.B - two.A;
   });
   
   ll ans = 0;
   for (long i = 0; i < N; ++i) {
      if (i < Y) ans += scores[i].B;
      else ans += scores[i].A;
   }
   
   FILE *out= fopen("hiring.out", "w");
   fprintf(out, "%lld\n", ans);
   fclose(out);
   
   return 0;
}

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

typedef long long ll;

struct Score {
   long A, B, C; 
};

long P,N,X,Y,Z;

ll ans = 0;

void try_all(const std::vector<Score>& scores, long i, ll cur_ans, long x, long y, long z) {
   if (i == scores.size()) {
      ans = std::max(ans, cur_ans);
      return;
   }
   if (x + 1 <= X) try_all(scores, i + 1, cur_ans + scores[i].A, x + 1, y, z);
   if (y + 1 <= Y) try_all(scores, i + 1, cur_ans + scores[i].B, x, y + 1, z);
   if (z + 1 <= Z) try_all(scores, i + 1, cur_ans + scores[i].C, x, y, z + 1);
}


int main(){
   FILE *in = fopen("hiring.in", "r");
   fscanf(in, "%ld\n", &P);
   fscanf(in, "%ld %ld %ld %ld\n", &N, &X, &Y, &Z);
   
   std::vector<Score> scores(N);
   for(long i = 0; i < N; ++i) {
      fscanf(in, "%ld%ld%ld", &scores[i].A, &scores[i].B, &scores[i].C);
   }
   fclose(in);
   
   try_all(scores, 0, 0, 0, 0, 0);
   
   FILE *out= fopen("hiring.out", "w");
   fprintf(out, "%lld\n", ans);
   fclose(out);
   
   return 0;
}

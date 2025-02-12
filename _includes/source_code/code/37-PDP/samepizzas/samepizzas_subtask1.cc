#include <algorithm>
#include <cstdio>
#include <vector>

int main(){
   FILE *in = fopen("samepizzas.in", "r");
   long P, N, K;
   fscanf(in, "%ld", &P);
   fscanf(in, "%ld%ld", &N, &K);
   fclose(in);
   
   std::vector<long> A(N);
   for(long i = 0; i < N; i++) {
      fscanf(in, "%ld", &A[i]);
   }
    
   FILE *out= fopen("samepizzas.out", "w");
   if (K == 1) fprintf(out, "%ld\n", std::max(A[0], A[1]));
   else fprintf(out, "%ld\n", std::min(A[0], A[1]));
   fclose(out);
   return 0;
}

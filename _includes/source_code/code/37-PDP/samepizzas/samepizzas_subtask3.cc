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
   for(long i = 0; i < N; i++) {
      fscanf(in, "%ld", &A[i]);
   }
   auto mx = *std::max_element(A.begin(), A.end());
   fprintf(out, "%ld\n", mx);
   
   fclose(out);
   fclose(in);
   return 0;
}

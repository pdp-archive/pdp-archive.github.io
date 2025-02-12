#include <algorithm>
#include <cstdio>
#include <vector>

int main(){
   FILE *in = fopen("samepizzas.in", "r");
   long P, N, K;
   fscanf(in, "%ld", &P);
   fscanf(in, "%ld%ld", &N, &K);
   
   std::vector<long> A(N);
   for(long i = 0; i < N; i++) {
      fscanf(in, "%ld", &A[i]);
   }
   fclose(in);
   
   auto mn = *std::min_element(A.begin(), A.end());
   
   FILE *out= fopen("samepizzas.out", "w");
   fprintf(out, "%ld\n", mn);
   fclose(out);
   return 0;
}

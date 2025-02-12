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
   for(long i = 0; i < N; ++i) fscanf(in, "%ld", &A[i]);
    
   for(long i = 0; i < N; ++i) {
      for (long j = i - 1; j >= 0; --j) {
         if (A[j+1] > A[j]) std::swap(A[j+1], A[j]);
         else break;
      }
   }
    
   fprintf(out, "%ld\n", A[K-1]);
   fclose(out);
   fclose(in);
   return 0;
}

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
   for(long i = 0; i < N; i++)fscanf(in, "%ld", &A[i]);
   
   // Το std::greater<long>() χρειάζεται ώστε η ταξινόμηση 
   // να γίνει σε φθίνουσα σειρά.
   std::sort(A.begin(), A.end(), std::greater<long>());
    
   fprintf(out, "%ld\n", A[K-1]);
   fclose(out);
   fclose(in);
   return 0;
}

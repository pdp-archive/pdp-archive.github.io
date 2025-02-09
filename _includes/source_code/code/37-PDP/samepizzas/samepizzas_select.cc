#include <algorithm>
#include <cstdio>
#include <vector>

int main(){
   FILE *in = fopen("samepizzas.in", "r");
   FILE *out= fopen("samepizzas.out", "w");
   long P,N,K;
   fscanf(in, "%ld\n", &P);
   fscanf(in, "%ld %ld\n", &N, &K);
   
   std::vector<long> A(N);
   for(long i = 0; i < N; ++i) fscanf(in, "%ld", &A[i]);
   
   std::nth_element(
      A.begin(),              // Αρχή του πίνακα.
      A.begin() + (K-1),      // Θέση του στοιχείου που θέλουμε (δηλαδή το Κ-οστό).
      A.end(),                // Τέλος του πίνακα.
      std::greater<long>());  // Ταξινόμηση σε φθίνουσα σειρά.
   
   fprintf(out, "%ld\n", A[K-1]);
   fclose(out);
   fclose(in);
   return 0;
}

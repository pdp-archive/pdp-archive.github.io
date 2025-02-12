#include <algorithm>
#include <cstdio>
#include <vector>

int main(){
   FILE *in = fopen("samepizzas.in", "r");
   long P, N, K;
   fscanf(in, "%ld", &P);
   fscanf(in, "%ld%ld", &N, &K);
   
   std::vector<long> A(N);
   for(long i = 0; i < N; ++i) fscanf(in, "%ld", &A[i]);
   fclose(in);
   
   std::nth_element(
      A.begin(),              // Αρχή του πίνακα.
      A.begin() + (K-1),      // Θέση του στοιχείου που θέλουμε (δηλαδή το Κ-οστό).
      A.end(),                // Τέλος του πίνακα.
      std::greater<long>());  // Ταξινόμηση σε φθίνουσα σειρά.
   
   FILE *out= fopen("samepizzas.out", "w");
   fprintf(out, "%ld\n", A[K-1]);
   fclose(out);
   return 0;
}

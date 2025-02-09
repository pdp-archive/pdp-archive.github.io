#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

int main(){
   FILE *in = fopen("samepizzas.in", "r");
   FILE *out= fopen("samepizzas.out", "w");
   long P,N,K;
   fscanf(in, "%ld\n", &P);
   fscanf(in, "%ld %ld\n", &N, &K);
   
   std::vector<long> A(N);
   for(long i = 0; i < N; ++i) fscanf(in, "%ld", &A[i]);
   
   // Ορίζουμε μία ουρά προτεραιότητας που κρατάει τα Κ μεγαλύτερα στοιχεία, 
   // και το top() επιστρέφει το μικρότερο από αυτά.
   std::priority_queue<long, std::vector<long>, std::greater<long>> pq;
   for (long i = 0; i < K; ++i) pq.push(A[i]);
   for (long i = K; i < N; ++i) {
      if (A[i] > pq.top()) {
         pq.pop();
         pq.push(A[i]);
      }
   }
    
   fprintf(out, "%ld\n", pq.top());
   fclose(out);
   fclose(in);
   return 0;
}

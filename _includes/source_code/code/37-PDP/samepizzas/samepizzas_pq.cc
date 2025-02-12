#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

int main(){
   FILE *in = fopen("samepizzas.in", "r");
   long P, N, K;
   fscanf(in, "%ld", &P);
   fscanf(in, "%ld%ld", &N, &K);
   
   std::vector<long> A(N);
   for(long i = 0; i < N; ++i) fscanf(in, "%ld", &A[i]);
   fclose(in);
   
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
    
   FILE *out= fopen("samepizzas.out", "w"); 
   fprintf(out, "%ld\n", pq.top());
   fclose(out);
   return 0;
}

#include <algorithm>
#include <cstdio>

const long MAXN = 100'000;
// Η μέγιστη δυνατή τιμή είναι η αρχική τιμή + log2 N.
const long MAXV = 1e9 + 17;

long A[MAXN];

int main() {
   FILE *fi = fopen("mergegame.in", "r");
   long S, N;
   fscanf(fi, "%ld%ld", &S, &N);
   
   long smallest = MAXV;
   for (long i = 0; i < N; ++i) {
         fscanf(fi, "%ld", &A[i]);
         smallest = std::min(smallest, A[i]);
   }
   fclose(fi);
   
   long j = N;
   // Σε κάθε γύρο βρίσκουμε το μικρότερο στοιχείο smallest.
   // Αν υπάρχουν δύο διαδοχικά smallest τα ενώνουμε.
   // Διαφορετικά το αφαιρούμε.
   while (j > 1) {
      long j_prev = j;
      j = 0;
      long nxt_smallest = MAXV;
      for (long i = 0; i < j_prev; ++i) {
         if (A[i] == smallest) {
            // Αν το γειτονικό είναι ίσο, τα ενώνουμε.
            // Αλλιώς τα αφαιρούμε.
            if (i + 1 < j_prev && A[i] == A[i+1]) {
               A[j++] = smallest + 1;
               nxt_smallest = std::min(nxt_smallest, smallest + 1);
               ++i;
            } 
         } else {
            A[j++] = A[i];
            nxt_smallest = std::min(nxt_smallest, A[i]);
         }
      }
      smallest = nxt_smallest;
   }
   
   FILE *fo = fopen("mergegame.out", "w");
   fprintf(fo, "%ld\n", smallest);
   fclose(fo);
   
   return 0;
}


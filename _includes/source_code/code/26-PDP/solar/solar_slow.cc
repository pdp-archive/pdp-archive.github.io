#include <cstdio>

const long MAXN = 1000000;

long A[MAXN];
long N;

/* Ελέγξτε αν τα στοιχεία από [0, idx) είναι μικρότερα από το A[idx]. */
bool arePreviousSmallerThan(long idx) {
   for (long k = 0; k < idx; ++k) {
      if (A[idx] <= A[k]) return false;
   }
   return true;
}

/* Ελέγξτε αν τα στοιχεία από (idx, N) είναι μεγαλύτερα από το A[idx]. */
bool areSubsequentLargerThan(long idx) {
   for (long k = idx + 1; k < N; ++k) {
      if (A[idx] >= A[k]) return false;
   }
   return true;
}

int main() {
   FILE *fi = fopen("solar.in", "r");
   fscanf(fi, "%ld", &N);
  
   for (long i = 0; i < N; ++i) {
      fscanf(fi, "%ld\r\n", &A[i]);
   }
  
   long answer = -1;
   for (long i = 0; i < N; ++i) {
      if (answer < A[i] && arePreviousSmallerThan(i) && areSubsequentLargerThan(i)) {
         answer = A[i];
      }
   }
   fclose(fi);
  
   FILE *fo = fopen("solar.out", "w");
   if (answer == -1) fprintf(fo, "NOT FOUND\n");
   else fprintf(fo, "%ld\n", answer);
  
   return 0;
}

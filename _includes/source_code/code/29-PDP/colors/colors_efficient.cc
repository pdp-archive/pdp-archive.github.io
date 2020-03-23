#include <algorithm>
#include <cstdio>

const long MAXN = 1000000;
const long MAXK = 100000;

long A[MAXN];
long count[MAXK + 1];

int main() {
  FILE *fi = fopen("colors.in", "r");
  long N, K;
  fscanf(fi, "%ld %ld", &N, &K);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  fclose(fi);
  
  // Βρίσκουμε το πρώτο διάστημα.
  long different_colors = 0;
  long j = 0;
  while(different_colors < K && j < N) {
    if (count[A[j]] == 0) ++different_colors;
	++count[A[j]];
	++j;
  }
  // Αν δεν βρήκαμε όλα τα χρώματα τότε δεν υπάρχει λύση. 
  long min_length = (different_colors != K) ? 0 : j;
  for (long i = 1; i < N; ++i) {
    --count[A[i-1]];
	if (count[A[i-1]] == 0) {
	  do {
	    count[A[j]]++;
	    ++j;
	  } while (j < N && A[j-1] != A[i-1]);
	  // Δεν βρήκαμε άλλο τέτοιο χρώμα.
	  if (A[j-1] != A[i-1]) break;
	}
	min_length = std::min(min_length, j - i);
  }
  
  FILE *fo = fopen("colors.out", "w");
  fprintf(fo, "%ld\n", min_length);
  fclose(fo);
  return 0;
}

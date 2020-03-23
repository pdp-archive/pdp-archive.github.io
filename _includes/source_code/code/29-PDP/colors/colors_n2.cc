#include <algorithm>
#include <cstdio>
#include <set>

const long MAXN = 1000000;
const long MAXK = 100000;

long A[MAXN];

int main() {
  FILE *fi = fopen("colors.in", "r");
  long N, K;
  fscanf(fi, "%ld %ld", &N, &K);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  fclose(fi);
  
  long min_length = N + 1;
  for (long i = 0; i < N; ++i) {
    std::set<long> colors_set;
    for (long j = i; j < N; ++j) {
	  colors_set.insert(A[j]);
	  if (colors_set.size() == K) {
	    // Βρήκαμε όλα τα διαφορετικά χρώματα.
		min_length = std::min(min_length, j - i + 1);
		break;
	  }
	}
  }
  
  FILE *fo = fopen("colors.out", "w");
  fprintf(fo, "%ld\n", (min_length == N + 1) ? 0 : min_length);
  fclose(fo);
  return 0;
}

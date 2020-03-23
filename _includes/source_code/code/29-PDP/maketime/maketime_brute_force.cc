#include <algorithm>
#include <cstdio>

const size_t MAXM = 2000000;

long D[MAXM];

int main() {
  FILE *fi = fopen("maketime.in", "r");
  long N, M, K;
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  
  for (long i = 0; i < M; ++i) {
    fscanf(fi, "%ld", &D[i]);
  }
  fclose(fi);
  
  long max_diff = 0;
  for (long i = 1; i <= N; ++i) {
    for (long j = i; j <= N; ++j) {
	  long count = 0;
	  for (long d = 0; d < M; ++d) {
		if (i <= D[d] && D[d] <= j) {
		  ++count;
		}
	  }
	  if (count <= K) {
	    max_diff = std::max(max_diff, j - i + 1);
	  }
	}
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", max_diff);
  fclose(fo);
  return 0;
}

#include <algorithm>
#include <cstdio>
#include <set>

const long MAXN = 1000000;

long A[MAXN];

long countColoursInInterval(long st, long en) {
  std::set<long> colors_set;
  for (long i = st; i <= en; ++i) {
    colors_set.insert(A[i]);
  }
  return colors_set.size();
}
    

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
    for (long j = i; j < N; ++j) {
	  if (countColoursInInterval(i, j) == K) {
	    min_length = std::min(min_length, j - i + 1);
	  }
	}
  }
  
  FILE *fo = fopen("colors.out", "w");
  fprintf(fo, "%ld\n", (min_length == N + 1) ? 0 : min_length);
  fclose(fo);
  return 0;
}

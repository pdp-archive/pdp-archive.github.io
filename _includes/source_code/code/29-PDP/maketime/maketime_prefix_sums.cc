#include <algorithm>
#include <cstdio>

const size_t MAXN = 2000000;

long counts[MAXN + 1];
long prefix_sum[MAXN + 1];

long N, M, K;

void computePrefixSum() {
  for (long i = 1; i <= N; ++i) {
    prefix_sum[i] = prefix_sum[i-1] + counts[i];
  }
}

int main() {
  FILE *fi = fopen("maketime.in", "r");
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  
  for (long i = 0; i < M; ++i) {
    long temp;
    fscanf(fi, "%ld", &temp);
	++counts[temp];
  }
  fclose(fi);
  
  computePrefixSum();
  
  long max_diff = 0;
  for (long i = 0; i < N; ++i) {
    for (long j = i + 1; j <= N; ++j) {
	  long count_between = prefix_sum[j] - prefix_sum[i];
	  if (count_between <= K) {
	    max_diff = std::max(max_diff, j - i);
	  }
	}
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", max_diff);
  fclose(fo);
  return 0;
}

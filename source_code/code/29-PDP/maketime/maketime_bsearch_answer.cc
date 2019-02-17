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

bool doesIntervalWithLengthExist(long len) {
  for (long i = 0; i + len <= N; ++i) {
	long count_between = prefix_sum[i + len] - prefix_sum[i];
	if (count_between <= K) {
	  return true;
	}
  }
  return false;
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
  
  long lo = 0, hi = N;
  while (lo < hi) {
    long mid = (lo + hi + 1)/2;
	if (doesIntervalWithLengthExist(mid)) lo = mid;
	else hi = mid - 1;
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", lo);
  fclose(fo);
  return 0;
}

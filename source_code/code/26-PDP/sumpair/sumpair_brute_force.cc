#include <cstdio>

const size_t MAXN = 1000000;

long A[MAXN];
long N, Q;

bool doesPairExist(long target) {
  for (long i = 0; i < N; ++i) {
    for (long j = i + 1; j < N; ++j) {
	  if (A[i] + A[j] == target) {
	    return true;
	  }
	}
  }
  return false;
}

int main() {
  FILE *fi = fopen("sumpair.in", "r");
  fscanf(fi, "%ld %ld", &N, &Q);
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  FILE *fo = fopen("sumpair.out", "w");
  for (long j = 0; j < Q; ++j) {
    long target;
	fscanf(fi, "%ld", &target);
    fprintf(fo, "%s\n", doesPairExist(target) ? "true" : "false");
  }
  return 0;
}

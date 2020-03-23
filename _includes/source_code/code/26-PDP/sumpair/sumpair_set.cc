#include <cstdio>
#include <set>

const size_t MAXN = 1000000;

std::set<long> s, has_duplicate;

long A[MAXN];
long N, Q;

bool doesPairExist(long target) {
  for (long i = 0; i < N; ++i) {
    if (2 * A[i] == target) {
	  if (has_duplicate.find(A[i]) != has_duplicate.end())
	    return true;
	} else {
	  if (s.find(target - A[i]) != s.end()) {
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
	if (s.find(A[i]) != s.end()) {
      has_duplicate.insert(A[i]);
	}
	s.insert(A[i]);
  }
  FILE *fo = fopen("sumpair.out", "w");
  for (long j = 0; j < Q; ++j) {
    long target;
	fscanf(fi, "%ld", &target);
    fprintf(fo, "%s\n", doesPairExist(target) ? "true" : "false");
  }
  return 0;
}
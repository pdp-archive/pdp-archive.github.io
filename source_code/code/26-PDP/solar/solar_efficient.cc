#include <algorithm>
#include <cstdio>

const long MAXN = 1000000;
const long MAXK = 1000000;
long A[MAXN], mx[MAXN], mn[MAXN];
long N;

int main() {
  FILE *fi = fopen("solar.in", "r");
  fscanf(fi, "%ld", &N);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld\r\n", &A[i]);
  }
  
  mx[0] = -1;
  for (long i = 1; i < N; ++i) {
    mx[i] = std::max(mx[i-1], A[i - 1]);
  }
  
  mn[N-1] = MAXK;
  for (long i = N - 2; i >= 0; --i) {
    mn[i] = std::min(mn[i+1], A[i + 1]);
  }
  
  long answer = -1;
  for (long i = 0; i < N; ++i) {
    if (answer < A[i] && mx[i] < A[i] && mn[i] > A[i]) {
	  answer = A[i];
	}
  }
  fclose(fi);
  
  FILE *fo = fopen("solar.out", "w");
  if (answer == -1) fprintf(fo, "NOT FOUND\n");
  else fprintf(fo, "%ld\n", answer);
  
  return 0;
}

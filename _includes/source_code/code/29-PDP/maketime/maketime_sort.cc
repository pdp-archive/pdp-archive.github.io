#include <algorithm>
#include <cstdio>

const size_t MAXM = 2000000;

long D[MAXM];

int main() {
  FILE *fi = fopen("maketime.in", "r");
  long N, M, K;
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  D[0] = 0;
  for (long i = 0; i < M; ++i) {
    fscanf(fi, "%ld", &D[i]);
  }
  D[M+1] = N+1;
  fclose(fi);
  
  std::sort(D, D + M + 2);
  
  long max_diff = 0;
  for (long i = 1; i + K <= M + 1; ++i) {
    max_diff = std::max(max_diff, D[i+K] - D[i-1] - 1);
  }
  
  FILE *fo = fopen("maketime.out", "w");
  fprintf(fo, "%ld\n", max_diff);
  fclose(fo);
  return 0;
}

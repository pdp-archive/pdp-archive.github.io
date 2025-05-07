#include <cstdio>

int main() {
  FILE *fi = fopen("reviews.in", "r");
  long T, N;
  fscanf(fi, "%ld%ld", &T, &N);
  fclose(fi);
  FILE *fo = fopen("reviews.out", "w");
  for (long i = 0; i < N; ++i) {
    fprintf(fo, "%ld\n", N);
  }
  fclose(fo);
  return 0;
}


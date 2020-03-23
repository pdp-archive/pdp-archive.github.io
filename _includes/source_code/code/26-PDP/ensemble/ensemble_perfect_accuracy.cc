#include <algorithm>
#include <cstdio>

const long MAXN = 100000;

long A[MAXN];

void print_value(FILE *fo, long val);

int main() {
  FILE *fi = fopen("ensemble.in", "r");
  long N, K;
  fscanf(fi, "%ld %ld", &N, &K);
  
  for (long i = 0; i < N; ++i) {
	double temp;
    fscanf(fi, "%lf", &temp);
	A[i] = temp * 1000;
  }
  
  std::sort(A, A+N);
  
  long sum1 = 0;
  long sum2 = 0;
  
  for (long i = 0; i < N; ++i) {
    if (i < K) {
	  sum2 += A[K];
	} else if (i > N - K -1) {
	  sum2 += A[N-K-1];
	} else {
	  sum1 += A[i];
	  sum2 += A[i];
	}
  }
  fclose(fi);
  
  FILE *fo = fopen("ensemble.out", "w");
  long av1 = sum1 / (N - 2 * K);
  long av2 = sum2 / N;
  print_value(fo, av1);
  fprintf(fo, " ");
  print_value(fo, av2);
  fprintf(fo, "\n");
  fclose(fo);
  return 0;
}

void print_value(FILE *fo, long val) {
  long decimal = val / 10;
  if (val % 10 >= 5) {
    decimal++;
  }
  long first_two = decimal / 100;
  long last_two = decimal % 100;
  fprintf(fo, "%ld.%02ld", first_two, last_two);
}

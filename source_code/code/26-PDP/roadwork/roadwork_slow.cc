#include <algorithm>
#include <cstdio>

const size_t MAXL = 1000000;
const size_t MAXN = 1000000;

bool is_covered[MAXL];

long cover(long s, long t) {
  for (long j = s; j < t; ++j) {
	is_covered[j] = true;
  }
}

long N, L, X;

long findMaxGap() {
  long prev_one = -1;
  long max_gap = 0;
  for (long j = 0; j < L; ++j) {
    if (is_covered[j]) prev_one = j;
	else {
	  long gap = j - prev_one;
	  max_gap = std::max(max_gap, gap);
	}
  }
  return max_gap;
}

int main() {
  FILE *fi = fopen("roadwork.in", "r");
  fscanf(fi, "%ld %ld %ld", &N, &L, &X);
  long solution = -1;
  if (findMaxGap() <= X) {
    solution = 0;
  } else {	
	  for (long j = 0; j < N; ++j) {
		long s, t;
		fscanf(fi, "%ld %ld", &s, &t);
		cover(s, t);
		if (findMaxGap() <= X) {
		  solution = j + 1;
		  break;
		}
	  }
  }
  FILE *fo = fopen("roadwork.out", "w");
  fprintf(fo, "%ld\n", solution);
  fclose(fi);
  fclose(fo);
  return 0;
}  
  
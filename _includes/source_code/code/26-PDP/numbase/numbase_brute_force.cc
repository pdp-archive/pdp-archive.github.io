#include <cstdio>

typedef long long ll;

ll solve(ll M) {
  for (ll k = 2; k < M; ++k) {
    for (ll x = 1; x < k; ++x) {
	  ll sum = 0;
	  ll power = 1;
	  while (sum < M) {
	    sum += x * power;
		power *= k;
	  }
	  if (sum == M) {
	    return k;
	  }
	}
  }
  return M + 1;
}

int main() {
  FILE *fi = fopen("numbase.in", "r");
  long N;
  fscanf(fi, "%ld", &N);
  FILE *fo = fopen("numbase.out", "w");
  for (long test_case = 0; test_case < N; ++test_case) {
    ll M;
    fscanf(fi, "%lld", &M);
	fprintf(fo, "%lld\n", solve(M));
  }
  fclose(fi);
  fclose(fo);
  return 0;
}


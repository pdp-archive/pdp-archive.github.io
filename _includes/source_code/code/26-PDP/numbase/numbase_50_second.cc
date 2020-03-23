#include <algorithm>
#include <cstdio>

typedef long long ll;

int cmpSum(ll k, ll x, ll n, ll M) {
  ll sum = 0;
  ll pw = 1;
  for (ll i = 0; i < n; ++i) {
    sum += pw * x;
	if (sum > M) return 1;
	pw *= k;
  }
  if (sum == M) return 0;
  return -1;
}

ll findOptimal(ll x, ll n, ll M) {
  ll lo = x + 1;
  ll hi = M - 1;
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
	int cmp = cmpSum(mid, x, n, M);
	if (cmp == 0) return mid;
	else if (cmp == -1) lo = mid + 1;
	else hi = mid - 1;
  }
  if (cmpSum(lo, x, n, M) == 0) return lo;
  return M + 1;
}

ll smallestPowerOfTwoGreaterThan(ll M) {
  ll pw = 1;
  ll exponent = 0;
  while (pw < M) {
    pw <<= 1;
	++exponent;
  }
  return exponent;
}

ll solve(ll M) {
  ll best_k = M + 1;
  ll max_n = smallestPowerOfTwoGreaterThan(M);
  for (ll x = 1; x < M; ++x) {
	for (ll n = max_n; n >= 1; --n) {
	  best_k = std::min(findOptimal(x, n, M), best_k);
	}
  } 
  return best_k;
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


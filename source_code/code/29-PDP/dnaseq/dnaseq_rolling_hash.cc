#include <algorithm>
#include <cstdio>

const size_t MAXN = 1000000;

typedef long long ll;

ll p = 1000000123LL; // Πρώτος αριθμός
ll x = 26; // Βάση 

char A[MAXN + 2];
char B[MAXN + 2];

ll pw[MAXN + 2]; // pw[i] = x^i mod p.
ll RA[MAXN + 2], RB[MAXN + 2];
ll LA[MAXN + 2], LB[MAXN + 2];

long N;

void precomputePowers() {
  pw[0] = 1;
  for (long i = 1; i <= N; ++i) {
    pw[i] = (pw[i-1] * x) % p;
  }
}

void precomputeR() {
  for (long i = 1; i <= N; ++i) {
    RA[i] = (RA[i-1] + A[i] * pw[i]) % p;
	RB[i] = (RB[i-1] + B[i] * pw[i]) % p;
  }
}

void precomputeL() {
  for (long i = N; i >= 1; --i) {
    LA[i] = (LA[i+1] + A[i] * pw[N-i+1]) % p;
	LB[i] = (LB[i+1] + B[i] * pw[N-i+1]) % p;
  }
}

bool checkEqualPrefix(long L) {
  return RA[L-1] == RB[L-1];
}

bool checkEqualSuffix(long M) {
  return LA[M+1] == LB[M+1];
}

bool checkReversedMiddleStrings(long L, long M) {
  return ((RA[M] - RA[L-1] + p) * pw[N-M+1])%p == ((LB[L] - LB[M+1] + p) * pw[L]) % p;
}

// Βάζουμε τους λατινικούς χαρακτήρες στο [0, 25].
void normaliseSequences() {
  for (long i = 1; i <= N; ++i) {
    A[i] -= 'A';
	B[i] -= 'A';
  }
}

int main() {
  FILE *fi = fopen("dnaseq.in", "r");
  fscanf(fi, "%ld\n", &N);
  fgets(A + 1, N + 2, fi);
  fgets(B + 1, N + 2, fi);
  
  normaliseSequences();
  precomputePowers();
  precomputeL();
  precomputeR();

  long min_diff = N + 1;
  for (long L = 1; L <= N; ++L) {
    for (long M = L; M <= N; ++M) {
      if (checkEqualPrefix(L) && checkEqualSuffix(M)
	    && checkReversedMiddleStrings(L, M)) {
		min_diff = std::min(min_diff, M - L);
	  }
    }
  }
  fclose(fi);
  
  FILE *fo = fopen("dnaseq.out", "w");
  if (min_diff == N + 1) fprintf(fo, "no\n");
  else fprintf(fo, "%ld\n", min_diff);
  fclose(fo);
  return 0;
}

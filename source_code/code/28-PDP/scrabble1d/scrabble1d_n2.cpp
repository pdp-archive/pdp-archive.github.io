#include <cstdio>

using namespace std;

const size_t MAXN = 2000000;
const size_t MAXK = 1000000;

long N, K;
long sums[MAXN]; // Το άθροισμα των πόντων ξεκινώντας από την αρχή

int main () {
	freopen("scrabble1d.in", "r", stdin);
	freopen("scrabble1d.out", "w", stdout);

	sums[0] = 0;
	scanf("%ld %ld", &N, &K);
	long val;
	for (int i = 1; i <= N; i++) {
		scanf("%ld", &val);
		// Ανανεώνουμε το επόμενο στοιχείο του πίνακα sums
		sums[i] = sums[i-1] + val;
	}

	long maxSum = 0;
	for (int s1 = 1; s1 <= N - 2 * K + 1; s1++) {
		long sum1 = sums[s1 + K - 1] - sums[s1 - 1];
		long maxSum2 = 0;
		for (int s2 = s1 + K; s2 <= N - K + 1; s2++) {
			long sum2 = sums[s2 + K - 1] - sums[s2 - 1];
			if (sum2 > maxSum2) { maxSum2 = sum2; }
		}
		if (sum1 + maxSum2 > maxSum) {
			maxSum = sum1 + maxSum2;
		}
	}
	printf("%ld\n", maxSum);
	return 0;
}

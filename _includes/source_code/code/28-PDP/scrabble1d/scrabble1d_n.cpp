#include <cstdio>

using namespace std;

const size_t MAXN = 2000001;

long N, K;
long sums[MAXN];

int main () {
	freopen("scrabble1d.in", "r", stdin);
	freopen("scrabble1d.out", "w", stdout);
	
	sums[0] = 0;
	scanf("%ld %ld", &N, &K);
	long val;
	for (int i = 1; i <= N; i++) {
		scanf("%ld", &val);
		sums[i] = sums[i-1] + val;
	}

	long maxSum = 0;
	long maxSum2 = 0;
	// Ελέγχουμε για κάθε υποψήφια θέση της αρχής της πρώτης λέξης.
	for (int s1 = N - 2 * K + 1; s1 >= 1; s1--) {
		// Υπολογίζουμε των Κ-αθροισμάτων που ξεκινάνε από το s1 και το s1+K αντίστοιχα.
		long sum1 = sums[s1 + K - 1] - sums[s1 - 1];
		long sum2 = sums[s1 + 2 * K - 1] - sums[s1 + K - 1];
		// Ανανεώνουμε το καλύτερο άθροισμα maxSum2.
		if (sum2 > maxSum2) { maxSum2 = sum2; }
		// Ανανεώνουμε το καλύτερο συνολικό άθροισμα.
		if (sum1 + maxSum2 > maxSum) { maxSum = sum1 + maxSum2; }
	}
	printf("%ld\n", maxSum);
	return 0;
}

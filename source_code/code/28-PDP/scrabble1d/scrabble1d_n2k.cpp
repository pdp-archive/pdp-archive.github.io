#include <cstdio>

using namespace std;

const size_t MAXN = 2000000;
const size_t MAXK = 1000000;

long N, K;
long P[MAXN]; // Οι πόντοι του ταμπλό

int main () {
	// Άνοιγμα αρχείων για διαβασμα και γράψιμο
	freopen("scrabble1d.in", "r", stdin);
	freopen("scrabble1d.out", "w", stdout);
	
	// Διάβσμα αρχείου εισόδου
	scanf("%ld %ld", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%ld", P + i);
	}

	// Αρχικοποιούμε το μέγιστο άθροισμα με 0
	long maxSum = 0;
	for (int s1 = 1; s1 <= N - 2 * K + 1; s1++) {
		// Εύρεση των πόντων που παίρνει η λέξη αν ξεκινάει από το s1
		long sum1 = 0;
		for (int e1 = 0; e1 < K; e1++) {
			sum1 += P[s1 + e1];
		}

		// Αρχικοποιούμε το μέγιστο άθροισμα για την
		// δεύτερη λέξη
		long maxSum2 = 0;
		// Η επανάληψη για το s2 ξεκινάει τουλάχιστον Κ στοιχεία
		// μετά το s1 για να μην επικαλύπτονται τα διαστήματα
		for (int s2 = s1 + K; s2 <= N - K + 1; s2++) {
			// Βρίσκουμε τους πόντους που παίρνει η λέξη αν ξεκινάει από το s2
			long sum2 = 0;
			for (int e2 = 0; e2 < K; e2++) {
				sum2 += P[s2 + e2];
			}
			if (sum2 > maxSum2) { maxSum2 = sum2; }
		}
		// Αν το άθροισμα των πόντων των δύο λέξεων είναι καλύτερο
		// από αυτό που έχουμε ως τώρα, ανανεώνουμε το maxSum
		if (sum1 + maxSum2 > maxSum) {
			maxSum = sum1 + maxSum2;
		}
	}
	printf("%ld\n", maxSum);
	return 0;
}

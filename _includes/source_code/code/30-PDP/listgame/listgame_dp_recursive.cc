#include <algorithm>
#include <cstdio>

const size_t MAXN = 10000;

long a[MAXN];

// Παρατηρήστε ότι για συγκεκριμένο i και j μόνο ένα από τα best_a(i, j)
// και best_b(i, j) είναι δυνατό (γιατί μετά από συγκεκριμένο αριθμό κινήσεων
// πάντα παίζει ο ίδιος παίχτης).
bool already_calculated[MAXN][MAXN]; // Αν έχουμε υπολογίσει την τιμή για το (i, j).
long dp[MAXN][MAXN]; // Η τιμή για το (i, j).

long set_and_return(long i, long j, long v) {
   already_calculated[i][j] = true;
   return dp[i][j] = v;
}

long best_b(long i, long j);

long best_a(long i, long j) {
   if (already_calculated[i][j]) return dp[i][j];
   // Βασική συνθήκη.
   if (i == j) return a[i];
   // Διαλέγουμε το καλύτερο από τα δύο ενδεχόμενα.
   long v = std::max(a[i] + best_b(i + 1, j), best_b(i, j - 1) + a[j]);
   return set_and_return(i, j, v);
}

long best_b(long i, long j) {
	if (already_calculated[i][j]) return dp[i][j];
   // Βασική συνθήκη.
   if (i == j) return -a[i];
   // Διαλέγουμε το καλύτερο από τα δύο ενδεχόμενα.
   long v = std::min(-a[i] + best_a(i + 1, j), best_a(i, j - 1) - a[j]);
   return set_and_return(i, j, v);
}

int main() {
    long N;
    FILE *fi = fopen("listgame.in", "r");
	fscanf(fi, "%ld", &N);
	long total = 0;
	for (long i = 0; i < N; ++i) {
	   fscanf(fi, "%ld", &a[i]);
	   total += a[i];
	}
	fclose(fi);

	FILE *fo = fopen("listgame.out", "w");
	long outcome = best_a(0, N - 1); 
	fprintf(fo, "%ld\n", (outcome + total)/2);
	fclose(fo);
	return 0;
}

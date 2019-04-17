#include <algorithm>
#include <cstdio>

const size_t MAXN = 10000;

long a[MAXN];

long best_b(long i, long j);

long best_a(long i, long j) {
   // Βασική συνθήκη.
   if (i == j) return a[i];
   // Διαλέγουμε το καλύτερο από τα δύο ενδεχόμενα.
   return std::max(a[i] + best_b(i + 1, j), best_b(i, j - 1) + a[j]);
}

long best_b(long i, long j) {
   // Βασική συνθήκη.
   if (i == j) return -a[i];
   // Διαλέγουμε το καλύτερο από τα δύο ενδεχόμενα.
   return std::min(-a[i] + best_a(i + 1, j), best_a(i, j - 1) - a[j]);
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

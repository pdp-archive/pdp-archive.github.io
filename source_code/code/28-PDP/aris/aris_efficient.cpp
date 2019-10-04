#include <cstdio>

const size_t MAXN = 1000000;

long N, M;
long counts[MAXN + 1]; // Αρχικοποίηση του πίνακα counts με μηδενικά

int main () {
    // Διάβασμα του αρχείου εισόδου
    freopen("aris.in", "r", stdin);
    scanf("%ld %ld", &N, &M);
    for (long i = 0; i < N; ++i) {
        long m;
        scanf("%ld", &m);
        counts[m] ++; // Συναντήσαμε την τιμή m, άρα αυξάνουμε την θέση m του πίνακα
    }    

    // Αρχικοποίηση των μεγεθών που ψάχνουμε
    long progs = 0;
    long minCount = N;
	long maxCount = 0;    

    for (long m = 1; m <= M; ++m) {
        if (counts[m] > 0) {
            // Μη μηδενική τιμή
            // Αυξάνουμε τον αριθμό των προγραμμάτων
            // και συγκρίνουμε με τo μέχρι στιγμής μέγιστo
            // και ελάχιστo
            progs ++;
            if (counts[m] < minCount) { minCount = counts[m]; }
            if (counts[m] > maxCount) { maxCount = counts[m]; }
        }
    }
    
    // Αφού ελέγξουμε για όλα τα πιθανά Μ, έχουμε τις 
    // απαντήσεις οπότε τις εκτυπώνουμε
    freopen("aris.out", "w", stdout);
    printf("%ld %ld %ld\n", progs, minCount, maxCount);
    return 0;
}


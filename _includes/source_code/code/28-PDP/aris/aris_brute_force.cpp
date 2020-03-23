#include <cstdio>

const size_t MAXN = 1000000;

long N, M;
long windows[MAXN + 1];

int main () {
    // Διάβασμα του αρχείου εισόδου
    freopen("aris.in", "r", stdin);
    scanf("%ld %ld", &N, &M);
    for (long i = 0; i < N; ++i) { scanf("%ld", &windows[i]); }
    
    // Αρχικοποίηση των μεγεθών που ψάχνουμε
    long progs = 0; // Πόσα προγράμματα έχουν τρέξει
    long minCount = N; // Ελάχιστη υπολογιστική ισχύς
    long maxCount = 0; // Μέγιστη υπολογιστική ισχύς
    
    for (long m = 1; m <= M; ++m) {
        long count = 0; // Πόσες φορές βρήκαμε το πρόγραμμα m
        for (long i = 0; i < N; ++i) {
            if (windows[i] == m) { count ++; } // Βρήκαμε άλλο ένα παράθυρο με το m
        }
        // Άμα το count δεν είναι 0, βρήκαμε κι άλλο πρόγραμμα που εκτελέστηκε
        if (count > 0) {
			progs ++;
			// Αν το count είναι μεγαλύτερο από το ως τώρα μεγαλύτερο, ανανεώνουμε την
			// τιμή του μεγαλύτερου
			if (count > maxCount) { maxCount = count; }
			// Αντίστοιχα ανανεώνουμε την τιμή του μικρότερου
			if (count < minCount) { minCount = count; }
		}
    }
    
    // Αφού ελέγξουμε για όλα τα πιθανά Μ, έχουμε τις 
    // απαντήσεις οπότε τις εκτυπώνουμε
    freopen("aris.out", "w", stdout);
    printf("%ld %ld %ld\n", progs, minCount, maxCount);
    return 0;
}


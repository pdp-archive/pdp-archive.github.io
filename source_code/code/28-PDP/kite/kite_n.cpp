#include <cstdio>

const size_t MAXN = 2000000;

long N, K;
long C[MAXN + 1];

long S(long i, long j) {
    return C[j] - C[i - 1];
}

int main () {
    freopen("kite.in", "r", stdin);
    scanf("%ld %ld", &N, &K);
    C[0] = 0;
    
    for (long i = 1; i <= N; ++i) { 
        long piece;
        scanf("%ld", &piece);
        C[i] = C[i - 1] + piece;
    }
    
    long minPieces = N + 1;
    long i = 1, j = 1;
    // Αυξάνουμε το j ένα-ένα τη φορά
    while(j <= N) {
        // Όσο το S(i, j) > K, αυξάνουμε το i κατά 1
        while (S(i, j) > K) { ++i; }
        // Ελέγχουμε αν το S(i, j) = Κ
        if (S(i, j) == K) {
            // Βρήκαμε μία πιθανή λύση οπότε την ελέγχουμε
            if (j - i + 1 < minPieces) { minPieces = j - i + 1; }
            // Αυξάνουμε το i, αφού δεν πρόκειται να μας δώσει πάνω
            // από μία λύση
            ++i;
        }
        // Τελειώνει η επανάληψη γνωρίζοντας ότι S(i, j) < K
        // και άρα το j θα αυξηθεί
        ++j;
    }
    freopen("kite.out", "w", stdout);
    if (minPieces == N + 1) {
        // Δεν βρέθηκε κομμάτι με μήκος Κ
        printf("0\n");
        return 0;
    }
    // Αλλιώς έχουμε βρει κομμάτι
    printf("%ld\n", minPieces);
    return 0;
}

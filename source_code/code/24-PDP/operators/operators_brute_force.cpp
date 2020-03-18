#include <cstdio>
#include <algorithm>

using namespace std;

const long MAXN = 1000005;

long A[MAXN];

int main() {
    freopen("operators.in", "r", stdin);
    freopen("operators.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // Διάβασμα ακολουθίας ακεραίων
    for (long i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
    }
    // Δήλωση βοηθητικών μεταβλητών
    long mn = 2 * 1000 * 1000 * 1000 + 1, mn_i, mn_j;
    // Έλεγχος όλων των ζευγών ακεραίων της ακολουθίας
    for (long i = 0; i < N; i++) {
        for (long j = i + 1; j < N; j++) {
            // Υπολογισμός μέτρου αθροίσματος τρέχοντος ζεύγους
            long cur_abs_sum = abs(A[i] + A[j]);
            // Έλεγχος για ελάχιστο
            if (cur_abs_sum < mn) {
                // Ενημέρωση αποτελεσμάτων σε περίπτωση ελαχίστου
                mn = cur_abs_sum;
                mn_i = i;
                mn_j = j;
            }
        }
    }
    printf("%ld %ld\n", A[mn_i], A[mn_j]);
    return(0);
}

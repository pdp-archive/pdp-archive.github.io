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
    // Έλεγχος για το αν έχουμε μόνο θετικούς ή μόνο αρνητικούς ακεραίους
    if (A[0] > 0) {
        printf("%ld %ld\n", A[0], A[1]);
        return(0);
    }
    else if (A[N - 1] < 0) {
        printf("%ld %ld\n", A[N - 2], A[N - 1]);
        return(0);
    }
    // Δήλωση βοηθητικών μεταβλητών
    long mn = 2 * 1000 * 1000 * 1000 + 1, mn_1, mn_2;
    for (long i = 0; i < N; i++) {
        long K = A[i];
        long a, b;
        if (K) {
            // Εντοπισμός γειτόνων αντιθέτου με δυαδική αναζήτηση
            long pos = lower_bound(A, A + N - 1, -K) - A;
            if (pos < N && A[pos] == -K) {
                printf("%ld %ld\n", min(K, -K), max(K, -K));
                return(0);
            }
            a = pos - 1;
            b = pos;
        }
        else {
            // ’μεσος προσδιορισμός γειτόνων
            a = i - 1;
            b = i + 1;
        }
        // Προσαρμογή γειτόνων
        if (a == i || a == -1)
            a++;
        if (b == i || b == N)
            b--;
        // Ενημέρωση αποτελεσμάτων σε περίπτωση ελαχίστου
        if (abs(K + A[a]) < mn) {
            mn = abs(K + A[a]);
            mn_1 = i;
            mn_2 = a;
        }
        if (abs(K + A[b]) < mn) {
            mn = abs(K + A[b]);
            mn_1 = i;
            mn_2 = b;
        }
    }
    printf("%ld %ld\n", min(A[mn_1], A[mn_2]), max(A[mn_1], A[mn_2]));
    return(0);
}

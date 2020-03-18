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
    // Αρχικοποίηση μεταβλητής-δείκτη
    long j = N - 1;
    for (long i = 0; i < j; i++) {
        // Υπολογισμός βέλτιστου j με i < j
        while (j > i + 1 && abs(A[i] + A[j - 1]) < abs(A[i] + A[j])) {
            j--;
        }
        // Έλεγχος για ελάχιστο
        if (abs(A[i] + A[j]) < mn) {
            mn = abs(A[i] + A[j]);
            mn_i = i;
            mn_j = j;
        }
    }
    printf("%ld %ld\n", A[mn_i], A[mn_j]);
    return(0);
}

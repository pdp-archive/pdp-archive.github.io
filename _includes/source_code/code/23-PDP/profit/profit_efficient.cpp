#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("profit.in", "r", stdin);
    freopen("profit.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // Αρχικοποίηση μεταβλητής μέγιστου κέρδους
    double P = 1;
    // Αρχικοποίηση μεταβλητής ελάχιστης
    long mn = 1000;
    // Διάβασμα ακολουθίας τιμών και υπολογισμός απάντησης
    for (long i = 0; i < N; i++) {
        long x;
        scanf("%ld", &x);
        // Ενημέρωση ελάχιστης τιμής
        mn = min(mn, x);
        // Ενημέρωση μέγιστου κέρδους
        P = max(P, 1.0 * x / mn);
    }
    printf("%.3f\n", P);
    return(0);
}

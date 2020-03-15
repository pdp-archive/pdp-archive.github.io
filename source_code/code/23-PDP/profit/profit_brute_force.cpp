#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000005

long X[MAXN];

int main() {
    freopen("profit.in", "r", stdin);
    freopen("profit.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // Διάβασμα ακολουθίας τιμών
    for (long i = 0; i < N; i++) {
        scanf("%ld", &X[i]);
    }
    // Αρχικοποίηση μεταβλητής μέγιστου κέρδους
    double P = 1;
    // Δοκιμή όλων των συνδυασμών αγοράς και πώλησης
    for (long i = 0; i < N; i++) {
        for (long j = 0; j <= i; j++) {
            // Διατήρηση μέγιστου μέχρι στιγμής κέρδους
            P = max(P, 1.0 * X[i] / X[j]);
        }
    }
    printf("%.3f\n", P);
    return(0);
}

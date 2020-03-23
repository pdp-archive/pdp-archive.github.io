#include <cstdio>
#include <algorithm>

#define MAXN 1000005

using namespace std;

long A[MAXN], S[MAXN];
int main() {
    freopen("share.in", "r", stdin);
    freopen("share.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // Διάβασμα προβλεπόμενων κερδών και υπολογισμός μερικών αθροισμάτων
    S[0] = 0;
    for (long i = 1; i <= N; i++) {
        scanf("%ld", &A[i]);
        S[i] = S[i - 1] + A[i];
    }
    long ans = 1000 * 1000 * 1000;  // Αρχικοποίηση ελάχιστου μεγίστου στο μέγιστο δυνατό
    for (long i = 1; i < N - 1; i++) {
        for (long j = i + 1; j <= N - 1; j++) {
            // Υπολογισμός προβλεπόμενων κερδών
            long v1 = S[i], v2 = S[j] - S[i], v3 = S[N] - S[j];
            // Υπολογισμός μέγιστου κέρδους
            long mx = max(v1, v2);
            mx = max(mx, v3);
            // Έλεγχος αν το τρέχον μέγιστο κέρδος είναι ελάχιστο μέγιστο μέχρι στιγμής
            if (mx < ans)
                ans = mx;
        }
    }
    printf("%ld\n", ans);
    return(0);
}

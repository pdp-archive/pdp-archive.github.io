#include <cstdio>
#include <algorithm>

#define MAXN 1000005

using namespace std;

long A[MAXN];
// Επιστρέφει το άθροισμα των κερδών στο διάστημα [a, b]
long sum(long a, long b)
{
    long res = 0;
    for (long k = a; k <= b; k++) {
        res += A[k];
    }
    return(res);
}
int main() {
    freopen("share.in", "r", stdin);
    freopen("share.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    for (long i = 1; i <= N; i++) {
        scanf("%ld", &A[i]);
    }
    long ans = 1000 * 1000 * 1000;  // Αρχικοποίηση ελάχιστου μεγίστου στο μέγιστο δυνατό
    for (long i = 1; i < N - 1; i++) {
        for (long j = i + 1; j <= N - 1; j++) {
            // Υπολογισμός προβλεπόμενων κερδών
            long v1 = sum(1, i), v2 = sum(i + 1, j), v3 = sum(j + 1, N);
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

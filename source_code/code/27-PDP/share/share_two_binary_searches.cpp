#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000005
long N;
long A[MAXN], S[MAXN];
// Συνάρτηση άπληστου ελέγχου με δυαδικές αναζητήσεις
bool check(long K) {
    long lo = 0, hi = N;
    // Υπολογισμός πρώτου ορίου
    while (lo < hi) {
        long mid = lo + (hi - lo + 1) / 2;
        if (S[mid] <= K) lo = mid;
        else hi = mid - 1;
    }
    long a = lo;
    hi = N;
    // Υπολογισμός δεύτερου ορίου
    while (lo < hi) {
        long mid = lo + (hi - lo + 1) / 2;
        if (S[mid] - S[a] <= K) lo = mid;
        else hi = mid - 1;
    }
    long b = lo;
    // Απάντηση ελέγχου ανάλογα με το κέρδος των υπόλοιπων ημερών
    return(S[N] - S[b] <= K);
}
int main() {
    freopen("share.in", "r", stdin);
    freopen("share.out", "w", stdout);
    scanf("%ld", &N);
    // Διάβασμα προβλεπόμενων κερδών και υπολογισμός μερικών αθροισμάτων
    S[0] = 0;
    for (long i = 1; i <= N; i++) {
        scanf("%ld", &A[i]);
        S[i] = S[i - 1] + A[i];
    }
    long lo = 0, hi = S[N];  // Αρχικοποίηση ορίων δυαδικής αναζήτησης
    // Δυαδική αναζήτηση
    while (lo < hi) {
        long mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    long ans = lo;
    printf("%ld\n", ans);
    return(0);
}

#include <cstdio>

#define MAXN 1000005

using namespace std;

long N;
long A[MAXN], S[MAXN];
// Συνάρτηση άπληστου ελέγχου με γραμμική διάσχιση
bool check(long K) {
    long p = 0, sum = 0;
    // Αντιστοιχία ημερών στον πρώτο αδερφό
    while (p < N && sum + A[p + 1] <= K) {
        sum += A[++p];
    }
    sum = 0;
    // Αντιστοιχία ημερών στο δεύτερο αδερφό
    while (p < N && sum + A[p + 1] <= K) {
        sum += A[++p];
    }
    // Απάντηση ελέγχου ανάλογα με το κέρδος των υπόλοιπων ημερών
    return(S[N] - S[p] <= K);
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

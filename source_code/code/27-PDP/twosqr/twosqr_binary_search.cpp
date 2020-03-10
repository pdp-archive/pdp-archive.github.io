#include <cstdio>
using namespace std;

int main() {
    freopen("twosqr.in", "r", stdin);
    freopen("twosqr.out", "w", stdout);
    long T;
    scanf("%ld", &T);
    for (long tc = 0; tc < T; tc++) {
        long N, cnt = 0;  // Αρχικοποίηση μετρητή
        scanf("%ld", &N);
        for (long b = 0; b * b <= N; b++) {
            long lo = 0, hi = N - b * b;  // Αρχικοποίηση ορίων δυαδικής αναζήτησης
            while (lo < hi) {
                long mid = lo + (hi - lo + 1) / 2;
                if (mid * mid <= N - b * b)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            long h = lo;
            if (h <= b && h * h == N - b * b)  // Έλεγχος συνθήκης
                cnt++;
        }
        printf("%ld\n", cnt);
    }
    return(0);
}

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
            for (long a = 0; a <= b; a++) {
                if (a * a + b * b == N)  // Έλεγχος συνθήκης
                    cnt++;
            }
        }
        printf("%ld\n", cnt);
    }
    return(0);
}

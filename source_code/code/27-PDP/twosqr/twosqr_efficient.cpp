  
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    freopen("twosqr.in", "r", stdin);
    freopen("twosqr.out", "w", stdout);
    long T;
    scanf("%ld", &T);
    for (long tc = 0; tc < T; tc++) {
        long N, cnt = 0;  // Αρχικοποίηση μετρητή
        scanf("%ld", &N);
        long mn_b = sqrt(N / 2);  // Υπολογισμός ελάχιστου δυνατού b
        for (long b = mn_b; b * b <= N; b++) {
            long h = sqrt(N - b * b);
            if (h <= b && h * h == N - b * b)  // Έλεγχος συνθήκης
                cnt++;
        }
        printf("%ld\n", cnt);
    }
    return(0);
}

#include <cstdio>

using namespace std;

const long MAXN = 100005;

long A[MAXN];

int main() {
    freopen("snow_run.in", "r", stdin);
    freopen("snow_run.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    for (long i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
        // Αύξηση τελικής κατάταξης προηγούμενων δρομέων που τερμάτισαν αργότερα
        for (long j = 0; j < i; j++) {
            if (A[j] >= A[i])
                A[j]++;
        }
    }
    // Εκτύπωση τελικών κατατάξεων
    for (long i = 0; i < N; i++) {
        printf("%ld\n", A[i]);
    }
    return(0);
}

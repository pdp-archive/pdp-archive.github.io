#include <cstdio>
using namespace std;
const long MAXN = 100005;
long A[MAXN];
bool B[MAXN];
int main() {
    freopen("snow_run.in", "r", stdin);
    freopen("snow_run.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // Διάβασμα κατατάξεων τη στιγμή τερματισμού κάθε δρομέα
    for (long i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
    }
    for (long i = N - 1; i >= 0; i--) {
        long a = A[i];
        long b = 0;
        // Εύρεση a-οστού κενού στη θέση b
        while (a) {
            if (!B[++b])
                a--;
        }
        // Το b είναι η τελική κατάταξη του τρέχοντος παίκτη
        B[b] = true;
        A[i] = b;
    }
    // Εκτύπωση τελικών κατατάξεων
    for (long i = 0; i < N; i++) {
        printf("%ld\n", A[i]);
    }
    return(0);
}

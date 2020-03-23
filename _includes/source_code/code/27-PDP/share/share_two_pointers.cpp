#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000005
long A[MAXN];
int main() {
    freopen("share.in", "r", stdin);
    freopen("share.out", "w", stdout);
    long N, sum = 0;
    scanf("%ld", &N);
    // Διάβασμα προβλεπόμενων κερδών και υπολογισμός αθροίσματός τους
    for (long i = 1; i <= N; i++) {
        scanf("%ld", &A[i]);
        sum += A[i];
    }
    // Υπολογισμός αρχικών προβλεπόμενων κερδών για τα τρία αδέρφια
    long sum1 = A[1], sum3 = A[N], sum2 = sum - sum1 - sum3;
    // Αρχικοποίηση ορίων τμημάτων ημερών
    long a = 1, b = N - 1;
    while (sum2 > sum1 && sum2 > sum3) {
        // Υπολογισμός νέων προβλεπόμενων κερδών μετά από μεταφορά ημέρας
        long inc_sum1 = sum1 + A[a + 1], inc_sum3 = sum3 + A[b];
        if (inc_sum1 < sum2 && inc_sum1 <= inc_sum3) {
            // Μεταφορά ημέρας προς τον πρώτο αδερφό
            sum1 = inc_sum1;
            sum2 -= A[++a];
        }
        else if (inc_sum3 < sum2 && inc_sum3 <= inc_sum1) {
            // Μεταφορά ημέρας προς τον τρίτο αδερφό
            sum3 = inc_sum3;
            sum2 -= A[b--];
        }
        else
            break;
    }
    // Υπολογισμός μέγιστου κέρδους
    long ans = max(sum1, sum2);
    ans = max(ans, sum3);
    printf("%ld\n", ans);
    return(0);
}

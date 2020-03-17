#include <cstdio>

using namespace std;

const long MAXN = 100005;
long A[MAXN];

// Δηλώσεις για segment tree
long C[MAXN], tree[4 * MAXN];

void build(long node, long start, long end) {
    if(start == end)
        tree[node] = C[start];
    else {
        long mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

// Εντοποπισμός επιθυμητού 1 και ενημέρωση segment tree
long query(long node, long start, long end, long k) {
    tree[node]--;
    if(start == end) {
        C[start] = 0;
        return(start);
    }
    long mid = (start + end) / 2;
    long c = tree[2 * node];
    // Επιλογή κατάλληλου υποδέντρου
    if (c >= k)
        return(query(2 * node, start, mid, k));
    return(query(2 * node + 1, mid + 1, end, k - c));
}

int main() {
    freopen("snow_run.in", "r", stdin);
    freopen("snow_run.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // Διάβασμα κατατάξεων τη στιγμή τερματισμού κάθε δρομέα
    // και αρχικοποίηση πίνακα C
    for (long i = 1; i <= N; i++) {
        scanf("%ld", &A[i]);
        C[i] = 1;
    }
    // Κατασκευή segment tree
    build(1, 1, N);
    // Υπολογισμός τελικών κατατάξεων με εντοπισμό 1
    for (long i = N; i; i--) {
        A[i] = query(1, 1, N, A[i]);
    }
    // Εκτύπωση τελικών κατατάξεων
    for (long i = 1; i <= N; i++) {
        printf("%ld\n", A[i]);
    }
    return(0);
}

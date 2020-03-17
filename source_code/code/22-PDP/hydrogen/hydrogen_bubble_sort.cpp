#include <cstdio>
#include <algorithm>
using namespace std;
const long MAXL = 10005;
struct car_part {
    long id, freq;
};

car_part A[MAXL];

int main() {
    freopen("hydrogen.in", "r", stdin);
    freopen("hydrogen.out", "w", stdout);
    long C, L = 0;
    scanf("%ld", &C);
    for (long i = 0; i < C; i++) {
        long id, freq;
        scanf("%ld %ld", &id, &freq);
        // Αποθήκευση δεδομένων για τμήματα με βλάβες ευθύνης κατασκευαστή
        if (freq)
           A[L++] = { id, freq };
    }
    // Εκτύπωση πλήθους τμημάτων με βλάβες ευθύνης κατασκευαστή
    printf("%ld\n", L);
    // Ταξινόμηση με bubblesort
    for (long i = 0; i < L; i++) {
        // Πέρασμα από δεξιά προς τα αριστερά
        for (long j = L - 1; j > i; j--) {
            // Αντιμετάθεση γειτονικών αταξινόμητων στοιχείων
            if (A[j].freq > A[j - 1].freq || A[j].freq == A[j - 1].freq && A[j].id < A[j - 1].id)
                swap(A[j], A[j - 1]);
        }
        // Εμφάνιση έτοιμων αποτελεσμάτων
        printf("%ld\n", A[i].id);
    }
    return(0);
}

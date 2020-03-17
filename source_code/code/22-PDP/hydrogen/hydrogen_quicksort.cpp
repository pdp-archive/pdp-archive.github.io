#include <cstdio>
#include <algorithm>
using namespace std;
const long MAXL = 10005;
struct car_part {
    long id, freq;
};

car_part A[MAXL];
bool comp(car_part a, car_part b) {
   if (a.freq == b.freq) return a.id < b.id;
   return a.freq > b.freq;
}

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
    // Ταξινόμηση με quicksort
    sort(A, A + L, comp);
    // Εμφάνιση αποτελεσμάτων
    for (long i = 0; i < L; i++) {
        printf("%ld\n", A[i].id);
    }
    return(0);
}

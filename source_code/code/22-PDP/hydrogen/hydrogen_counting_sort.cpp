#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXID 10000
#define MAXF 50000

long B[MAXID + 5];
vector<long> D[MAXF + 5];

int main() {
    freopen("hydrogen.in", "r", stdin);
    freopen("hydrogen.out", "w", stdout);
    long C, L = 0;
    scanf("%ld", &C);
    for (long i = 0; i < C; i++) {
        long id, freq;
        scanf("%ld %ld", &id, &freq);
        // Ουσιαστικά ταξινόμηση με βάση τον αριθμό τμήματος
        if (freq) {
            L++;
            B[id] = freq;
        }
    }
    // Ταξινόμηση με βάση τη συχνότητα εμφάνισης
    for (long i = 1; i <= MAXID; i++) {
        long freq = B[i];
        D[freq].push_back(i);
    }
    // Εκτύπωση πλήθους τμημάτων με βλάβες ευθύνης κατασκευαστή
    printf("%ld\n", L);
    // Εμφάνιση κατάλληλα ταξινομημένων αριθμών τμημάτων αυτοκινήτου
    for (int i = MAXF; i; i--) {
        for (int j = 0; j < D[i].size(); j++) {
            printf("%ld\n", D[i][j]);
        }
    }
    return(0);
}

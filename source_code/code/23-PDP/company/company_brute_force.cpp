#include <cstdio>
using namespace std;
const long MAXN = 400005;
// Πίνακας με id προϊσταμένων
long P[MAXN];
// Πίνακας με φύλο εργαζομένων
char S[MAXN];
// Μεταβλητή για το αποτέλεσμα (r_m - r_f)
long D;
// Αναδρομική συνάρτηση υπολογισμών
void calc(long id, char w_sex) {
    // Αν κλήθηκες από το διευθυντή απλά επίστρεψε
    if (!id)
        return;
    // Αν έχεις άλλο φύλο από τον εργαζόμενο άλλαξε το D
    if (S[id] != w_sex) {
        if (S[id] == 'm')
            D++;
        else
            D--;
    }
    // Κάλεσε τη συνάρτηση για τον προσϊστάμενό σου
    calc(P[id], w_sex);
}
int main() {
    freopen("company.in", "r", stdin);
    freopen("company.out", "w", stdout);
    long N;
    scanf("%ld", &N);
    // Διάβασε τα id των προϊσταμένων και τα φύλα των εργαζομένων
    for (long i = 1; i <= N; i++) {
        scanf("%ld %c", &P[i], &S[i]);
    }
    // Ρύθμισε αναδρομικά το D για κάθε εργαζόμενο
    for (long i = 1; i <= N; i++) {
        calc(P[i], S[i]);
    }
    // Εκτύπωσε το αποτέλεσμα
    printf("%ld\n", D);
    return(0);
}

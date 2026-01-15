#include <cstdio>

using namespace std;

typedef long long ll;

int Q; // Αριθμός ερωτημάτων
ll L, R; // Όρια ερωτήματος
ll pow3[64]; // Δυνάμεις του 3

ll calculate_bquery(ll L, ll R) {
  ll total = 1; // Συνολικός αριθμός ζευγών
  ll upperBounded = 1; // Αριθμός ζευγών με άνω όριο
  ll lowerBounded = 1; // Αριθμός ζευγών με κάτω όριο
  ll digits = 0;
  // Για κάθε bit μικρότερο ή ίσο του R
  for (ll bit = 1; bit <= R; bit <<= 1) {
    digits++;
    ll rBit = R & bit;
    ll lBit = L & bit;
    if (rBit == 0 && lBit == bit) {
      // Αν το bit είναι 0 στο R και 1 στο L, τα ζεύγη στα μικρότερα bits δεν
      // είναι πλέον έγκυρα
      total = 0;
    } else if (rBit == bit && lBit == 0) {
      // Αν το bit είναι 1 στο R και 0 στο L, τοτε προσθέτουμε και όλα τα
      // ζεύγη που σχηματίζονται από τα bounds
      total += upperBounded + lowerBounded;
    }

    if (rBit == bit) {
      upperBounded = pow3[digits - 1] + 2 * upperBounded;
    }
    if (lBit == 0) {
      lowerBounded = pow3[digits - 1] + 2 * lowerBounded;
    }
  }


  return total;
}

int main () {
  // Προϋπολογισμός δυνάμεων του 3
  pow3[0] = 1;
  for (int i = 1; i < 64; i++) {
    pow3[i] = pow3[i - 1] * 3;
  }

  scanf("%d", &Q);
  for (int q = 0; q < Q; q++) {
    scanf("%lld %lld", &L, &R);
    ll result = calculate_bquery(L, R);
    printf("%lld\n", result);
  }
  return 0;
}

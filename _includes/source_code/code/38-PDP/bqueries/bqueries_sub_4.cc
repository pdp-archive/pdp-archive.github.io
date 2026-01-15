#include <cstdio>

using namespace std;

typedef long long ll;

int Q;   // Αριθμός ερωτημάτων
ll L, R; // Όρια ερωτήματος
ll pow3[64]; // Δυνάμεις του 3

ll calculate_bquery(ll L, ll R) {
  // Λύση για το υποπρόβλημα με L = 0
  // Υπολογίζουμε αναδρομικά την απάντηση για τα τελευταία i bits του R

  ll count = 1;

  long i = 0;
  for (ll bit = 1; bit <= R; bit <<= 1) {
    ++i;
    if ((R & bit) == 0) continue;
    count = 2 * count + pow3[i - 1];
  }

  return count;
}

int main() {
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

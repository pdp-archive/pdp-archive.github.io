#include <cstdio>

using namespace std;

typedef long long ll;

long Q;      // Αριθμός ερωτημάτων
ll L, R;     // Όρια ερωτήματος
ll pow2[64]; // Δυνάμεις του 2
ll pow3[64]; // Δυνάμεις του 3

int find_bit_count(ll x) {
  int count = 0;
  while (x) {
    count++;
    x >>= 1;
  }
  return count;
}

ll calculate_bquery(ll L, ll R) {
  // Λύση για το υποπρόβλημα με L = 2^k, R = 2^m - 1
  // Υπολογίζουμε τα k, m και επιστρέφουμε 3^m−2^(m−k)3^k

  int m = find_bit_count(R);
  int k = find_bit_count(L) - 1;

  return pow3[m] - pow2[m - k] * pow3[k];
}

int main() {
  // Προϋπολογισμός δυνάμεων του 2 και του 3
  pow2[0] = 1;
  pow3[0] = 1;
  for (int i = 1; i <= 32; i++) {
    pow2[i] = pow2[i - 1] * 2;
    pow3[i] = pow3[i - 1] * 3;
  }

  scanf("%ld", &Q);
  for (long q = 0; q < Q; q++) {
    scanf("%lld %lld", &L, &R);
    ll result = calculate_bquery(L, R);
    printf("%lld\n", result);
  }
  return 0;
}

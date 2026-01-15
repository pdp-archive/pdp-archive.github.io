#include <cstdio>

using namespace std;

typedef long long ll;

int Q;   // Αριθμός ερωτημάτων
ll L, R; // Όρια ερωτήματος

ll calculate_bquery(ll L, ll R) {
  // Λύση για το υποπρόβλημα με R <= 200'000
  // Σε αυτή την περίπτωση, μπορούμε για κάθε τιμή του x να μετρήσουμε πόσες
  // τιμές του y υπάρχουν

  if (R == 0)
    return 1;

  ll bit;
  // Πόσα bits έχει το R
  ll totalBits = 0;
  // Η τελική απάντηση
  ll totalCount = 0;
  // Για κάθε x, πόσα y είναι μεγαλύτερα του R
  ll count = 0;

  for (bit = 1; bit <= R; bit <<= 1LL) {
    totalBits++;
  }

  // Το xZeros[i] κρατάει πόσα μηδενικά bits υπάρχουν στα bits αριστερά
  // (μικρότερα) του i
  ll xZeros[65];
  xZeros[0] = 0;
  ll totalXZeros = 0;
  for (ll x = L; x <= R; ++x) {
    count = 0;
    long idx = 1;
    totalXZeros = 0;
    for (bit = 1; bit <= R; bit <<= 1LL) {
      xZeros[idx] = xZeros[idx - 1];
      if ((bit & x) == 0) {
        xZeros[idx]++;
        totalXZeros++;
      }
      idx++;
    }

    idx = totalBits;
    for (bit = 1LL << (totalBits - 1); bit > 0; bit >>= 1LL) {
      idx--;
      // Αν το bit του R είναι 1, συνεχίζουμε στο επόμενο bit
      ll rBit = R & bit;
      if (rBit == bit) continue;
      // Κάθε μηδενικό του x έχει 2 επιλογές στο y οπότε προσθέτουμε
      // 2^xZeros[idx]
      count += (1LL << xZeros[idx]);
      // Αν το bit του x είναι 1, σταματάμε
      ll xBit = x & bit;
      if (xBit == bit) break;
    }
    totalCount += (1LL << totalXZeros) - count;
  }

  return totalCount;
}

int main() {
  scanf("%d", &Q);
  for (int q = 0; q < Q; q++) {
    scanf("%lld %lld", &L, &R);
    ll result = calculate_bquery(L, R);
    printf("%lld\n", result);
  }
  return 0;
}

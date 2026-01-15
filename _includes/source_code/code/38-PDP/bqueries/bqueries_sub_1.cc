#include <cstdio>

using namespace std;

typedef long long ll;

int Q; // Αριθμός ερωτημάτων
ll L, R; // Όρια ερωτήματος

ll calculate_bquery(ll L, ll R) {
  // Λύση για το υποπρόβλημα με R <= 5000
  // Σε αυτή την περίπτωση, μπορούμε να απλά να μετρήσουμε
  // όλα τα έγκυρα ζεύγη (x, y) με L <= x, y <= R

  ll count = 0;
  for (ll x = L; x <= R; x++) {
    for (ll y = x; y <= R; y++) {
      // Ελέγχουμε αν το ζεύγος (x, y) είναι έγκυρο
      if ((x & y) == x) {
        count++;
      }
    }
  }

  return count;
}

int main () {
  scanf("%d", &Q);
  for (int q = 0; q < Q; q++) {
    scanf("%lld %lld", &L, &R);
    ll result = calculate_bquery(L, R);
    printf("%lld\n", result);
  }
  return 0;
}

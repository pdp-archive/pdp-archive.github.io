#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

typedef long long ll;

const long MAXN = 200'000;

int main() {
  long N;
  scanf("%ld", &N);
  bool found_even = false, found_odd = false;
  std::multiset<ll> pq;
  for (long i = 0; i < N; ++i) {
     long tmp;
     scanf("%ld", &tmp);
     if (tmp % 2 == 0) found_even = true;
     else found_odd = true;
     pq.insert(tmp);
  }
  // Αν βρήκαμε και περιττούς και ζυγούς αριθμούς, τότε 
  // δεν είναι εφικτό να φτάσουμε σε ένα στοιχείο.
  if (found_odd && found_even) {
     printf("-1\n");
     return 0;
  }
  
  ll additive_factor = found_even ? 8 : 7;
  ll cost = 0;
  while (pq.size() != 1) {
    // Διαλέγουμε τα δύο μικρότερα στοιχεία.
    ll one = *pq.begin(); pq.erase(pq.begin());
    ll two = *pq.begin(); pq.erase(pq.begin());
    // Προσθέτουμε το κόστος για το βήμα.
    ll new_item = one + two + additive_factor;
    cost += new_item;
    // Αντικαθιστούμε το καινούργιο στοιχείο.
    pq.insert(new_item);
  }
  
  printf("%lld\n", cost);
  return 0;
}


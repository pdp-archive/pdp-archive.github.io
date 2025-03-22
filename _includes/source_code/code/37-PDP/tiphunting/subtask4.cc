#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

using ll = pair<long, long>;
using vl = vector<long>;
using vvll = vector<vector<ll>>;

vvll tree;
vl tip;
vector<long long> best_subtree_tour, best_supertree_tour;

long long positive_part(long long x) { return max(0LL, x); }

// Πρώτη διάσχιση η οποία υπολογίζει το `best_subtree_tour` για την κορυφή `u`
// κι όλους τους απογόνους της.
//
// best_subtree_tour[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει και
// καταλήγει πάλι πίσω στο `u`, παραμένοντας στο υποδέντρο που ορίζει η κορυφή
// `u`. Με άλλα λόγια, η διαδρομή απαγορεύεται να διασχίσει τον δρόμο `(u,
// parent)`.
void compute_best_subtree_tour(long u, long parent) {
  best_subtree_tour[u] = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent) continue;
    compute_best_subtree_tour(v, u);
    best_subtree_tour[u] += positive_part(best_subtree_tour[v] - 2*w);
  }
}

// Δεύτερη διάσχιση η οποία υπολογίζει το `best_supertree_tour` για την κορυφή
// `u` κι όλους τους απογόνους της, χρησιμοποιώντας τις τιμές
// `best_subtree_tour` που υπολογίσαμε ήδη στην πρώτη διάσχιση.
//
// best_supertree_tour[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει αλλά
// ΚΑΙ καταλήγει στην κορυφή `u`, και μένει πάντα ΕΚΤΟΣ του υποδέντρου που
// ορίζει η `u`. Το φιλοδώρημα της κορυφής `u` ΔΕΝ προσμετράται.
void compute_best_supertree_tour(long u, long parent, long w) {
  best_supertree_tour[u] = 0;

  // Αν η κορυφή `u` ΔΕΝ είναι ρίζα.
  if (parent != u)
    best_supertree_tour[u] =
      positive_part(best_subtree_tour[parent] + best_supertree_tour[parent]
      - positive_part(best_subtree_tour[u] - 2*w) - 2*w);

  for (auto [v, w]: tree[u])
    if (v != parent)
      compute_best_supertree_tour(v, u, w);
}

int main() {
  int subtask;
  scanf("%i", &subtask);
  assert(subtask == 2 || subtask == 4);

  long n, q;
  scanf("%li%li", &n, &q);
  
  tip.resize(n);
  for (long i = 0; i < n; ++i)
    scanf("%li", &tip[i]);

  // Αναπαράσταση του δέντρου με adjacency list:
  // To `tree[u]` περιέχει ένα vector με pairs `(v, w)` για κάθε κορυφή `v` που
  // συνδέεται με τη `u` με κόστός `w`.
  tree.resize(n);
  for (long i = 0; i < n-1; ++i) {
    long u, v, w;
    scanf("%li%li%li", &u, &v, &w);

    tree[u-1].push_back({v-1, w});
    tree[v-1].push_back({u-1, w});
  }

  best_subtree_tour.resize(n);
  compute_best_subtree_tour(0, 0);

  best_supertree_tour.resize(n);
  compute_best_supertree_tour(0, 0, 0);

  for (long i = 0; i < q; ++i) {
    long L, R;
    scanf("%li%li", &L, &R);
    L--, R--;
    assert(L == R);

    printf("%lli\n", best_subtree_tour[L] + best_supertree_tour[L]);
  }

  return 0;
}

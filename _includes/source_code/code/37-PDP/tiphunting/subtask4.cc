#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

using ll = pair<long, long>;
using vl = vector<long>;
using vvll = vector<vector<ll>>;

vvll tree;
vl tip;
vector<long long> subtree_loop_opt, supertree_loop_opt;

long long positive_part(long long x) { return max(0LL, x); }

// Πρώτη διάσχιση η οποία υπολογίζει το `subtree_loop_opt` για την κορυφή `u`
// κι όλους τους απογόνους της.
//
// subtree_loop_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// και καταλήγει πάλι πίσω στο `u`, παραμένοντας στο υποδέντρο που ορίζει
// η κορυφή `u`. Με άλλα λόγια, η διαδρομή απαγορεύεται να διασχίσει
// τον δρόμο `(u, parent)`.
void compute_subtree_loop_opt(long u, long parent) {
  subtree_loop_opt[u] = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent) continue;
    compute_subtree_loop_opt(v, u);
    subtree_loop_opt[u] += positive_part(subtree_loop_opt[v] - 2*w);
  }
}

// Δεύτερη διάσχιση η οποία υπολογίζει το `supertree_loop_opt` για την κορυφή
// `u` κι όλους τους απογόνους της, χρησιμοποιώντας τις τιμές
// `subtree_loop_opt` που υπολογίσαμε ήδη στην πρώτη διάσχιση.
//
// supertree_loop_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει αλλά
// ΚΑΙ καταλήγει στην κορυφή `u`, και μένει πάντα ΕΚΤΟΣ του υποδέντρου που
// ορίζει η `u`. Το φιλοδώρημα της κορυφής `u` ΔΕΝ προσμετράται.
void compute_supertree_loop_opt(long u, long parent, long w) {
  supertree_loop_opt[u] = 0;

  // Αν η κορυφή `u` ΔΕΝ είναι ρίζα.
  if (parent != u)
    supertree_loop_opt[u] =
      positive_part(subtree_loop_opt[parent] + supertree_loop_opt[parent]
      - positive_part(subtree_loop_opt[u] - 2*w) - 2*w);

  for (auto [v, w]: tree[u])
    if (v != parent)
      compute_supertree_loop_opt(v, u, w);
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

  subtree_loop_opt.resize(n);
  compute_subtree_loop_opt(0, 0);

  supertree_loop_opt.resize(n);
  compute_supertree_loop_opt(0, 0, 0);

  for (long i = 0; i < q; ++i) {
    long L, R;
    scanf("%li%li", &L, &R);
    L--, R--;
    assert(L == R);

    printf("%lli\n", subtree_loop_opt[L] + supertree_loop_opt[L]);
  }

  return 0;
}

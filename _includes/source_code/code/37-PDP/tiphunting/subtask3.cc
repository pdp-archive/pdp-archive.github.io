#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

using ii = pair<int, int>;
using vvii = vector<vector<ii>>;

long positive_part(long x) { return max(0L, x); }

// Πρώτη διαπέραση η οποία υπολογίζει το `subtree_loop_opt` για την κορυφή `u`
// κι όλους τους απογόνους της.
//
// subtree_loop_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// και καταλλήγει πάλι πίσω στο `u`, παραμένοντας στο υποδέντρο που ορίζει
// η κορυφή `u` -- με άλλα λόγια, η διαδρομή απαγορεύεται να διασχίσει
// τον δρόμο `(u, parent)`.
void compute_subtree_loop_opt(vector<long>& subtree_loop_opt, const vvii& tree, const vector<int>& tip, int u, int parent) {
  subtree_loop_opt[u] = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent) continue;
    compute_subtree_loop_opt(subtree_loop_opt, tree, tip, v, u);
    subtree_loop_opt[u] += positive_part(subtree_loop_opt[v] - 2*w);
  }
}

// Δεύτερη διαπέραση η οποία υπολογίζει το `supertree_root_opt` για την κορυφή
// `u` κι όλους τους απογόνους της, χρησιμοποιώντας τις τιμές
// `subtree_loop_opt` που υπολογίσαμε ήδη στην πρώτη διαπέραση.
//
// supertree_root_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// από την κορυφή `u`, καταλλήγει στη ρίζα τους δέντρου και
// μένει πάντα ΕΚΤΟΣ του υποδέντρου που ορίζει η `u`. Το φιλοδώρημα της κορυφής
// `u` ΔΕΝ προσμετράται.
void compute_supertree_root_opt(vector<long>& supertree_root_opt, const vector<long>& subtree_loop_opt, const vvii& tree, int u, int parent, int w) {
  assert(0 <= u && u < tree.size());
  assert(-1 <= parent && parent < (long)tree.size());

  supertree_root_opt[u] = 0;

  if (parent != -1)
    supertree_root_opt[u] = subtree_loop_opt[parent] + supertree_root_opt[parent] - positive_part(subtree_loop_opt[u] - 2*w) - w;

  for (auto [v, w]: tree[u])
    if (v != parent)
      compute_supertree_root_opt(supertree_root_opt, subtree_loop_opt, tree, v, u, w);
}

int main() {
  int subtask;
  scanf("%i", &subtask);
  assert(subtask == 2 || subtask == 3);

  int n, q;
  scanf("%i%i", &n, &q);
  
  vector<int> tip(n);
  for (int i = 0; i < n; ++i)
    scanf("%i", &tip[i]);

  // Αναπαράσταση του δέντρου με adjacency list:
  // To `tree[u]` περιέχει ένα vector με pairs `(v, w)` για κάθε κορυφή `v` που
  // συνδέεται με τη `u` με κόστός `w`.
  vvii tree(n, vector<ii>{});
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    scanf("%i%i%i", &u, &v, &w);
    assert(1 <= u && u <= n);
    assert(1 <= v && v <= n);

    tree[u-1].push_back({v-1, w});
    tree[v-1].push_back({u-1, w});
  }

  for (int i = 0; i < q; ++i) {
    int src, dst;
    scanf("%i%i", &src, &dst);
    src -= 1;
    dst -= 1;

    vector<long> subtree_loop_opt(n), supertree_root_opt(n);
    compute_subtree_loop_opt(subtree_loop_opt, tree, tip, dst, -1);
    compute_supertree_root_opt(supertree_root_opt, subtree_loop_opt, tree, dst, -1, -1);

    printf("%li\n", subtree_loop_opt[src] + supertree_root_opt[src]);
  }

  return 0;
}

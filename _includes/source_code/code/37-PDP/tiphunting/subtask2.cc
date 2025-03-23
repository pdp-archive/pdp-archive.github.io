#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

using ll = pair<long, long>;
using vl = vector<long>;
using vvll = vector<vector<ll>>;

vvll tree;
vl tip;

long long positive_part(long long x) { return max(0LL, x); }

// Επιστρέφει το κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// από την κορυφή `u`, καταλήγει πίσω σε αυτή και παραμένει
// εξ' ολοκλήρου μέσα στο υποδέντρο που ορίζει η `u`. Με άλλα λόγια,
// η διαδρομή απαγορεύεται να διασχίσει το δρόμο `(u, parent)`.
long long best_subtree_tour(long u, long parent) {
  long long sol = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent) continue;
    long long s = best_subtree_tour(v, u);
    sol += positive_part(s - 2*w);
  }

  return sol;
}

int main() {
  int subtask;
  scanf("%i", &subtask);
  assert(subtask == 2);

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

  for (long i = 0; i < q; ++i) {
    long L, R;
    scanf("%li%li", &L, &R);
    L--, R--;
    assert(L == R);

    printf("%lli\n", best_subtree_tour(L, L));
  }

  return 0;
}

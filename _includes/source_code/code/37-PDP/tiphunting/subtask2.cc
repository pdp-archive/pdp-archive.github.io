#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

using ll = pair<long, long>;
using vvll = vector<vector<ll>>;

long long positive_part(long long x) { return max(0LL, x); }

// Επιστρέφει το κέρδος της βέλτιστης διαδρομή η οποία ξεκινάει
// από την κορυφή `u`, καταλλήγει πίσω σε αυτή και παραμένει
// εξ' ολοκλήρου μέσα στο υποδέντρο που ορίζει η `u` -- με άλλα λόγια,
// η διαδρομή απαγορεύεται να διασχίσει το δρόμο `(u, parent)`.
long long subtree_loop_opt(const vvll& tree, const vector<long>& tip, long u, long parent) {
  long long sol = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent) continue;
    long long s = subtree_loop_opt(tree, tip, v, u);
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
  assert(1 <= n && n <= 1'000);
  assert(1 <= q && q <= 1'000);
  
  vector<long> tip(n);
  for (long i = 0; i < n; ++i)
    scanf("%li", &tip[i]);

  // Αναπαράσταση του δέντρου με adjacency list:
  // To `tree[u]` περιέχει ένα vector με pairs `(v, w)` για κάθε κορυφή `v` που
  // συνδέεται με τη `u` με κόστός `w`.
  vvll tree(n);
  for (long i = 0; i < n-1; ++i) {
    long u, v, w;
    scanf("%li%li%li", &u, &v, &w);
    assert(1 <= u && u <= n);
    assert(1 <= v && v <= n);

    tree[u-1].push_back({v-1, w});
    tree[v-1].push_back({u-1, w});
  }

  for (long i = 0; i < q; ++i) {
    long src, dst;
    scanf("%li%li", &src, &dst);
    assert(src == dst);

    printf("%lli\n", subtree_loop_opt(tree, tip, src-1, -1));
  }

  return 0;
}

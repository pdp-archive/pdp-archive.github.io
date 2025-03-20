#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

using ii = pair<int, int>;
using vvii = vector<vector<ii>>;

long positive_part(long x) { return max(0L, x); }

// Επιστρέφει το κέρδος της βέλτιστης διαδρομή η οποία ξεκινάει
// από την κορυφή `u`, καταλλήγει πίσω σε αυτή και παραμένει
// εξ' ολοκλήρου μέσα στο υποδέντρο που ορίζει η `u` -- με άλλα λόγια,
// η διαδρομή απαγορεύεται να διασχίσει το δρόμο `(u, parent)`.
long subtree_loop_opt(const vvii& tree, const vector<int>& tip, int u, int parent) {
  long sol = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent) continue;
    long s = subtree_loop_opt(tree, tip, v, u);
    sol += positive_part(s - 2*w);
  }

  return sol;
}

int main() {
  int subtask;
  scanf("%i", &subtask);
  assert(subtask == 2);

  int n, q;
  scanf("%i%i", &n, &q);
  assert(1 <= n && n <= 1'000);
  assert(1 <= q && q <= 1'000);
  
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
    assert(src == dst);

    printf("%li\n", subtree_loop_opt(tree, tip, src-1, -1));
  }

  return 0;
}

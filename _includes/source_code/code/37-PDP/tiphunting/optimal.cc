#include <cstdio>
#include <cassert>
#include <vector>
#include <cmath>
// #define DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__) 
#else
#define debug(...)
#endif

using namespace std;

using ii = pair<int, int>;
using iii = pair<int, pair<int, int>>;
using vvii = vector<vector<ii>>;
using vvi = vector<vector<int>>;

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

// Τρίτη διαπέραση η οποία υπολογίζει το `supertree_loop_opt` για την κορυφή
// `u` κι όλους τους απογόνους της, χρησιμοποιώντας τις τιμές
// `subtree_loop_opt` που υπολογίσαμε ήδη στην πρώτη διαπέραση.
//
// supertree_loop_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει αλλά
// ΚΑΙ καταλήγει στην κορυφή `u`, και μένει πάντα ΕΚΤΟΣ του υποδέντρου που
// ορίζει η `u`. Το φιλοδώρημα της κορυφής `u` ΔΕΝ προσμετράται.
void compute_supertree_loop_opt(vector<long>& supertree_loop_opt, const vector<long>& subtree_loop_opt, const vvii& tree, int u, int parent, int w) {
  assert(0 <= u && u < tree.size());
  assert(-1 <= parent && parent < (long)tree.size());

  supertree_loop_opt[u] = 0;

  if (parent != -1)
    supertree_loop_opt[u] = positive_part(subtree_loop_opt[parent] + supertree_loop_opt[parent] - positive_part(subtree_loop_opt[u] - 2*w) - 2*w);

  for (auto [v, w]: tree[u])
    if (v != parent)
      compute_supertree_loop_opt(supertree_loop_opt, subtree_loop_opt, tree, v, u, w);
}

void preprocess(const vvii& tree, int u, vector<int>& depth, vector<int>& parent, vector<int>& parent_weight) {
  const int n = tree.size();
  assert(depth.size() >= n);
  assert(parent.size() >= n);
  assert(parent_weight.size() >= n);
  assert(0 <= u && u < n);

  for (auto [v, w]: tree[u]) {
    if (v == parent[u]) continue;
    assert(0 <= v && v < n);

    parent[v] = u;
    parent_weight[v] = w;
    depth[v] = depth[u] + 1;

    preprocess(tree, v, depth, parent, parent_weight);
  }
}

// Set `pred[h][u] = v` when `v` is the `2^h`-th predecessor of `u`
// according to the `parent` relation.
void compute_pred(const vector<int>& parent, vvi& pred) {
  const int H = pred.size() - 1;
  const int n = parent.size();

  for (int u = 0; u < n; ++u)
    pred[0][u] = parent[u];

  for (int h = 1; h <= H; ++h)
    for (int u = 0; u < n; ++u) {
      assert(0 <= pred[h-1][u] && pred[h-1][u] < n);
      pred[h][u] = pred[h-1][ pred[h-1][u] ];
    }
}


iii lca(const vector<vector<int>>& pred, const vector<int>& depth, int u, int v) {
  const int H = pred.size() - 1;

  if (u == v)
    return {u, {-1, -1}};

  if (depth[u] < depth[v]) {
    auto [w, ij] = lca(pred, depth, v, u);
    auto [i, j] = ij;
    return {w, {j, i}};
  }

  if (depth[u] != depth[v]) {
    for (int h = H; h >= 0; h--)
      if (depth[ pred[h][u] ] > depth[v])
        u = pred[h][u];
    
    assert(depth[pred[0][u]] == depth[v]);

    if (pred[0][u] == v)
      return { v, { u, -1} };

    u =pred[0][u];
  }

  assert(depth[u] == depth[v]);
  assert(u != v);

  for (int h = H; h >= 0; --h) {
    if (pred[h][u] != pred[h][v]) {
      u = pred[h][u];
      v = pred[h][v];
    }
  }

  assert(pred[0][u] == pred[0][v]);
  return { pred[0][u], { u, v } };
}

int main() {
  int subtask;
  scanf("%i", &subtask);

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

  debug("Read the tree\n");

  // "Hang" the tree from node 0 and compute the depth of each node.
  vector<int> depth(n, 0), parent(n, 0), parent_weight(n, 0);
  debug("Created vectors\n");
  preprocess(tree, 0, depth, parent, parent_weight);
  debug("preprocessed\n");

  int max_depth = 0;
  for (int i = 0; i < n; ++i)
    max_depth = max(max_depth, depth[i]);

  // Using the parent relation, compute `pred[h][u]`, the `2^h`-th predecessor
  // of each node `u` for every `h \in {0, 1, ..., ceil(log_2(n-1))}`.
  // const int H = int(ceil(log2(n-1)));
  const int H = int(ceil(log2(max_depth)));
  vector<vector<int>> pred(H+1, vector<int>(n, 0));
  compute_pred(parent, pred);
  debug("computed pred\n");

  vector<long> subtree_loop_opt(n), supertree_root_opt(n), supertree_loop_opt(n);
  compute_subtree_loop_opt(subtree_loop_opt, tree, tip, 0, -1);
  debug("done with pass1\n");
  compute_supertree_root_opt(supertree_root_opt, subtree_loop_opt, tree, 0, -1, -1);
  debug("done with pass2\n");
  compute_supertree_loop_opt(supertree_loop_opt, subtree_loop_opt, tree, 0, -1, -1);
  debug("done with pass3\n");

  for (int i = 0; i < q; ++i) {
    int src, dst;
    scanf("%i%i", &src, &dst);
    src -= 1;
    dst -= 1;

    if (src == dst) {
      printf("%li\n", subtree_loop_opt[src] + supertree_loop_opt[src]);
      continue;
    }

    auto [mid, uv] = lca(pred, depth, src, dst);
    auto [u, v] = uv;
    assert(u != -1 || v != -1);
    debug("LCA(%i, %i) = (%i, (%i, %i))\n", src+1, dst+1, mid+1, u+1, v+1);

    long sol = 0;
    if (u == -1) {
      // src is an ancestor of dst.
      assert(mid == src);
      sol = supertree_root_opt[dst] - supertree_root_opt[src] + supertree_loop_opt[src] + subtree_loop_opt[dst];
    } else if (v == -1) {
      // dst is an ancestor of src.
      assert(mid == dst);
      sol = supertree_root_opt[src] - supertree_root_opt[dst] + supertree_loop_opt[dst] + subtree_loop_opt[src];
    } else {
      // `src` and `dst` have a common ancestor.
      assert(pred[0][u] == mid);
      assert(pred[0][v] == mid);

      sol = supertree_root_opt[src] + subtree_loop_opt[src] - supertree_root_opt[u];
      debug("%li, ", sol);
      sol += supertree_root_opt[dst] + subtree_loop_opt[dst] - supertree_root_opt[v];
      debug("%li, ", sol);
      sol -= (parent_weight[u] + parent_weight[v]);
      debug("%li, ", sol);

      sol += subtree_loop_opt[mid];
      debug("%li, ", sol);
      sol -= positive_part(subtree_loop_opt[u] - 2*parent_weight[u]);
      debug("%li, ", sol);
      sol -= positive_part(subtree_loop_opt[v] - 2*parent_weight[v]);
      debug("%li, ", sol);

      sol += supertree_loop_opt[mid];
      debug("%li, ", sol);
      debug("\n");
    }

    printf("%li\n", sol);
  }

  return 0;
}

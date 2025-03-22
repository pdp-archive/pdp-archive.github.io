#include <cstdio>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

using ll = pair<long, long>;
using lll = tuple<long, long, long>;
using vvll = vector<vector<ll>>;
using vl = vector<long>;
using vvl = vector<vector<long>>;

vvll tree;
vl tip, depth, parent, parent_weight;
vvl pred;
vector<long long> subtree_loop_opt, supertree_loop_opt, supertree_root_opt;

long long positive_part(long long x) { return max(0LL, x); }

// Αρχικοποίηση όλων των global vectors για ένα δέντρο με `n` κορυφές. 
void init(int n) {
  // ceil(log2(max_N))
  constexpr int kMaxH = 18;

  tip.resize(n);
  tree.resize(n);

  // Αρχικοποιώντας `depth[0] = 0`, `parent[0] = 0` θέτουμε την κορυφή
  // 0 ως ρίζα του δέντρου. Η συνάρτηση `compute_auxiliary` συμπληρώνει
  // τις τιμές και για τους υπόλοιπους κόμβους.
  depth.resize(n, 0);
  parent.resize(n, 0);
  parent_weight.resize(n, 0);

  pred.resize(kMaxH, vector<long>(n));
  subtree_loop_opt.resize(n);
  supertree_loop_opt.resize(n);
  supertree_root_opt.resize(n);
}

// Διασχίζει το δέντρο `tree` ξεκινώντας από την κορυφή `u` και υπολογίζει
// αναδρομικά τις τιμές `depth[v]`, `parent[v]` και `parent_weight[v]` για κάθε
// κορυφή `v != u` στο υποδέντρο της `u`. Οι τιμές `depth[u]`, `parent[u]` και
// `parent_weight[u]` θα πρέπει να έχουν ήδη υπολογισθεί από τον caller.
//
// `depth[u]`: Το βάθος του `u` στο δέντρο, το οποίο ορίζεται ως το πλήθος
// των ακμών στο μονοπάτι από τον `u` προς τη ρίζα. Για παράδειγμα το βάθος
// της ρίζας είναι 0.
// `parent[u]`: Ο γονέας του `u`.
// `parent_weight[u]`: Κόστος του δρόμου που συνδέει τον `u` με τον γονέα του.
void compute_auxiliary(int u) {
  for (auto [v, w]: tree[u]) {
    if (v == parent[u]) continue;
    parent[v] = u;
    parent_weight[v] = w;
    depth[v] = depth[u] + 1;

    compute_auxiliary(v);
  }
}

// Διασχίζει το δέντρο `tree` και υπολογίζει αναδρομικά τις τιμές
// `subtree_loop_opt` για την κορυφή `u` κι όλους τους απογόνους της.
//
// `subtree_loop_opt[u]`: Το κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// και καταλήγει πάλι πίσω στο `u`, παραμένοντας στο υποδέντρο που ορίζει
// η κορυφή `u`. Mε άλλα λόγια, η διαδρομή απαγορεύεται να διασχίσει
// τον δρόμο `(u, parent)`.
void compute_subtree_loop_opt(long u) {
  subtree_loop_opt[u] = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent[u]) continue;
    compute_subtree_loop_opt(v);
    subtree_loop_opt[u] += positive_part(subtree_loop_opt[v] - 2*w);
  }
}

// Διασχίζει το δέντρο `tree` και υπολογίζει αναδρομικά τις τιμές
// `subtree_root_opt` για την κορυφή `u` κι όλους τους απογόνους της,
// χρησιμοποιώντας τις τιμές `subtree_loop_opt` που υπολογίσαμε ήδη στην
// προηγούμενη διάσχιση.
//
// `supertree_root_opt[u]`: Το κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// από την κορυφή `u`, καταλήγει στη ρίζα του δέντρου και
// μένει πάντα ΕΚΤΟΣ του υποδέντρου που ορίζει η `u`. Το φιλοδώρημα της κορυφής
// `u` ΔΕΝ προσμετράται.
void compute_supertree_root_opt(long u) {
  supertree_root_opt[u] = 0;

  // Αν η κορυφή `u` ΔΕΝ είναι ρίζα.
  if (parent[u] != u)
    supertree_root_opt[u] =
      subtree_loop_opt[parent[u]] + supertree_root_opt[parent[u]]
    - positive_part(subtree_loop_opt[u] - 2*parent_weight[u]) - parent_weight[u];

  for (auto [v, w]: tree[u])
    if (v != parent[u])
      compute_supertree_root_opt(v);
}

// Διασχίζει το δέντρο `tree` και υπολογίζει αναδρομικά τις τιμές
// `subtree_loop_opt` για την κορυφή `u` κι όλους τους απογόνους της,
// χρησιμοποιώντας τις τιμές `subtree_loop_opt` που υπολογίσαμε ήδη στην
// προηγούμενη διάσχιση.
//
// supertree_loop_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει αλλά
// ΚΑΙ καταλήγει στην κορυφή `u`, και μένει πάντα ΕΚΤΟΣ του υποδέντρου που
// ορίζει η `u`. Το φιλοδώρημα της κορυφής `u` ΔΕΝ προσμετράται.
void compute_supertree_loop_opt(int u) {
  supertree_loop_opt[u] = 0;

  // Αν η κορυφή `u` ΔΕΝ είναι ρίζα.
  if (parent[u] != u)
    supertree_loop_opt[u] =
      positive_part(subtree_loop_opt[parent[u]] + supertree_loop_opt[parent[u]]
    - positive_part(subtree_loop_opt[u] - 2*parent_weight[u]) - 2*parent_weight[u]);

  for (auto [v, w]: tree[u])
    if (v != parent[u])
      compute_supertree_loop_opt(v);
}

// Υπολογίζει τον πίνακα `pred` έτσι ώστε για κάθε 0 <= h <= H, 0 <= u < N:
// `pred[h][u] == v` αν και μόνο αν ο `v` είναι ο `2^h`-πρόγονος του `u`.
// Για παράδειγμα `pred[0][u] == parent[u]` γιατί ο γονέας του $u$
// είναι ο `2^0 = 1`-ος πρόγονός του.
// O caller θα πρέπει να έχει ήδη υπολογίσει τον πίνακα parent
// (δες `compute_auxiliary`) έτσι ώστε η τιμή `parent[u]` να είναι
// ο γονέας της `u`, εκτός από την ρίζα `r` για την οποία `r == parent[r]`.
void compute_pred() {
  const long n = parent.size();
  const long H = pred.size() - 1;

  for (long u = 0; u < n; ++u)
    pred[0][u] = parent[u];

  for (long h = 1; h <= H; ++h)
    for (long u = 0; u < n; ++u)
      pred[h][u] = pred[h - 1][pred[h - 1][u]];
}

// Υπολογίζει τρεις τιμές `(z, a, b)` όπου `z` είναι ο Ελάχιστος Κοινός Πρόγονος
// (LCA) των `u, v`, η `a` είναι η μοναδική κορυφή στο μονοπάτι από `a` προς `z`
// για την οποία `parent[u] == z` (ή `a == -1` αν τέτοια κορυφή δεν υπάρχει) και
// αντίστοιχα `b` είναι η μοναδική κορυφή στο μονοπάτι από `z` προς `v` τέτοια
// ώστε `parent[v] == z` (ή `b == -1` αν τέτοια κορυφή δεν υπάρχει).
// 
// Η συνάρτηση χρησιμοποιεί τον πίνακα `pred` που υπολόγισε νωρίτερα η
// συνάρτηση `compute_pred` καθώς και τον πίνακα `depth` που υπολόγισε νωρίτερα
// η συνάρτηση `compute_auxiliary`.
lll lca(long u, long v) {
  const long H = pred.size() - 1;

  if (u == v)
    return {u, -1, -1};

  if (depth[u] < depth[v]) {
    auto [w, i, j] = lca(v, u);
    return {w, j, i};
  }

  if (depth[u] != depth[v]) {
    for (long h = H; h >= 0; h--)
      if (depth[ pred[h][u] ] > depth[v])
        u = pred[h][u];

    if (pred[0][u] == v)
      return { v,  u, -1 };

    u = pred[0][u];
  }

  for (long h = H; h >= 0; --h) {
    if (pred[h][u] != pred[h][v]) {
      u = pred[h][u];
      v = pred[h][v];
    }
  }

  return { pred[0][u], u, v };
}

int main() {
  int subtask;
  scanf("%i", &subtask);

  long n, q;
  scanf("%li%li", &n, &q);
  
  init(n);

  for (long i = 0; i < n; ++i)
    scanf("%li", &tip[i]);

  // Αναπαράσταση του δέντρου με adjacency list:
  // To `tree[u]` περιέχει ένα vector με pairs `(v, w)` για κάθε κορυφή `v` που
  // συνδέεται με τη `u` με κόστός `w`.
  for (long i = 0; i < n-1; ++i) {
    long u, v, w;
    scanf("%li%li%li", &u, &v, &w);

    tree[u-1].push_back({v-1, w});
    tree[v-1].push_back({u-1, w});
  }

  compute_auxiliary(0);

  compute_pred();

  compute_subtree_loop_opt(0);
  compute_supertree_loop_opt(0);
  compute_supertree_root_opt(0);

  for (long i = 0; i < q; ++i) {
    long L, R;
    scanf("%li%li", &L, &R);
    L--, R--;

    if (L == R) {
      printf("%lli\n", subtree_loop_opt[L] + supertree_loop_opt[L]);
      continue;
    }

    auto [z, u, v] = lca(L, R);
    assert(u != -1 || v != -1);

    long long sol = 0;
    if (u == -1) {
      // Η κορυφή `L` είναι πρόγονος της `R`.
      assert(z == L);
      sol = supertree_root_opt[R] - supertree_root_opt[L] + supertree_loop_opt[L] + subtree_loop_opt[R];
    } else if (v == -1) {
      // Η κορυφή `R` είναι πρόγονος της `L`.
      assert(z == R);
      sol = supertree_root_opt[L] - supertree_root_opt[R] + supertree_loop_opt[R] + subtree_loop_opt[L];
    } else {
      // Οι κορυφές `L, R` έχουν κοινό πρόγονο τον `z != L, R`.
      assert(pred[0][u] == z);
      assert(pred[0][v] == z);

      sol = supertree_root_opt[L] - supertree_root_opt[u] + subtree_loop_opt[L] // (a)
            + supertree_root_opt[R] - supertree_root_opt[v] + subtree_loop_opt[R] // (b)
            + subtree_loop_opt[z] // (c1)
            - positive_part(subtree_loop_opt[u] - 2*parent_weight[u]) // (c2)
            - positive_part(subtree_loop_opt[v] - 2*parent_weight[v]) // (c3)
            + supertree_loop_opt[z] // (d)
            - (parent_weight[u] + parent_weight[v]); // (e)
    }

    printf("%lli\n", sol);
  }

  return 0;
}

#include <cstdio>
#include <cassert>
#include <vector>
#include <cmath>
// #define DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

using namespace std;

using ll = pair<long, long>;
using lll = tuple<long, long, long>;
using vvll = vector<vector<ll>>;
using vvl = vector<vector<long>>;

long long positive_part(long long x) { return max(0LL, x); }

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
void compute_auxiliary(const vvll& tree, int u, vector<long>& depth, vector<long>& parent, vector<long>& parent_weight) {
  const long n = tree.size();
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

    compute_auxiliary(tree, v, depth, parent, parent_weight);
  }
}

// Διασχίζει το δέντρο `tree` και υπολογίζει αναδρομικά τις τιμές
// `subtree_loop_opt` για την κορυφή `u` κι όλους τους απογόνους της. Η τιμή της
// `parent` είναι ο γονέας της `u`.
//
// `subtree_loop_opt[u]`: Το κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// και καταλήγει πάλι πίσω στο `u`, παραμένοντας στο υποδέντρο που ορίζει
// η κορυφή `u`. Mε άλλα λόγια, η διαδρομή απαγορεύεται να διασχίσει
// τον δρόμο `(u, parent)`.
void compute_subtree_loop_opt(vector<long long> &subtree_loop_opt, const vvll &tree, const vector<long> &tip, long u, long parent) {
  subtree_loop_opt[u] = tip[u];

  for (auto [v, w]: tree[u]) {
    if (v == parent) continue;
    compute_subtree_loop_opt(subtree_loop_opt, tree, tip, v, u);
    subtree_loop_opt[u] += positive_part(subtree_loop_opt[v] - 2*w);
  }
}

// Διασχίζει το δέντρο `tree` και υπολογίζει αναδρομικά τις τιμές
// `subtree_root_opt` για την κορυφή `u` κι όλους τους απογόνους της,
// χρησιμοποιώντας τις τιμές `subtree_loop_opt` που υπολογίσαμε ήδη στην
// προηγούμενη διάσχιση. Η τιμή της `parent` είναι ο γονέας της `u`.
//
// `supertree_root_opt[u]`: Το κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει
// από την κορυφή `u`, καταλήγει στη ρίζα του δέντρου και
// μένει πάντα ΕΚΤΟΣ του υποδέντρου που ορίζει η `u`. Το φιλοδώρημα της κορυφής
// `u` ΔΕΝ προσμετράται.
void compute_supertree_root_opt(vector<long long>& supertree_root_opt, const vector<long long>& subtree_loop_opt, const vvll& tree, long u, long parent, long w) {
  assert(0 <= u && u < tree.size());
  assert(-1 <= parent && parent < (long)tree.size());

  supertree_root_opt[u] = 0;

  if (parent != -1)
    supertree_root_opt[u] = subtree_loop_opt[parent] + supertree_root_opt[parent] - positive_part(subtree_loop_opt[u] - 2*w) - w;

  for (auto [v, w]: tree[u])
    if (v != parent)
      compute_supertree_root_opt(supertree_root_opt, subtree_loop_opt, tree, v, u, w);
}

// Διασχίζει το δέντρο `tree` και υπολογίζει αναδρομικά τις τιμές
// `subtree_loop_opt` για την κορυφή `u` κι όλους τους απογόνους της,
// χρησιμοποιώντας τις τιμές `subtree_loop_opt` που υπολογίσαμε ήδη στην
// προηγούμενη διάσχιση. Η τιμή της `parent` είναι ο γονέας της `u`.
//
// supertree_loop_opt[u] = κέρδος της βέλτιστης διαδρομής η οποία ξεκινάει αλλά
// ΚΑΙ καταλήγει στην κορυφή `u`, και μένει πάντα ΕΚΤΟΣ του υποδέντρου που
// ορίζει η `u`. Το φιλοδώρημα της κορυφής `u` ΔΕΝ προσμετράται.
void compute_supertree_loop_opt(vector<long long>& supertree_loop_opt, const vector<long long>& subtree_loop_opt, const vvll& tree, int u, int parent, int w) {
  assert(0 <= u && u < tree.size());
  assert(-1 <= parent && parent < (long)tree.size());

  supertree_loop_opt[u] = 0;

  if (parent != -1)
    supertree_loop_opt[u] = positive_part(subtree_loop_opt[parent] + supertree_loop_opt[parent] - positive_part(subtree_loop_opt[u] - 2*w) - 2*w);

  for (auto [v, w]: tree[u])
    if (v != parent)
      compute_supertree_loop_opt(supertree_loop_opt, subtree_loop_opt, tree, v, u, w);
}

// Υπολογίζει τον πίνακα `pred` έτσι ώστε:
// `pred[h][u] == v` αν και μόνο αν ο `v` είναι ο `2^h`-πρόγονος του `u`.
// Για παράδειγμα `pred[0][u] == parent[u]` γιατί ο γονέας του $u$
// είναι ο `2^0 = 1`-ος πρόγονός του.
// Ο πίνακας εισόδου `parent` θα πρέπει για κάθε κορυφή να περιέχει
// τον γονέα της, εκτός από την ρίζα `r` για την οποία θα πρέπει να ισχύει
// `parent[r] == r`.
void compute_pred(const vector<long> &parent, vvl &pred)
{
  const long H = pred.size() - 1;
  const long n = parent.size();

  for (long u = 0; u < n; ++u)
    pred[0][u] = parent[u];

  for (long h = 1; h <= H; ++h)
    for (long u = 0; u < n; ++u)
    {
      assert(0 <= pred[h - 1][u] && pred[h - 1][u] < n);
      pred[h][u] = pred[h - 1][pred[h - 1][u]];
    }
}

// Υπολογίζει τρεις τιμές `(z, a, b)` όπου `z` είναι ο Ελάχιστος Κοινός Πρόγονος
// (LCA) των `u, v`, η `a` είναι η μοναδική κορυφή στο μονοπάτι από `a` προς `z`
// για την οποία `parent[u] == z` (ή `a == -1` αν τέτοια κορυφή δεν υπάρχει) και
// αντίστοιχα `b` είναι η μοναδική κορυφή στο μονοπάτι από `z` προς `v` τέτοια
// ώστε `parent[v] == z` (ή `b == -1` αν τέτοια κορυφή δεν υπάρχει).
// 
// Η συνάρτηση λαμβάνει ως είσοδο και τον πίνακα `pred` που υπολόγισε νωρίτερα η
// συνάρτηση `compute_pred` καθώς και τον πίνακα `depth` που υπολόγισε νωρίτερα
// η συνάρτηση `compute_auxiliary`.
lll lca(const vector<vector<long>> &pred, const vector<long> &depth, long u, long v) {
  const long H = pred.size() - 1;

  if (u == v)
    return {u, -1, -1};

  if (depth[u] < depth[v]) {
    auto [w, i, j] = lca(pred, depth, v, u);
    return {w, j, i};
  }

  if (depth[u] != depth[v]) {
    for (long h = H; h >= 0; h--)
      if (depth[ pred[h][u] ] > depth[v])
        u = pred[h][u];
    
    assert(depth[pred[0][u]] == depth[v]);

    if (pred[0][u] == v)
      return { v,  u, -1 };

    u =pred[0][u];
  }

  assert(depth[u] == depth[v]);
  assert(u != v);

  for (long h = H; h >= 0; --h) {
    if (pred[h][u] != pred[h][v]) {
      u = pred[h][u];
      v = pred[h][v];
    }
  }

  assert(pred[0][u] == pred[0][v]);
  return { pred[0][u], u, v };
}

int main() {
  int subtask;
  scanf("%i", &subtask);

  long n, q;
  scanf("%li%li", &n, &q);
  
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

  // Αρχικοποιώντας `depth[0] = 0`, `parent[0] = 0` θέτουμε την κορυφή
  // 0 ως ρίζα του δέντρου. Η συνάρτηση `compute_auxiliary` συμπληρώνει
  // τις τιμές και για τους υπόλοιπους κόμβους.
  vector<long> depth(n, 0), parent(n, 0), parent_weight(n, 0);
  compute_auxiliary(tree, 0, depth, parent, parent_weight);

  // Θα χρειαστούμε το μέγιστο βάθος ώστε να υπολογίσουμε τις διαστάσεις
  // πίνακα `pred` παρακάτω.
  long max_depth = 0;
  for (long i = 0; i < n; ++i)
    max_depth = max(max_depth, depth[i]);

  // Υπολογισμός του πίνακα `pred` από τον πίνακα `parent`.
  // Το δέντρο έχει ύψος `max_depth` επομένως θα χρειαστούμε τους
  // απογόνους (predecessors) το πολύ μέχρι `max_depth <= 2^H` επίπεδα παραπάνω.
  const long H = long(ceil(log2(max_depth)));
  vector<vector<long>> pred(H+1, vector<long>(n, 0));
  compute_pred(parent, pred);

  vector<long long> subtree_loop_opt(n), supertree_root_opt(n), supertree_loop_opt(n);
  compute_subtree_loop_opt(subtree_loop_opt, tree, tip, 0, -1);
  compute_supertree_root_opt(supertree_root_opt, subtree_loop_opt, tree, 0, -1, -1);
  compute_supertree_loop_opt(supertree_loop_opt, subtree_loop_opt, tree, 0, -1, -1);

  for (long i = 0; i < q; ++i) {
    long L, R;
    scanf("%li%li", &L, &R);
    L -= 1;
    R -= 1;

    if (L == R) {
      printf("%lli\n", subtree_loop_opt[L] + supertree_loop_opt[L]);
      continue;
    }

    auto [z, u, v] = lca(pred, depth, L, R);
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

      // (a)
      sol = supertree_root_opt[L] - supertree_root_opt[u] + subtree_loop_opt[L] ;

      // (b)
      sol += supertree_root_opt[R] - supertree_root_opt[v] + subtree_loop_opt[R];

      // (c)
      sol += subtree_loop_opt[z];
      sol -= positive_part(subtree_loop_opt[u] - 2*parent_weight[u]);
      sol -= positive_part(subtree_loop_opt[v] - 2*parent_weight[v]);

      // (d)
      sol += supertree_loop_opt[z];
      
      // (e)
      sol -= (parent_weight[u] + parent_weight[v]);
    }

    printf("%lli\n", sol);
  }

  return 0;
}

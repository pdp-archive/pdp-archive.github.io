#include <cstdio>
#include <stack>
#include <vector>

std::vector<std::vector<long>> adj;
std::vector<long> cycle;
std::vector<long> index_in_cycle;

/* Βρίσκουμε ποιοι κόμβοι ανήκουν στον κύκλο. 
   Το κάνουμε αυτό κρατώντας μία στοίβα με τους κόμβους που είναι στο μονοπάτι 
   της DFS. Όταν βρούμε δύο φορές τον ίδιο κόμβο, το μονοπάτι έγινε κύκλος. */
std::vector<long> is_on_stack;
void find_cycle() {
  std::stack<std::tuple<long, long, long>> st;
  st.push({ 1, -1, 0 });
  while (!st.empty()) {
    auto [node, par, neigh_idx] = st.top();
    st.pop();
    if (neigh_idx == 0 && is_on_stack[node]) {
      // Βρήκαμε τον κύκλο. 
      long prev, idx = 0;
      do {
        prev = std::get<0>(st.top());
        index_in_cycle[prev] = cycle.size();
        cycle.push_back(prev);
        st.pop();
      } while (prev != node);
      return;
    }
    is_on_stack[node] = true;
    if (adj[node].size() > neigh_idx && adj[node][neigh_idx] == par) ++neigh_idx;
    if (adj[node].size() > neigh_idx) {
      st.push({ node, par, neigh_idx + 1 });
      st.push({ adj[node][neigh_idx], node, 0 });
    } else {
      is_on_stack[node] = false;
    }
  }
}

/* Το μακρύτερο μονοπάτι από έναν κόμβο χωρίς να διατρέχουμε τις ακμές του κύκλου. */
std::pair<long /* max_distance */, long /* node */> furthest_node_avoiding_cycle(long node) {
  long max_depth = 0;
  long max_depth_node = node;
  
  std::stack<std::tuple<long, long, long, long>> st;
  st.push({node, -1, 0, 0 });
  while (!st.empty()) {
    auto [node, par, neigh_idx, depth] = st.top();
    st.pop();
    // Προσπερνάμε τον πατέρα και άλλους κόμβους στον κύκλο.
    while (adj[node].size() > neigh_idx 
      && (adj[node][neigh_idx] == par || index_in_cycle[adj[node][neigh_idx]] != -1)) ++neigh_idx;
    if (adj[node].size() > neigh_idx) {
      st.push({ node, par, neigh_idx + 1, depth });
      st.push({ adj[node][neigh_idx], node, 0, depth + 1 });
      if (max_depth < depth + 1) {
        max_depth = depth + 1;
        max_depth_node = node;
      }
    }
  }
  return {max_depth, max_depth_node};
}

int main() {
  FILE *fi = fopen("reviews.in", "r");
  long T, N;
  fscanf(fi, "%ld%ld", &T, &N);
  adj.resize(N+1);
  std::vector<std::pair<long, long>> edges(N+1);
  for (long i = 1; i <= N; ++i) {
    long tmp;
    fscanf(fi, "%ld", &tmp);
    edges[i] = {i, tmp};
    adj[i].push_back(tmp);
    adj[tmp].push_back(i);
  }
  fclose(fi);
  
  index_in_cycle.resize(N+1, -1);
  is_on_stack.resize(N+1, false);
  find_cycle();
  
  std::vector<long> w(N+1, 0);
  long mx_internal_dist = 0;
  for (auto node : cycle) {
    // Υπολογίζουμε για κάθε κόμβο στον κύκλο, το βάθος του υποδέντρου του.
    auto [d, furthest_node] = furthest_node_avoiding_cycle(node);
    w[node] = d;
    
    // Βρίσκουμε την μακρύτερη απόσταση μέσα στο υποδέντρο του.
    // "Βγάζουμε" τον κόμβο από τον κύκλο για να επιτρέψουμε μονοπάτια που μπορεί να
    // διέρχονται από αυτό.
    long tmp = index_in_cycle[node];
    index_in_cycle[node] = -1;
    auto [dist, y] = furthest_node_avoiding_cycle(furthest_node);
    index_in_cycle[node] = tmp;
    
    // Υπολογίζουμε την μεγαλύτερη από τις αποστάσεις σε ένα από τα δέντρα.
    mx_internal_dist = std::max(mx_internal_dist, std::max(dist+1, w[node]) + 1);
  }
  
  FILE *fo = fopen("reviews.out", "w");
  for (long i = 1; i <= N; ++i) {
    if (index_in_cycle[i] == -1 || index_in_cycle[edges[i].second] == -1) {
      // Αν κάποια από τις δύο κορυφές δεν είναι στον κύκλο, τότε
      // ο γράφος δεν είναι συνδεδεμένος.
      fprintf(fo, "-1\n");
    } else {
      long u = i, v = edges[i].second;
      if (index_in_cycle[v] == (index_in_cycle[u] + 1) % cycle.size()) u = v;
      // Δοκιμάσουμε όλα τα δυνατά ζεύγη από κόμβους στον κύκλο:
      // Το μονοπάτι ξεκινάει στον j-οστό κόμβο στον κύκλο και καταλήγει στον jj-οστό.
      // Στους δύο ακριανούς κόμβους επιλέγουμε το μακρύτερο μονοπάτι. 
      long mx = 0;
      for (long j = 0; j < cycle.size(); ++j) {
        long idx_j = (index_in_cycle[u] + j) % cycle.size();
        for (long jj = j + 1; jj < cycle.size(); ++jj) {
          long idx_jj = (index_in_cycle[u] + jj) % cycle.size();
          long candidate = (jj - j) + w[cycle[idx_j]] + w[cycle[idx_jj]] + 1;
          mx = std::max(mx, candidate);
        }
      }
      // Η απάντηση είναι η μέγιστη από το mx και την μεγαλύτερη απόσταση δύο κόμβων, 
      // που περιέχεται πλήρως σε κάποιο από τα υποδέντρα.
      fprintf(fo, "%ld\n", std::max(mx, mx_internal_dist));
    }
  }
  fclose(fo);
  return 0;
}


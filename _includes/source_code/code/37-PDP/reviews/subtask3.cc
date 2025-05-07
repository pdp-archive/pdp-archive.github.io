#include <cstdio>
#include <stack>
#include <vector>

std::vector<std::vector<long>> adj;
std::vector<long> in_cycle;

/* Βρίσκουμε ποιοι κόμβοι ανήκουν στον κύκλο. 
   Το κάνουμε αυτό κρατώντας μία στοίβα με τους κόμβους που είναι στο μονοπάτι 
   της DFS. Όταν βρούμε δύο φορές τον ίδιο κόμβο, το μονοπάτι έγινε κύκλος. */
void find_cycle() {
  std::stack<std::tuple<long, long, long>> st;
  std::vector<long> is_on_stack(adj.size(), false);
  st.push({ 1, -1, 0 });
  while (!st.empty()) {
    auto [node, par, neigh_idx] = st.top();
    st.pop();
    if (neigh_idx == 0 && is_on_stack[node]) {
      // Βρήκαμε τον κύκλο. 
      long prev, idx = 0;
      do {
        prev = std::get<0>(st.top());
        in_cycle[prev] = true;
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

bool are_same_edge(std::pair<long, long> p1, std::pair<long, long> p2) {
  return p1 == p2 || (std::make_pair(p1.second, p1.first) == p2);
}

/* Το μακρύτερο μονοπάτι από έναν κόμβο χωρίς να διατρέχουμε την δοσμένη ακμή. */
std::pair<long /* max_distance */, long /* node */> furthest_node_avoiding_edge(
    long node,
    std::pair<long, long> restricted_edge) {
  long max_depth = 0;
  long max_depth_node = node;
  
  std::stack<std::tuple<long, long, long, long>> st;
  st.push({node, -1, 0, 0 });
  while (!st.empty()) {
    auto [node, par, neigh_idx, depth] = st.top();
    st.pop();
    // Προσπερνάμε τον πατέρα και άλλους κόμβους στον κύκλο.
    while (adj[node].size() > neigh_idx 
      && (adj[node][neigh_idx] == par 
          || are_same_edge({node, adj[node][neigh_idx]}, restricted_edge))) ++neigh_idx;
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
  
  in_cycle.resize(N+1, false);
  find_cycle();
  
  FILE *fo = fopen("reviews.out", "w");
  for (long i = 1; i <= N; ++i) {
    if (!in_cycle[i] || !in_cycle[edges[i].second]) {
      // Αν κάποια από τις δύο κορυφές δεν είναι στον κύκλο, τότε
      // ο γράφος δεν είναι συνδεδεμένος.
      fprintf(fo, "-1\n");
    } else {
      auto [x, furthest_node_from_1] = furthest_node_avoiding_edge(1, edges[i]);
      auto [dist, y] = furthest_node_avoiding_edge(furthest_node_from_1, edges[i]);
      fprintf(fo, "%ld\n", dist+2);
    }
  }
  fclose(fo);
  return 0;
}


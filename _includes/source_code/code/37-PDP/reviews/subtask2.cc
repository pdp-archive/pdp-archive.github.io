#include <cstdio>
#include <vector>

std::vector<std::vector<long>> adj;

/* Βοηθητική συνάρτηση που ελέγχει αν δύο ακμές είναι ίσες. */
bool are_same_edge(std::pair<long, long> p1, std::pair<long, long> p2) {
  return p1 == p2 || (std::make_pair(p1.second, p1.first) == p2);
}

/* Αναζήτηση κατά βάθος αποφεύγοντας την αφαιρεμένη ακμή. */
void dfs(long node, std::pair<long, long> forbidden_edge, std::vector<int>& visited) {
  visited[node] = true;
  for (auto neigh : adj[node]) {
    if (are_same_edge({node, neigh}, forbidden_edge)) continue;
    if (!visited[neigh]) dfs(neigh, forbidden_edge, visited);
  }
}

/* Έλεγχος αν ο γράφος είναι συνδεδεμένος. */
bool is_graph_connected(std::pair<long, long> forbidden_edge) {
  std::vector<int> visited(adj.size(), false);
  dfs(1, forbidden_edge, visited);
  for (long i = 1; i < adj.size(); ++i) {
    if (!visited[i]) return false;
  }
  return true;
}

/* Βρίσκει τον βαθύτερο κόμβο σε ένα δέντρο. */
std::pair<long /* max_distance */, long /* node */> find_furthest_node_in_tree(
    long node, 
    long par, 
    long depth, 
    std::pair<long, long> forbidden_edge) {
  long max_depth = depth;
  long max_depth_node = node;
  
  for (auto neigh : adj[node]) {
    if (neigh == par) continue;
    if (are_same_edge({node, neigh}, forbidden_edge)) continue;
    auto [cur_depth, cur_depth_node] = find_furthest_node_in_tree(neigh, node, depth + 1, forbidden_edge);
    if (cur_depth > max_depth) {
      max_depth = cur_depth;
      max_depth_node = cur_depth_node;
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
  
  FILE *fo = fopen("reviews.out", "w");
  for (long i = 1; i <= N; ++i) {
    if (!is_graph_connected(edges[i])) {
      fprintf(fo, "-1\n");
    } else {
      auto [x, furthest_node_from_1] = find_furthest_node_in_tree(1, -1, 0, edges[i]);
      auto [dist, y] = find_furthest_node_in_tree(furthest_node_from_1, -1, 0, edges[i]);
      fprintf(fo, "%ld\n", dist+1);
    }
  }
  fclose(fo);
  return 0;
}


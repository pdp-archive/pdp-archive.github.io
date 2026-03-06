#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>

const int MAXN = 100'000;

// https://kallinikos.github.io/Bridges-Articulation-Points
std::vector<int> gr[MAXN+1];
int num[MAXN+1], low[MAXN+1], par[MAXN+1], is_art[MAXN+1];
int counter = 0;
int bridges = 0;
int articulation_points = 0;

void dfs(int u) {
  low[u] = num[u] = counter++;
  int children = 0;

  for (auto v : gr[u]) {
    if (num[v] == -1) {
      par[v] = u;
      dfs(v);
      children++;

      if (par[u] == -1 && children > 1) is_art[u] = 1;
      else if (par[u] != -1 && low[v] >= num[u]) is_art[u] = 1;
      if (low[v] > num[u]) ++bridges;
      low[u] = std::min(low[u], low[v]);
    } else if (par[u] != v) {
      low[u] = std::min(low[u], num[v]);
    }
  }
  articulation_points += is_art[u];
}

int main() {
  long N, K, L;
  scanf("%ld%ld%ld", &N, &K, &L);
  bool exists = false;  
  auto add_edge = [&](int u, int v) { gr[u].push_back(v); gr[v].push_back(u); };
  memset(num, -1, sizeof num);
  memset(low, -1, sizeof low);
  memset(par, -1, sizeof par);
  counter = 0;
  if (N == 2) {
    if (K == 0 && L == 1) {
      exists = true;
      add_edge(1, 2);
    }
  } else if (K == 0) {
    if (L == 0) {
      exists = true;
      // Δημιουργούμε έναν κύκλο.
      for (int i = 1; i < N; ++i) {
         add_edge(i, i + 1);
      }
      add_edge(N, 1);
    }
  } else if (L >= N) {} 
  else if (K >= N - 1) {}
  else if (L >= K) {
    if (L == N - 2) {} 
    else {
      exists = true;
      // Φτιάχνουμε ένα μονοπάτι με τα κομβικά σημεία. 
      for (int i = 1; i <= K; ++i) {
         add_edge(i,i+1);
      }
      // Βάζουμε κόμβους συνδεδεμένους μόνο με την πρώτη 
      // κορυφή για να δημιουργήσουμε τις υπόλοιπες γέφυρες.
      int independent_start = K + 2;
      for (int j = 0; j < (L - K); ++j) {
        add_edge(1, independent_start + j);
      }
      // Βάζουμε έναν κύκλο με τις υπόλοιπες κορυφές.
      int non_critical_start = L + 3;
      if (non_critical_start <= N) {
        for (int j = non_critical_start; j <= N; ++j) {
          if (j < N) add_edge(j, j + 1);
          else add_edge(N, non_critical_start);
        }
        add_edge(1, N);
        add_edge(1, non_critical_start);
      }
    } 
  } else /* (L < K)*/ {
    if (2 * K - L + 3 <= N) {
      exists = true;
      // Βάζουμε όλα τα κομβικά σημεία σε ένα μονοπάτι
      // και μία κορυφή στο τέλος.
      for (int i = 1; i <= K; ++i) {
        add_edge(i, i + 1);
      }
      // Βάζουμε ενδιάμεσες κορυφές, ώστε οι K - L ακμές του
      // μονοπατιού να μην είναι πλέον γέφυρες.
      int intermmediate_nodes_start = K + 2;
      for (int j = 0; j < (K - L); ++j) {
        add_edge(j + 1, intermmediate_nodes_start + j);
        add_edge(j + 2, intermmediate_nodes_start + j);
      }
      // Προσθέτουμε έναν κύκλο με τις υπόλοιπες κορυφές που δεν 
      // είναι κομβικές.
      int non_critical_nodes_start = 2*K - L + 2;
      add_edge(K+1, non_critical_nodes_start);
      for (int j = non_critical_nodes_start; j < N; ++j) {
        add_edge(j, j + 1);
      }
      if (non_critical_nodes_start < N) add_edge(N, K+1);
    }
  }

  if (exists) {
    printf("1\n");
    dfs(1);
    if (articulation_points != K  || bridges != L) {
        printf("%ld vs %ld and bridges %ld vs %ld\n", articulation_points, K, bridges, L);
    }
  } else printf("-1\n");
  
  return 0;
}


#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>

int main() {
  long N, K, L;
  scanf("%ld%ld%ld", &N, &K, &L);
  bool exists = false;  
  std::vector<std::pair<long,long>> edges;
  auto add_edge = [&](int u, int v) { edges.push_back({u,v}); };

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
  } 
  else if (L >= N) {} 
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
    printf("%ld\n", edges.size());
    for (auto [u, v] : edges) {
      printf("%ld %ld\n", u, v);
    }
  } else printf("-1\n");
  
  return 0;
}


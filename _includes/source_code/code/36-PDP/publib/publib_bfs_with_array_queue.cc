#include <stdio.h>
#include <queue>
#include <vector>

int main() {
   FILE *fi = fopen("publib.in", "r");
   long N, M;
   fscanf(fi, "%ld%ld", &N, &M);
   
   std::vector<std::vector<long>> adj(N);
   
   while(M--) {
      long a, b;
      fscanf(fi, "%ld%ld", &a, &b);
      a--; b--;
      
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
   
   std::vector<bool> visited(N); // Αν έχουμε επισκεφτεί έναν κόμβο.
   std::vector<std::pair<long, long>> q(N); // Η ουρά.
   
   long best_dist = N + 1;
   for (int i = 0; i < N; ++i) {
      std::fill(visited.begin(), visited.end(), false);
      q[0] = { i, 0 };
      visited[i] = true;
      long dist = 0;
      long l = 0, r = 0; // Η ουρά είναι στις θέσεις q[l..r].
      // Τρέχουμε την BFS.
      while (l <= r) {
         auto [v, d] = q[l]; // front
         ++l; // pop
         
         for (auto neigh : adj[v]) {
            if (!visited[neigh]) {
               ++r;
               q[r] = {neigh, d + 1}; // push
               visited[neigh] = true;
            }
         }
         dist = d;
      }
      best_dist = std::min(dist, best_dist);
   }
   
   FILE *fo = fopen("publib.out", "w");
   fprintf(fo, "%ld\n", best_dist);
   
   
   return 0;
}

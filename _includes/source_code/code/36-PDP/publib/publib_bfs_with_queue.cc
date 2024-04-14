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
   std::queue<std::pair<long, long>> q; // Η ουρά.
   
   long best_dist = N + 1;
   for (int i = 0; i < N; ++i) {
      std::fill(visited.begin(), visited.end(), false);
      q.push({ i, 0 });
      visited[i] = true;
      long dist = 0;
      // Τρέχουμε την BFS.
      while (!q.empty()) {
         auto [v, d] = q.front();
         q.pop();
         
         for (auto neigh : adj[v]) {
            if (!visited[neigh]) {
               q.push({neigh, d + 1});
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

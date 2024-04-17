#include <cstdio>
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
   
   fclose(fi);
   
   std::vector<bool> visited(N); // Αν έχουμε επισκεφτεί έναν κόμβο.
   std::queue<std::pair<long, long>> q; // Η ουρά.
   
   long graph_radius = N + 1;
   for (int i = 0; i < N; ++i) {
      std::fill(visited.begin(), visited.end(), false);
      q.push({ i, 0 });
      visited[i] = true;
      long max_dist = 0;
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
         max_dist = d;
      }
      graph_radius = std::min(max_dist, graph_radius);
   }
   
   FILE *fo = fopen("publib.out", "w");
   fprintf(fo, "%ld\n", graph_radius);
   
   
   return 0;
}

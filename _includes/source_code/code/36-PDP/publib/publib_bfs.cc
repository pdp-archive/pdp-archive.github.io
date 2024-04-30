#include <cstdio>
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
   std::vector<long> next, cur; // Το τωρινό και το επόμενο επίπεδο.
   long best_dist = N + 1;
   for (int i = 0; i < N; ++i) {
      std::fill(visited.begin(), visited.end(), false);
      cur.push_back(i);
      visited[i] = true;
      long max_dist = -1;
      // Τρέχουμε την BFS.
      while (!cur.empty()) {
         for (auto v : cur) {
            for (auto neigh : adj[v]) {
               if (!visited[neigh]) {
                  visited[neigh] = true;
                  next.push_back(neigh);
               }
            }
         }
         cur = next;
         next.clear();
         ++max_dist;
      }
      best_dist = std::min(max_dist, best_dist);
   }
   
   FILE *fo = fopen("publib.out", "w");
   fprintf(fo, "%ld\n", best_dist);
   fclose(fo);
   
   return 0;
}

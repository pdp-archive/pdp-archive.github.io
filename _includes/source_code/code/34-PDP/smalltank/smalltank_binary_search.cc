#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
#include <tuple>

typedef std::tuple<long /* βάρος */, long /* 1η κορυφή */, long /* 2η κορυφή */> Edge;

const long MAXN = 10000;

bool visited[MAXN + 1];

std::vector<std::vector<long>> adj; // Λίστα γειτνίασης.

// Ελέγχουμε αν ο γράφος είναι συνδεδεμένος με 
// μη-αναδρομική DFS.
bool is_connected(long N) {
   std::fill(visited+1, visited+N+1, false);
   
   std::stack<long> st;
   long visited_count = 0;
   st.push(1);
   while (!st.empty()) {
      long cur = st.top();
      st.pop();
      if (visited[cur]) continue;
      ++visited_count;
      visited[cur] = true;
      for (auto neigh : adj[cur]) {
         st.push(neigh);
      }
   }
   return visited_count == N;   
}

int main() {
   long N, M;
   FILE *fi = fopen("smalltank.in", "r");
   fscanf(fi, "%ld%ld", &N, &M);
   adj.resize(N + 1);

   std::vector<Edge> edges;
   for (long i = 0; i < M; ++i) {
      long u, v, w;
      fscanf(fi, "%ld%ld%ld", &u, &v, &w);
      edges.push_back({ w, u, v });
   }
   fclose(fi);
   
   std::sort(edges.begin(), edges.end());
   
   long st = 0, en = M - 1;
   while (st < en) {
      long mn = (st + en) / 2;
      // Προσθέτουμε τις πρώτες mn ακμές.
      for (long i = 0; i <= mn; ++i) {
         auto [_, u, v] = edges[i];
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      if (is_connected(N)) {
         en = mn; // Απορρίπτουμε τα μεγαλύτερα βάρη.
      } else {
         st = mn + 1; // Απορρίπτουμε μικρότερα ή ίσα βάρη.
      }
      // Αδειάζουμε τον γράφο.
      adj = std::vector<std::vector<long>>(N + 1);
   }
   long mx = std::get<0>(edges[st]);
   
   FILE *fo = fopen("smalltank.out", "w");
   fprintf(fo, "%ld\n", mx);
   fclose(fo);
   
   return 0;
}

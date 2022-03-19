#include <algorithm>
#include <cstdio>
#include <stack>

typedef std::tuple<long /* βάρος */, long /* 1η κορυφή */, long /* 2η κορυφή */> Edge;

const long MAXN = 10'000;

bool visited[MAXN + 1];
std::vector<std::vector<long>> adj; // Λίστα γειτνίασης.

// Ελέγχουμε αν ο γράφος είναι συνδεδεμένος με 
// μη-αναδρομική DFS.
bool is_connected(long N) {
   for (int i = 1; i <= N; ++i) visited[i] = false;
   
   std::stack<long> st;
   long visited_count = 0;
   // Μπορούμε να ξεκινήσουμε από οποιαδήποτε κορυφή.
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
   // Ο γράφος είναι συνδεδεμένος αν επισκεφτήκαμε 
   // όλους τους γείτονες.
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
   
   // Ταξινομούμε τις ακμές κατά αύξον βάρος.
   std::sort(edges.begin(), edges.end());
   
   long mx;
   for (auto [w, u, v] : edges) {
      // Προσθέτουμε την ακμή (u, v).
      adj[u].push_back(v);
      adj[v].push_back(u);
      if (is_connected(N)) {
         mx = w;
         break;
      }
   }
   
   FILE *fo = fopen("smalltank.out", "w");
   fprintf(fo, "%ld\n", mx);
   fclose(fo);
   
   return 0;
}

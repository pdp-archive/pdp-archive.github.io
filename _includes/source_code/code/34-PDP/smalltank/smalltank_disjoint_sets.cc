#include <algorithm>
#include <cstdio>
#include <vector>
#include <tuple>

typedef std::tuple<long /* βάρος */, long /* 1η κορυφή */, long /* 2η κορυφή */> Edge;

const long MAXN = 10000;

int par[MAXN + 1];
int sz[MAXN + 1];

/* Αρχικοποίηση των disjoint sets. */
void init(long N) {
   for (int i = 1; i <= N; ++i) {
      par[i] = i;
      sz[i] = 1;
   }
}

/* Βρίσκουμε τον αντιπρόσωπο του συνόλου. */
long find_parent(long u) {
   if (u == par[u]) return u;
   return par[u] = find_parent(par[u]);
}

/* Ενώνουμε τα σύνολα που περιέχουν το 
   u και το v και επιστρέφουμε αν έγινε 
   καινούργια ένωση. */
bool merge(long u, long v) {
   long p_u = find_parent(u);
   long p_v = find_parent(v);
   
   if (p_u == p_v) return false;
   
   if (sz[p_u] < sz[p_v]) {
      par[p_u] = p_v;
   } else {
      par[p_v] = p_u;
      if (sz[p_u] == sz[p_v]) ++sz[p_u];
   }
   return true;
}

int main() {
   long N, M;
   FILE *fi = fopen("smalltank.in", "r");
   fscanf(fi, "%ld%ld", &N, &M);

   std::vector<Edge> edges;
   for (long i = 0; i < M; ++i) {
      long u, v, w;
      fscanf(fi, "%ld%ld%ld", &u, &v, &w);
      edges.push_back({ w, u, v });
   }
   fclose(fi);
   
   init(N);
   // Ταξινομούμε τις ακμές κατά αύξον βάρος.
   std::sort(edges.begin(), edges.end());
   
   long mx;
   for (auto [w, u, v] : edges) {
      if (merge(u, v)) {
         // Η τελευταία ενωση που κάνουμε είναι η 
         // μέγιστη ακμή (άρα και η απάντηση).
         mx = w;
      }
   }
   
   FILE *fo = fopen("smalltank.out", "w");
   fprintf(fo, "%ld\n", mx);
   fclose(fo);
   
   return 0;
}

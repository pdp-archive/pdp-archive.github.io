#include <algorithm>
#include <cstdio>
#include <stack>

typedef std::tuple<long /* βάρος */, long /* 1η κορυφή */, long /* 2η κορυφή */> Edge;

const long MAXN = 10000;

std::vector<Edge> edges; // Οι υπόλοιπες ακμές.
std::vector<Edge> smaller, larger; // Οι μικρές (<= w_median) και οι μεργάλες ακμές.
std::vector<long> active_groups; // Ποιες κορυφές ακουμπάνε σε κάποια 
                                 // από τις μικρές ακμές.
std::vector<bool> is_active; // Αν η συγκεκριμένη κορυφή είναι active.
std::vector<std::vector<long>> adj; // Λίστα γειτνίασης για τις active ακμές.
long last_id; // Το τελευταίο ID που δώσαμε σε ομάδα.
long remaining_merges; // Πόσες ενώσεις απομένουν.
int cur_color; // Το πλήθος των ομάδων που έχουμε συναντήσει στην dfs 
               // των μικρότερων ακμών.
std::vector<long> color; // Η ομάδα στην οποία ανήκει η κορυφή μετά την
                         // dfs στις μικρές ακμές.
int groups_merged; // Πόσες κορυφές έχουμε ενώσει.
long w_median; // Το βάρος της τωρινής μεσαίας ακμής.
long mx; // Η απάντηση.

// Μοίρασμα σε ακμές μικρότερες από το w_median και μεγαλύτερες.
// Και προετοιμασία για την dfs στις μικρότερες ακμές.
void splitIntoSmallLarge() {
   std::nth_element(edges.begin(), edges.begin() + (edges.size()-1)/2, edges.end());
   w_median = std::get<0>(*(edges.begin() + (edges.size()-1)/2));
   auto median = *(edges.begin() + (edges.size()-1)/2);
   
   bool found_median = false;
   for (auto e : edges) {
      if (e <= median) {
         if (e == median) {
            // Edge case: αν υπάρχουν πολλές ακμές ίσες
            // με το median τότε προσθέτουμε μόνο μία.
            if (found_median) continue;
            found_median = true;
         }
         auto [w, u, v] = e;
         if (!is_active[u]) active_groups.push_back(u);
         if (!is_active[v]) active_groups.push_back(v);
         is_active[u] = true;
         is_active[v] = true;
         adj[u].push_back(v);
         adj[v].push_back(u);
         smaller.push_back(e);
      } else larger.push_back(e);
   }
}

// Η dfs στις μικρότερες ακμές. Κρατάμε τις ομάδες
// που δημιουργούνται. Αν ο γράφος δεν είναι συνδεδεμένος
// τότε αυτές θα ενωθούν σε έναν κόμβο.
void dfsMarkGroups() {
   cur_color = 0;
   groups_merged = 0;
   for (auto active_group : active_groups) {
      if (color[active_group] == 0) {
         ++cur_color;
         std::stack<long> st;
         st.push(active_group);
         while (!st.empty()) {
            long cur = st.top();
            st.pop();
            if (color[cur] != 0) continue;
            ++groups_merged;
            color[cur] = cur_color;
            for (auto neigh : adj[cur]) {
               st.push(neigh);
            }
         }
         --groups_merged;
      }
   }
}

// Ενώνουμε τις ομάδες σε έναν κόμβο και κάνουμε
// update τις υπόλοιπες ακμές.
void updateGraph() {
   remaining_merges -= groups_merged;
   for (long i = 0; i < cur_color; ++i) {
      color.push_back({});
      adj.push_back({});
      is_active.push_back(false);
   }
   
   edges.clear();
   
   // Update the new groups.
   for (auto [w, u, v] : larger) {
      long c_u = is_active[u] ? (last_id + color[u]) : u;
      long c_v = is_active[v] ? (last_id + color[v]) : v;
      edges.push_back({ w, c_u, c_v });
   }
   last_id += cur_color;
}

void reset() {
   for (auto active_group : active_groups) {
      color[active_group] = 0;
      adj[active_group].clear();
      is_active[active_group] = false;
   }
   smaller.clear();
   larger.clear();
   active_groups.clear();
}

int main() {
   long N, M;
   FILE *fi = fopen("smalltank.in", "r");
   fscanf(fi, "%ld%ld", &N, &M);
   adj.resize(N + 1);
   color.resize(N + 1);
   is_active.resize(N + 1);

   for (long i = 0; i < M; ++i) {
      long u, v, w;
      fscanf(fi, "%ld%ld%ld", &u, &v, &w);
      edges.push_back({ w, u, v });
   }
   fclose(fi);
   
   last_id = N;
   mx = 0;
   remaining_merges = N - 1;
   
   while (edges.size() >= 1) {
      splitIntoSmallLarge();
      dfsMarkGroups();
      
      if (cur_color == 1 && remaining_merges == groups_merged) {
         edges = smaller;
         mx = w_median;
         if (edges.size() == 1) break;
      } else {
         // The graph is not connected, so we need to add these new edges.
         updateGraph();
      }
      reset();
   }
   
   FILE *fo = fopen("smalltank.out", "w");
   fprintf(fo, "%ld\n", mx);
   fclose(fo);
   
   return 0;
}

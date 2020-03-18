---
layout: solution
codename: telecom
---

*Η λύση απαιτεί γνώσεις για το ελάχιστο συνδετικό δένδρο. Η βέλτιση λύση απαιτεί γνώσεις disjoint set union*


## Επεξήγηση εκφώνησης

Μας δίνεται ένα δένδρο και μας ζητείται να βρούμε τα βάρη των υπόλοιπων ακμών για να γίνει ο γράφος πλήρης, ώστε το ελάχιστο συνδετικό του δένδρο να είναι το δοθέν και να είναι μοναδικό. Το άθροισμα των βαρών πρέπει να είναι το ελάχιστο δυνατόν (διαφορετικά θα θέταμε τα βάρη πολύ μεγάλα και θα ικανοποιούσε τις συνθήκες). 

Θα ξεκινήσουμε αποδεικνύοντας το εξής:

**Θεώρημα:** Ένας γράφος έχει μοναδικό ελάχιστο συνδετικό δένδρο $$T$$ αν και μόνο αν για κάθε δύο κορυφές $$i$$ και $$j$$, αν $$(i, j)$$ δεν είναι στο συνδετικό δένδρο $$T$$, τότε $$w_{ij} > w’$$, όπου $$w’$$ είναι το βάρος της μεγαλύτερης ακμής στο μονοπάτι που συνδέει το $$i$$ και το $$j$$ στο $$T$$.


*Απόδειξη:* Θα ξεκινήσουμε δείχνοντας την απλή κατεύθυνση:


Έστω ότι ο γράφος έχει μοναδικό ελάχιστο συνδετικό δένδρο $$T$$ και υπήρχαν δύο κορυφές $$i$$ και $$j$$ ώστε $$(i, j)$$ να μην είναι στο συνδετικό δένδρο $$T$$ και $$w_{ij} \leq w_{kl}$$ για κάποια ακμή $$(k, l)$$ στο μονοπάτι από το $$i$$ στο $$j$$. Τότε, αν αντικαταστήσουμε την ακμή $$(i, j)$$ με την $$(k, l)$$, τότε παίρνουμε ένα ελάχιστο συνδετικό δένδρο με συνολικό βάρος μικρότερο ή ίσο του αρχικού (αφού αλλάζει κατά $$w_{kl} - w_{ij} \geq 0$$). Άτοπο.


Για την αντίθετη φορά. Έστω ότι δεν υπάρχει ζευγάρι $$(i, j)$$, ώστε $$w_{ij} > w’$$ και το $$T$$ δεν είναι το μοναδικό ελάχιστο συνδετικό δένδρο (δηλαδή υπάρχει άλλο ένα $$T’$$ με το ίδιο βάρος και κάποιες διαφορετικές ακμές). Έστω $$(u, v)$$ μία ακμή που ανήκει στο $$T’$$ και όχι στο $$T$$. Τότε για το $$(u, v)$$ όλες οι ακμές στο μονοπάτι μεταξύ $$u$$ και $$v$$ στο $$T$$ έχουν βάρος μικρότερο από $$w_{uv}$$. Αν αντικαταστήσουμε την ακμή $$(u, v)$$ στο $$T’$$ με οποιαδήποτε από αυτές τις ακμές, τότε βρίσκουμε ένα συνδετικό δένδρο με μικρότερο βάρος. Άτοπο, γιατί $$T’$$ ήταν ελάχιστο συνδετικό δένδρο. 



## Αρχική λύση

Το παραπάνω θεώρημα μας δίνει έναν τρόπο να βρούμε την τιμή κάθε ακμής. Για κάθε ζεύγος $$(i, j)$$, βρίσκουμε την ακμή με το μεγαλύτερο βάρος στο μονοπάτι μεταξύ $$i$$ και $$j$$ στο $$T$$ και προσθέτουμε $$1$$. Αυτό είναι το ελάχιστο βάρος που θα μπορούσε να έχει για να είναι το δοθέν δένδρο το ελάχιστο συνδετικό. 


Για να βρούμε το μεγαλύτερο βάρος στο μονοπάτι μεταξύ $$i$$ και $$j$$ κάνουμε αναζήτηση κατά βάθος. Υπάρχουν $$N(N-1)/2 - (N-1) = O(N^2)$$ ακμές και κάθε DFS θέλει $$O(N)$$ χρόνο, άρα συνολικά ο αλγόριθμος θέλει $$O(N^3)$$ και $$O(N)$$ μνήμη. 


```c++
#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 500000;

std::vector<std::pair<long, long>> v[MAXN + 1];

void findMax(long current, long target, long par, long cur_max, long& ans) {
   if (current == target) {
      ans = cur_max;
      return;
   }
   for (const auto& edge : v[current]) {
      if (edge.first == par) continue;
      findMax(edge.first, target, current, std::max(cur_max, edge.second), ans);
   }
}
      

long findMaxEdgeInPath(long u, long v) {
   long ans = -1;
   findMax(u, v, -1, -1, ans);
   return ans;
}

int main() {
   long N;
   FILE *fi = fopen("telecom.in", "r");
   fscanf(fi, "%ld", &N);
   
   for (long i = 1; i < N; ++i) {
      long a, b, weight;
      fscanf(fi, "%ld%ld%ld", &a, &b, &weight);
      v[a].push_back(std::make_pair(b, weight));
      v[b].push_back(std::make_pair(a, weight));
   }
   fclose(fi);
   
   ll total = 0;
   for (long u = 1; u <= N; ++u) {
      for (long v = u + 1; v <= N; ++v) {
         total += findMaxEdgeInPath(u, v) + 1;
      }
   }
   total -= N - 1;
   
   FILE *fo = fopen("telecom.out", "w");
   fprintf(fo, "%lld\n", total);
   fclose(fo);
   return 0;
}

```


## Επιταχυμένη αρχική λύση

Μπορούμε να επιταχύνουμε την εύρεση της μέγιστης ακμής μεταξύ δύο κορυφών σε ένα δένδρο. Το κάνουμε αυτό βρίσκοντας την μέγιστη ακμή για όλα τα μονοπάτια που ξεκινάνε από μία κορυφή με μία αναζήτηση κατά βάθος. Ξεκινάμε την αναζήτηση κατά βάθος από κάθε $$u$$ και σε κάθε κορυφή $$v$$ που επισκεπτόμαστε κρατάμε στο $$\mathit{cur\_max}$$ την μέγιστη ακμή που έχουμε συναντήσει από το $$u$$.

Συνεπώς, μπορούμε να βρούμε το άθροισμα όλων των μέγιστων αποστάσεων σε χρόνο $$O(N^2)$$ (αφού για κάθε κορυφή χρειάζεται $$O(N)$$) και με $$O(N)$$ μνήμη.


```c++
#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 500000;

std::vector<std::pair<long /* κορυφή */, long /* βάρος */>> v[MAXN + 1];

void findSumMax(long current, long par, long cur_max, ll& ans) {
   ans += cur_max + 1;
   for (const auto& edge : v[current]) {
      if (edge.first == par) continue;
      findSumMax(edge.first, current, std::max(cur_max, edge.second), ans);
   }
}

ll findSumMax(long u) {
   ll ans = 0;
   findSumMax(u, -1, -1, ans);
   return ans;
}

int main() {
   long N;
   FILE *fi = fopen("telecom.in", "r");
   fscanf(fi, "%ld", &N);
   
   for (long i = 1; i < N; ++i) {
      long a, b, weight;
      fscanf(fi, "%ld%ld%ld", &a, &b, &weight);
      v[a].push_back(std::make_pair(b, weight));
      v[b].push_back(std::make_pair(a, weight));
   }
   fclose(fi);
   
   ll total = 0;
   for (long u = 1; u <= N; ++u) {
      total += findSumMax(u);
   }
   total = (total)/2 - (N - 1);
   
   FILE *fo = fopen("telecom.out", "w");
   fprintf(fo, "%lld\n", total);
   fclose(fo);
   return 0;
}

```


## Βέλτιστη λύση

Για την βέλτιστη λύση, χρειάζεται να σκεφτούμε διαφορετικά: αντί να απαντήσουμε ποια είναι η μέγιστη ακμή για κάθε δυνατό ζεύγος κορυφών, θα απαντήστουμε για πόσα ζεύγη κορυφών είναι μία ακμή η μέγιστη στο μονοπάτι τους. 


Για να το κάνουμε αυτό ξεκινάμε με έναν γράφο χωρίς ακμές και προσθέτουμε μία μία τις ακμές του $$T$$ (κατά αύξοντα βάρη). Όταν βάζουμε την ακμή $$(i, j)$$, τότε οι κορυφές $$i$$ και $$j$$ μπορεί να συνδέονται με μερικές άλλες κορυφές μόνο μέσω ακμών με βάρος μικρότερο από $$w_{ij}$$. Αν η $$u$$ συνδέεται με την $$i$$ και η $$v$$ συνδέεται με την $$j$$, τότε θα είναι μέσω ακμών με βάρος μικρότερο από $$w_{ij}$$, άρα η $$(i, j)$$ είναι μέγιστη στο μονοπάτι μεταξύ $$u$$ και $$v$$.

![Παράδειγμα όπου η (i, j) είναι στον κύκλο](/assets/25-pdp-c-telecom-solution-i-j-u-v.svg){:width="350px"}

Αν η κορυφή $$u$$ συνδέεται με την $$i$$ και η $$v$$ δεν συνδέεται με την $$j$$, τότε θα υπάρχει μία μεγαλύτερη ακμή που τις συνδέει (απλά δεν την έχουμε βρει ακόμα). Άρα η $$(i, j)$$ δεν είναι μέγιστη. 

![Παράδειγμα όπου το v δεν συνδέεται με το j](/assets/25-pdp-c-telecom-solution-i-j-u-v-disjoint.svg){:width="350px"}

Παρόμοιες είναι οι περιπτώσεις: 
 1. η $$u$$ δεν συνδέεται με την $$i$$
 2. ούτε η $$u$$ ούτε η $$v$$ συνδέονται με τις $$i$$ και $$j$$

Αν οι $$u$$ και $$v$$ συνδέονται από πριν, τότε η $$(i, j)$$ δεν ανήκει στον κύκλο. 

![Παράδειγμα όπου το u και το v συνδέονται ήδη](/assets/25-pdp-c-telecom-solution-i-j-u-v-connected.svg){:width="350px"}

Άρα αν ξέρουμε ότι η $$i$$ συνδέεται με $$\mathit{count}_{i}$$ κορυφές και η $$j$$ συνδέεται με $$\mathit{count}_j$$ κορυφές, τότε η ακμή $$(i, j)$$ είναι μέγιστη σε $$\mathit{count}_{i} \cdot \mathit{count}_{j} - 1$$ μονοπάτια (αυτά μεταξύ των κορυφών που συνδέονται τα $$i$$ και τα $$j$$).


Αφού βρούμε τα μονοπάτια για μία ακμή, πρέπει να ενώσουμε τους κόμβους με τους οποίους συνδέονται οι δύο κορυφές. Η κατάλληλη δομή δεδομένων για αυτό είναι η disjoint union-set (με την παραλλαγή ότι κάθε φορά που συνδέουμε δύο ομάδες προσθέτουμε τον συνολικό αριθμό στοιχείων). 


Ο αλγόριθμος αυτός έχει πολυπλοκότητα $$O(N\alpha(N) + N\log{N})$$ ή $$O(N\alpha(N))$$ (αν η ταξινόμηση γίνει γραμμικά). 

```c++
#include <algorithm>
#include <cstdio>
#include <vector>

typedef long long ll;

const size_t MAXN = 500000;

struct Edge {
   long u;
   long v;
   long weight;
   
   Edge(long u, long v, long weight) : u(u), v(v), weight(weight) {}
   
   // Ταξινομούμε βάζοντας πρώτα τις ακμές με μικρότερα βάρη. 
   bool operator<(const Edge& e) const {
      if (weight != e.weight) return weight < e.weight;
      if (u != e.u) return u < e.u;
      return v < e.v;
   }
};

long N;

long parent[MAXN + 1];
long rank[MAXN + 1];
ll count[MAXN + 1];

void init() {
   for (long i = 1; i <= N; ++i) {
      parent[i] = i;
      rank[i] = 1;
      count[i] = 1;
   }
}

long findParent(long n) {
   if (n == parent[n]) return n;
   return parent[n] = findParent(parent[n]);
}

void unite(long u, long v) {
   if (rank[u] < rank[v]) std::swap(u, v);
   parent[v] = u;
   count[u] += count[v];
   if (rank[u] == rank[v]) ++rank[u];
}

int main() {
   FILE *fi = fopen("telecom.in", "r");
   fscanf(fi, "%ld", &N);
   std::vector<Edge> edges;
   
   for (long i = 1; i < N; ++i) {
      long u, v, weight;
      fscanf(fi, "%ld%ld%ld", &u, &v, &weight);
      edges.push_back(Edge(u, v, weight));
   }
   fclose(fi);
   std::sort(edges.begin(), edges.end());
   init();
   ll total = 0;
   for (const Edge& e : edges) {
      long parent_u = findParent(e.u);
      long parent_v = findParent(e.v);
      total += e.weight;
      if (parent_u != parent_v) {
         total += (count[parent_u] * count[parent_v] - 1) * (e.weight + 1);
         unite(parent_u, parent_v);
      }
   }
   
   FILE *fo = fopen("telecom.out", "w");
   fprintf(fo, "%lld\n", total);
   fclose(fo);
   return 0;
}

```

---
layout: solution
codename: uflights
---
## Επεξήγηση εκφώνησης
Μας δίνεται ένας γράφος με κόμβους τα αεροδρόμια, ακμές τις κάρτες και βάρη ακμών τα κόστη των καρτών. Η εκφώνηση εγγυάται ότι θα υπάρχει μονοπάτι μεταξύ οποιονδήποτε δύο κόμβων, άρα ο γράφος είναι συνεκτικός. Μας ζητείτε να βρούμε ένα υποσύνολο των ακμών ώστε να μπορούμε να μετακινηθούμε μεταξύ δύο οποιονδήποτε αεροδρομίων και να ελαχιστοποιεί το συνολικό κόστος των ακμών. 

Αυτή ακριβώς η διατύπωση είναι o ορισμός του ελάχιστου συνδετικού δένδρου. Επομένως μπορούμε να χρησιμοποιήσουμε έναν από τους δύο γνωστούς αλγορίθμους των Kruskal και Prim. Με την παρατήρηση ότι τα κόστη είναι στο $$[1, 100]$$, ο αλγόριθμος του Kruskal είναι βέλτιστος.

(Δείτε το CLRS για περαιτέρω πληροφορίες για αυτούς τους αλγορίθμους)


## Λύση με αλγόριθμο του Prim
Ο αλγόριθμος του Prim διατηρεί ένα σύνολο κόμβων και τις αποστάσεις για τις υπόλοιπους κόμβους. Σε κάθε επανάληψη, προσθέτει τον κόμβο που είναι κοντύτερα στο σύνολο και την ακμή που τον συνδέει με το υπάρχον σύνολο, στο συνδετικό δένδρο.

Ο αλγόριθμος έχει πολυπλοκότητα $$O(M \log N)$$ και χρειάζεται μνήμη $$O(M)$$.

```c++
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>

const long MAXN = 100000;
const int MAXK = 100;

std::vector<std::pair<long, int>> v[MAXN + 1];

// Υποψήφιος κόμβος για προσθήκη μαζί με την απόσταση του από το σύνολο.
struct Candidate {
  long dist;
  long node;
  
  bool operator<(const Candidate& other) const {
    if (dist == other.dist) return node < other.node;
    return dist > other.dist;
  }
  
  Candidate(long dist, long node) 
    : dist(dist), node(node) { }
};

long dist[MAXN + 1];

int main() {
  FILE *fi = fopen("uflights.in", "r");
  long N, M;
  fscanf(fi, "%ld %ld", &N, &M);
  for (long i = 0; i < M; ++i) {
    long a, b;
    int k;
    fscanf(fi, "%ld %ld %d", &a, &b, &k);
    // Ο γράφος είναι μη-κατευθυνόμενος.
    v[a].push_back(std::make_pair(b, k));
    v[b].push_back(std::make_pair(a, k));
  }
  fclose(fi);
  
  for (long i = 1; i <= N; ++i) dist[i] = -1;
  
  // Ξεκινάει η εκτέλεση του Prim.
  long cost = 0;
  std::priority_queue<Candidate> pq;
  pq.push(Candidate(0, 1)); // Βάζουμε τον πρώτο κόμβο στην αρχή.
  while(!pq.empty()) {
    Candidate current = pq.top();
    pq.pop();
    long node = current.node;
    if (dist[node] != -1) continue;
    else {
      dist[node] = current.dist;
      cost += current.dist;
      for (const auto& neighbour : v[node]) {
        // Αν δεν είναι ήδη στο σύνολο ο κόμβος, τον προσθέτουμε
        // ως υποψήφιο.
        if (dist[neighbour.first] == -1) {
          pq.push(Candidate(neighbour.second, neighbour.first));
        }
      }
    }
  }
  
  FILE *fo = fopen("uflights.out", "w");
  fprintf(fo, "%ld\n", cost);
  fclose(fo);
  return 0;
}

```

## Λύση με αλγόριθμο του Kruskal
Ο αλγόριθμος Kruskal επεξεργάζεται τις ακμές με αυξανόμενο βάρος, βάζοντας στο συνδετικό δένδρο της ακμές που συνδέουν κόμβους σε διαφορετικές συνδετικές συνιστώσες. 

Χρησιμοποιούμε την δομή δεδομένων union-find για να ελέγξουμε αν δύο κόμβοι είναι στην ίδια συνιστώσα και για να ενώσουμε δύο συνιστώσες.

Χρησιμοποιούμε έναν πίνακα από $$100$$ λίστες για να ταξινομήσουμε τις ακμές σε χρόνο $$O(K)$$.

Ο αλγόριθμος έχει πολυπλοκότητα $$O(M\cdot \alpha(N) + K)$$ και χρειάζεται μνήμη $$O(M)$$.

```c++
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <list>

const long MAXN = 100000;
const int MAXK = 100;

std::list<std::pair<long, long>> edges[MAXK + 1];

long parent[MAXN + 1];
long height[MAXN + 1];

// Στην αρχή κάθε κόμβος έχει ως πατέρα τον εαυτό του
// και ύψος 1.
void initUnionFind(long N) {
  for (long i = 1; i <= N; ++i) {
    parent[i] = i;
    height[i] = 1;
  }
}

// Επιστρέφει τον αρχηγό της ομάδας του x.
long findParent(long x) {
  if (x == parent[x]) return x;
  return x = findParent(parent[x]);
}

// Ενώνει τις ομάδες των κόμβων (αν δεν είναι ήδη στην ίδια ομάδα).
// Επιστρέφει αν ήταν οι κόμβοι ήταν σε διαφορετική ομάδα.
bool unite(long a, long b) {
  long par_a = findParent(a);
  long par_b = findParent(b);
  
  // Ήδη συνδεδεμένα.
  if (par_a == par_b) return false;
  
  // Βάζουμε το πιο χαμηλό στο Α.
  if (height[par_a] > height[par_b]) std::swap(par_a, par_b);
  
  // Συνδέουμε το πιο χαμηλό στο πιο ψηλό.
  parent[par_a] = par_b;
  if (height[par_a] == height[par_b]) ++height[par_b];
  return true;
}
    

int main() {
  FILE *fi = fopen("uflights.in", "r");
  long N, M;
  fscanf(fi, "%ld %ld", &N, &M);
  for (long i = 0; i < M; ++i) {
    long a, b;
    int k;
    fscanf(fi, "%ld %ld %d", &a, &b, &k);
    edges[k].push_back(std::make_pair(a, b));
  }
  fclose(fi);
  
  initUnionFind(N);
  
  // Ξεκινάει η εκτέλεση του Kruskal.
  long cost = 0;
  for (int k = 1; k <= MAXK; ++k) {
    for (const auto& edge : edges[k]) {
      if (unite(edge.first, edge.second)) {
        cost += k;
      }
    }
  }
  
  FILE *fo = fopen("uflights.out", "w");
  fprintf(fo, "%ld\n", cost);
  fclose(fo);
  return 0;
}

```

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

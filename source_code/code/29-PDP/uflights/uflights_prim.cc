#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>

const long MAXN = 100000;
const int MAXK = 100;

std::vector<std::pair<long, int>> v[MAXN + 1];

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
	v[a].push_back(std::make_pair(b, k));
	v[b].push_back(std::make_pair(a, k));
  }
  fclose(fi);
  
  for (long i = 1; i <= N; ++i) dist[i] = -1;
  
  long cost = 0;
  std::priority_queue<Candidate> pq;
  pq.push(Candidate(0, 1));
  while(!pq.empty()) {
    Candidate current = pq.top();
	pq.pop();
	long node = current.node;
	if (dist[node] != -1) continue;
	else {
	  dist[node] = current.dist;
	  cost += current.dist;
	  for (const auto& neighbour : v[node]) {
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

#include <algorithm>
#include <cstdio>
#include <vector>

const size_t MAXN = 1000000;

std::vector<long> adj_list[MAXN + 1];
bool visited[MAXN + 1];

long N, M, K;
 
void visit(long n) {
  std::vector<long> st;
  st.push_back(n);
  
  while (!st.empty()) {
	long n = st.back();
	st.pop_back();
    for (const auto& neighbour : adj_list[n]) {
      if (!visited[neighbour]) {
		visited[neighbour] = true;
	    st.push_back(neighbour);
	  }
	}
  }
}

int main() {
  FILE *fi = fopen("villages.in", "r");
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  
  for (long i = 0; i < M; ++i) {
    long A, B;
    fscanf(fi, "%ld %ld", &A, &B);
	adj_list[A].push_back(B);
	adj_list[B].push_back(A);
  }
  fclose(fi);
  
  // Μετράμε τις διαφορετικές ομάδες που υπάρχουν.
  long groups = 0;
  for (long i = 1; i <= N; ++i) {
    if (!visited[i]) {
	  ++groups;
	  visit(i);
	}
  }

  FILE *fo = fopen("villages.out", "w");
  fprintf(fo, "%ld\n", std::max(1L, groups - K));
  fclose(fo);
  return 0;
}

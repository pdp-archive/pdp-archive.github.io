#include <algorithm>
#include <cstdio>

// Στοχεύουμε μόνο για το 50%.
const size_t MAXN = 10000;

bool adj_matrix[MAXN + 1][MAXN + 1];
bool visited[MAXN + 1];

long N, M, K;

void visit(long n) {
  visited[n] = true;
  // Διατρέχουμε όλους τους κόμβους.
  for (long i = 1; i <= N; ++i) {
    // Αν συνδέεται ο n με κάποιον που δεν έχουμε επισκεπτεί,
	// τότε τον επισκεπτόμαστε.
    if (adj_matrix[n][i] && !visited[i]) {
      visit(i);
	}
  }
}

int main() {
  FILE *fi = fopen("villages.in", "r");
  fscanf(fi, "%ld %ld %ld", &N, &M, &K);
  
  for (long i = 0; i < M; ++i) {
    long A, B;
    fscanf(fi, "%ld %ld", &A, &B);
	adj_matrix[A][B] = 1;
	adj_matrix[B][A] = 1;
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

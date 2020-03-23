#include <algorithm>
#include <cstdio>

const long MAXN = 1000000;
const long MAXK = 100000;

long A[MAXN];
long count[MAXK + 1];

long N, K;

void clearCount() {
  for (long k = 1; k <= K; ++k) count[k] = 0;
}

// Ελέγχει αν υπάρχει διάστημα με μήκος len, που να
// περιέχει όλα τα Κ χρώματα.
bool existsIntervalWithLength(long len) {
  clearCount();
  long different_colors = 0;
  // Αρχικοποιούμε τον πίνακα count.
  for (long i = 0; i < len; ++i) {
    if (count[A[i]] == 0) ++different_colors;
    ++count[A[i]];
  }
  if (different_colors == K) return true;
  
  // Κοιτάμε για κάθε δυνατό interval [i, i + len) αν έχει
  // όλα τα χρώματα διαφορετικά.
  for (long i = 1; i + len -1 < N; ++i) {
    // Μεταφέρουμε το παράθυρο κατά μία θέση άρα αφαιρούμε το στοιχείο
	// A[i-1] και προσθέτουμε το A[i+len-1].
    --count[A[i-1]];
	if (count[A[i-1]] == 0) --different_colors;
	if (count[A[i+len-1]] == 0) ++different_colors;
	++count[A[i+len-1]];
	if (different_colors == K) return true;
  } 
  return false;
}

int main() {
  FILE *fi = fopen("colors.in", "r");
  fscanf(fi, "%ld %ld", &N, &K);
  
  for (long i = 0; i < N; ++i) {
    fscanf(fi, "%ld", &A[i]);
  }
  fclose(fi);
  
  long lo = K, hi = N;
  while (lo < hi) {
	long mid = (lo + hi) / 2;
	if (existsIntervalWithLength(mid)) hi = mid;
	else lo = mid + 1;
  }
  
  FILE *fo = fopen("colors.out", "w");
  fprintf(fo, "%ld\n", existsIntervalWithLength(N) ? lo : 0);
  fclose(fo);
  return 0;
}

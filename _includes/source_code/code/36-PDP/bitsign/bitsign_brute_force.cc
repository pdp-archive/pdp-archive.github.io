#include <cstdio>
#include <vector>

const long MOD = 1'000'000'007L;
const int MAXN = 2'000;

char c[MAXN + 2];
std::vector<int> s;

long total;
int N, M;

/* Δοκιμάζουμε τις δυνατές τιμές για το c[c_idx], δεδομένου ότι έχουμε 
   συμπληρώσει τις τιμές για τα c[0..c_idx-1], έχουμε φτιάξει τα διαστήματα
   s[0..s_idx-1] και το μήκος της τωρινης ακολουθίας από άσους είναι 
   len_of_ones. */
void solve(int c_idx, int len_of_ones, int s_idx) {
   if (c_idx == N + 1) {
      // Συμπληρώσαμε όλη την ακολουθία. Ελέγχουμε αν είναι σωστή.
      if (s_idx == s.size() && len_of_ones == 0) total = (total + 1) % MOD;
      return;
   }
   if (c[c_idx] == '1' || c[c_idx] == '.') solve(c_idx + 1, len_of_ones + 1, s_idx);
   if (c[c_idx] == '0' || c[c_idx] == '.') {
      if (s_idx < s.size() && len_of_ones == s[s_idx]) solve(c_idx + 1, 0, s_idx + 1);
      else if (len_of_ones == 0) solve(c_idx + 1, 0, s_idx);
   }
}

int main() {
   FILE *fi = fopen("bitsign.in", "r");
   FILE *fo = fopen("bitsign.out", "w");
   
   int T;
   fscanf(fi, "%d\n", &T);
   while (T--) {
      fscanf(fi, "%d %d\n", &N, &M);
      for (int i = 0; i < N; ++i) {
         fscanf(fi, "%c", &c[i]);
      }
      c[N] = '0';
      s.resize(M);
      for (int i = 0; i < M; ++i) {
         fscanf(fi, "%d", &s[i]);
      }
      
      total = 0;
      solve(0, 0, 0);
      
      fprintf(fo, "%ld\n", total);
   }
   
   fclose(fi);
   fclose(fo);
   return 0;
}

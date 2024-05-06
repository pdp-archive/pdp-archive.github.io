#include <cstdio>
#include <vector>

const long MOD = 1'000'000'007L;
const int MAXN = 2'000;

char c[MAXN + 2];

int main() {
   FILE *fi = fopen("bitsign.in", "r");
   FILE *fo = fopen("bitsign.out", "w");
   
   int T;
   fscanf(fi, "%d\n", &T);
   while (T--) {
      int N, M;
      
      fscanf(fi, "%d %d\n", &N, &M);
      for (int i = 0; i < N; ++i) {
         fscanf(fi, "%c", &c[i+1]);
      }
      c[0] = c[N+1] = '0';
      std::vector<int> s(M);
      for (int i = 0; i < M; ++i) {
         fscanf(fi, "%d", &s[i]);
      }
      
      // Προϋπολογίζουμε το πρώτο μηδενικό στα δεξιά του κάθε στοιχείου.
      std::vector<int> first_zero_to_left(N + 2);
      for (int i = N + 1; i >= 0; --i) {
         if (c[i] == '0') {
            first_zero_to_left[i] = i;
            continue;
         }
         first_zero_to_left[i] = std::min(first_zero_to_left[i+1], i);
         while (c[first_zero_to_left[i]] != '0') --first_zero_to_left[i];
      }
      
      // Ο υπολογισμός με δυναμικό προγραμματισμό.
      std::vector<std::vector<int>> dp(M+1, std::vector<int>(N+2, 0));
      for (int i = 0; i <= N+1 && c[i] != '1'; ++i) dp[0][i] = 1;
      
      for (int j = 1; j <= M; ++j) {
         for (int i = 1; i <= N + 1; ++i) {
            if (c[i] == '1') continue;
            dp[j][i] = dp[j][i-1]; // Μπορούμε απλά να προσθέσουμε ένα 0.
            if (i - first_zero_to_left[i - 1] - 1 >= s[j-1]) // Υπάρχουν αρκετά ‘1' ή ‘.'?
               dp[j][i] = (dp[j][i] + dp[j - 1][i - s[j-1] - 1]) % MOD;
         }
      }
      fprintf(fo, "%ld\n", dp[M][N+1]);
   }
   
   fclose(fi);
   fclose(fo);
   return 0;
}

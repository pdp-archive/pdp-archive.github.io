#include <algorithm>
#include <cstdio>

const size_t MAXN = 1024;
const size_t MAXM = 65536;

typedef long long ll;

char S[MAXN + MAXM + 1];
long Z[MAXN + MAXM];

int main() {
   long N, M;
   FILE *fi = fopen("matrix.in", "r");
   fscanf(fi, "%ld\n", &N);
   for (long i = 0; i < N; ++i) {
      S[i] = fgetc(fi);
   }
   
   fscanf(fi, "%ld\n", &M);
   for (long i = 0; i < M; ++i) {
      S[N + i] = fgetc(fi);
   }
   long found_pos = -1;
   // Υπολογισμος του πίνακα Z για την S = Α + Β.
   long len = N + M;
   long L = 0, R = 0;
   Z[0] = len;
   for (long i = 1; i < len; ++i) {
      Z[i] = 0;
      if (i <= R) Z[i] = std::min(R - i + 1, Z[i - L]);
      while (i + Z[i] < len && S[Z[i]] == S[i + Z[i]]) Z[i]++;
      if (i + Z[i] - 1 > R) {
         L = i; R = i + Z[i] - 1;
      }
      // Αν κάποιο στοιχείο έχει N στοιχεία ή περισσότερα κοινά
      // με το prefix της συμβολοσειράς, τότε βρήκαμε μία 
      // εμφάνιση της Α.
      if (Z[i] >= N) {
         found_pos = i - N + 1;
         break;
      }
   }
   FILE *fo = fopen("matrix.out", "w");
   if (found_pos == -1) fprintf(fo, "F\n");
   else fprintf(fo, "%ld\n", found_pos);
   return 0;
}

#include <cstdio>

using namespace std;

const int MAXN = 100005;
const int MAXM = 505;

int N, M, K;
int items[MAXN];
// dp[i][j] είναι η βέλτιστη λύση για τα πρώτα i αντικείμενα με j μετακινήσεις.
int dp[MAXN][MAXM];

// Επιστρέφει 1 αν είναι πολλαπλάσιο του K, 0 αλλιώς.
// Πολλαπλασιαζουμε με αυτό την τιμή του αντικειμένου όταν το προσθέτουμε στο
// συνολικό αποτέλεσμα, ώστε να πάρουμε την τιμή του μόνο αν η τελική του θέση
// είναι πολλαπλάσιο του K.
inline int is_coupon_position(int position)
{
   return position % K == 0 ? 1 : 0;
}

int main()
{
   FILE *fin = fopen("supermarket.in", "r");
   FILE *fout = fopen("supermarket.out", "w");

   fscanf(fin, "%d %d %d", &N, &M, &K);
   if (M > N)
      M = N;
   for (int i = 1; i <= N; ++i)
      fscanf(fin, "%d", items + i);
   fclose(fin);

   // Αρχικοποιούμε τον πίνακα dp
   dp[0][0] = 0;

   // Ελέγχουμε όλα τα πιθανά πλήθη συνολικών μετακινήσεων
   int best_score = 0;
   for (int moves = 0; moves <= M; ++moves)
   {
      for (int i = 1; i <= N; ++i)
      {
         for (int curr_moves = 0; curr_moves <= moves; ++curr_moves)
         {
            // Δεν μπορούμε να μετακινήσουμε πιο πολλά αντικείμενα από αυτά που
            // έχουμε συναντήσει.
            if (curr_moves > i)
               break;

            dp[i][curr_moves] = 0;

            // Περίπτωση που δεν μετακινούμε το i-οστό αντικείμενο.
            if (curr_moves <= i - 1)
               dp[i][curr_moves] = dp[i - 1][curr_moves] + items[i] * is_coupon_position(i - curr_moves);

            // Περίπτωση που μετακινούμε το i-οστό αντικείμενο.
            if (curr_moves > 0)
            {
               int new_score = dp[i - 1][curr_moves - 1] + items[i] * is_coupon_position(N - moves + curr_moves);
               if (dp[i][curr_moves] < new_score)
                  dp[i][curr_moves] = new_score;
            }
         }
      }
      if (best_score < dp[N][moves])
         best_score = dp[N][moves];
   }

   fprintf(fout, "%d\n", best_score);
   fclose(fout);
}

// Λύση για το τρίτο υποπρόβλημα όπου h_i <= 10^5
// Επειδή τα μήκη των μπαμπού είναι μικρά, μπορούμε να χρησιμοποιήσουμε
// έναν πίνακα συχνοτήτων για να αποθηκεύσουμε πόσα
// μπαμπού υπάρχουν για κάθε μήκος.

#include <cstdio>

const size_t MAXN = 200'000;
const size_t MAXH = 100'005;

using namespace std;

long n;
long heights_count[MAXH];

int main() {
  scanf("%ld", &n);
  long len;
  for (long i = 0; i < n; i++) {
    // Διαβάζουμε το μήκος κάθε μπαμπού και αυξάνουμε
    // τη συχνότητά του στον πίνακα
    scanf("%ld", &len);
    heights_count[len]++;
  }

  // Για κάθε διαφορετικό μήκος μπαμπού που υπάρχει, χρειαζόμαστε μία μέρα
  long total_days = 0;
  for (long i = 0; i < MAXH; i++) {
    if (heights_count[i] > 0) {
      total_days++;
    }
  }

  printf("%ld\n", total_days);
}

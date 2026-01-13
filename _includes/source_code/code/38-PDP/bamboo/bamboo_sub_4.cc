#include <cstdio>
#include <algorithm>

#define MAXN 200005
#define MAXH 100005

using namespace std;

int n;
int heights_count[MAXH];

int main() {
  // Λύση για το τρίτο υποπρόβλημα όπου h_i <= 10^5
  // Επειδή τα μήκη των μπαμπού είναι μικρά, μπορούμε να χρησιμοποιήσουμε
  // έναν πίνακα συχνοτήτων για να αποθηκεύσουμε πόσα
  // μπαμπού υπάρχουν για κάθε μήκος.
  
  scanf("%d", &n);
  int len;
  for (int i = 0; i < n; i++) {
    // Διαβάζουμε το μήκος κάθε μπαμπού και αυξάνουμε
    // τη συχνότητά του στον πίνακα
    scanf("%d", &len);
    heights_count[len]++;
  }

  // Για κάθε διαφορετικό μήκος μπαμπού που υπάρχει, χρειαζόμαστε μία μέρα
  int total_days = 0;
  for (int i = 0; i < MAXH; i++) {
    if (heights_count[i] > 0) {
      total_days++;
    }
  }

  printf("%d\n", total_days);
}

// Λύση για το τρίτο υποπρόβλημα όπου h_i <= 10^5
// Επειδή τα μήκη των μπαμπού είναι μικρά, μπορούμε να χρησιμοποιήσουμε
// έναν πίνακα συχνοτήτων για να αποθηκεύσουμε πόσα
// μπαμπού υπάρχουν για κάθε μήκος.

#include <bitset>
#include <cstdio>

const size_t MAXN = 200'000;
const size_t MAXH = 100'000;

using namespace std;

long N;
bitset<MAXH + 1> lengths_found;

int main() {
  scanf("%ld", &N);
  long len;
  for (long i = 0; i < N; i++) {
    // Διαβάζουμε το μήκος κάθε μπαμπού και σημειώνουμε ότι το βρήκαμε
    scanf("%ld", &len);
    lengths_found[len] = true;
  }

  printf("%zu\n", lengths_found.count());
}

#include <algorithm>
#include <cstdio>

const size_t MAXN = 200'000;

using namespace std;

long N;
long lengths[MAXN];

int main() {
  // Διαβάζουμε τα μήκη των μπαμπού
  scanf("%ld", &N);
  for (long i = 0; i < N; i++) {
    scanf("%ld", &lengths[i]);
  }

  // Ταξινομούμε τα μήκη για να μετρήσουμε τα μοναδικά μήκη
  sort(lengths, lengths + N);

  long last_length = -1;
  long unique_count = 0;
  for (long i = 0; i < N; i++) {
    // Αν το μήκος είναι διαφορετικό από το προηγούμενο, αυξάνουμε τον μετρητή
    // μοναδικών μηκών και ενημερώνουμε το τελευταίο μήκος
    if (lengths[i] != last_length) {
      unique_count++;
      last_length = lengths[i];
    }
  }

  printf("%ld\n", unique_count);
}

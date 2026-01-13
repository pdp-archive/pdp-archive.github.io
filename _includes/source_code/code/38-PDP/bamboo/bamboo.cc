#include <cstdio>
#include <algorithm>

#define MAXN 200005

using namespace std;

int n;
int lengths[MAXN];

int main() {

  // Διαβάζουμε τα μήκη των μπαμπού
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &lengths[i]);
  }

  // Ταξινομούμε τα μήκη για να μετρήσουμε τα μοναδικά μήκη
  sort(lengths, lengths + n);

  int last_length = -1;
  int unique_count = 0;
  for (int i = 0; i < n; i++) {
    // Αν το μήκος είναι διαφορετικό από το προηγούμενο, αυξάνουμε τον μετρητή
    // μοναδικών μηκών και ενημερώνουμε το τελευταίο μήκος
    if (lengths[i] != last_length) {
      unique_count++;
      last_length = lengths[i];
    }
  }

  printf("%d\n", unique_count);
}

// Λύση για το τρίτο υποπρόβλημα όπου N <= 5'000
// Επειδή ο αριθμός των μπαμπού είναι μικρός, μπορούμε να
// απλά να προσομοιώσουμε τη διαδικασία κοπής μπαμπού
// μέρα με τη μέρα.

#include <cstdio>

const size_t MAXN = 200'000;

using namespace std;

long N;
long lengths[MAXN];

int main() {
  scanf("%ld", &N);
  for (long i = 0; i < N; i++) {
    scanf("%ld", &lengths[i]);
  }

  // Το μήκος του μπαμπού που κόβουμε την τρέχουσα μέρα
  long current_bamboo_length = 0;
  // Συνολικές μέρες που χρειάστηκαν
  long total_days = 0;
  while (true) {
    current_bamboo_length = 0;
    // Βρίσκουμε κάποιο μήκος μπαμπού που δεν έχει κοπεί ακόμα και κόβουμε
    // όλα τα μπαμπού με αυτό το μήκος.
    for (long i = 0; i < N; i++) {
      if (lengths[i] == 0)
        continue;
      if (current_bamboo_length == 0)
        current_bamboo_length = lengths[i];
      if (current_bamboo_length == lengths[i])
        lengths[i] = 0;
    }

    // Αν current_bamboo_length = 0, τότε έχουν κοπεί όλα τα bamboo και
    // σταματάμε
    if (current_bamboo_length > 0)
      total_days++;
    else
      break;
  }

  printf("%ld\n", total_days);
}

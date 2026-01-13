#include <cstdio>
#include <algorithm>

#define MAXN 200005

using namespace std;

int n;
int lengths[MAXN];

int main() {
  // Λύση για το τρίτο υποπρόβλημα όπου N <= 5000
  // Επειδή ο αριθμός των μπαμπού είναι μικρός, μπορούμε να
  // απλά να προσομοιώσουμε τη διαδικασία κοπής μπαμπού
  // μέρα με τη μέρα.
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &lengths[i]);
  }

  // Πόσα μπαμπού έχουν κοπεί μέχρι στιγμής
  int bamboos_cut = 0;
  // Το μέγιστο μήκος μπαμπού που κόπηκε στη τρέχουσα μέρα
  int current_max_bamboo = 0;
  // Συνολικές μέρες που χρειάστηκαν
  int total_days = 0;
  while (bamboos_cut < n) {
    current_max_bamboo = 0;
    // Βρίσκουμε το μέγιστο μήκος μπαμπού που δεν έχει κοπεί ακόμα
    for (int i = 0; i < n; i++) {
      if (lengths[i] > current_max_bamboo) {
        current_max_bamboo = lengths[i];
      }
    }

    for (int i = 0; i < n; i++) {
      // Κόβουμε όλα τα μπαμπού που έχουν μήκος ίσο με το μέγιστο
      if (lengths[i] == current_max_bamboo) {
        lengths[i] = 0; // Σηματοδοτούμε ότι το μπαμπού έχει κοπεί
        bamboos_cut++;
      }
    }

    // Αυξάνουμε την ημέρα
    total_days++;
  }

  printf("%d\n", total_days);
}

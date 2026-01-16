#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

long n;
vector<long> lengths;

int main() {
  // Διαβάζουμε τα μήκη των μπαμπού
  scanf("%ld", &n);
  lengths.resize(n);
  for (long i = 0; i < n; i++) {
    scanf("%ld", &lengths[i]);
  }

  // Χρησιμοποιήσουμε τις ήδη υπάρχουσες συναρτήσεις της STL για να
  // ταξινομήσουμε και έπειτα αν απομονόσουμε τις μοναδικές τιμές των μηκών.
  sort(lengths.begin(), lengths.end());
  lengths.erase(unique(lengths.begin(), lengths.end()), lengths.end());
  printf("%zu\n", lengths.size());
}

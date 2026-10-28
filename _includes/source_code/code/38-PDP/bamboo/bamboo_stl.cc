#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

long N;
vector<long> lengths;

int main() {
  // Διαβάζουμε τα μήκη των μπαμπού
  scanf("%ld", &N);
  lengths.resize(N);
  for (long i = 0; i < N; i++) {
    scanf("%ld", &lengths[i]);
  }

  // Χρησιμοποιήσουμε τις ήδη υπάρχουσες συναρτήσεις της STL για να
  // ταξινομήσουμε και έπειτα αν απομονόσουμε τις μοναδικές τιμές των μηκών.
  sort(lengths.begin(), lengths.end());
  lengths.erase(unique(lengths.begin(), lengths.end()), lengths.end());
  printf("%zu\n", lengths.size());
}

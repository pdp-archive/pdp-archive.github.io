#include <cstdio>
#include <unordered_set>

using namespace std;

long n;
unordered_set<long> unique_lengths;

int main() {
  // Διαβάζουμε τα μήκη των μπαμπού και τα αποθηκεύουμε στο unordered_set
  scanf("%ld", &n);
  long len;
  for (long i = 0; i < n; i++) {
    scanf("%ld", &len);
    unique_lengths.insert(len);
  }

  printf("%zu\n", unique_lengths.size());
}

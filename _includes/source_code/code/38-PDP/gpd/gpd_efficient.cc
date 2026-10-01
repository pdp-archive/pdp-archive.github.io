#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

const long T = 10'000'000;

long prime_factor[T + 1]; // Ο μικρότερος πρώτος που διαιρεί έναν αριθμό.
long cnt_primes[T + 1]; // Πόσοι πρώτοι αριθμοί μικρότεροι από x.
long primes[T]; // Οι πρώτοι αριθμοί.

int main() {
  long Q;
  scanf("%ld", &Q);
  
  // Βρίσκουμε τον μέγιστο γνήσιο διαιρέτη για κάθε μικρό αριθμό.
  long prime_idx = 0;
  for (long i = 2; i < T; ++i) {
    cnt_primes[i] = cnt_primes[i-1];
    if (prime_factor[i] != 0) continue;
    ++cnt_primes[i];
    primes[prime_idx] = i;
    ++prime_idx;
    for (long j = i * i; j < T; j += i) {
      if (prime_factor[j] == 0) prime_factor[j] = i;
    }
  }
  
  while (Q--) {
    long long G;
    scanf("%lld", &G);
    long long smallest_prime_factor;
    if (G < T) smallest_prime_factor = prime_factor[G];
    else {
      for (long j = 0; j <= prime_idx; ++j) {
        if (G % primes[j] == 0) {
          smallest_prime_factor = primes[j];
          break;
        }
      }
    }
    printf("%ld\n", cnt_primes[smallest_prime_factor]);
  }
  
  return 0;
}


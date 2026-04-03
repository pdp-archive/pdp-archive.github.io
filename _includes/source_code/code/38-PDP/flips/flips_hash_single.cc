#include <cstdint>
#include <cstdio>
#include <iostream>
#include <random>
#include <unordered_map>

const long MAXN = 100'000;

// Το hash για κάθε στήλη.
uint64_t column_hash[MAXN + 1];
// Το hash για μία (υποθετική) γραμμή με όλα 111.11.
uint64_t all_columns_hash;
// Το hash κάθε γραμμή.
uint64_t row_hash[MAXN + 1];

// Πλήθος των διαφορετικών τιμών hash.
std::unordered_map<uint64_t, long> hash_count;

void generate_column_hashes(long N) {
  // Ενώνουμε δύο 32-bit hash για να πάρουμε ένα 64-bit.
  std::mt19937 gen1(47), gen2(19);
  std::uniform_int_distribution<uint32_t> dis(0, std::numeric_limits<uint32_t>::max());
  all_columns_hash = 0;
  for (long i = 1; i <= N; ++i) {
    column_hash[i] = (uint64_t(dis(gen1)) << 32) | dis(gen2);
    all_columns_hash ^= column_hash[i];
  }
}

void toggle(long r, long c) {
  // Ανανεώνουμε το hash της γραμμής x.
  uint64_t& cur_row_hash = row_hash[r];
  // 1. Μειώνουμε τον μετρητή για αυτό το hash.
  long rem = --hash_count[cur_row_hash];
  if (rem == 0) hash_count.erase(cur_row_hash);
  // 2. Υπολογίζουμε το καινούργιο hash.
  cur_row_hash ^= column_hash[c];
  // 3. Αυξάνουμε τον μετρητή για το καινούργιο hash. 
  ++hash_count[cur_row_hash];
}

// Έλεγχος για το αν υπάρχουν ακριβώς δύο hash που το ένα αντιστοιχή σε γραμμή
// αντίθετη του άλλου. 
bool has_two_opposite_values() {
  if (hash_count.size() != 2) return false;
  auto it = hash_count.begin(); uint64_t one = it->first;
  ++it; uint64_t two = it->first;
  return one == (all_columns_hash ^ two);
}

void print_solution() {
  if (hash_count.size() == 1 || has_two_opposite_values()) printf("2\n"); 
  else printf("0\n");
}

int main() {
  long N, K, Q;
  scanf("%ld%ld%ld", &N, &K, &Q);
  
  generate_column_hashes(N);
  
  // Αρχικά έχουμε Ν γραμμές με το ίδιο hash.
  hash_count[0] = N;
  
  for (long i = 0; i < K; ++i) {
    long r, c;
    scanf("%ld%ld", &r, &c);
    toggle(r, c);
  }
  print_solution();
  
  for (long i = 0; i < Q; ++i) {
    long a, b, c, d;
    scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
    toggle(a, c);
    print_solution();
  }
  return 0;
}


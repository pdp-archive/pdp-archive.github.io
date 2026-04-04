#include <algorithm>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <random>
#include <unordered_map>

std::unordered_map<uint64_t, long> hash_count;

// Το hash για κάθε στήλη.
std::unordered_map<long, uint64_t> column_hash;
// Το hash για μία (υποθετική) γραμμή με όλα 111.11.
uint64_t all_columns_hash = 0;
// Το hash κάθε γραμμή.
std::unordered_map<long, uint64_t> row_hash;

// Ελέγχουμε αν όλες οι στήλες έχουν ανανεωθεί σε κάποιο σημείο.
bool all_columns_touched = false;

// Ενώνουμε δύο 32-bit hash για να πάρουμε ένα 64-bit.
std::mt19937 gen1(47), gen2(19);
std::uniform_int_distribution<uint32_t> dis(0, std::numeric_limits<uint32_t>::max());

uint64_t get_column_hash(long i) {
  if (column_hash.find(i) == column_hash.end()) {
    column_hash[i] = (uint64_t(dis(gen1)) << 32) | dis(gen2);
    all_columns_hash ^= column_hash[i];
  }
  return column_hash[i];
}

void toggle(long x, long y) {
  // Ανανεώνουμε το hash της γραμμής x.
  uint64_t& cur_row_hash = row_hash[x];
  // 1. Μειώνουμε τον μετρητή για αυτό το hash.
  long rem = --hash_count[cur_row_hash];
  if (rem == 0) hash_count.erase(cur_row_hash);
  // 2. Υπολογίζουμε το καινούργιο hash.
  cur_row_hash ^= get_column_hash(y);
  // 3. Αυξάνουμε τον μετρητή για το καινούργιο hash. 
  ++hash_count[cur_row_hash];
}

// Έλεγχος για το αν υπάρχουν ακριβώς δύο hash που το ένα αντιστοιχεί σε γραμμή
// αντίθετη του άλλου. 
bool has_two_opposite_values() {
  if (hash_count.size() != 2) return false;
  if (!all_columns_touched) return false;
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
  
  // Αρχικά έχουμε Ν γραμμές με το ίδιο hash.
  hash_count[0] = N;
  
  std::vector<std::pair<long, long>> pts;
  pts.reserve(K);
  for (long i = 0; i < K; ++i) {
    long x, y;
    scanf("%ld%ld", &x, &y);
    get_column_hash(y);
    pts.push_back({x, y});
  }
  
  std::vector<std::tuple<long, long, long, long>> queries;
  queries.reserve(Q);
  
  for (long i = 0; i < Q; ++i) {
    long a, b, c, d;
    scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
    get_column_hash(c);
    queries.push_back({a, b, c, d});
  }
  
  all_columns_touched = (column_hash.size() == N);
  
  for (auto [x, y]: pts) {
    toggle(x, y);
  }
  print_solution();
  
  for (auto [a, b, c, d]: queries) {
    toggle(a, c);
    print_solution();
  }
  
  return 0;
}


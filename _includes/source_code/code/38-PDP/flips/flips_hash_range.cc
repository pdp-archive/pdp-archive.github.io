#include <algorithm>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <unordered_map>

long N;

// Οι τιμές των διαφορών δύο γειτονικών hash, δηλαδή row_hash[i] ^ row_hash[i+1].
std::unordered_map<uint64_t, long> diff_hash_count;

// Το hash για κάθε στήλη.
std::map<long, uint64_t> column_hash;

// prefix_column_hash[i] = column_hash[1] ^ .. ^ column_hash[i] 
std::unordered_map<long, uint64_t> prefix_column_hash;

// Το hash για μία (υποθετική) γραμμή με όλα 111.11.
uint64_t all_columns_hash = 0;
// diff_row_hash[i] = row_hash[i] ^ row_hash[i + 1]
std::map<long, uint64_t> diff_row_hash;

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

// Υπολογισμός του προθέματος των hash.
void compute_prefix_hash() {
  prefix_column_hash[0] = 0;
  uint64_t prev = 0;
  for (auto [c, hash] : column_hash) {
    prefix_column_hash[c] = prev ^ hash;
    prev = prefix_column_hash[c];
  }
}

// Ανανέωση της διαφοράς στην γραμμή r.
void update_hash(long r, uint64_t dy) {
  if (r == 0 || r == N) return;
  // Ανανεώνουμε το hash της γραμμής r.
  uint64_t& cur_diff_row_hash = diff_row_hash[r];
  // 1. Μειώνουμε τον μετρητή για αυτό το hash.
  long rem = --diff_hash_count[cur_diff_row_hash];
  if (rem == 0) diff_hash_count.erase(cur_diff_row_hash);
  // 2. Υπολογίζουμε το καινούργιο hash.
  cur_diff_row_hash ^= dy;
  // 3. Αυξάνουμε τον μετρητή για το καινούργιο hash. 
  ++diff_hash_count[cur_diff_row_hash];
}

void toggle(long a, long b, long c, long d) {
  uint64_t columns_range_hash = prefix_column_hash[d] ^ prefix_column_hash[c-1];
  update_hash(a-1, columns_range_hash);
  update_hash(b, columns_range_hash);
}

// Έλεγχος για το αν υπάρχουν ακριβώς δύο hash που το ένα αντιστοιχεί σε γραμμή
// αντίθετη του άλλου. 
bool has_two_valid_values() {
  if (diff_hash_count.size() != 2) return false;
  if (!all_columns_touched) return false;
  auto it = diff_hash_count.begin(); uint64_t one = it->first;
  ++it; uint64_t two = it->first;
  return (one == 0 && two == all_columns_hash) || (one == all_columns_hash && two == 0);
}

bool has_one_valid_value() {
  if (diff_hash_count.size() != 1) return false;
  uint64_t diff_hash_value = diff_hash_count.begin()->first;
  return diff_hash_value == 0 || diff_hash_value == all_columns_hash;
}

void print_solution() {
  if (has_one_valid_value() || has_two_valid_values()) {printf("2\n"); } 
  else {printf("0\n"); }
}
  
int main() {
  long K, Q;
  scanf("%ld%ld%ld", &N, &K, &Q);
  
  // Αρχικά έχουμε Ν γραμμές με το ίδιο hash.
  diff_hash_count[0] = N - 1;
  
  std::vector<std::pair<long, long>> pts;
  pts.reserve(K);
  for (long i = 0; i < K; ++i) {
    long x, y;
    scanf("%ld%ld", &x, &y);
    pts.push_back({x, y});
  }
  
  std::vector<std::tuple<long, long, long, long>> queries;
  queries.reserve(Q);
  
  for (long i = 0; i < Q; ++i) {
    long a, b, c, d;
    scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
    queries.push_back({a, b, c, d});
  }
  
  // Ακουμπάμε όλες τις στήλες (αργό για μεγάλα Ν).
  for (long i = 1; i <= N; ++i) {
    get_column_hash(i);
  }
  compute_prefix_hash();
  all_columns_touched = true;
  
  for (auto [x, y]: pts) {
    toggle(x, x, y, y);
  }
  print_solution();
  
  for (auto [a, b, c, d]: queries) {
    toggle(a, b, c, d);
    print_solution();
  }
  
  return 0;
}


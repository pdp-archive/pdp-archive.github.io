#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <limits>
#include <map>
#include <vector>



// append(x, y) = 0b x100...00
//                        y
// Παράδειγμα: 
//   append(0b1011010100, 4) = 0b101101010010000
void append(uint32_t& ans, uint32_t val) {
  ans = (ans << (val + 1)) | (1 << val); 
}

// Κωδικοποιεί τις διαφορές μεταξύ διαδοχικών στοιχείων στην δοσμένη
// ακολουθία σε έναν ακέραιο 64-bit. 
// Παράδειγμα:
//   simple_encode({2, 6, 9, 10, 7, 3})
//   left = {2, 6, 9, 10}  right = {10, 7, 3}
//          {4, 3, 1}              {3, 4}
//          10000100010            100010000
//   ans = 00..0010000100010|00..00100010000
uint64_t simple_encode(const std::vector<int>& seq) {
  uint32_t left = 1;
  int prev = 0;
  int seq_idx = 0;
  for (;seq_idx < seq.size(); ++seq_idx) {
    int v = seq[seq_idx];
    if (v < prev) break;
    append(left, v - prev);
    prev = v;
  }
  uint32_t right = 1;
  for (;seq_idx < seq.size(); ++seq_idx) {
    int v = seq[seq_idx];
    append(right, prev - v);
    prev = v;
  }
  return (uint64_t(left) << 32) | right;
}

// Παράδειγμα:
//   simple_decode_half(10000100010) = {4, 3, 1}
std::vector<int> simple_decode_half(uint32_t seq) {
  std::vector<int> ans;
  while (seq != 0) {
    int val = 0;
    while (seq % 2 != 1) {
      ++val;
      seq /= 2;
    }
    seq /= 2;
    ans.push_back(val);
  }
  ans.pop_back();
  std::reverse(ans.begin(), ans.end());
  return ans;
}

// Παράδειγμα:
//   ans = 00..0010000100010|00..00100010000
//          10000100010            100010000
//          {4, 3, 1}              {3, 4}
//          {4, 3, 1, -3, -4}
//   ans =  {2, 6, 9, 10, 7, 3}
std::vector<int> simple_decode(uint64_t encoding) {
  auto inc = simple_decode_half(encoding >> 32);
  auto dec = simple_decode_half(encoding & 0xFFFFFFFFULL);
  std::vector<int> ans;
  int prev = 0;
  for (auto delta : inc) {
    prev += delta;
    ans.push_back(prev);
  }
  for (auto delta : dec) {
    prev -= delta;
    ans.push_back(prev);
  }
  return ans;
}

std::vector<std::pair<uint64_t,int>> forwards; // Ταξινομημένος πίνακας.
std::vector<uint64_t> backwards; // Ανίστροφος πίνακας.

int counter = 0;

// Δημιουργούμε όλες τις δυνατές ακολουθίες που ικανοποιούν την ιδιότητα της
// πυραμίδας και τις αντιστούμε σε έναν αριθμό.
void explore(std::vector<int>& cur_seq, bool is_increasing, bool is_forwards) {
  if (!cur_seq.empty()) {
    auto encoding = simple_encode(cur_seq);
    if (is_forwards) forwards.push_back({encoding, counter});
    else backwards.push_back(encoding);
    ++counter;
  }
  
  int prev = cur_seq.empty() ? 0 : cur_seq.back();
  cur_seq.push_back(-1);
  // Προσθέτουμε ένα μικρότερο στοιχείο.
  for (int nxt = 1; nxt < prev; ++nxt) {
    cur_seq.back() = nxt;
    explore(cur_seq, false, is_forwards);
  }
  // Προσθέτουμε ένα μεγαλύτερο στοιχείο.
  if (is_increasing) {
    for (int nxt = prev + 1; nxt <= 12; ++nxt) {
      cur_seq.back() = nxt;
      explore(cur_seq, true, is_forwards);
    } 
  }
  cur_seq.pop_back();
}

// Τυπώνουμε τον αριθμό:
// Αν cnt >  2^22 τότε βάζουμε κάποια μηδενικά στην αρχή.
// Αν cnt <= 2^22 τότε τυπώνουμε χωρίς μηδενικά.
void print_binary_seq(int cnt) {
  bool fill_with_zeros = false;
  if (cnt >= (1 << 22)) {
    fill_with_zeros = true;
    cnt -= (1 << 22);
  }
  int num_bits = 0;
  while (cnt) {
    if (cnt & 1) printf("1");
    else printf("0");
    cnt >>= 1;
    ++num_bits;
  }
  // Γεμίζουμε τον αριθμό με μηδενικά.
  if (fill_with_zeros) {
    while (num_bits < 22) {
      printf("0");
      ++num_bits;
    }
  } 
  printf("\n");
}

void print_seq(const std::vector<int>& seq) {
  printf("%d\n", seq.size());
  bool is_first = true;
  for (auto v : seq) {
    if (!is_first) printf(" ");
    else is_first = false;
    printf("%d", v);
  }
  printf("\n");
}

int main() {
  long M, T;
  scanf("%ld",&M);
  
  if (M == 1) {
    // Περνάμε στο vector πόσα στοιχεία θα έχουμε 
    // (1) για να μην το κάνει μεγαλύτερο από ότι πρέπει, και
    // (2) για να μην κάνει περιττές δεσμεύσεις μνήμης.
    forwards.reserve(5592406);
    std::vector<int> tmp_seq;
    explore(tmp_seq, true, true);
    std::sort(forwards.begin(), forwards.end());
    
    long T;
    scanf("%ld", &T);
    printf("2\n");
    printf("%ld\n", T);
    while (T--) {
      int N;
      scanf("%d", &N);
      std::vector<int> seq;
      for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        seq.push_back(tmp);
      }
      std::pair<uint64_t, int> key{simple_encode(seq), 0 };
      auto it = std::lower_bound(forwards.begin(), forwards.end(), key);
      print_binary_seq(it->second);
    }
  } else {
    std::vector<int> tmp_seq;
    explore(tmp_seq, true, false);
    long T;
    printf("1\n");
    scanf("%ld\n", &T);
    printf("%ld\n", T);
    char str[128];
    while (T--) {
      std::fgets(str, 100, stdin);
      int i = 0;
      int val = 0;
      for (; str[i] != '\n'; ++i) {
        if (str[i] == '1') val |= 1 << i;
      }
      if (i == 22 && val < (1 << 21) ) val |= (1 << 22); 
      print_seq(simple_decode(backwards[val]));
    }
  }
  return 0;
}


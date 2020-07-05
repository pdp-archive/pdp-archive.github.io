#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct State {
   vector<int> positions;
   int rightmost;
   int leftmost;
   int count;
   bool complement;
   
   State reverse() const {
      State other = *this;
      // Αντιστρέφουμε τις θέσεις των στοιχείων που έχουμε δει.
      for (size_t i = 0; i < 4; ++i) {
         if (other.positions[i] != 0) other.positions[i] = (count + 1) - other.positions[i];
      }
      other.leftmost = rightmost;
      other.rightmost = leftmost;
      return other;
   }
   
   void appendRight(int val) {
      if (positions[val] == 0) {
         ++count;
         positions[val] = count;
         if (count == 1) leftmost = val;
         rightmost = val;
      }
   }
   
   bool canAppend(int val) const {
      return rightmost == val || positions[val] == 0;
   }
   
   /* Χρειάζεται ώστε το State να μπορεί να είναι κλειδί σε set. */
   bool operator<(const State& other) const {
      if (count != other.count) return count < other.count;
      if (rightmost != other.rightmost) return rightmost < other.rightmost;
      if (leftmost != other.leftmost) return leftmost < other.leftmost;
      if (count != other.count) return count < other.count;
      if (complement != other.complement) return complement < other.complement;
      return positions < other.positions;
   }
   
   State() {
      positions.push_back(0); positions.push_back(0); positions.push_back(0); positions.push_back(0);
      leftmost = rightmost = -1;
      count = 0;
      complement = false;
   }
};
   

bool is_smaller(const string& s1, const string& s2) {
   if (s1.size() != s2.size()) return s1.size() < s2.size();
   return s1 < s2;
}

void compare_and_add(map<State, string>& mp, State& state, string& val) {
   if (mp.find(state) == mp.end()) {
     mp[state] = val;
   } else if (is_smaller(val, mp[state])){
     mp[state] = val;
   }
}


string solve(vector<int>& x) {
  map<State, string> current, next;
  State p_state; p_state.appendRight(x[0]);
  current[p_state] = "p";
  State cp_state; cp_state.appendRight(3 - x[0]); cp_state.complement = true;
  current[cp_state] = "cp";
  // Δεν έχει νόημα να κάνουμε rp στην αρχή.
  
  for (size_t i = 1; i < x.size(); ++i) {
    for (auto& state_and_sequence : current) {
      const auto& state = state_and_sequence.first;
      const auto& sequence = state_and_sequence.second;
      int current_val = state.complement ? (3 - x[i]) : x[i];
      
      // Push.
      if (state.canAppend(current_val)) {
         string new_sequence = sequence + "p";
         State new_state = state;
         new_state.appendRight(current_val);
         compare_and_add(next, new_state, new_sequence);
      }
      // Reverse και push.
      State reverse_state = state.reverse();
      if (reverse_state.canAppend(current_val)) {
         string new_sequence = sequence + "rp";
         reverse_state.appendRight(current_val);
         compare_and_add(next, reverse_state, new_sequence);
      }
      
      // Complement και push.
      if (state.canAppend(3-current_val)) {
         string new_sequence = sequence + "cp";
         State new_state = state;
         new_state.appendRight(3-current_val);
         new_state.complement = !new_state.complement;
         compare_and_add(next, new_state, new_sequence);
      }
      
      // Complement, reverse και push.
      State complement_and_reverse_state = state.reverse();
      if (complement_and_reverse_state.canAppend(3-current_val)) {
         string new_sequence = sequence + "crp";
         complement_and_reverse_state.appendRight(3-current_val);
         complement_and_reverse_state.complement = !complement_and_reverse_state.complement;
         compare_and_add(next, complement_and_reverse_state, new_sequence);
      }
    }
    current = next;
    next.clear();
  }
  // Εύρεση λεξικογραφικά μικρότερης ακολουθίας.
  string smallest_seq = "";
  for (const auto& state_and_sequence : current) {
    if (smallest_seq.empty() || is_smaller(state_and_sequence.second, smallest_seq)) {
      smallest_seq = state_and_sequence.second;
    }
  }
  return smallest_seq;
}

int main() {
  long N, T;
  FILE *fi = fopen("pcr.in", "r");
  fscanf(fi, "%ld %ld", &T, &N);
  
  FILE *fo = fopen("pcr.out", "w");
  for (long i = 0; i < T; ++i) {
    vector<int> x;
    for (long j = 0; j < N; ++j) {
      int tmp;
      fscanf(fi, "%d", &tmp);
      x.push_back(tmp);
    }
    fputs(solve(x).c_str(), fo);
    fputs("\n", fo);
  }
  
  return 0;
}

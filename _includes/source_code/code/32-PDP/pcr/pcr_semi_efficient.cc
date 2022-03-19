#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct State {
   vector<int> positions;
   int rightmost;
   int leftmost;
   int count;
   bool is_complemented;
   
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
   
   void append_right(int val) {
      if (positions[val] == 0) {
         ++count;
         positions[val] = count;
         if (count == 1) leftmost = val;
         rightmost = val;
      }
   }
   
   bool can_append(int val) const {
      return rightmost == val || positions[val] == 0;
   }
   
   bool operator<(const State& other) const {
      if (count != other.count) return count < other.count;
      if (rightmost != other.rightmost) return rightmost < other.rightmost;
      if (leftmost != other.leftmost) return leftmost < other.leftmost;
      if (count != other.count) return count < other.count;
      if (is_complemented != other.is_complemented) return is_complemented < other.is_complemented;
      return positions < other.positions;
   }
   
   State() {
      positions.push_back(0); positions.push_back(0); positions.push_back(0); positions.push_back(0);
      leftmost = rightmost = -1;
      count = 0;
      is_complemented = false;
   }
};

void compare_and_add(map<State, tuple<int, long, long> >& next, vector<pair<int, long> >& par, State state, long order_id, long length, long par_id, long operation_id) {
   if (next.find(state) == next.end() || std::get<2>(next[state]) > length) {
      next[state] = make_tuple(order_id, par.size(), length);
      par.push_back({operation_id, par_id});
   }
}

const int CP = 0, P = 1, RP = 2, CRP = 3;

string solve(vector<int>& x) {
  map<State, tuple<int /* order ID */, long /* state ID */, long /* length */> > next;
  vector<pair<int /* operation ID */, long /* ordered ID */> > par;
  set<tuple<int /* order ID */, long /* state ID */, long /* length */, State> > ordered_current;
  // Κατάσταση cp (πρώτη λεξικογραφικά).
  State cp_state; cp_state.append_right(3 - x[0]); cp_state.is_complemented = true;
  ordered_current.insert(make_tuple(0, 0, 2, cp_state));
  par.push_back({par.size(), -1});
  // Κατάσταση p.
  State p_state; p_state.append_right(x[0]);
  ordered_current.insert(make_tuple(1, 1, 1, p_state));
  par.push_back({par.size(), -1});
  // Δεν έχει νόημα να κάνουμε rp στην αρχή.
  
  for (size_t i = 1; i < x.size(); ++i) {
     long order_id = 0;
    for (const auto cur : ordered_current) {
      const State state = std::get<3>(cur);
      int cur_id = std::get<1>(cur);
      int length = std::get<2>(cur);
      int current_val = state.is_complemented ? (3 - x[i]) : x[i];
      
      // Complement και push.
      if (state.can_append(3-current_val)) {
         State new_state = state;
         new_state.append_right(3-current_val);
         new_state.is_complemented = !new_state.is_complemented;
         compare_and_add(next, par, new_state, order_id, length + 2, cur_id, CP);
      }
      
      // Complement, reverse και push.
      State complement_reverse_state = state.reverse();
      complement_reverse_state.is_complemented = !complement_reverse_state.is_complemented;
      if (complement_reverse_state.can_append(3 - current_val)) {
         complement_reverse_state.append_right(3 - current_val);
         compare_and_add(next, par, complement_reverse_state, order_id, length + 3, cur_id, CRP);
      }
      
      // Push.
      if (state.can_append(current_val)) {
         State new_state = state;
         new_state.append_right(current_val);
         compare_and_add(next, par, new_state, order_id, length + 1, cur_id, P);
      }
      
      // Reverse και push.
      State reverse_state = state.reverse();
      if (reverse_state.can_append(current_val)) {
         reverse_state.append_right(current_val);
         compare_and_add(next, par, reverse_state, order_id, length + 2, cur_id, RP);
      }
      
      ++order_id;
    }
    // Λεξικογραφική ταξινόμηση.
    ordered_current.clear();
    for (const auto& val : next) {
       ordered_current.insert(
           make_tuple(std::get<0>(val.second), std::get<1>(val.second), std::get<2>(val.second), val.first));
    }
    next.clear();
  }
  
  string str;
  // Εύρεση κατάστασης με την βέλτιστη ακολουθία.
  long smallest_val = std::get<2>(*ordered_current.begin()), 
       smallest_id = std::get<1>(*ordered_current.begin());
  for (const auto val : ordered_current) {
     if (smallest_val > std::get<2>(val)) {
        smallest_val = std::get<2>(val);
        smallest_id = std::get<1>(val);
     }
  }
  long cur = smallest_id;
  while (cur != -1) {
     long val = par[cur].first;
     if (val == CP) str += "pc";
     else if (val == 1) str += "p";
     else if (val == 2) str += "pr";
     else if (val == 3) str += "prc";
     cur = par[cur].second;
  }
  
  reverse(str.begin(), str.end());
  return str;
}

int main() {
  long N, T;
  FILE *fi = fopen("pcr.in", "r");
  fscanf(fi, "%ld %ld", &T, &N);
  
  FILE *fo = fopen("pcr.out", "w");
  for (long i = 0; i < T; ++i) {
    vector<int> v;
    for (long j = 0; j < N; ++j) {
      int tmp;
      fscanf(fi, "%d", &tmp);
      v.push_back(tmp);
    }
    fputs(solve(v).c_str(), fo);
    fputs("\n", fo);
  }
  
  return 0;
}
    

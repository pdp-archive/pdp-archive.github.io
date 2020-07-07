#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

/* Αναπαριστούμε την κατάσταση ως έναν ακέραιο με την μορφή:

   is_complement (1) | Rightmost (3) | Leftmost (3) | 4x positions (3x4) | count (3)
*/
const unsigned long _111 = 7; // Στην δυαδική αναπαράσταση είναι 111

struct State {
   
   unsigned long state;
   
   /* Επιστρέφει τα τρία bits στην θέση offset. */
   int get_three_bits(int offset) const {
      // 1. Δημιουργούμε ένα ακέραιο _111με μόνο τρία bits.
      // 2. Μετακινούμε αυτά τα bits κατά offset θέσεις.
      // 3. Κάνοντας state & (_111 << offset) μένουν μόνο οι θέσεις 
      //    [offset, offset + 3) του state.
      // 3. Μετακινώντας αριστερά (state & (_111 << offset)) κατά offset
      //    μας μένει ο αριθμός στα τρία αυτά bits.
      return (state & (_111 << offset)) >> offset;
   }
   
   /* Θέτει τα τρία bits στην θέση offset. */
   void set_three_bits(int offset, int val) {
      // 1. Δημιουργούμε έναν ακέραιο ~(_111 << offset) με bit 1 παντού 
      //    εκτός από τις θέσεις [offset, offset + 3).
      // 2. Κάνοντας state & ~(_111 << offset) μένουν όλες οι άλλες θέσεις του state.
      // 3. Μετακινώντας δεξιά την τιμή val, πηγαίνει στην θέση offset.
      // 4. Κάνοντας |= (val << offset) μεταφέρουμε αυτή την τιμή στο state. 
      state &= ~(_111 << offset);
      state |= (val << offset);
   }
   
   int positions(int i) const {
      int offset = 1 + 3 + 3 + 3 * i;
      return get_three_bits(offset);
   }
   
   void set_position(int i, int val) {
      int offset = 1 + 3 + 3 + 3 * i;
      set_three_bits(offset, val);
   }
   
   int rightmost() const { return get_three_bits(1); }
   int leftmost() const { return get_three_bits(1 + 3); }
   bool is_complemented() const { return state & 1; }
   
   void set_rightmost(int val) { set_three_bits(1, val); }
   void set_leftmost(int val) { set_three_bits(1 + 3, val); }
   void flip_complemented() { state ^= 1; }
   
   int count() const {
      int offset = 1 + 3 + 3 + 12;
      return get_three_bits(offset);
   }
   
   void set_count(int val) {
      int offset = 1 + 3 + 3 + 12;
      set_three_bits(offset, val);
   }
   
   State reverse() const {
      State other = *this;
      // Αντιστρέφουμε τις θέσεις των στοιχείων που έχουμε δει.
      int cnt = count();
      for (size_t i = 0; i < 4; ++i) {
         int cur_position = other.positions(i);
         if (cur_position != 0) other.set_position(i, (cnt + 1) - cur_position);
      }
      other.set_leftmost(rightmost());
      other.set_rightmost(leftmost());
      return other;
   }
   
   void append_right(int val) {
      if (positions(val) == 0) {
         int cnt = count();
         ++cnt;
         set_count(cnt);
         set_position(val, cnt);
         if (cnt == 1) set_leftmost(val);
         set_rightmost(val);
      }
   }
   
   bool can_append(int val) const {
      return rightmost() == val || positions(val) == 0;
   }
   
   bool operator<(const State& other) const {
      return state < other.state;
   }
   
   State() {
      state = 0;
      set_leftmost(5);
      set_rightmost(5);
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
  State cp_state; cp_state.append_right(3 -x[0]); cp_state.flip_complemented();
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
      int current_val = state.is_complemented() ? (3 - x[i]) : x[i];
      
      // Complement και push.
      if (state.can_append(3-current_val)) {
         State new_state = state;
         new_state.append_right(3-current_val);
         new_state.flip_complemented();
         compare_and_add(next, par, new_state, order_id, length + 2, cur_id, CP);
      }
      
      // Complement, reverse και push.
      State complement_reverse_state = state.reverse();
      complement_reverse_state.flip_complemented();
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
    

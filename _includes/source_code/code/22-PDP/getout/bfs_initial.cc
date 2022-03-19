#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>

typedef unsigned long long ull;

int N, R;

struct State {
   /* Οι συνεταγμένες των οριζόντιων και κάθετων αυτοκινήτων. */
   std::vector<std::pair<char, char>> hor;
   std::vector<std::pair<char, char>> ver;
   
   bool operator<(const State& other) const {
      for (int i = 0; i < hor.size(); ++i)
         if (hor[i] != other.hor[i]) return hor[i] < other.hor[i];
      for (int i = 0; i < ver.size(); ++i)
         if (ver[i] != other.ver[i]) return ver[i] < other.ver[i];
      return false;
   }
   
   
};

/* Συναρτήσεις για να θέτουμε (και να βρίσκουμε) το i-οστό bit. */
void set(ull& v, char x, char y, ull t) {
   char n = (x * N + y);
   v = (v & ~(1ULL << n)) | (t << n);
}
bool get(ull v, char x, char y) {
   return (v & (1ULL << (x * N + y))) > 0;
}
void setHor(ull& v, std::pair<char, char> pt, ull t) {
   set(v, pt.first, pt.second, t);
   set(v, pt.first, pt.second + 1, t);
}
void setVer(ull& v, std::pair<char, char> pt, ull t) {
   set(v, pt.first, pt.second, t);
   set(v, pt.first + 1, pt.second, t);
}

std::vector<State> getNext(const State& cur) {
   std::vector<State> nxts;
   // Κρατάμε την αναπαράσταση του πίνακα σε έναν ακέραιο με 
   // 64 bit (που χωράει έναν 8x8 πίνακα) για να μπορούμε να ελέγξουμε
   // γρήγορα αν μία θέση είναι άδεια.
   ull not_free = 0;
   for (const auto& h : cur.hor) setHor(not_free, h, true);
   for (const auto& v : cur.ver) setVer(not_free, v, true);
   
   for (int j = 0; j < cur.hor.size(); ++j) {
      auto h = cur.hor[j];
      // Βγάζουμε προσωρινά το αυτοκίνητο από τον πίνακα.
      setHor(not_free, h, false);
      // Δοκιμάζουμε να μετακινήσουμε το αυτοκίνητο προς τα δεξιά.
      for (int i = h.second + 1; i <= N - 2; ++i) {
         if (!get(not_free, h.first, i) && !get(not_free, h.first, i+1)) {
            State nxt = cur;
            nxt.hor[j].second = i;
            nxts.push_back(nxt);
         } else break;
      }
      // Δοκιμάζουμε να μετακινήσουμε το αυτοκίνητο προς τα αριστερά.
      for (int i = h.second - 1; i >= 0; --i) {
         if (!get(not_free, h.first, i) && !get(not_free, h.first, i+1)) {
            State nxt = cur;
            nxt.hor[j].second = i;
            nxts.push_back(nxt);
         } else break;
      }
      // Επαναφέρουμε το αυτοκίνητο στον πίνακα.
      setHor(not_free, h, true);
   }
   
   for (int j = 0; j < cur.ver.size(); ++j) {
      auto v = cur.ver[j];
      // Βγάζουμε προσωρινά το αυτοκίνητο από τον πίνακα.
      setVer(not_free, v, false);
      // Δοκιμάζουμε να μετακινήσουμε το αυτοκίνητο προς τα πάνω.
      for (int i = v.first + 1; i <= N - 2; ++i) {
         if (!get(not_free, i, v.second) && !get(not_free, i+1, v.second)) {
            State nxt = cur;
            nxt.ver[j].first = i;
            nxts.push_back(nxt);
         } else break;
      }
      // Δοκιμάζουμε να μετακινήσουμε το αυτοκίνητο προς τα κάτω.
      for (int i = v.first - 1; i >= 0; --i) {
         if (!get(not_free, i, v.second) && !get(not_free, i+1, v.second)) {
            State nxt = cur;
            nxt.ver[j].first = i;
            nxts.push_back(nxt);
         } else break;
      }
      // Επαναφέρουμε το αυτοκίνητο στον πίνακα.
      setVer(not_free, v, true);
   }
   return nxts;
}

/* Ελέγχουμε αν το δοσμένο state έχει την R-οστή γραμμή κενή. */
bool isTerminal(const State& cur) {
   for (auto pr : cur.ver) {
      if (pr.first == R || pr.first + 1 == R) return false;
   }
   for (auto pr : cur.hor) {
      if (pr.first == R) return false;
   }
   return true;
}

int bfs(const State& init) {
   if (isTerminal(init)) return 0;
   
   std::set<State> visited;
   std::queue<State> states[2];
   states[0].push(init);
   visited.insert(init);
   
   int cur = 0, depth = 0;
   while (!states[cur].empty()) {
      while (!states[cur].empty()) {
         for (auto& nxt : getNext(states[cur].front())) {
            if (isTerminal(nxt)) return depth + 1;
            if (visited.find(nxt) == visited.end()) {
               visited.insert(nxt);
               states[(cur + 1) % 2].push(nxt);
            }
         }
         states[cur].pop();
      }
      cur = (cur + 1) % 2;
      ++depth;
   }
   return -1;
}
               

int main() {
   FILE *fi = fopen("getout.in", "r");
   fscanf(fi, "%d%d", &N, &R); --R;
   State init;
   int cnt, tmp;
   for (int i = 0; i < N; ++i) {
      fscanf(fi, "%d", &cnt);
      for (int j = 0; j < cnt; ++j) {
         fscanf(fi, "%d", &tmp);
         init.hor.push_back({ i, tmp - 1 });
      }
   }
   for (int i = 0; i < N; ++i) {
      fscanf(fi, "%d", &cnt);
      for (int j = 0; j < cnt; ++j) {
         fscanf(fi, "%d", &tmp);
         init.ver.push_back({ tmp - 1, i });
      }
   }
   
   FILE *fo = fopen("getout.out", "w");
   fprintf(fo, "%d\n", bfs(init));
   return 0;
}

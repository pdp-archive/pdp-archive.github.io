#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>

typedef unsigned long long ull;

int N, R;

struct config {
   std::vector<std::pair<char, char>> hor;
   std::vector<std::pair<char, char>> ver;
   
   bool operator<(const config& other) const {
      for (int i = 0; i < hor.size(); ++i)
         if (hor[i] != other.hor[i]) return hor[i] < other.hor[i];
      for (int i = 0; i < ver.size(); ++i)
         if (ver[i] != other.ver[i]) return ver[i] < other.ver[i];
      return false;
   }
};

void set(ull& v, char x, char y, ull t) {
   char n = (x * N + y);
   v = (v & ~(1ULL << n)) | (t << n);
}
void setHor(ull& v, std::pair<char, char> pt, ull t) {
   set(v, pt.first, pt.second, t);
   set(v, pt.first, pt.second + 1, t);
}
void setVer(ull& v, std::pair<char, char> pt, ull t) {
   set(v, pt.first, pt.second, t);
   set(v, pt.first + 1, pt.second, t);
}

bool get(ull v, char x, char y) {
   return (v & (1ULL << (x * N + y))) > 0;
}

std::vector<config> getNext(const config& cur) {
   std::vector<config> nxts;
   ull not_free = 0;
   for (const auto& h : cur.hor) setHor(not_free, h, true);
   for (const auto& v : cur.ver) setVer(not_free, v, true);
   
   for (int j = 0; j < cur.hor.size(); ++j) {
      auto h = cur.hor[j];
      setHor(not_free, h, false);
      // Δοκιμάζουμε να μετακινήσουμε το αυτοκίνητο αριστερά και δεξιά.
      for (int dir : {-1, 1}) {
         for (int i = h.second + dir; 0 <= i && i <= N - 2; i += dir) {
            if (!get(not_free, h.first, i) && !get(not_free, h.first, i+1)) {
               config nxt = cur;
               nxt.hor[j].second = i;
               nxts.push_back(nxt);
            } else break;
         }
      }
      setHor(not_free, h, true);
   }
   
   for (int j = 0; j < cur.ver.size(); ++j) {
      auto v = cur.ver[j];
      setVer(not_free, v, false);
      // Δοκιμάζουμε να μετακινήσουμε το αυτοκίνητο πάνω και κάτω.
      for (int dir : {-1, 1}) {
         for (int i = v.first + dir; 0 <= i && i <= N - 2; i += dir) {
            if (!get(not_free, i, v.second) && !get(not_free, i+1, v.second)) {
               config nxt = cur;
               nxt.ver[j].first = i;
               nxts.push_back(nxt);
            } else break;
         }
      }
      setVer(not_free, v, true);
   }
   return nxts;
}

/* Ελέγχουμε αν το δοσμένο state έχει την R-οστή γραμμή κενή. */
bool isTerminal(const config& cur) {
   for (auto pr : cur.ver) {
      if (pr.first == R || pr.first + 1 == R) return false;
   }
   for (auto pr : cur.hor) {
      if (pr.first == R) return false;
   }
   return true;
}

int bfs(const config& init) {
   if (isTerminal(init)) return 0;
   std::set<config> visited;
   std::queue<config> configs[2];
   configs[0].push(init);
   visited.insert(init);
   int cur = 0, depth = 0;
   while (!configs[cur].empty()) {
      while (!configs[cur].empty()) {
         for (auto& nxt : getNext(configs[cur].front())) {
            if (isTerminal(nxt)) return depth + 1;
            if (visited.find(nxt) == visited.end()) {
               visited.insert(nxt);
               configs[(cur + 1) % 2].push(nxt);
            }
         }
         configs[cur].pop();
      }
      cur = (cur + 1) % 2;
      ++depth;
   }
   return -1;
}
               

int main() {
   FILE *fi = fopen("getout.in", "r");
   fscanf(fi, "%d%d", &N, &R); --R;
   config init;
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

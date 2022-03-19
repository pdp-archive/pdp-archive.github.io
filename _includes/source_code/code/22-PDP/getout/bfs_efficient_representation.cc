#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

typedef unsigned long long ull;

int N, R;

struct State {
   ull mask[2];
   
   State() { mask[0] = mask[1] = 0; }
   
   bool operator<(const State& other) const {
      if (mask[0] != other.mask[0]) return mask[0] < other.mask[0];
      return mask[1] < other.mask[1];
   }
};

bool isHorizontal(std::tuple<char, char, bool> pt) { return std::get<2>(pt); }

void set(ull& v, char x, char y, ull t) {
   char n = (x * N + y);
   v = (v & ~(1ULL << n)) | (t << n);
}
int dx[] = {1, 0}, dy[] = {0, 1};
void set(ull& v, std::tuple<char, char, bool> pt, ull t) {
   bool type = isHorizontal(pt);
   set(v, std::get<0>(pt), std::get<1>(pt), t);
   set(v, std::get<0>(pt) + dx[type], std::get<1>(pt) + dy[type], t);
}

bool get(ull v, std::pair<char, char> pt) {
   return (v & (1ULL << (pt.first * N + pt.second))) > 0;
}

char get_diff_coord(std::tuple<char, char, bool> pt) {
   return isHorizontal(pt) ? std::get<1>(pt) : std::get<0>(pt);
}

std::pair<char, char> get_same_coord(std::tuple<char, char, bool> pt, char y) {
   return isHorizontal(pt) ? std::make_pair(std::get<0>(pt), y) : std::make_pair(y, std::get<1>(pt));
}

std::vector<State> getNext(const State& cur) {
   std::vector<State> nxts;
   ull not_free = 0;
   for (bool is_vertical : {0, 1})
      for (char x = 0; x < N; ++x)
         for (char y = 0; y < N; ++y) {
            if (!get(cur.mask[is_vertical], {x, y})) continue;
            std::tuple<char, char, bool> pt({ x, y, !is_vertical });
            set(not_free, pt, true);
         }
   
   for (bool is_vertical : {0, 1})
      for (char x = 0; x < N; ++x)
         for (char y = 0; y < N; ++y) {
            if (!get(cur.mask[is_vertical], {x, y})) continue;
            std::tuple<char, char, bool> pt({ x, y, !is_vertical });
            set(not_free, pt, false);
            for (int dir : {-1, 1}) {
               for (int i = get_diff_coord(pt) + dir; 0 <= i && i <= N - 2; i += dir) {
                  if (!get(not_free, get_same_coord(pt, i)) && !get(not_free, get_same_coord(pt, i+1))) {
                     State nxt = cur;
                     set(nxt.mask[is_vertical], x, y, false);
                     set(nxt.mask[is_vertical], is_vertical ? i : x, is_vertical ? y : i, true);
                     nxts.push_back(nxt);
                  } else break;
               }
            }
            set(not_free, pt, true);
         }

   return nxts;
}

bool isTerminal(const State& cur) {
   for (char x = 0; x < N; ++x) {
      if (get(cur.mask[true], {R, x})) return false;
      if (R >= 1 && get(cur.mask[true], {R - 1, x})) return false;
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
   for (bool k : {0, 1}) {
      for (int i = 0; i < N; ++i) {
         fscanf(fi, "%d", &cnt);
         for (int j = 0; j < cnt; ++j) {
            fscanf(fi, "%d", &tmp);
            if (!k) set(init.mask[k], i, tmp - 1, true);
            else set(init.mask[k], tmp - 1, i, true);
         }
      }
   }
   
   FILE *fo = fopen("getout.out", "w");
   fprintf(fo, "%d\n", bfs(init));
   return 0;
}

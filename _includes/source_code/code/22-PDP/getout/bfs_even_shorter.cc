#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

typedef unsigned long long ull;

int N, R;

struct State {
   std::vector<std::tuple<char, char, bool>> pts;
   
   bool operator<(const State& other) const {
      for (int i = 0; i < pts.size(); ++i)
         if (pts[i] != other.pts[i]) return pts[i] < other.pts[i];
      return false;
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
   for (const auto& pt : cur.pts) set(not_free, pt, true);
   
   for (int j = 0; j < cur.pts.size(); ++j) {
      auto pt = cur.pts[j];
      set(not_free, pt, false);
      for (int dir : {-1, 1}) {
         for (int i = get_diff_coord(pt) + dir; 0 <= i && i <= N - 2; i += dir) {
            if (!get(not_free, get_same_coord(pt, i)) && !get(not_free, get_same_coord(pt, i+1))) {
               State nxt = cur;
               if (isHorizontal(pt)) std::get<1>(nxt.pts[j]) = i;
               else std::get<0>(nxt.pts[j]) = i;
               nxts.push_back(nxt);
            } else break;
         }
      }
      set(not_free, pt, true);
   }

   return nxts;
}

bool isTerminal(const State& cur) {
   for (auto pt : cur.pts) {
      if (!isHorizontal(pt) && (std::get<0>(pt) == R || std::get<0>(pt) + 1 == R)) return false;
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
            if (!k) init.pts.push_back({ i, tmp - 1, true });
            else init.pts.push_back({ tmp - 1, i, false });
         }
      }
   }
   
   FILE *fo = fopen("getout.out", "w");
   fprintf(fo, "%d\n", bfs(init));
   return 0;
}

#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>

const int MAXN = 1'000;

// +2 γιατί βάζουμε το ψεύτικο περίγραμμα από @.
char grid[MAXN+2][MAXN+2];
bool visited[MAXN+2][MAXN+2]; 

std::vector<std::pair<int, int>> ds({ {0, 1}, {1, 0}, {-1, 0}, {0, -1} });

int dfs(int x0, int y0) {
   std::stack<std::pair<int, int>> st;
   st.push({ x0, y0 });
   visited[x0][y0] = true;
   int total = 0;
   while(!st.empty()) {
      auto [x,y] = st.top();
      st.pop();
      ++total;
      for (auto [dx, dy] : ds) {
         if (!visited[x+dx][y+dy] && grid[x+dx][y+dy] != '@') {
            visited[x+dx][y+dy] = true;
            st.push({ x+dx, y+dy });
         }
      }
   }
   return total;
}

int main() {
   FILE *fi = fopen("fire.in", "r");
   int N, M, Nf, Mf;
   fscanf(fi, "%d %d\n", &N, &M);
   fscanf(fi, "%d %d\n", &Nf, &Mf);
   for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
         fscanf(fi, "%c", &grid[i][j]);
      }
      fscanf(fi, "\n");
   }
   fclose(fi);
   
   // Δημιουργούμε το ψεύτικο περίγραμμα.
   for (int i = 0; i <= M + 1; ++i) grid[i][0] = grid[i][N+1] = '@';
   for (int i = 0; i <= N + 1; ++i) grid[0][i] = grid[M+1][i] = '@';
   
   FILE *fo = fopen("fire.out", "w");
   fprintf(fo, "%ld\n", dfs(Mf, Nf));
   fclose(fo);
   
   return 0;
}

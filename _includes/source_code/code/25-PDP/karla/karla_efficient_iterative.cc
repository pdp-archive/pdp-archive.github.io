#include <algorithm>
#include <stdio.h>
#include <stack>

const size_t MAXN = 100;

int values[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N, M;

bool isWithinBounds(int i, int j) {
   return i >= 0 && j >= 0 && i < N && j < N;
}

void dfsIteratively(int begin_i, int begin_j) {
   std::stack<std::pair<int, int>> st;
   st.push(std::make_pair(begin_i, begin_j));
   
   while (!st.empty()) {
      int i = st.top().first;
      int j = st.top().second;
      st.pop();
      
      if (isWithinBounds(i+1, j) && !visited[i+1][j] && values[i+1][j] > M) {
         visited[i+1][j] = true;
         st.push(std::make_pair(i+1, j));
      }
      if (isWithinBounds(i-1, j) && !visited[i-1][j] && values[i-1][j] > M) {
         visited[i-1][j] = true;
         st.push(std::make_pair(i-1, j));
      }
      if (isWithinBounds(i, j+1) && !visited[i][j+1] && values[i][j+1] > M) {
         visited[i][j+1] = true;
         st.push(std::make_pair(i, j+1));
      }
      if (isWithinBounds(i, j-1) && !visited[i][j-1] && values[i][j-1] > M) {
         visited[i][j-1] = true;
         st.push(std::make_pair(i, j-1));
      }
   }
}

int main() {
   FILE *fi = fopen("karla.in", "r");
   fscanf(fi, "%d%d", &N, &M);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         fscanf(fi, "%d", &values[i][j]);
      }
   }
   fclose(fi);
   
   int total = 0;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         if (!visited[i][j] && values[i][j] > M) {
            dfsIteratively(i, j);
            ++total;
         }
      }
   }
   
   FILE *fo = fopen("karla.out", "w");
   fprintf(fo, "%d\n", total);
   fclose(fo);
   
   return 0;
}
   

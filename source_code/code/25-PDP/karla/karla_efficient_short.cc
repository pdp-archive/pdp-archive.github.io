#include <algorithm>
#include <stdio.h>
#include <vector>

const size_t MAXN = 100;

int values[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N, M;

bool isWithinBounds(int i, int j) {
   return i >= 0 && j >= 0 && i < N && j < N;
}

std::vector<std::pair<int, int>> deltas({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

void visitAndMark(int i, int j) {
   visited[i][j] = true;
   for (const auto& delta : deltas) {
      int ii = i + delta.first;
      int jj = j + delta.second;
      if (isWithinBounds(ii, jj) && !visited[ii][jj] && values[ii][jj] > M) {
         visitAndMark(ii, jj);
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
            visitAndMark(i, j);
            ++total;
         }
      }
   }
   
   FILE *fo = fopen("karla.out", "w");
   fprintf(fo, "%d\n", total);
   fclose(fo);
   
   return 0;
}
   

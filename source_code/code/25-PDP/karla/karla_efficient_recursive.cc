#include <stdio.h>

const size_t MAXN = 100;

int values[MAXN][MAXN];
bool visited[MAXN][MAXN];

int N, M;

bool isWithinBounds(int i, int j) {
   return i >= 0 && j >= 0 && i < N && j < N;
}

void visitAndMark(int i, int j) {
   visited[i][j] = true;
   if (isWithinBounds(i+1, j) && !visited[i+1][j] && values[i+1][j] > M) {
      visitAndMark(i+1, j);
   }
   if (isWithinBounds(i-1, j) && !visited[i-1][j] && values[i-1][j] > M) {
      visitAndMark(i-1, j);
   }
   if (isWithinBounds(i, j+1) && !visited[i][j+1] && values[i][j+1] > M) {
      visitAndMark(i, j+1);
   }
   if (isWithinBounds(i, j-1) && !visited[i][j-1] && values[i][j-1] > M) {
      visitAndMark(i, j-1);
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
   

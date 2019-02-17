#include <algorithm>
#include <cstdio> 
#include <cstdlib>

const size_t MAXN = 1000;

int T[MAXN][MAXN];
int max_path[MAXN][MAXN];
int N;

int main() { 
   FILE *fi = fopen("triangle.in", "r");
   fscanf(fi, "%d", &N);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
         fscanf(fi, "%d", &T[i][j]);
      }
   }
   fclose(fi);
   
   max_path[0][0] = T[0][0];
   for (int i = 1; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
         max_path[i][j] = T[i][j];
         if (j == 0) max_path[i][j] += max_path[i - 1][j];
         else max_path[i][j] += std::max(max_path[i - 1][j - 1], max_path[i - 1][j]);
      }
   }
   
   int max_path_to_bottom = max_path[N-1][0];
   for (int i = 0; i < N; ++i) {
      max_path_to_bottom = std::max(max_path[N-1][i], max_path_to_bottom);
   }

   FILE *fo = fopen("triangle.out", "w");
   fprintf(fo, "%d\n", max_path_to_bottom);
   fclose(fo);
   return 0;
}

#include <algorithm>
#include <cstdio> 
#include <cstdlib>

const size_t MAXN = 1000;

int T[2][MAXN];
int max_path[2][MAXN];
int N;

int main() { 
   FILE *fi = fopen("triangle.in", "r");
   fscanf(fi, "%d", &N);
   max_path[0][0] = 0;
   for (int i = 0; i < N; ++i) {
      int cur_row = (i + 1) % 2;
	  int prev_row = i % 2;
      for (int j = 0; j <= i; ++j) {
         fscanf(fi, "%d", &T[cur_row][j]);
      }
	  for (int j = 0; j <= i; ++j) {
         max_path[cur_row][j] = T[cur_row][j];
         if (j == 0) max_path[cur_row][j] += max_path[prev_row][j];
         else max_path[cur_row][j] += std::max(max_path[prev_row][j - 1], max_path[prev_row][j]);
      }
   }
   fclose(fi);
   
   int last_row = N % 2;
   int max_path_to_bottom = max_path[last_row][0];
   for (int i = 0; i < N; ++i) {
      max_path_to_bottom = std::max(max_path[last_row][i], max_path_to_bottom);
   }

   FILE *fo = fopen("triangle.out", "w");
   fprintf(fo, "%d\n", max_path_to_bottom);
   fclose(fo);
   return 0;
}

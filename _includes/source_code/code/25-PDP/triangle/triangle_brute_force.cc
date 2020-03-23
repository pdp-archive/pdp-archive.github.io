#include <algorithm>
#include <cstdio> 
#include <cstdlib>

const size_t MAXN = 1000;

int T[MAXN][MAXN];
int N;

int findMaxPath(int i, int j) {
   if (i == N) return 0; 
   if (j == N - 1) return T[i][j] + findMaxPath(i + 1, j);
   return T[i][j] + std::max(findMaxPath(i + 1, j), findMaxPath(i + 1, j + 1));
}

int main() { 
   FILE *fi = fopen("triangle.in", "r");
   fscanf(fi, "%d", &N);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
         fscanf(fi, "%d", &T[i][j]);
      }
   }
   fclose(fi);
   
   FILE *fo = fopen("triangle.out", "w");
   fprintf(fo, "%d\n", findMaxPath(0, 0));
   fclose(fo);
   return 0;
}

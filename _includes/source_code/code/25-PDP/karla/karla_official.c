#include <stdio.h>
#define MAX_DIM 101

//Variable Declerations
int table[MAX_DIM + 1][MAX_DIM + 1];
short visited[MAX_DIM + 1][MAX_DIM + 1];
int N, M, K;
int flood(int a, int b) {
   //Out of bounds check
   if( a == 0 || a > N || b == 0 || b > N || visited[a][b] == 1 || table[a][b] <= M)
      return 0;
   visited[a][b] = 1;
   flood(a + 1, b);
   flood(a - 1, b);
   flood(a, b + 1);
   flood(a, b - 1);
   return 1;
}

int main(void) {
   FILE *in = fopen("karla.in", "rt"), *out = fopen("karla.out", "wt");
   //Input proceudure
   fscanf(in, "%d%d", &N, &M);
   int i , j;
   for(i = 1; i <= N; i++) {
      for(j = 1; j <= N; j++)
         fscanf(in, "%d", &table[i][j]);
   }
   //Processing
   for(i = 1; i <= N; i++) {
      for(j = 1; j <= N; j++) {
         if(flood(i, j) == 1)
            K++;
      }
   }
   fprintf(out, "%d\n", K);
   return 0;
}

#include <stdio.h>

#define MAXN 1000000

int Y[2][2*MAXN+1];
int N;

int main ()
{
  int max, i, a, par;
  FILE *f;

  f = fopen("oddeven.in", "rt");
  fscanf(f, "%d\n", &N);
  
  for (i=-N; i<=N; i++) Y[0][N+i]=-1;

  par=0;
  Y[0][N+0] = Y[1][N+0] = 0;
  for (i=1; i<=N; i++) {
    fscanf(f, "%d", &a);
    if (a%2!=0) par++; else par--;
    if (Y[0][N+par] == -1) Y[0][N+par] = i; else Y[1][N+par] = i;
  }
  fclose(f);

  max = 0;
  for (i=-N; i<=N; i++)
    if (Y[0][N+i] >= 0 && Y[1][N+i]-Y[0][N+i] > max)
      max = Y[1][N+i]-Y[0][N+i];
  
  f = fopen("oddeven.out", "wt");
  fprintf(f, "%d\n", max);
  fclose(f);

  return 0;
}

/* Ουρουελίδης Ευστάθιος (2ο ΓΕΛ Πολίχνης) */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int i, N, M, V, Vr, a, b, tmp2;
  double tmp, Va;
  FILE *fin = fopen("hydrologis.in", "r");

  fscanf(fin, "%d %d %d %d %d", &N, &M, &Vr, &a, &b);
  fclose(fin);

  tmp = 1;
  for (i=1;i<=N;i++)
    tmp = ((tmp*1000000) * i)/1000000;
  tmp2 = 0;
  for (i=1;i<=M;i++)
    tmp2 += i;
  Va = Vr + (a * (tmp/1000000)) - (b * tmp2);
  V = (int)(Va+0.5);

  FILE *fout = fopen("hydrologis.out", "w");
  fprintf(fout, "%d\n", V);
  fclose(fout);return 0;
}


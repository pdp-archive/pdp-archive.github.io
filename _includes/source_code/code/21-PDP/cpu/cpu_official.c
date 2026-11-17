/* Αρσένης Γεράσιμος (2ο ΓΕΛ Μοσχάτου) */

#include <stdio.h>

#define MAX 50005

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}

struct vert {
  int x, y;
};

int diff_side(int a, int b, int c, int d) {
  if (d<b && d>a && (c>b || c<a)) return 1;
  if (c<b && c>a && (d>b || d<a)) return 1;
  return 0;
}

int main() {
  FILE *fin=fopen("cpu.in", "r"), *fout=fopen("cpu.out", "w");
  int n, m, x, y, i, j, type[MAX], t1, t2;
  struct vert cpu[MAX];

  fscanf(fin, "%d %d", &n, &m);
  for (i=1; i<=m; i++) {
    fscanf(fin, "%d %d", &x, &y);
    if (x>y) swap(&x, &y);
    cpu[i].x = x;
    cpu[i].y = y;
    t1=t2=0;
    for (j=1; j<i; j++)
      if (diff_side(x, y, cpu[j].x, cpu[j].y)) { 
        if (type[j]==1) { t1++; } else { t2++; } 
      }
    //printf("%d\n", cnt);
    if (t1 && t2) { fprintf(fout, "%d\n", i-1); return 0; }
    if (t1) type[i] = 2;
    else type[i] = 1;
  }
  //printf("diff: %d\n", diff_side(1, 4, 3, 6));
  fprintf(fout, "%d\n", m);
  return 0;
}


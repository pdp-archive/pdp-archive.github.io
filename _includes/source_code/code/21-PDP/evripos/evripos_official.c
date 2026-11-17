/* Αρσένης Γεράσιμος (2ο ΓΕΛ Μοσχάτου) */
#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

#define MAX 205

typedef struct {
  int x, y;
} coords;

coords point[MAX];
double a[MAX][MAX];
int n;

double dist(int i, int j) { 
  return sqrt( (point[i].xpoint[j].x)*(point[i].x-point[j].x) 
             + (point[i].ypoint[j].y)*(point[i].y-point[j].y) ); 
}

int cmp(const coords *i, const coords *j) { return i->x - j->x; }

int main() {
  FILE *fin=fopen("evripos.in", "r"), *fout=fopen("evripos.out","w");
  int i, j, k, x, y;
  double min, tmp;

  fscanf(fin, "%d", &n);
  n+=2;
  point[1].x = point[1].y = 0;
  for (i=2; i<=n; i++) {
    fscanf(fin, "%d %d", &x, &y);
    point[i].x=x;
    point[i].y=y;
  }

  qsort(point+1, n, sizeof(coords), cmp);

  a[1][2] = dist(1, 2);

  for (j=2; j<=n; j++)
    for (i=1; i<=j-1; i++) {
      if (i==1 && j==2) a[i][j] = dist(i, j);
      else if (i<j-1)
        a[i][j] = a[i][j-1] + dist(j, j-1);
      else {
        a[i][j] = a[1][i] + dist(1, j);
        for (k=2; k<=i-1; k++) {
          tmp = a[k][i]+dist(k, j);
          if (tmp < a[i][j]) a[i][j] = tmp;
        }
      }
    }

  min = a[n-1][n] + dist(n-1, n);
  fprintf(fout, "%d\n", (int)round(min));
  return 0;
}


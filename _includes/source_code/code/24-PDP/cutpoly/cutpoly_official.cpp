#include <stdio.h>
#define MAX 1000001

double x[MAX], y[MAX], back[MAX];

int main()
{
#ifdef CONTEST
  freopen("cutpoly.in", "rt", stdin);
  freopen("cutpoly.out", "wt", stdout);
#endif

  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%lf %lf", &x[i], &y[i]);
  int offset = y[0];

  for (int i=0; i<n; i++)
    y[i] -= offset;
  offset = y[n-1];
  for (int i=0; i<n; i++)
    back[i] = offset - y[i];

  double y_sol = (y[0] + y[n-1]) / 2;
  int l=0;
  while (y[l] < y_sol) l++;

  double lambda = (y[l] - y[l-1]) / (x[l] - x[l-1]);
  double x_sol = (y_sol - y[l]) / lambda + x[l];

  double sum = 0;
  int i;
  for (i=1; x[i] < x_sol; i++)
    sum += (x[i] - x[i-1]) * (y[i] + y[i-1]) / 2;

  sum += (x_sol - x[i-1]) * (y_sol + y[i-1]) / 2;
  sum += (x[i] - x_sol) * (offset - y_sol + back[i]) / 2;

  for (i++; i<n; i++)
    sum += (x[i] - x[i-1]) * (back[i] + back[i-1]) / 2;
  printf("%0.6lf\n", sum);
  return 0;
}

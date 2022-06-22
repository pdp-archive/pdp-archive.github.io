/* NAME: KONSTANDINOS KANELIS
 * TASK: PULSARS
 * LANG: C++
 */
#include <stdio.h>
#include <algorithm>
#define MAXN 1000010
using namespace std;
struct pt
{
  int x, y, id;
  bool operator<(const pt &a) const
  {
    return (x < a.x) || (x == a.x && y < a.y);
  }
};
pt P[MAXN], C[2 * MAXN];
int N, M = 0;

int CCW(pt a, pt b, pt c)
{
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool cmp(pt a, pt b)
{
  return a.id < b.id;
}
int main()
{
  FILE *fin = fopen("pulsars.in", "r");
  FILE *fout = fopen("pulsars.out", "w");
  int i, t;

  fscanf(fin, "%d", &N);
  for (i = 0; i < N; i++)
  {
    fscanf(fin, "%d %d", &P[i].x, &P[i].y);
    P[i].id = i + 1;
  }
  sort(P, P + N);
  for (i = 0; i < N; i++)
  {
    while (M >= 2 && CCW(C[M - 2], C[M - 1], P[i]) <= 0)
      M--;
    C[M++] = P[i];
  }
  for (i = N - 2, t = M + 1; i >= 0; i--)
  {
    while (M >= t && CCW(C[M - 2], C[M - 1], P[i]) <= 0)
      M--;
    C[M++] = P[i];
  }
  M--;
  sort(C, C + M, cmp);
  fprintf(fout, "%d\n", M);
  for (i = 0; i < M; i++)
  {
    fprintf(fout, "%d\n", C[i].id);
  }
  fclose(fout);
  return 0;
}

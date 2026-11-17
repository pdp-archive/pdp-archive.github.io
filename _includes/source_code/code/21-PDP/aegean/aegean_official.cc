/* Μπιτζές Γεώργιος (1ο ΓΕΛ Κερατσινίου) */

#include <stdio.h>
#include <map>

using namespace std;

map<int, int> horiz;
map<int, int> vert;

int D = 0;
int horCount = 0;
int vertCount = 0;
int horizontals[200000];
int verticals[200000];
int N;

int process(int x, int y)
{
  if(x > D) D = x;
  if(y > D) D = y;
  if(horiz[x] == 0) { horizontals[++horCount] = x; horiz[x] = y; }
  if(vert[y] == 0) { verticals[++vertCount] = y; vert[y] = x; }
  if(horiz[x] > y) horiz[x] = y;
  if(vert[y] > x) vert[y] = x;
}

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

int readFile(void)
{
  FILE *in = fopen("aegean.in", "r");
  fscanf(in, "%d", &N);
  int i, x, y;
  for(i = 1; i <= N; i++)
  {
    fscanf(in, "%d %d", &x, &y);
    process(x, y);
  }
}

int output(void)
{
  FILE *out = fopen("aegean.out", "w");
  fprintf(out, "%d\n", D);
  fprintf(out, "%d %d\n", horCount, vertCount);
  qsort(horizontals+1, horCount, sizeof(int), compare);
  qsort(verticals+1, vertCount, sizeof(int), compare);
  int i;
  for(i = 1; i <= horCount; i++)
    fprintf(out, "%d %d\n", horizontals[i], D+1 - horiz[horizontals[i]]);
  for(i = 1; i <= vertCount; i++)
    fprintf(out, "%d %d\n", verticals[i], D+1 - vert[verticals[i]]);
  fclose(out);
}

int main(void)
{
  readFile();
  output();
  return 0;
}


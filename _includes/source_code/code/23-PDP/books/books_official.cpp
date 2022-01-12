#include<stdio.h>

using namespace std;

int N, K;
int books[100000];

int check (int m)
{
  int i, k, s=0;
	
  for (i=0; i<N; i++) if (books[i] > m) return 0;

  k = 1;
  for (i=0; i<N; i++) {
    s += books[i];
    if (s > m) {
      k++;
      s = books[i];
    }
  }
  return k <= K;
}

int main ()
{
  FILE *f;
  int i, sum=0, st, md, en;

  f = fopen("books.in", "rt");
  fscanf(f, "%d %d", &N, &K);
  for (i=0; i<N; i++) {
    fscanf(f, "%d", &books[i]);
    sum += books[i];
  }
  fclose(f);

  st = 0;
  en = sum;
  while (st < en) {
    md = (st+en)/2;
    if (check(md)) en = md; else st = md+1;
  }

  f = fopen("books.out", "wt");
  fprintf(f, "%d\n", en);
  fclose(f);

  return 0;
}

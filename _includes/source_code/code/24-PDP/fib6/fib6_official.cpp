#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

using namespace std;

int main ()
{
#ifdef CONTEST
  freopen("fib6.in", "rt", stdin);
  freopen("fib6.out", "wt", stdout);
#endif
  // input
  int X;
  scanf("%d", &X);
  // calculate fib up to X
  int f[50];
  int k = 0;
  int p = 1;
  f[0] = 1;
  while (f[k] + p <= X) {
    f[k+1] = f[k] + p;
    p = f[k];
    k++;
  }
  // greedy algorithm for calculating the answer
  int c[50];
  int count = 0;
  while (X > 0) {
    X -= f[k];
    c[count++] = f[k];
    while (k > 0 && f[k] > X)
      k--;
  }
  // answer
  if (count <= 6) {
    printf("%d", count);
    for (int i=0; i<count; i++)
      printf(" %d", c[i]);
    printf("\n");
  }
  else
    printf("impossible\n");
  return 0;
}

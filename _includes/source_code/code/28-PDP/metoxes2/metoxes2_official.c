#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int xxx (int n, int x[])
{
  int q = 0, p = 0, best = 0;
  int i;

  for (i=n-1; i>=0; i--) {
    q -= x[i];
    if (q < 0) q = 0;
    p += x[i];
    if (q == 0 && p > best) best = p;
  }
  return best;
}


#define MAX 1000000

int n;
int x[MAX];

int main ()
{
#ifdef CONTEST  
  freopen("metoxes2.in", "rt", stdin);  
  freopen("metoxes2.out", "wt", stdout);  
#endif  
  int i;
  scanf("%d\n", &n);
  for (i=0; i<n; i++) scanf("%d", &(x[i]));
  printf("%d\n", xxx(n, x));
  return 0;
}

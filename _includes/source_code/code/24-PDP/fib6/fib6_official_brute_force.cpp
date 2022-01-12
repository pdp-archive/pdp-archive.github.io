#define DEBUG

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
  int k = 1;
  int p = 1;
  f[0] = 0;
  f[1] = 1;
  while (f[k] + p <= X) {
    f[k+1] = f[k] + p;
    p = f[k];
    k++;
  }
  // brute-force
  for (int i1=0; i1<=k; i1++)
    for (int i2=i1; i2<=k; i2++)
      for (int i3=i2; i3<=k; i3++)
        for (int i4=i3; i4<=k; i4++)
          for (int i5=i4; i5<=k; i5++)
            for (int i6=i5; i6<=k; i6++)
              if (f[i1]+f[i2]+f[i3]+f[i4]+f[i5]+f[i6] == X) {
                if (f[i1] > 0) {
                  printf("6 %d %d %d %d %d %d\n", f[i6], f[i5], f[i4], f[i3], f[i2], f[i1]);
                  return 0;
                }
                if (f[i2] > 0) {
                  printf("5 %d %d %d %d %d\n", f[i6], f[i5], f[i4], f[i3], f[i2]);
                  return 0;
                }
                if (f[i3] > 0) {
                  printf("4 %d %d %d %d\n", f[i6], f[i5], f[i4], f[i3]);
                  return 0;
                }
                if (f[i4] > 0) {
                  printf("3 %d %d %d\n", f[i6], f[i5], f[i4]);
                  return 0;
                }
                if (f[i5] > 0) {
                  printf("2 %d %d\n", f[i6], f[i5]);
                  return 0;
                }
                printf("1 %d\n", f[i6]);
                return 0;
              }
  printf("impossible\n");
  return 0;
}

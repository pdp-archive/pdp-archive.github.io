#include <cstdio>
#include <cmath>
#include <cassert>

#undef NDEBUG

using namespace std;

#define MAXRT 1000
int cub[MAXRT+1];

int main ()
{
#ifdef CONTEST  
    freopen("sumofcubes.in", "rt", stdin);  
    freopen("sumofcubes.out", "wt", stdout);  
#endif

  for (int i=0; i<=MAXRT; i++)
    cub[i] = i*i*i;
  int T;
  scanf("%d", &T);
  for (int t=0; t<T; t++) {
    int N;
    scanf("%d", &N);
    int count = 0;
    for (int a=0; 3*cub[a]<=N; a++) {
      int c = MAXRT;
      for (int b=a; cub[a]+2*cub[b]<=N; b++) {
        while (cub[a] + cub[b] + cub[c] > N)
          c--;
        if (cub[a] + cub[b] + cub[c] == N)
          count++;
      }
    }
    printf("%d\n", count);
  }
  return 0;
}

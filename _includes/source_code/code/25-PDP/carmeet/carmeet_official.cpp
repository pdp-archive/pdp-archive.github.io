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
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAX_K 10000

int main ()
{
#ifdef CONTEST
  freopen("carmeet.in", "rt", stdin);
  freopen("carmeet.out", "wt", stdout);
#endif

  int N, K;
  int dist[MAX_K];
  int i, c, m, a, d, cycl, cost;

  scanf("%d %d\n", &N, &K);
  for (i=0; i<K; i++) {
    scanf("%d\n", &d);
    dist[i] = d > 0 ? N - d : 0;
  }

  sort(dist, dist+K);

  int min = N * K;
  int chn = -1;

  for (m=0; m<N; m++) {
    debug("Reaching level m=%d\n", m);
    a = d = 0;
    for (i=0; i<K; i++) {
      d = dist[i] > a + 1 ? dist[i] - a - 1 : 0;
      a += dist[i];
    }
    debug("=> a = %d\td = %d\t", a, d);
    assert(d < N);
    if (d == 0)
      cycl = 0;
    else if (a >= N - 1)
      cycl = 1;
    else
      cycl = 2;
    cost = a + cycl * N;
    debug("cycl = %d\t=> cost = %d", cycl, cost);
    if (cost < min) {
      debug(", minimum\n");
      min = cost;
      chn = m;
    }
    else
      debug("\n");

    for (i=K-1, c=0; i>=0; i--)
      if (dist[i] == N-1)
        c++;
      else
        break;
    for (i=K-1; i>=c; i--)
      dist[i] = dist[i-c] + 1;
    for (i=0; i<c; i++)
      dist[i] = 0;
  }

  printf("%d %d\n", min, chn);
  return 0;
}

#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cell { int x, y, dist; };

bool operator < (const cell &a, const cell &b)
{
  return a.dist > b.dist;
}

#define INF INT_MAX

int main ()
{
#ifdef CONTEST
  freopen("knight.in", "rt", stdin);
  freopen("knight.out", "wt", stdout);
#endif

  int N, M;
  scanf("%d %d", &N, &M);

  int d[N][M];
  priority_queue<cell> S;

  for (int i=0; i<N; i++)
    for (int j=0; j<M; j++)
      d[i][j] = INF;

  S.push((cell) {0, 0, 0});
  while (!S.empty()) {
    cell c = S.top();
    S.pop();
    if (c.dist < d[c.x][c.y]) {
      d[c.x][c.y] = c.dist;

#define CONSIDER(x, y, dist) do {                                       \
        if ((x) >= 0 && (x) < N && (y) >= 0 && (y) < M &&               \
            dist < d[x][y])                                             \
          S.push((cell) {x, y, dist});                                  \
      } while(0)

      CONSIDER(c.x+2, c.y+1, c.dist + 1);
      CONSIDER(c.x+2, c.y-1, c.dist + 1);
      CONSIDER(c.x+1, c.y+2, c.dist + 1);
      CONSIDER(c.x+1, c.y-2, c.dist + 1);
      CONSIDER(c.x-2, c.y+1, c.dist + 1);
      CONSIDER(c.x-2, c.y-1, c.dist + 1);
      CONSIDER(c.x-1, c.y+2, c.dist + 1);
      CONSIDER(c.x-1, c.y-2, c.dist + 1);
    }
  }
  printf("%d\n", d[N-1][M-1]);
  return 0;
}

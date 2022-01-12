#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <queue>

using namespace std;

struct point {
  int i, j, cost;
  point (int ii, int jj, int cc) { i = ii; j = jj; cost = cc; }
};

bool operator < (const point &a, const point &b)
{
  return a.cost > b.cost;
}

enum state { WHITE=0, GRAY=1, BLACK=2 };

#define MAX 500
int N, Ti, Tj, Gi, Gj;
state visited[MAX][MAX];

void consider(priority_queue<point> &q, int i, int j, int cost)
{
  if (visited[i][j] == BLACK)
    return;
  debug("  considering going to (%d, %d) at cost %d\n", i, j, cost);
  q.push(point(i, j, cost));
  visited[i][j] = GRAY;
}

int main ()
{
#ifdef CONTEST
  freopen("golfo.in", "rt", stdin);
  freopen("golfo.out", "wt", stdout);
#endif
  // input
  scanf("%d\n", &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      char c;
      scanf("%c", &c);
      visited[i][j] = (c == 'X' ? BLACK : WHITE);
      switch (c) {
      case 'T': Ti = i; Tj = j; break;
      case 'G': Gi = i; Gj = j; break;
      }
    }
    scanf("\n");
  }
  // calculate
  priority_queue<point> q;
  q.push(point(Ti, Tj, 0));
  visited[Ti][Tj] = GRAY;
  int result = -1;
  while (!q.empty()) {
    point curr = q.top();
    q.pop();
    if (visited[curr.i][curr.j] == BLACK)
      continue;
    visited[curr.i][curr.j] = BLACK;
    debug("at (%d, %d) with cost %0d\n", curr.i, curr.j, curr.cost);
    if (curr.i == Gi && curr.j == Gj) {
      result = curr.cost;
      break;
    }
    consider(q, curr.i+1, curr.j, curr.cost+0);
    consider(q, curr.i-1, curr.j, curr.cost+2);
    consider(q, curr.i, curr.j+1, curr.cost+1);
    consider(q, curr.i, curr.j-1, curr.cost+1);
  }
  // output
  if (result >= 0)
    printf("%d\n", result);
  else
    printf("IMPOSSIBLE\n");
  return 0;
}

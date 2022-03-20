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
#include <set>

using namespace std;

enum state { WHITE=0, BLACK=1, GRAY=2 };

int main ()
{
#ifdef CONTEST
  freopen("shades.in", "rt", stdin);
  freopen("shades.out", "wt", stdout);
#endif
  // input
  int N, M;
  scanf("%d %d", &N, &M);
  state st[N+1];
  for (int i=1; i<=N; i++) {
    int s;
    scanf("%d", &s);
    st[i] = (state) s;
  }
  set<int> fwd[N+1], rev[N+1];
  for (int i=0; i<M; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    fwd[u].insert(v);
    rev[v].insert(u);
  }
  debug("finished reading!\n");
  // solve
  bool fromWhite[N+1], toBlack[N+1];
  for (int i=1; i<=N; i++)
    fromWhite[i] = toBlack[i] = false;
  queue<int> q;
  for (int i=1; i<=N; i++) {
    debug("starting from %d\n", i);
    switch (st[i]) {
    case WHITE:
      // traverse from i forward and update "fromWhite"
      debug("  is WHITE\n");
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (fromWhite[u])
          continue;
        debug("  considering %d\n", u);
        fromWhite[u] = true;
        for (set<int>::iterator i=fwd[u].begin(); i!=fwd[u].end(); i++)
          if (st[*i] != BLACK && !fromWhite[*i])
            q.push(*i);
          else
            fromWhite[*i] = true;
      }
      break;
    case BLACK:
      // traverse from i backward and update "toBlack"
      debug("  is BLACK\n");
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        debug("  considering %d\n", u);
        toBlack[u] = true;
        for (set<int>::iterator i=rev[u].begin(); i!=rev[u].end(); i++)
          if (st[*i] != BLACK && !toBlack[*i])
            q.push(*i);
      }
      break;
    }
  }
  // print: whatever is both "fromWhite" and "toBlack"
  for (int i=1; i<=N; i++)
    printf("%d%s", (fromWhite[i] && toBlack[i] ? 1 : 0), (i==N ? "\n" : " "));
  return 0;
}

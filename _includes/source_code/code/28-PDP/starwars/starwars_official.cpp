#include <cstdio>
#include <algorithm>

using namespace std;

int X, Y, Z, Q;

struct node {
  int cnt;
  bool lazy;
  int L, R;
  node *l, *r;

  void init () {
    cnt = lazy = 0;
    if (L != R) {
      int M = (L+R)/2;
      if (l == NULL) l = new node, l->l = l->r = 0;
      l->L = L;
      l->R = M;
      l->init();
      if (r == NULL) r = new node, r->l = r->r = 0;
      r->L = M+1;
      r->R = R;
      r->init();
    }
  }

  int query (int i, int j) {
    if (i <= L && j >= R) return cnt;
    int M = (L+R)/2;
    if (lazy) {
      lazy = 0;
      l->update(L,M);
      r->update(M+1,R);
    }
    int ret = 0;
    if (i <= M) ret += l->query(i,min(j,M));
    if (j > M) ret += r->query(max(i,M+1),j);
    return ret;
  }

  void update (int i, int j) {
    if (i <= L && j >= R) {
      lazy = 1 - lazy;
      cnt = R - L + 1 - cnt;
      return;
    }
    int M = (L+R)/2;
    if (lazy) {
      lazy = 0;
      l->update(L,M);
      r->update(M+1,R);
    }
    if (i <= M) l->update(i,min(j,M));
    if (j > M) r->update(max(i,M+1),j);
    cnt = l->cnt + r->cnt;
  }
};

int main () {
#ifdef CONTEST
  freopen("starwars.in", "rt", stdin);
  freopen("starwars.out", "wt", stdout);
#endif

  int TS;
  scanf("%d", &TS);
  node *T[3];
  for (int i=0; i<3; ++i) T[i] = new node, T[i]->l = T[i]->r = 0;
  while (TS--) {
    int X[3];
    scanf("%d %d %d %d", X, X+1, X+2, &Q);
    for (int i=0; i<3; ++i) {
      T[i]->L = 0;
      T[i]->R = X[i]-1;
      T[i]->init();
    }
    while (Q--) {
      int type;
      scanf("%d", &type);
      if (type == 3) {
        int dim[3][2], ans[3][2];
        for (int j=0; j<2; ++j)
          for (int i=0; i<3; ++i)
            scanf("%d", &dim[i][j]);
        for (int i=0; i<3; ++i) {
          ans[i][1] = T[i]->query(dim[i][0],dim[i][1]);
          ans[i][0] = dim[i][1] - dim[i][0] + 1 - ans[i][1];
        }
        long long ret = 0;
        for (int a=0; a<2; ++a)
          for (int b=0; b<2; ++b)
            for (int c=0; c<2; ++c)
              if ((a+b+c)%2 == 1)
                ret += (long long) ans[0][a] * ans[1][b] * ans[2][c];
        printf("%lld\n", ret);
      }
      else {
        int i, j;
        scanf("%d %d", &i, &j);
        T[type]->update(i,j);
      }
    }
  }
  return 0;
}

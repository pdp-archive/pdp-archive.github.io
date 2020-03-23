#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 2000000

struct Node {
  int id;
  Node* next;
  Node(int the_id, Node* the_next) : id(the_id), next(the_next) {}
};

int W[MAXN], S[MAXN][2];
short int V[MAXN];
Node *G[MAXN];

int compute(int id, int mode) {
  Node *v=G[id];
  int in=W[id], out=0;

  V[id]=1;
  if (S[id][0] == -1) {
    while (v != NULL) {
      if (V[v->id]) { v=v->next; continue; }
      out += compute(v->id, 1);
      in += compute(v->id, 2);
      v = v->next;
    }
    S[id][0]=out; S[id][1]=in;
  }
  switch (mode) {
    case 0: return S[id][0];
    case 1: return S[id][1];
    default: return min(S[id][0], S[id][1]);
  }
}

int main() {
#ifdef CONTEST
  freopen("schoolnet.in", "rt", stdin);
  freopen("schoolnet.out", "wt", stdout);
#endif

  int N;
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &W[i]);
    G[i]=NULL; V[i]=0; S[i][0]=-1;
  }
  for (int i=1; i<N; i++) {
    int x, y;
    scanf("%d %d", &x, &y); x--; y--;
    G[x] = new Node(y, G[x]);
    G[y] = new Node(x, G[y]);
  }
  printf("%d\n", compute(0, 2));
  return 0;
}

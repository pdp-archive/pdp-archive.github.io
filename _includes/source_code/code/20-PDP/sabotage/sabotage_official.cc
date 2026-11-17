/* ΙΩΑΝΝΗΣ ΧΑΤΖΗΜΙΧΟΣ 8ο ΓΕΛ ΛΑΡΙΣΑΣ */

#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

int moves[3][2] = { {0, -1}, {0, 1}, {1, 0} };

struct point {
  int r;
  int c;
};

int par[1001][1001], R, C;


void BFS(int r, int c) {
  queue<point> Q;
  point cur, next;
  int i;
  cur.r = r;
  cur.c = c;
  Q.push(cur);
  
  while(!Q.empty()) {
    cur = Q.front();
    Q.pop();
    for (i=0; i<3; i++) {
      next.r = cur.r + moves[i][0];
      next.c = cur.c + moves[i][1];
      if ( next.r <= 0 || next.r > R || next.c <= 0 || next.c > C ) continue;
      if ( par[next.r][next.c] ) continue;
      par[next.r][next.c] = i+1;
      Q.push(next);
    }
  }
}


int main(void) {
  FILE *in = fopen("sabotage.in", "r"), *out =
    fopen("sabotage.out", "w");
  int i, M, r, c, sr, sc;
  int mv[1000001], mvcnt = 0, mvid;
  
  fscanf(in, "%d %d %d", &C, &R, &M);
  for (i=1; i<=M; i++) {
    fscanf(in, "%d %d", &c, &r);
    par[r][c] = 8888;
  }
  
  fscanf(in, "%d %d", &sc, &sr);
  BFS(sr, sc);
  fscanf(in, "%d %d", &c, &r);
  
  if ( !par[r][c] ) {
    fprintf(out, "0\n");
  }
  else {
    while (r!=sr || c!=sc) {
      mvid = par[r][c]-1;
      mv[++mvcnt] = mvid;
      r -= moves[mvid][0];
      c -= moves[mvid][1];
    }
    fprintf(out, "%d\n%d %d\n", mvcnt+1, sc, sr);
    r = sr; c = sc;
    for (i=mvcnt; i>=1; i--) {
      r += moves[mv[i]][0];
      c += moves[mv[i]][1];
      fprintf(out, "%d %d\n", c, r);
    }
  }
  
  fclose(in); fclose(out); return 0;
}


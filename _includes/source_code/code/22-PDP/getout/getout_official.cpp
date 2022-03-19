/*
USER: 22pdp91
LANG: C++
TASK: getout
*/
#include <cstdio>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
int n, r;
FILE *fin, *fout;

struct state {
   char park[9][9];
   int moves;
   
   bool operator==(const state &b) const {
      int i, j;
      for (i=1; i<=n; i++) for (j=1; j<=n; j++) if (park[i][j]!=b.park[i][j]) return false;
      return true;
   }
   
   bool operator<(const state &b) const {
      int i, j;
      for (i=1; i<=n; i++) 
         for (j=1; j<=n; j++) 
            if (park[i][j]<b.park[i][j]) return true;
            else if (park[i][j]>b.park[i][j]) return false;
      return false;
   }
   void operator=(const state &b) {
      int i, j;
      for (i=1; i<=n; i++) for (j=1; j<=n; j++) park[i][j] = b.park[i][j];
      moves = b.moves;
   }
};

set<state> s;
queue<state> q;
char dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void print(state &tmp) {
   for (int i=n; i>=1; i--) {
      for (int j=1; j<=n; j++)
         printf("%d ", tmp.park[i][j]);
      printf("\n");
   }
   printf("\n");
}

void check(state &tmp) {
   int i;
   //print(tmp);
   for (i=1; i<=n; i++) if (tmp.park[r][i]!=0) return;
   fprintf(fout, "%d\n", tmp.moves);
   exit(0);
   //printf("ok with %d moves\n", tmp.moves);
   //if (tmp.moves==4) print(tmp);
}

int main() {
   fin=fopen("getout.in", "r");
   fout=fopen("getout.out", "w");
   state init, tmp, buk;
   int d=1, i ,j, t, x, y, k, z;
   fscanf(fin, "%d %d", &n, &r);
   for (i=1; i<=n; i++) for (j=1; j<=n; j++) init.park[i][j] = 0;
   for (i=1; i<=n; i++) {
      fscanf(fin, "%d", &t);
      if (i==r && t!=0) { fprintf(fout, "-1\n"); return 0; }
      for (j=1; j<=t; j++) { 
         fscanf(fin, "%d", &y);
         init.park[i][y] = d; init.park[i][y+1] = d++;
      }
   }
   for (i=1; i<=n; i++) {
      fscanf(fin, "%d", &t);
      for (j=1; j<=t; j++) {
         fscanf(fin, "%d", &x);
         init.park[x][i] = d;
         init.park[x+1][i] = d++;
      }
   }
   init.moves = 0;
   s.insert(init);
   q.push(init);
   check(init);
   while (!q.empty()) {
      char used[100]={0};
      tmp = q.front();
      q.pop();
      //print(tmp);
      tmp.moves++;
      buk = tmp;
      for (i=1; i<=n; i++)
         for (j=1; j<=n; j++) {
            if (tmp.park[i][j]) {
               for (k=0; k<4; k++) {
                  x = i + dir[k][0]; y = j + dir[k][1];
                  if (i>=1 && i<=n && j>=1 && j<=n
                     && tmp.park[i][j]==tmp.park[x][y] && !used[tmp.park[i][j]]) break;

               }
               if (k!=4) {
                  used[tmp.park[i][j]] = 1;
                  //printf("found (%d %d) (%d %d): %d\n", i, j, x, y, tmp.park[i][j]);
                  if (i==x) {
                     //if (j<y) k = j; else k = y;
                     k = j;
                     for (z=k-1; z>=1; z--) {
                        if (!tmp.park[i][z]) {
                           tmp.park[i][z] = tmp.park[i][z+1];
                           tmp.park[i][z+2] = 0;
                        } else break;
                        if (s.find(tmp)==s.end()) {
                           q.push(tmp);
                           s.insert(tmp);
                           check(tmp);
                        }
                     }
                     tmp = buk;
                     for (z=k+2; z<=n; z++) {
                        if (!tmp.park[i][z]) {
                           tmp.park[i][z] = tmp.park[i][z-2];
                           tmp.park[i][z-2] = 0;
                        } else break;
                        if (s.find(tmp)==s.end()) {
                           q.push(tmp);
                           s.insert(tmp);
                           check(tmp);
                        }
                     }
                     tmp = buk;
                  } else {
                     //if (i<x) k = i; else k = x;
                     k = i;
                     //printf("second\n");
                     //print(tmp);
                     for (z=k-1; z>=1; z--) {
                        if (!tmp.park[z][j]) {
                           //printf("ok\n");
                           tmp.park[z][j] = tmp.park[z+1][j];
                           tmp.park[z+2][j] = 0;
                        } else break;
                        if (s.find(tmp)==s.end()) {
                           q.push(tmp);
                           s.insert(tmp);
                           check(tmp);
                        }
                     }
                     tmp = buk;
                     for (z=k+2; z<=n; z++) {
                        if (!tmp.park[z][j]) {
                           tmp.park[z][j] = tmp.park[z-2][j];
                           tmp.park[z-2][j] = 0;
                        } else break;
                        if (s.find(tmp)==s.end()) {
                           q.push(tmp);
                           s.insert(tmp);
                           check(tmp);
                        }
                     }
                     tmp = buk;
                  }
               }
            }
         }
      //return 0;
   }
   fprintf(fout, "-1\n");
   return 0;
}

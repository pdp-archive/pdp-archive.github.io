#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const size_t MAXN = 10000;
const long INF = 0x3f3f3f3f;

long N, M, qX, qY, ans[MAXN+5], nPQA, pqa[MAXN+5], root[2*MAXN+5], par[2*MAXN+5], r[2*MAXN+5];

struct segment{
  long X, Y, C;
} seg[MAXN+5];

struct event{
  bool type;
  long id;
} events[2*MAXN+5];

long getCoord(event A) {
  return A.type ? seg[ A.id ].Y : seg[ A.id ].X;
}

bool compEv(event A, event B) {
  if (getCoord(A) != getCoord(B)) return getCoord(A) < getCoord(B);
  return A.type < B.type;
}

long Find(long u) {
  if (u!=par[u]) par[u] = Find(par[u]);
  return par[u];
}

void Union(long u, long v) {
  u = Find(u);
  v = Find(v);
  if(r[u] > r[v]) swap(u,v);
  if(r[u] == r[v]) ++r[u];
  par[v] = u;
}

int main() {
   FILE *fi = fopen("roadfix.in", "r");
   fscanf(fi, "%ld %ld", &N, &M);
   for (long i = 1; i <= N; ++i) {
     fscanf(fi, "%ld %ld %ld", &seg[i].X, &seg[i].Y, &seg[i].C);
     seg[i].Y += seg[i].X; //convert length to right-end-point     
     events[i].type = 0, events[i].id=i;
     events[i+N].type = 1, events[i+N].id=i;
   }

   sort(events+1, events+2*N+1, compEv);

   FILE *fo = fopen("roadfix.out", "w");
   long sol, start;
   for(long q = 1; q <= M; ++q) {
     fscanf(fi, "%ld %ld", &qX, &qY);
     qY += qX; //convert length to right-end-point
     sol = INF;
     memset(r, 0, sizeof(r));
     memset(root, 0, sizeof(root));
     memset(par, 0, sizeof(par));

     nPQA = 0;
     pqa[0] = 0;
     start = 1;
     for(long i=1; i<=2*N; ++i) {
       if (events[i].type==0) {
	 if (events[i-1].type==1) start = i;
	 par[ events[i].id ] = events[i].id;
	 continue;
       }

       //else: we have the right endpoint of an interval
       //first we find the successor of its starting point
       long evPos = Find(events[i].id);
       long successor = root[evPos];
       long best = (seg[ events[i].id ].X <= qX) ? 0 : INF;
       if(seg[ events[successor].id ].Y >= seg[ events[i].id ].X) best=min(best, ans[ successor ]);       

       //then we use it to compute ans[i] using the recursive relation
       if (best==INF) { //if no previous segment finishes before i's start
	 if (seg[events[i].id].Y <= qX) ans[i] = 0; // [qX,seg[i].Y] is trivially satisfied
	 else if (seg[events[i].id].X <= qX) ans[i] = seg[events[i].id].C; //i is enough to satisfy it
	 else ans[i] = INF; //i is not enough and no-one else can help
       }
       else ans[i] = seg[events[i].id].C + best; //recursive relation
       if (seg[events[i].id].Y >= qY) sol = min(sol, ans[i]);

       //now we update our structure using ans[i]
       //let everything from start till i-1 know that its successor is i
       par[ events[i].id+N ] = events[i].id+N;
       root[ events[i].id+N ] = i;
       if (events[start].type==0) {
	 for(long j=start; j<i; ++j) {
	   root[Find(events[j].id)] = i;
	   Union( events[j].id, events[i].id+N);
	 }
       }
       start = i;
       //Remove elements from the top if they are worse than i, and add i
       //if an element A was the successor of an element B and A is removed, then B has i as the new successor
       while(nPQA && ans[pqa[nPQA]] >= ans[i]) {
	 root[Find(events[pqa[nPQA]].id+N)] = i;
	 Union(events[ pqa[nPQA] ].id+N, events[i].id+N);
	 --nPQA;
       }
       pqa[++nPQA] = i;
     }

     if (sol < INF) fprintf(fo, "%ld\n", sol);
     else fprintf(fo, "-1\n");
   }
   fclose(fi), fclose(fo);
   return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

const size_t MAXN = 10000;
const long INF = 0x3f3f3f3f;
const long MAXVAL = 1000000000;
const long MAXNODES = 30*MAXN;

long N, M, qX, qY, ans[MAXN+5], l[MAXNODES], r[MAXNODES], minim[MAXNODES], currNode;
struct segment{
  long X, Y, C;
} seg[MAXN+5];

bool comp(segment A, segment B) {
  return A.Y < B.Y;
}

long Left(long v) {
  if (!l[v]) {
    l[v] = ++currNode;
    minim[currNode] = INF;
  }
  return l[v];
}

long Right(long v) {
  if (!r[v]) {
    r[v] = ++currNode;
    minim[currNode] = INF;
  }
  return r[v];
}

long Minimum(long from, long v=1, long x=1, long y=MAXVAL) {
  if(x==from) return minim[v];
  long mid=(x+y)/2;
  if (mid < from) return Minimum(from, Right(v), mid+1, y);
  return min( Minimum(from, Left(v), x, mid), minim[Right(v)] );
}

void Add(long pos, long val, long v=1, long x=1, long y=MAXVAL) {
  if (x==y) {
    minim[v] = min(minim[v],val);
    return;
  }

  long mid=(x+y)/2;
  if(pos<=mid) Add(pos, val, Left(v), x, mid);
  else Add(pos, val, Right(v), mid+1, y);
  minim[v] = min(minim[Left(v)],minim[Right(v)]);
}

int main() {
   FILE *fi = fopen("roadfix.in", "r");
   fscanf(fi, "%ld %ld", &N, &M);
   for (long i = 1; i <= N; ++i) {
     fscanf(fi, "%ld %ld %ld", &seg[i].X, &seg[i].Y, &seg[i].C);
     seg[i].Y += seg[i].X; //convert length to right-end-point
   }

   sort(seg+1, seg+N+1, comp);

   FILE *fo = fopen("roadfix.out", "w");
   long sol;
   for(long i = 1; i <= M; ++i) {
     fscanf(fi, "%ld %ld", &qX, &qY);
     qY += qX; //convert length to right-end-point
     sol = INF;

     currNode = 1;
     for(long i=1; i<=N; ++i) {
       //Find best j that finishes after (or exactly at) i's start
       long best = Minimum(seg[i].X);

       if (best==INF) { //if no previous segment finishes before i's start
	 if (seg[i].Y <= qX) ans[i] = 0; // [qX,seg[i].Y] is trivially satisfied
	 else if (seg[i].X <= qX) ans[i] = seg[i].C; //i is enough to satisfy it
	 else ans[i] = INF; //i is not enough and no-one else can help
       }
       else ans[i] = seg[i].C + best; //recursive relation
       Add(seg[i].Y, ans[i]);
	 
       if (seg[i].Y >= qY) sol = min(sol, ans[i]);
     }
     
     if (sol < INF) fprintf(fo, "%ld\n", sol);
     else fprintf(fo, "-1\n");

     for(long i=1; i<=currNode; ++i) {
       l[i] = r[i] = 0;
       minim[i] = INF;
     }
   }
   fclose(fi), fclose(fo);
   return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

const size_t MAXN = 10000;
const long INF = 0x3f3f3f3f;

long N, M, qX, qY, ans[MAXN+5], nPQA, pqa[MAXN+5];
struct segment{
  long X, Y, C;
} seg[MAXN+5];

bool comp(segment A, segment B) {
  return A.Y < B.Y;
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
   for(long q = 1; q <= M; ++q) {
     fscanf(fi, "%ld %ld", &qX, &qY);
     qY += qX; //convert length to right-end-point
     sol = INF;

     nPQA = 0;
     pqa[0] = 0;
     seg[0].Y = 0;
     for(long i=1; i<=N; ++i) {
       //Find best j that finishes after (or exactly at) i's start
       long best = (seg[i].X <= qX && qX <= seg[i].Y ) ? 0 : INF, lo=1, hi=nPQA, mid;
       while (lo<hi) {
	 mid = (lo+hi)/2;
	 if (seg[ pqa[mid] ].Y < seg[i].X) lo=mid+1;
	 else hi=mid;
       }
       if(nPQA>0 && seg[ pqa[hi] ].Y >= seg[i].X) best=min(best, ans[ pqa[hi] ]);

       if (best==INF) { //if no previous segment finishes before i's start
	 if (seg[i].Y <= qX) ans[i] = 0; // [qX,seg[i].Y] is trivially satisfied
	 else if (seg[i].X <= qX) ans[i] = seg[i].C; //i is enough to satisfy it
	 else ans[i] = INF; //i is not enough and no-one else can help
       }
       else ans[i] = seg[i].C + best; //recursive relation

       //Remove elements from the top if they are worse than i, and add i
       while(nPQA && ans[pqa[nPQA]] >= ans[i]) --nPQA;
       pqa[++nPQA] = i;
	 
       if (seg[i].Y >= qY) sol = min(sol, ans[i]);
     }

     if (sol < INF) fprintf(fo, "%ld\n", sol);
     else fprintf(fo, "-1\n");
   }
   fclose(fi), fclose(fo);
   return 0;
}

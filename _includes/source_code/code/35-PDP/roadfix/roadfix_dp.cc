#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const size_t MAXN = 10000;
const long INF = 0x3f3f3f3f;

long N, M, qX, qY, ans[MAXN+1][MAXN+1], order[MAXN+1];
vector< pair<long, long> > begins;
struct segment{
  long X, Y, C;
} seg[MAXN+1];

bool compSeg(segment A, segment B) {
  return A.Y < B.Y;
}

int main() {
   FILE *fi = fopen("roadfix.in", "r");
   fscanf(fi, "%ld %ld", &N, &M);
   for (long i = 1; i <= N; ++i) {
     fscanf(fi, "%ld %ld %ld", &seg[i].X, &seg[i].Y, &seg[i].C);
     seg[i].Y += seg[i].X; //convert length to right-end-point
   }

   sort(seg+1, seg+N+1, compSeg);
   for(long i=1; i<=N; ++i) begins.push_back({seg[i].X, i});
   sort(begins.begin(), begins.end());

   FILE *fo = fopen("roadfix.out", "w");
   long sol;
   for(long q = 1; q <= M; ++q) {
     fscanf(fi, "%ld %ld", &qX, &qY);
     qY += qX; //convert length to right-end-point

     //insert {qY,N+1} in sorted order
     begins.insert( upper_bound( begins.begin(), begins.end(), make_pair(qY,N+1) ), make_pair(qY,N+1) );
     for(long i=0; i<=N; ++i) order[ begins[i].second ] = i;

     for(long YtIndex=0; YtIndex<=N; ++YtIndex) {
       long Yt = begins[YtIndex].first;       
       ans[0][YtIndex] = ((qX >= Yt) ? 0 : INF); //if qX>=Yt there is nothing to cover
	 
       for(long last=1; last<=N; ++last) {       
	 if (qX >= Yt) ans[last][YtIndex] = 0; //nothing left to cover
	 else if (seg[last].X > Yt) ans[last][YtIndex] = ans[last-1][YtIndex]; //last is irrelevant, ignore it
	 else if (seg[last].Y < Yt) ans[last][YtIndex] = INF; //no-one can cover Yt
	 else { //Recursive relation
	   ans[last][YtIndex] = min( seg[last].C + ans[last-1][order[last]], ans[last-1][YtIndex] );
	 }
	 if (Yt == qY) sol = ans[last][YtIndex];
       }
     }
     
     if (sol < INF) fprintf(fo, "%ld\n", sol);
     else fprintf(fo, "-1\n");
     begins.erase( find(begins.begin(), begins.end(), make_pair(qY,N+1) ) );
   }
   
   fclose(fi), fclose(fo);
   return 0;
}

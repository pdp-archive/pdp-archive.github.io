#include <cstdio>
#include <algorithm>
using namespace std;

const size_t MAXN = 10000;
const long INF = 0x3f3f3f3f;

long N, M, qX, qY, ans[MAXN+5][MAXN+5];
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
   for(long i = 1; i <= M; ++i) {
     fscanf(fi, "%ld %ld", &qX, &qY);
     qY += qX; //convert length to right-end-point

     for(long YtIndex=1; YtIndex<=N+1; ++YtIndex) {
       long Yt;
       if (YtIndex!=N+1) Yt = seg[YtIndex].X;
       else Yt = qY;
       
       ans[YtIndex][0] = (qX >= Yt) ? 0 : INF;
       for(long last=1; last<=N; ++last) {
	 if (qX >= Yt) ans[YtIndex][last]=0; //nothing left to cover
	 if (seg[last].X > Yt) ans[YtIndex][last] = ans[YtIndex][last-1]; //last is irrelevant, ignore it
	 else if (seg[last].Y < Yt) ans[YtIndex][last] = INF; //no-one can cover Yt
	 else { //Recursive relation
	   ans[YtIndex][last] = min( seg[last].C + ans[last][last-1], ans[YtIndex][last-1] );
	 }
       }
     }
     
     if (ans[N+1][N] < INF) fprintf(fo, "%ld\n", ans[N+1][N]);
     else fprintf(fo, "-1\n");
   }
   fclose(fi), fclose(fo);
   return 0;
}

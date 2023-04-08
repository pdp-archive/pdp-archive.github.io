#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const size_t MAXN = 10000;
const long INF = 0x3f3f3f3f;

long N, M, qX, qY, ans[MAXN+2][MAXN+2];
bool computed[MAXN+2][MAXN+2];
struct segment{
  long X, Y, C;
} seg[MAXN+1];

bool comp(segment A, segment B) {
  return A.Y < B.Y;
}

long Ans(long last, long YtIndex) {
  long Yt;
  if (YtIndex!=N+1) Yt = seg[YtIndex].X;
  else Yt = qY;
  
  if (qX >= Yt) return 0; //nothing left to cover
  if (last==0) return INF; //impossible to cover [qX, Yt] without any segments left
  if (!computed[last][YtIndex]) {
    computed[last][YtIndex] = 1;
    if (seg[last].X > Yt) ans[last][YtIndex] = Ans(last-1, YtIndex); //last is irrelevant, ignore it
    else if (seg[last].Y < Yt) ans[last][YtIndex] = INF; //no-one can cover Yt
    else { //Recursive relation
      ans[last][YtIndex] = min( seg[last].C + Ans(last-1, last), Ans(last-1, YtIndex) );
    }
  }
  return ans[last][YtIndex];
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
   for(long q = 1; q <= M; ++q) {
     fscanf(fi, "%ld %ld", &qX, &qY);
     qY += qX; //convert length to right-end-point
     if (Ans(N,N+1) < INF) fprintf(fo, "%ld\n", Ans(N,N+1));
     else fprintf(fo, "-1\n");
     memset(computed, 0, sizeof(computed));
   }
   fclose(fi), fclose(fo);
   return 0;
}

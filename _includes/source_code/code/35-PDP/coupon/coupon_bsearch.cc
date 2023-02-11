#include <cstdio>

typedef unsigned long long ull;

const size_t MAXN = 1000;

long N, C[MAXN+1];
double A;
ull B;
FILE *fo;

ull TotalMoney(ull X, bool printIt) {
  ull s=0;
  for(long i=1; i<=N; ++i) {
    if (X<10) X=0;
    s+=X*C[i];
    if(printIt) fprintf(fo, "%llu\n", X);
    X = (long)(A*X);    
  }
  return s;
}

int main() {
   FILE *fi = fopen("coupon.in", "r");
   fscanf(fi, "%ld %lf %llu", &N, &A, &B);
   for (long i = 1; i <= N; ++i) {
      fscanf(fi, "%ld", &C[i]);
   }
   fclose(fi);

   long X, lo=0, mid, hi=B/C[1]+10;
   while (lo<hi) {
     mid = (lo+hi+1)/2;
     if(TotalMoney(mid,false)<=B) lo=mid;
     else hi=mid-1;
   }
   X=lo;

   fo = fopen("coupon.out", "w");
   fprintf(fo, "%llu\n", TotalMoney(X,false));
   TotalMoney(X,true);
   fclose(fo);   
   return 0;
}

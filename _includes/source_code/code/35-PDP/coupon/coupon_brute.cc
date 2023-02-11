#include <cstdio>

typedef unsigned long long ull;

const size_t MAXN = 1000;

long N, C[MAXN+1];
double A;
ull B;
FILE *fo;

ull TotalMoney(ull first, bool printIt) {
  ull s=0;
  for(long i=1; i<=N; ++i) {
    if (first<10) first=0;
    s+=first*C[i];
    if(printIt) fprintf(fo, "%llu\n", first);
    first = (long)(A*first);    
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

   long val;
   for(val=10; TotalMoney(val,false)<=B; ++val);
   
   fo = fopen("coupon.out", "w");
   fprintf(fo, "%llu\n", TotalMoney(val-1,false));
   TotalMoney(val-1,true);
   fclose(fo);   
   return 0;
}

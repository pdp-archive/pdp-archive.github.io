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
    s+=X*C[i]; //the product doesn't fit in type 'long' - that's why we declare X as type 'ull'
    if(printIt) fprintf(fo, "%llu\n", X);
    X = (long)(A*X);    
  }
  return s;
}

int main() {
   long X;  
   FILE *fi = fopen("coupon.in", "r");
   fscanf(fi, "%ld %lf %llu", &N, &A, &B);
   for (long i = 1; i <= N; ++i) {
      fscanf(fi, "%ld", &C[i]);
   }
   fclose(fi);

   //the following loop does not have a main-body, it only searches for X - that's why it ends with ';'   
   for(X=1; TotalMoney(X,false)<=B; ++X);
   --X;
     
   fo = fopen("coupon.out", "w");
   fprintf(fo, "%llu\n", TotalMoney(X,false));
   TotalMoney(X,true);
   fclose(fo);   
   return 0;
}

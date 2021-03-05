#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long M;

int sm(long long k, long long n, long long L){
   long long pr = 1, sum = 0;
   for (long long i = 0; i!=n && sum < L; i++){
      sum += pr;
      pr *= k;
   }
   if (L > sum) return -1;
   if (L < sum) return 1;
   return 0;
}

long long minim;

void check(long long sum, long long test){
   long long point, st, en, mn;
   int tmp;
   for (long long i = 1; i!=45; i++){
      //point = M / i;
      st = 2; en = M+1;
      while(st < en-1){
         //printf("%lld %lld\n", st, en);
         mn = (st+en)/2;
         tmp = sm(mn, i, sum);
         if (tmp==0) {
            if (test < mn) {minim = min(mn, minim);}
            break;
         }
         else if (tmp==1) en = mn-1;
         else st = mn+1;
      }
      if (sm(en, i, sum)==0) if (test < en) minim = min(en, minim);
      if (sm(st, i, sum)==0) if (test < st) minim = min(st, minim);
   }
}

long long divi[2000100];

int main(){
   int N;
   FILE *fi = fopen("numbase.in", "r");
   fscanf(fi, "%d", &N);
   FILE *fo = fopen("numbase.out", "w");
   while(N--){
      fscanf(fi, "%lld", &M);
      //printf("%lld\n", M);
      if (M==1) {fprintf(fo, "2\n"); continue; }
         // For one
         long long z, mn, k = 1;
         // Find divisors
         int count = 0;
         while (k*k <= M) {
            if (M%k==0) {
               divi[count++] = k;
               divi[count++] = (long long) M / (long long) k;
            }
            k++;
         }
         minim = M+1;
         for (int i = 0; i<count; i++){
            //printf("hi %lld %lld\n", divi[i], M/divi[i]);
            check(divi[i], (long long)M/(long long)divi[i]);
         }
      fprintf(fo, "%lld\n", minim);
   }
   return 0;
}

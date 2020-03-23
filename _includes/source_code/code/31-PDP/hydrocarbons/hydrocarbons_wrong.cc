#include <bits/stdc++.h>
using namespace std;

struct ApodosiThesi {
   double apodosi;
   long thesi;
} Thetika[100001];

bool compare (ApodosiThesi ena, ApodosiThesi dio) {
   if (ena.apodosi != dio.apodosi) 
       return ena.apodosi > dio.apodosi;
   return ena.thesi < dio.thesi;
}

int main() {
   double a, b, c, apodosi;
   long N, posaThetika = 0;
   freopen("hydrocarbons.in","r",stdin);
   freopen("hydrocarbons.out","w",stdout);
   scanf("%ld", &N);
  
   for(long i=1; i<=N; ++i) {
      scanf("%lf %lf %lf", &a, &b, &c);
      apodosi = a-a*b/3000.0-a*c/40.0;
      if (apodosi > 0) {
         ++posaThetika;
         Thetika[posaThetika].apodosi = apodosi;
         Thetika[posaThetika].thesi = i;
      }
   }
   sort(Thetika+1, Thetika+posaThetika+1, compare);
   printf("%ld\n", posaThetika);
   for(long i=1; i<=posaThetika; ++i) {
      printf("%ld", Thetika[i].thesi);
      if(i<posaThetika) printf(" ");
      else printf("\n");
   }
   return 0;
}

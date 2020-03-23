#include <bits/stdc++.h>

using namespace std;

struct ApodosiThesi {
   long long apodosi;
   long thesi;
} Thetika[100001];

bool compare (ApodosiThesi ena, ApodosiThesi dio) {
   if (ena.apodosi != dio.apodosi)
      return ena.apodosi > dio.apodosi;
   return ena.thesi < dio.thesi;
}

int main() {
   long long a, b, c, apodosi;
   long N, posaThetika = 0;
   freopen("hydrocarbons.in","r",stdin);
   freopen("hydrocarbons.out","w",stdout);
   scanf("%ld", &N);
  
   for(int i=1; i<=N; ++i) {
      scanf("%lld %lld %lld", &a, &b, &c);
      apodosi = 3000*a-a*b-75*a*c;
      if (apodosi > 0) {
         ++posaThetika;
         Thetika[posaThetika].apodosi = apodosi;
         Thetika[posaThetika].thesi = i;
      }
   }

   sort(Thetika+1, Thetika+posaThetika+1, compare);
   printf("%ld\n", posaThetika);
   for(int i=1; i<=posaThetika; ++i) {
      printf("%ld", Thetika[i].thesi);
      if(i<posaThetika) printf(" ");
      else  printf("\n");
   }
   return 0;
}

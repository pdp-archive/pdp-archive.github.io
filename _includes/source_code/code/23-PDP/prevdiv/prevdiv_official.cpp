/*
USER : pdp23u1
LANG : C++
TASK : prevdiv
*/
#include <cstdio>
#include <algorithm>
#define INF 2100000000

int Calc ( int a, int b ) {
   int fac_a=1, fac_b=1;
   if ( a==1 || b==1 ) return ( a>b?a:b );
   if ( a < b ) fac_a = b/a;
   if ( b < a ) fac_b = a/b;
   while ( fac_a*a!=fac_b*b ) {
      if ( fac_a*a < fac_b*b )
         //fac_a = fac_b*b/fac_a*a;
         ++fac_a;
      else
         ++fac_b;
         //fac_b = fac_a*a/fac_b*b;
      if ( fac_a*a > INF || fac_b*b > INF ) return (INF);
   }
   return ( fac_a*a );
}

int main (void ) {
   int i, tmp, MaXiM, ekp, N;
   FILE *fin = fopen("prevdiv.in", "r"), *fout = fopen("prevdiv.out", "w" );
   fscanf ( fin, "%d %d", &N, &tmp );
   ekp = MaXiM = tmp;
   for ( i=2; i<=N; ++i ) {
      fscanf ( fin, "%d", &tmp );
      ekp = Calc ( tmp, ekp );
      if ( ekp == INF )
         break;
      if ( tmp > MaXiM ) {
         if ( tmp % ekp == 0 ) {
            MaXiM = ekp;
         }
      }
   }
   fprintf ( fout,"%d\n", MaXiM );
   fclose(fin);fclose(fout);
   return(0);
}

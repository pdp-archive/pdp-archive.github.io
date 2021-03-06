#include <cstdio>
#include <algorithm>

#define MAXN 1100000
#define INF 1000000000

using namespace std;

int seen[ MAXN + 12 ], prof[ MAXN + 12 ], par[ MAXN + 12 ], A[ MAXN + 12 ], visited[ MAXN + 12 ];
int N, K, ans = 0;

int find( int u ) {
   if( u == par[ u ] ) return u;
   return par[ u ] = find( par[ u ] );
}

void Union( int u, int v ) {
   u = find( u );
   v = find( v );
   par[ v ] = u;
   prof[ u ] += prof[ v ];
}

int main( void ) {
   int ans = 0;
   freopen("efimerides.in","rt",stdin);
   freopen("efimerides.out","wt",stdout);
   scanf("%d%d", &N, &K );
   for( int i = 0; i < N; i++ ) {
      scanf("%d", &A[ i ] );
   }
   for( int i = 0; i < N; i++ ) {
      par[ i ] = i;
      prof[ i ] = A[ i ];
      seen[ i ] = 0;
   }
   for( int u = 0; u < N; u++ ) {
      if( seen[ u ] ) continue;
      seen[ u ] = true;
      for( int i = ( u + K ) % N;; i = ( i + K ) % N ) {
         if( seen[ i ] ) break;
         seen[ i ] = true;
         Union( i, u );
      }
   }
   for( int i = 0; i < N; i++ ) {
      ans = max( ans, prof[ i ] );
   }
   printf("%d\n", ans );
   return 0;
}

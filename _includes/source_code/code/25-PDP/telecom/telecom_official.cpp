#include <cstdio>
#include <algorithm>
#define MAX 500000

long long p[MAX+1],num[MAX+1],rank[MAX+1];
struct edge {
   int u,v,w;
};

void makenode(int u) {
   p[ u ] = u;
   num[ u ] = 1;
   rank[ u ] = 1;
}

int find(int u) {
   if(u == p[ u ]) {
      return u;
   } else {
      return p[ u ] = find(p[ u ]);
   }
}

void Union(int u,int v) {
   u = find( u );
   v = find( v );
   if( rank[ u ] > rank[ v ] ) {
      p[ v ] = u;
      num[ u ] += num[ v ];
   } else {
      p[ u ] = v;
      num[ v ] += num[ u ];
      if( rank[ u ] == rank[ v ] ) {
         rank[ v ]++;
      }
   }
}

bool cmp( edge a, edge b ) {
   return a.w < b.w;
}

int main( void ) {
   freopen("telecom.in","rt",stdin);
   freopen("telecom.out","wt",stdout);
   int N;
   unsigned long long cost = 0;
   scanf("%d",&N);
   edge E[N-1];
   for(int i = 0; i < N - 1; i++ ) {
      scanf("%d%d%d",&E[ i ].u,&E[ i ].v,&E[ i ].w);
      makenode( E[ i ].u );
      makenode( E[ i ].v );
   }
   std::sort(E, E+N-1, cmp);
   for(int i = 0; i < N-1; i++ ) {
      int fu = find( E[ i ].u ),fv = find( E[ i ].v );
      if( fu != fv ) {
         cost += num[ fu ]*num[ fv ]*(E[ i ].w + 1);
         Union( E[ i ].u , E[ i ].v );
      }
   }
   printf("%llu\n",cost-N+1);
   return 0;
}

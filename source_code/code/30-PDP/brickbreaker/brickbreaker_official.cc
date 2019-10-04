#include <cstdio>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define MAXN 1200

using namespace std;

typedef pair< int, int > pii;

int N, M, size[ MAXN + 1 ][ MAXN + 1 ], grid[ MAXN + 1 ][ MAXN + 1 ];
pii par[ MAXN + 1][ MAXN + 1];

vector< pii > queries;

pii find( int u, int v ){
    if( par[ u ][ v ] == mp( u,v ) ) return par[ u ][ v ];
    return par[ u ][ v ] = find( par[ u ][ v ].X, par[ u ][ v ].Y );
}

void Union( pii u, pii v ){
    u = find( u.X, u.Y );
    v = find( v.X, v.Y );
    if( u == v ) return;
    par[ u.X ][ u.Y ] = v;
    size[ v.X ][ v.Y ] += size[ u.X ][ u.Y ];
}

void init( int u, int v ) {
    size[ u ][ v ] = 1;
    par[ u ][ v ] = mp( u, v );
}

int main( void ) {
#ifdef CONTEST
    freopen("brickbreaker.in","rt",stdin);
    freopen("brickbreaker.out","wt",stdout);
#endif
    char c;
    scanf("%d%d", &N, &M );
    for( int i = 1; i <= N; i++ ) {
        scanf("\n");
        for( int j = 1; j <= M; j++ ) {
            c = getchar();
            if( c == '#' ) grid[ i ][ j ] = 1;
        }
    }
    for( int i = 0; i <= M; i++ ) {
        grid[ 0 ][ i ] = 1;
    }
    for( int i = 0; i <= N; i++ ) {
        for( int j = 0; j <= M; j++ ) {
            if( grid[ i ][ j ] ) init( i, j );
        }
    }
    int Q, u, v;
    scanf("%d", &Q );
    for( int i = 0; i < Q; i++ ) {
        scanf("%d%d", &u, &v );
        queries.pb( mp( u, v ) );
        grid[ u ][ v ] = 0;
    }

    for( int i = 0; i <= N; i++ ) {
        for( int j = 0; j <= M; j++ ) {
            if( grid[ i ][ j ] ) {
                if( i > 0 && grid[ i - 1 ][ j ] ) Union( mp( i, j ), mp( i - 1, j ) );
                if( j > 0 && grid[ i ][ j - 1 ] ) Union( mp( i, j ), mp( i, j - 1 ) );
            }
        }
    }
    vector< int > results;
    pii node = find( 0, 0 );
    int com_size = size[ node.X ][ node.Y ];
    for( int i = Q - 1; i >= 0; i-- ) {
        int u = queries[ i ].X, v = queries[ i ].Y;
        grid[ u ][ v ] = 1;

        if( grid[ u - 1 ][ v ] ) Union( mp( u, v ), mp( u - 1, v ) );
        if( grid[ u + 1 ][ v ] ) Union( mp( u, v ), mp( u + 1, v ) );
        if( grid[ u ][ v - 1 ] ) Union( mp( u, v ), mp( u, v - 1 ) );
        if( grid[ u ][ v + 1 ] ) Union( mp( u, v ), mp( u, v + 1 ) );
        node = find( 0, 0 );
        int new_size = size[ node.X ][ node.Y ];
        if( new_size == com_size ) results.pb( 0 );
        else results.pb( new_size - com_size - 1 );
        com_size = new_size;
    }
    for( int i = Q - 1; i >= 0; i-- ) {
        printf("%d\n", results[ i ] );
    }
    return 0;
}

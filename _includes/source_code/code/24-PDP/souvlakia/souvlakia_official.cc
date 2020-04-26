/*
USED : pdp24u11
TASK : souvlakia
LANG : C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define MAXN 100005
#define mp make_pair
#define SAFE 60000000LL
#define INF 0x3f3f3f3f
#define X first
#define Y second
typedef long long llint;
typedef pair<int,int> pii;

struct Node {
    int d[3];
    int id;
} node[MAXN];

int N, M, A, B, C, L, in[MAXN], nstack, stack[MAXN];
vector<int> e[MAXN], dist[MAXN];
set< pii > coast;
set< pii >::iterator pos, pos2;

bool comp ( Node a, Node b ) {
    if ( a.d[0] < b.d[0] ) {
        return true;
    }
    if ( a.d[0] == b.d[0] && a.d[1] < b.d[1] ) {
        return true;
    }
    if ( a.d[0] == b.d[0] && a.d[1] == b.d[1] && a.d[2] <b.d[2] ) {
        return true;
    }
    return false;
}

void Read() {
    int i, a, b, d;
    scanf ("%d %d", &N, &M);
    for ( i=1; i<=M; ++i ) {
        scanf ("%d %d %d", &a, &b, &d);
        e[a].push_back(b);
        e[b].push_back(a);
        dist[a].push_back(d);
        dist[b].push_back(d);
    }
    scanf ("%d %d %d %d", &A, &B, &C, &L);
    for ( i=1; i<=N; ++i ) {
        node[i].d[0] = node[i].d[1] = node[i].d[2] = INF;
        node[i].id = i;
    }
}

void Print () {
    int i, a;
    for ( i=1; i<=L; ++i ) {
        scanf ("%d", &a);
        if ( in[a] ) {
            printf ("YES\n");
        }
        else {
            printf ("NO\n");
        }
    }
}

void Dijkstra ( int s, int d ) {
    int v, i;
    node[s].d[d] = 0;
    set< pii > S;
    S.insert ( mp(0,s) );
    while ( !S.empty() ) {
        v = S.begin()->Y;
        S.erase ( S.begin() );
        for ( i=0; i<e[v].size(); ++i ) {
            if ( node[ e[v][i] ].d[d] > node[v].d[d] + dist[v][i] ) {

                if ( node[ e[v][i] ].d[d] != INF ) {
                    S.erase ( S.find ( mp ( node[ e[v][i] ].d[d], e[v][i] ) ) );
                }
                node[ e[v][i] ].d[d] = node[v].d[d] + dist[v][i];

                S.insert ( mp ( node[ e[v][i] ].d[d], e[v][i] ) );
            }
        }
    }
}

bool Ok ( set< pii >::iterator thesi, int i ) {
    --thesi;
    // thesi->X < node[i].d[1]
    if ( thesi->Y < node[i].d[2] ) {
        return false;
    }
    return true;
}

void Insert ( int i ) {
    int new_val;
    pos = coast.lower_bound ( mp ( node[i].d[1], -1 ) );
    if ( pos == coast.begin() || Ok(pos, i) ) {
        if ( pos != coast.end() && pos->X == node[i].d[1] )
        {
            new_val = min ( pos->Y, node[i].d[2] );
            coast.erase ( coast.find ( mp ( pos->X, pos->Y) ) );
        }
        else {
            new_val = node[i].d[2];
        }
        coast.insert ( mp ( node[i].d[1], new_val ) );
        pos = pos2 = coast.find ( mp ( node[i].d[1], new_val) );

        for ( ++pos2, ++pos; pos2 != coast.end(); ++pos2 ) {
            if ( ! ( new_val <= pos2->Y ) ) {
                break;
            }
        }
        if ( pos != coast.end() && pos != pos2 ) {
            coast.erase ( pos, pos2 );
        }
    }
}

void Compute() {
    int i, j;
    sort ( node+1, node+N+1, comp );
    in[ node[1].id ] = 1;
    coast.insert ( mp ( node[1].d[1], node[1].d[2] ) );
    nstack = 0;
    for ( i=2; i<=N; ++i ) {
        if ( node[i].d[0] != node[i-1].d[0] ) {
            break;
        }
        in[ node[i].id ] = 1;
        stack[ ++nstack ] = i;
    }
    for ( ; i<=N; ++i ) {
        if ( node[i].d[0] != node[i-1].d[0] ) {
            for ( j=1; j<=nstack; ++j ) {
                Insert ( stack[j] );
            }
            nstack = 0;
        }
        pos = coast.lower_bound ( mp ( node[i].d[1], -1 ) );

        #ifdef D

        for ( pos2 = coast.begin(); pos2 != coast.end(); ++pos2 ) {
            printf ("%d %d\n", pos2->X, pos2->Y);
        }
        printf ("\n");
        
        #endif

        if ( pos == coast.begin() || Ok(pos, i) ) {
            in[ node[i].id ] = 1;
            stack[ ++nstack ] = i;
        }
    }
}

void Brute_Compute() {
    int i, j, no, a;
    for ( i=1; i<=L; ++i ) {
        scanf ("%d", &a);
        no = 0;
        for ( j=1; j<=N; ++j ) {
            if ( node[j].d[0] < node[a].d[0] &&
                node[j].d[1] < node[a].d[1] && node[j].d[2] < node[a].d[2] ) {

                printf ("NO\n");
                no = 1;
                break;
            }
        }
        if ( no==0 ) {
            printf ("YES\n");
        }
    }
}
int main ( void ) {
#ifdef D
    freopen ("input","r",stdin);
#endif
    freopen ("souvlakia.in","r",stdin);
    freopen ("souvlakia.out","w",stdout);
    Read();
    Dijkstra ( A, 0 );
    Dijkstra ( B, 1 );
    Dijkstra ( C, 2 );
    if ( (llint)N*(llint)L <= SAFE ) {
        Brute_Compute();
    }
    else {
        Compute();
        Print();
    }
    return 0;
}

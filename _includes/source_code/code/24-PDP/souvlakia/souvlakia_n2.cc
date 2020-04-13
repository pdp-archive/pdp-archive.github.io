#include <cstdio>
#include <algorithm>
#include <climits>
#include <cassert>
#include <vector>
#include <list>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const long 
    MAXN = long(1e5),    //max shops
    MAXQ = long(5e4),    //max queries
    INF  = LONG_MAX;    //INF for dijkstra
    
long    N,M,Q,C[3];

struct shop {
#define X  d[0]
#define Y  d[1]
#define Z  d[2]
    long d[3];//The 3 distances (X,Y,Z) from {A,B,C}
    shop(){ X=Y=Z=INF; }//help dijsktra initial values
} S[MAXN+1];

void dijsktra(long src,long dupd,vector<vector<pair<long,long>>>& edge){
    //src is one of {A,B,C}
    //dupd in [0,3). Update Shop[*].d[dupd] distance from src
    set<pair<long,long>> DS;//<distance,shopid> like a priority queue
    
    DS.insert({0,src});
    S[src].d[dupd] = 0;
    
    while(!DS.empty()){//explore
        auto x = *(DS.begin());//head of priority queue
        DS.erase(DS.begin());
        long daddy = x.second;
        for(auto y : edge[daddy]){//expand graph
            long child = y.first, dist = y.second;
            if(S[daddy].d[dupd]!=INF && S[child].d[dupd] > S[daddy].d[dupd] + dist){
                //this is an improvement
                if(S[child].d[dupd]!=INF)//was it in the queue already?
                    DS.erase(DS.find({S[child].d[dupd],child}));
                S[child].d[dupd] = S[daddy].d[dupd] + dist;
                DS.insert({S[child].d[dupd],child});
            }
        }
    }
}

int main(){
#ifdef CONTEST
    freopen("souvlakia.in", "r",stdin);
    freopen("souvlakia.out","w",stdout);
#endif
    scanf("%ld%ld",&N,&M);
    
    {//hint: edge vector below is temporary 
        //max mem usage: 400.000 * 2 * 3 * sizeof(long) = 2.400.000 * sizeof(long) = 19.2Mb
        //and we definitely benefit our program by releasing this mem when no more required
        //if we use a dynamic allocated scheme for implicit segment tree or use map template
        vector<vector<pair<long,long>>> edge(N+1);//<edge_to, distance>
        for(long a,b,d,i=0;i<M;++i){
            scanf("%ld%ld%ld",&a,&b,&d);
            edge[a].push_back({b,d});
            edge[b].push_back({a,d});
        }
        scanf("%ld%ld%ld%ld",&C[0],&C[1],&C[2],&Q);

        for(long i=0;i<3;++i)
            dijsktra(C[i],i,edge);
    }//memory of edge vector is released

    //read queries and store reference so we can answer offline
    for(long q,i=0;i<Q;++i){
        scanf("%ld",&q);
        bool capable = true;
        for(long i=1;i<=N;i++){
            if(i == q)continue;
            if(S[i].X<S[q].X && S[i].Y<S[q].Y && S[i].Z<S[q].Z){
                capable = false;
                break;
            }
        }    
        printf(capable?"YES\n":"NO\n");
    }
    return 0;
}

#ifdef CONTEST
    #define NDEBUG    //disable assert() checks
#endif

#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <cassert>
#include <vector>
#include <list>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int32_t 
    MAXN = int32_t(1e5),//max shops
    MAXQ = int32_t(5e4),//max queries
    INF  = INT32_MAX;  //INF for dijkstra
int32_t
    N,M,Q,C[3];

struct shop {
#define X  d[0]
#define Y  d[1]
#define Z  d[2]
    int32_t d[3];//The 3 distances (X,Y,Z) from {A,B,C}
    list<int32_t> queryid;//query ids that has to answer shop[i]
            //use list in case there are more than one queries per shop
    shop(){ X=Y=Z=INF; }//help dijsktra initial values
    bool operator <(const shop& b) const { 
        return X < b.X;
    }
} S[MAXN+1];

void dijsktra(int32_t src,int dupd,vector<vector<pair<int32_t,int32_t>>>& edge){
    //src is one of {A,B,C}
    //dupd in [0,3). Update Shop[*].d[dupd] distance from src
    set<pair<int32_t,int32_t>> DS;//<distance,shopid>
    
    DS.insert({0,src});
    S[src].d[dupd] = 0;
    
    while(!DS.empty()){//explore
        auto x = *(DS.begin());
        DS.erase(DS.begin());
        int32_t daddy = x.second;
        for(auto y : edge[daddy]){//expand
            int32_t child = y.first, dist = y.second;
            if(S[daddy].d[dupd]!=INF && S[child].d[dupd] > S[daddy].d[dupd] + dist){
                if(S[child].d[dupd]!=INF)
                    DS.erase(DS.find({S[child].d[dupd],child}));
                S[child].d[dupd] = S[daddy].d[dupd] + dist;
                DS.insert({S[child].d[dupd],child});
            }
        }
    }
}

inline int32_t read_fast(){//γρήγορη είσοδος/έξοδος από τα αρχεία in/out
    int32_t x = 0;
    char c;
    while((c=getchar_unlocked())<'0');//skip blanks
    do
        x = x*10 + (c-'0');
    while((c=getchar_unlocked())>='0');
    return x;
}

inline void write_fast(bool f){
    const char *s = f ? "YES\n":"NO\n";
    while(*s)
        putchar_unlocked(*s++);
}

//RMQ με χρήση Binary Indexed Tree και compressed Y τιμές
int32_t *BIT;
int32_t YMAX = 1; //μέγιστος αριθμός από διαφορετικές τιμές y
void compress_Yvalues(){
    map<int32_t,int32_t> compressY;//map ασυμπίεστες Y σε συμπιεσμένες τιμές
    
    //βρες τις διαφορετικές τιμές y
    for(int i=1;i<=N;i++)//O(NlogN) εισαγωγή το πολύ N τιμων
        compressY[S[i].Y];
    
    //συμπίεσε τα y αλλά κράτησε τη διάταξη τους
    for(auto it=compressY.begin();it!=compressY.end();it++)//O(N)
        it->second = YMAX++;
    
    //αντικατέστησε στα καταστήματα τα y
    for(int32_t i=1;i<=N;i++)//O(NlogN)
        S[i].Y = compressY[S[i].Y];
}

void sinit(){
    compress_Yvalues();    
    YMAX += 3;//το BIT έχει πεδίο ορισμού από το 1. Κάνουμε ολίσθηση ώστε να μετρά από το -1
    BIT = new int32_t[YMAX+1];
    memset(BIT,0x7f,sizeof(*BIT)*(YMAX+1));
}
int32_t squery(int32_t y){
    int32_t ymin = BIT[0];
    y+=2;
    while(y>0){
        ymin = min(ymin,BIT[y]);
        y -= y & -y;
    }
    return ymin;
}
void supdate(int32_t y,int32_t z){
    y+=2;
    while(y<=YMAX){
        BIT[y] = min(BIT[y],z);
        y += y & -y;
    }
}

int main(){
#ifdef CONTEST
    freopen("souvlakia.in", "r",stdin);
    freopen("souvlakia.out","w",stdout);
#endif
    N = read_fast(), M = read_fast();
    
    {//hint: edge vector below is temporary
        vector<vector<pair<int32_t,int32_t>>> edge(N+1);//<edge_to, distance>
        for(int32_t a,b,d,i=0;i<M;++i){
            a = read_fast(), b = read_fast(), d = read_fast();
            edge[a].push_back({b,d});
            edge[b].push_back({a,d});
        }
        for(int32_t i=0;i<3;i++)
            C[i]=read_fast();
        Q = read_fast();

        for(int i=0;i<3;++i)
            dijsktra(C[i],i,edge);
    }//memory of edge vector is released

    //read queries and store reference so we can answer offline
    for(int32_t i=0;i<Q;++i)
        S[read_fast()].queryid.push_back(i);//shop[q] has to answer i-th query

    sort(S+1,S+N+1);

    vector<bool> ans(MAXQ+1,false);        //offline answers

    sinit();
    for(int32_t right = 1, left = 1; left <=N;){
        while(right<=N && S[right].X == S[left].X){
            //for all shops with equal X postpone updates updates
            const shop& s = S[right];
            bool capable = (squery(s.Y-1) >= s.Z);
            
            for(auto e:s.queryid)
                ans[e] = capable;
            right++;
        }
        while(left<right){//do the postponed updates
            supdate(S[left].Y, S[left].Z);
            left++;
        }
    }
    
    for(int32_t i=0;i<Q;++i)
        write_fast(ans[i]);
    
    return 0;
}

/*
    complexity
        N=vertices, M=edges, D=values (width of segment tree)
        dijsktra:         O((N+M) * logN)
        sort shops:         O(NlogN)
        answer 1 query:        O(log(20000*N))
        (we have a maximum of 20000*N distinct Y values in the seg tree)
        answer all queries:    O(Nlog(20000*N))
        print queries:        O(Q)
        
        overall complexity:    O((N+M)logN + Nlog(20000N) + Q)
*/

#ifdef CONTEST
    #define NDEBUG    //disable assert() checks
#else
    #define getchar_unlocked    getchar
    #define putchar_unlocked    putchar
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
    MAXN = int32_t(1e5),    //max shops
    MAXQ = int32_t(5e4),    //max queries
    INF  = INT32_MAX;    //INF for dijkstra
int32_t    N,M,Q,C[3];

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
    set<pair<int32_t,int32_t>> DS;//<distance,shopid> like a priority queue
    
    DS.insert({0,src});
    S[src].d[dupd] = 0;
    
    while(!DS.empty()){//explore
        auto x = *(DS.begin());//head of priority queue
        DS.erase(DS.begin());
        int32_t daddy = x.second;
        for(auto y : edge[daddy]){//expand graph
            int32_t child = y.first, dist = y.second;
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

inline int32_t read_fast(){//fast IO is required for this problem due to huge io
    int32_t x = 0;
    char c;
    while((c=getchar_unlocked())<'0');//skip blank,CR,TF,TAB
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

//RMQ with implicit segment tree node and functions
//segment tree nodes are created upon request (by expand function)
//segment tree usage is RangeMinimumQuery for Y in [0,20000*MAXN] range
int32_t stn;//keep track of ST[] pool usage
const int32_t SMAX = MAXN * 30;//log2(MAXN * D) == 30
const int32_t YMAX = int32_t(2e4)*MAXN;    //max value of Y

struct node {//implicit segment tree (lazy build)
    int32_t left,right;//Y limits that this node handles
    int32_t minZ;//min Shop.Z value of segment tree
    int32_t leftptr,rightptr;//"pointers" to the children 
        
    node(int32_t le,int32_t ri,int32_t z){
        left = le, right = ri, minZ = z;
        leftptr = rightptr = 0;
    }
    node(){}
} st[SMAX];

void sinit(){
    st[0] = node(0,YMAX,INF);//root node
}
void expand(int32_t root){
    node& s = st[root];
    if(!s.leftptr && s.left<s.right){
        int32_t mid = (s.left + s.right)/2;
        assert(stn + 2 < SMAX);
        st[s.leftptr = ++stn] = node(s.left,mid,s.minZ);
        st[s.rightptr= ++stn] = node(mid+1,s.right,s.minZ);
    }
}
int32_t squery(int32_t y,int32_t root = 0){
    node& s = st[root];
    if(s.right <= y)//completely involved
        return s.minZ;
    if(y < s.left)//not involved
        return INF;
    expand(root);
    assert(s.leftptr);assert(s.rightptr);
    return min(squery(y,s.leftptr),squery(y,s.rightptr));
}
void supdate(int32_t y,int32_t z,int32_t root = 0){
    node& s = st[root];    
    s.minZ = min(s.minZ,z);
    if(s.right == y)
        return;//no need to build below
    expand(root);
    if(s.leftptr){
        if(y <= st[s.leftptr].right)
            supdate(y,z,s.leftptr);
        else
            supdate(y,z,s.rightptr);    
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
        for(int i=0;i<3;i++){
            C[i]=read_fast();
            dijsktra(C[i],i,edge);
        }
        Q = read_fast();
    }//memory of edge vector is released

    //read queries and store reference so we can answer offline
    for(int32_t i=0;i<Q;++i)
        S[read_fast()].queryid.push_back(i);//shop[q] has to answer i-th query

    sort(S+1,S+N+1);

    vector<bool> ans(MAXQ+1,false);        //offline answers

    sinit();
    for(int32_t right = 1, left = 1; left <=N;){
        while(right<=N && S[right].X == S[left].X){
            //for all shops with equal X postpone updates
            const shop& s = S[right];
            bool capable = (squery(s.Y-1) >= s.Z);

            for(auto e:s.queryid)
                ans[e] = capable;
            right++;
        }
        while(left<right){//do postponed updates
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
        N=vertices, M=edges, D=valus (width of segment tree)
        dijsktra:         O((N+M) * logN)
        sort shops:         O(NlogN)
        answer 1 query:        O(logN)
        (we have a maximum of N distinct Y values in the segment tree)
        answer all queries:    O(NlogN)
        print queries:        O(Q)
        
        overall complexity:    O((N+M)logN + Q)
*/

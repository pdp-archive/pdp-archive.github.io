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
    MAXN = int32_t(1e5),    //καταστήματα
    MAXQ = int32_t(5e4),    //queries
    INF  = INT32_MAX;       //INF για Dijkstra
    
int32_t N,M,Q,C[3];

struct shop {
#define X  d[0]
#define Y  d[1]
#define Z  d[2]
    int32_t d[3];//το triplet των αποστάσεων
    list<int32_t> queryid;//τα query ids που απαντά το τρέχον κατάστημα
            //αποθηκευμένα σε λίστα μήπως υπάρχουν πάνω από 
            //ενα querυ για το ίδιο κατάστημα
    shop(){ X=Y=Z=INF; }//αρχικές τιμές για Dijsktra
    bool operator <(const shop& b) const { 
        return X < b.X;
    }
} S[MAXN+1];

void dijsktra(int32_t src,int dupd,vector<vector<pair<int32_t,int32_t>>>& edge){
    //src είναι το τρέχον προεπιλεγμένο κατάστημα
    //dupd είναι η θέση στον πίνακα Shop[*].d[dupd] που θα ενημερωθεί
    set<pair<int32_t,int32_t>> DS;//<distance,shopid> χρήση σαν priority queue
    
    DS.insert({0,src});
    S[src].d[dupd] = 0;
    
    while(!DS.empty()){
        auto x = *(DS.begin());
        DS.erase(DS.begin());
        int32_t daddy = x.second;
        for(auto y : edge[daddy]){
            int32_t child = y.first, dist = y.second;
            if(S[daddy].d[dupd]!=INF && S[child].d[dupd] > S[daddy].d[dupd] + dist){
                //υπήρξε βελτίωση
                if(S[child].d[dupd]!=INF)//υπήρχε στην "queue"?
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
    while((c=getchar_unlocked())<'0');//skip blanks, CR, LF
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

//Instead of a RMQ we should consider that we only need to store on the increasing 
//sequence of Y line, the corresponding descending sequence of Z values. 
//In fact forevery Y<Y' <=> Z>Z' (stricly descreasing subsequence)
//So let's make it in a map of Y values to Z
map<int32_t,int32_t> Zmin;

void sinit(){
    //προσθήκη δυο ακραίων τιμών στο map ώστε να μην χρειάζεται να ελέγχουμε 
    //αν φτάσαμε στα όρια begin(), end().
    Zmin.insert({-2,INF});//κάτω όριο για τα queries
    Zmin.insert({INF,-1});//άνω όριο για να μην φτάσουμε στο end()
}
int32_t squery(int32_t y){
    auto it = Zmin.lower_bound(y-1);
    while(it->first >= y)it--;
    return it->second;
}
void supdate(int32_t y,int32_t z){
    auto curr = Zmin.lower_bound(y);
    while(curr->first > y)curr--;
    if(curr->second <= z)
        return;//αγνόησε το
    else if(curr->first == y)//βελτίωσε προηγούμενο σημείο
        curr->second = z;
    else //εισαγωγή του νέου σημείου
        curr = (Zmin.insert({y,z})).first;
    
    //βελτιστοποίησε προς τα δεξιά
    auto next = ++curr;
    while(next->second >= z)
        next++;
    Zmin.erase(curr,next);//std::map διαγραφή περιοχής
}

int main(){
#ifdef CONTEST
    freopen("souvlakia.in", "r",stdin);
    freopen("souvlakia.out","w",stdout);
#endif
    N = read_fast(), M = read_fast();
    
    {//το vector παρακάτω δεσμεύει μνήμη μέχρι το κλείσιμο αυτού του bracket
        //δηλαδή 400.000 * 2 * 3 * sizeof(long) = 2.400.000 * sizeof(int32_t)
        vector<vector<pair<int32_t,int32_t>>> edge(N+1);//<edge_to, distance>
        for(int32_t a,b,d,i=0;i<M;++i){
            a = read_fast(), b = read_fast(), d = read_fast();
            edge[a].push_back({b,d});
            edge[b].push_back({a,d});
        }
        for(int i=0;i<3;i++)
            C[i] = read_fast();
        Q = read_fast();

        for(int i=0;i<3;++i)
            dijsktra(C[i],i,edge);
    }//η μνήμη του vector απελευθερώθηκε (destructor called)

    //αποθήκευσε ερωτήματα για να απαντήσουμε offline
    for(int32_t i=0;i<Q;++i)
        S[read_fast()].queryid.push_back(i);//το shop[q] να απαντήσει το i ερώτημα

    sort(S+1,S+N+1);

    vector<bool> ans(MAXQ+1,false);        //offline απαντήσεις

    sinit();
    for(int32_t right = 1, left = 1; left <=N;){
        while(right<=N && S[right].X == S[left].X){
            //καθηστέρησε τα updates των καταστημάτων με ίδιο X
            const shop& s = S[right];
            bool capable = (squery(s.Y-1) >= s.Z);
            
            for(auto e:s.queryid)
                ans[e] = capable;
            right++;
        }
        while(left<right){//εκτέλεσε τα updates της ομάδας
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
        (we have a maximum of N distinct Y values in the map)
        answer all queries:    O(NlogN)
        print queries:        O(Q)
        
        overall complexity:    O((N+M)logN + Q)
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const int MAXNM = 700;
struct pt {
    int x,y;
    pt(int x=0,int y=0):x(x),y(y){}
} ho,po,yo;//ho(me),po(liceman),yo(u)
int T,XM,YN;//XM=στήλες, YN=γραμμές

struct cell {
    long hview,vview; //ώρες θέασης κελιού από οριζόντια και κατακόρυφη επόπτευση
    bool you_visit; //δικιά μας επίσκεψη
    bool pol_visit; //επίσκεψη αστυνομικού
    char c;//χαρακτηριστικό κελιού του grid
    
    void init(){ 
        c = '#';//εκτός grid 
        hview = vview = LONG_MAX; 
        you_visit = pol_visit = false; 
    }
    inline bool is_road() const { return c!='#'; }
    inline bool is_home() const { return c=='H'; }
} G[MAXNM+2][MAXNM+2];//grid
/*
 * Το grid του προβλήματος εκτείνεται από 
 * θέση (1,1) έως (Ν,Μ). Δεσμεύονται οι περιμετρικές γραμμές του
 * grid ώστε να γίνεται εύκολος ο έλεγχος στα άκρα.
 * Οι περιμετρικές γραμμές έχουν '#' (building)
 * οπότε γίνεται απλός ο έλεγχος αν μια θέση βρίσκεται εντός ή εκτός grid.
 * Λόγω των επιπλέον περιμετρικών γραμμών, ο πίνακας μας απαιτεί 2 επιπλέον
 * στοιχεία, οπότε δεσμεύεται ως G[MAXNM+2][MAXNM+2]
 */

#define min3(a,b,c) min(min((a),(b)),(c))

//Κίνηση αστυνομικού
void pol_go(queue<pt>& Q,int x,int y){//επόμενο βήμα αστυνόμου
    if(G[x][y].is_road() && !G[x][y].pol_visit)
        Q.push(pt(x,y)), G[x][y].pol_visit = true;
}

void pol_bfs(){//bfs αστυνόμου
    queue<pt> Q;
    Q.push(po);
    long tim = 0;//time stamp
    while(!Q.empty()){
        for(size_t sz = Q.size(),i=0;i<sz;i++){
            int x = Q.front().x, y = Q.front().y; Q.pop();
            //ανάκτησε ώρες θέασης τρέχοντος κελιού από τα γειτονικά κελιά
            G[x][y].hview = min3(G[x-1][y].hview, G[x+1][y].hview, tim);
            G[x][y].vview = min3(G[x][y-1].vview, G[x][y+1].vview, tim);
            //επισκέψου τα επόμενα κελιά
            pol_go(Q,x+1,y);
            pol_go(Q,x-1,y);
            pol_go(Q,x,y+1);
            pol_go(Q,x,y-1);
        }
        tim++;
    }
}

//Κίνηση δικιά μας
void you_go(queue<pt>& Q,int x,int y,int tim){//επόμενο βήμα δικό μας
    if(G[x][y].is_road() && !G[x][y].you_visit &&
        tim<G[x][y].hview && tim<G[x][y].vview)
        Q.push(pt(x,y)), G[x][y].you_visit=true;
}

bool you_bfs(){
    queue<pt> Q;
    Q.push(yo);
    long tim = 0;
    while(!Q.empty()){
        tim++;//σε αυτό το χρόνο θα γίνουν οι επομενες κινησεις
        for(size_t sz = Q.size(),i=0;i<sz;i++){
            int x = Q.front().x, y = Q.front().y; Q.pop();
            if(G[x][y].is_home())
                return true;
            you_go(Q,x+1,y,tim);
            you_go(Q,x-1,y,tim);
            you_go(Q,x,y+1,tim);
            you_go(Q,x,y-1,tim);
        }
    }
    return false;
}

void init(){//αρχικοποίηση για νεο σεναριο
    for(int y=0,yn=YN+2;y<yn;y++)
        for(int x=0,xm=XM+2;x<xm;x++)
            G[x][y].init();
}

int main(){
    freopen("wayhome.in", "r",stdin);
    freopen("wayhome.out","w",stdout);
    scanf("%d",&T);
        
    while(T--){
        scanf("%d%d",&YN,&XM);
        init();
        for(int y=1;y<=YN;y++){
            char s[MAXNM+1];
            scanf(" %s",s);
            for(int x=1;x<=XM;x++){
                switch(G[x][y].c = s[x-1]){
                    case 'Y': yo = pt(x,y); break;
                    case 'P': po = pt(x,y); break;
                    case 'H': ho = pt(x,y); break;
                }
            }
        }
        pol_bfs();
        printf(you_bfs()?"YES\n":"NO\n");
    }
    return 0;
}


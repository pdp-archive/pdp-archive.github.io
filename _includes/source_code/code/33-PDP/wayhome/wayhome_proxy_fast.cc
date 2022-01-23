#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXNM = 700;
int T,XM,YN;//XM=στήλες, YN=γραμμές

typedef pair<int,int> pt;
#define xx  first
#define yy  second
pt ho,po,yo;//ho(me),po(liceman),yo(u)

char cell[MAXNM+2][MAXNM+2];
int leftmost[MAXNM+2][MAXNM+2],//αριστερότερο ορατό κελί της σειράς y και
    topmost [MAXNM+2][MAXNM+2];// κορυφαίο ορατό της στήλης x του κάθε κελιού x,y
inline bool is_road(int x,int y) { return cell[x][y] != '#'; }
inline bool is_home(int x,int y) { return cell[x][y] == 'H'; }

bool pol_visit[MAXNM+2][MAXNM+2], you_visit[MAXNM+2][MAXNM+2];
long hview[MAXNM+2][MAXNM+2];//χρόνική στιγμή οριζόντιας και
long vview[MAXNM+2][MAXNM+2];//κατακόρυφης θέασης κελιών

//Κίνηση αστυνομικού
void pol_go(queue<pt>& Q,int x,int y){//επόμενο βήμα αστυνόμου
    if(is_road(x,y) && !pol_visit[x][y])
        Q.push({x,y}), pol_visit[x][y] = true;
}

void pol_bfs(){//bfs αστυνόμου
    queue<pt> Q;
    Q.push(po);
    long tim = 0;//time stamp
    while(!Q.empty()){
        for(size_t sz = Q.size(),i=0;i<sz;i++){
            int x = Q.front().xx, y = Q.front().yy; Q.pop();
            //ενημέρωσε ώρες θέασης της ομάδας
            hview[leftmost[x][y]][y] = min(hview[leftmost[x][y]][y],tim);
            vview[x][topmost [x][y]] = min(vview[x][topmost [x][y]],tim);
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
    if(!is_road(x,y) || you_visit[x][y]) 
        return;
    if(tim<hview[leftmost[x][y]][y] && tim<vview[x][topmost[x][y]])
        Q.push({x,y}), you_visit[x][y] = true;
}

bool you_bfs(){
    queue<pt> Q;
    Q.push(yo);
    long tim = 0;
    while(!Q.empty()){
        tim++;//σε αυτό το χρόνο θα γίνουν οι επομενες κινησεις
        for(size_t sz = Q.size(),i=0;i<sz;i++){
            int x = Q.front().xx, y = Q.front().yy; Q.pop();
            if(is_home(x,y))
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
    memset(pol_visit,0,sizeof(pol_visit));//αρχικοποίηση σε false
    memset(you_visit,0,sizeof(you_visit));
    memset(hview,0x7f,sizeof(hview));//αρχικοποίηση σε πολύ μεγάλη τιμή
    memset(vview,0x7f,sizeof(vview));
    memset(cell,'#',sizeof(cell));
}

int main(){
    freopen("wayhome.in", "r",stdin);
    freopen("wayhome.out","w",stdout);
    scanf("%d",&T);
        
    while(T--){
        scanf("%d%d",&YN,&XM);
        init();
        vector<int> left(YN+2,1), top(XM+2,1);
        for(int y=1;y<=YN;y++){
            char s[MAXNM+1];
            scanf(" %s",s);
            for(int x=1;x<=XM;x++){
                switch(cell[x][y] = s[x-1]){
                    case 'Y': yo = {x,y}; break;
                    case 'P': po = {x,y}; break;
                    case 'H': ho = {x,y}; break;
                    case '#'://βρέθηκε κτίριο
                            top [x] = y+1;//ενημέρωσε το τρέχον αριστερότερο
                            left[y] = x+1;//και κορυφαίο ορατό κελί
                            break;
                }
                if(is_road(x,y)){//ενημέρωσε το κελί για τους 2 εκπροσώπους του
                    leftmost[x][y] = left[y];
                    topmost [x][y] = top [x];
                }
            }
        }
        
        pol_bfs();
        printf(you_bfs()?"YES\n":"NO\n");
    }
    return 0;
}


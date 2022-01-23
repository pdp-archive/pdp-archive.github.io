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

bool go_home(){
    int po_time = min(abs(po.x-ho.x),abs(po.y-ho.y));
    int yo_time = abs(yo.x-ho.x) + abs(yo.y-ho.y);
    return yo_time<po_time;
}

int main(){
    freopen("wayhome.in", "r",stdin);
    freopen("wayhome.out","w",stdout);
    scanf("%d",&T);
        
    while(T--){
        scanf("%d%d",&YN,&XM);
        for(int y=1;y<=YN;y++){
            char s[MAXNM+1];
            scanf(" %s",s);
            for(int x=1;x<=XM;x++){
                switch(s[x-1]){
                    case 'Y': yo = pt(x,y); break;
                    case 'P': po = pt(x,y); break;
                    case 'H': ho = pt(x,y); break;
                }
            }
        }
        printf(go_home()?"YES\n":"NO\n");
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

const int RMAX = 1000, CMAX = 1000;
int R,C;//R=rows(γραμμές), C=columns(στήλες)
char G[RMAX][CMAX+1];//το +1 για την αποθήκευση του τελικού '\0' στο string

struct dj_team {
    long head;//εκπρόσωπος ομάδας
    long count;//πλήθος ομάδας
    bool escapes;//αν η ομάδα έχει διέξοδο
} dj[RMAX * CMAX];
long ans;

inline long yx(int y,int x){//μετέτρεψε την 2D συντεταγμένη σε 1D
    return long(y)*C + x;
}

long dj_find(long yx){
    if(dj[yx].head==yx)
        return yx;
    return dj[yx].head = dj_find(dj[yx].head);
}

void dj_escapes(int yx){//μάρκαρε την ομάδα του yx ότι έχει διέξοδο
    dj[dj_find(yx)].escapes = true;
}

bool dj_union(long yx1,long yx2){
    yx1 = dj_find(yx1), yx2 = dj_find(yx2);
    if(yx1!=yx2){
        if(dj[yx1].count<dj[yx2].count)
            std::swap(yx1,yx2);
        dj[yx1].count   += dj[yx2].count;
        dj[yx1].escapes |= dj[yx2].escapes;
        dj[yx2].head    = yx1;
        return true;
    }
    return false;
}

int main(){
    freopen("fairmaze.in","r",stdin);
    freopen("fairmaze.out","w",stdout);

    scanf("%d%d",&R,&C);
    for(long i=0,n=R*C;i<n;i++){
        dj[i].head  = i;
        dj[i].count = 1;
    }    

    ans = C * R;//όλοι οι κόμβοι
    
    struct checks {
        char edge;//τιμή ακμής εξόδου για διέξοδο
        int dy,dx;
    } Z[] = {
        {'U',-1, 0},
        {'D', 1, 0},
        {'L', 0,-1},
        {'R', 0, 1},
    };
    
    for(int y=0;y<R;y++){
        scanf(" %s",G[y]);
        for(int x=0;x<C;x++){
            long yx1 = dj_find(yx(y,x));
            for(const auto& test:Z){
                if(test.edge == G[y][x]){
                    int ydest=y+test.dy, xdest=x+test.dx;
                    if(ydest<0||ydest==R||xdest<0||xdest==C){
                        if(!dj[yx1].escapes)
                            ans -= dj[yx1].count;
                        dj_escapes(yx1);
                    }else {
                        long yx2 = dj_find(yx(ydest,xdest));
                        if(yx1!=yx2){
                            //αφαίρεσε τις ομάδες από το ans πριν την ένωση αν χρειάζεται
                            if(!dj[yx1].escapes) ans-=dj[yx1].count;
                            if(!dj[yx2].escapes) ans-=dj[yx2].count;
                            //συνένωσε τις ομάδες
                            dj_union(yx1,yx2);
                            //ενημέρωσε το ans με την ενωμένη ομάδα αν χρειάζεται
                            yx1 = dj_find(yx1);
                            if(!dj[yx1].escapes) ans+=dj[yx1].count;
                        }
                    }
                }
            }//έλεγχος κατεύθυνσης ακμής εξόδου
        }//x (column)
    }//y (row)

    printf("%ld\n",ans);
    return 0;
}

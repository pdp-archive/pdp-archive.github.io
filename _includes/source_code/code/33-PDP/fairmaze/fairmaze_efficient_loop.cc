#include <cstdio>

const int RMAX = 1000, CMAX = 1000;
int R,C;//R=rows(γραμμές), C=columns(στήλες)
char G[RMAX][CMAX+1];//το +1 για την αποθήκευση του τελικού '\0' στο string
bool visit[RMAX][CMAX],escapes[RMAX][CMAX];

struct step {
    int y,x;
    step(int y,int x):y(y),x(x){}
    step(){}
} path[RMAX*CMAX];
int path_count;

bool dfs(int y,int x){
    if(visit[y][x])//έχουμε εξερευνήσει τον κόμβο
        return escapes[y][x];
    
    bool result = false;
    path_count = 0;
    
    while(true){
        //αποθήκευσε τη διαδρομή που εξερευνούμε στο path[]
        //ώστε στο "γυρισμό" να αποθηκεύσουμε το αποτέλεσμα
        path[path_count++] = step(y,x);
        
        visit[y][x] = true;
        switch(G[y][x]){
            case 'U':y--;break;
            case 'D':y++;break;
            case 'L':x--;break;
            case 'R':x++;break;
        }
        if(y<0||x<0 || x>=C||y>=R){
            result = true;//βρήκαμε διέξοδο
            break;
        }
        if(visit[y][x]){//τον έχουμε εξερευνήσει
            result = escapes[y][x];
            break;
        }
    }
    
    if(result)
        for(int i=0;i<path_count;i++)
            escapes[path[i].y][path[i].x] = result;
        
    return result;
}

int main(){
    freopen("fairmaze.in","r",stdin);
    freopen("fairmaze.out","w",stdout);
    scanf("%d%d",&R,&C);
        
    for(int y=0;y<R;y++)
        scanf(" %s",G[y]);
    
    long ans = R * C;
    for(int y=0;y<R;y++)
        for(int x=0;x<C;x++)
            if(dfs(y,x))
                ans--;

    printf("%ld\n",ans);
    return 0;
}

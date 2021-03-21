#include <cstdio>

const int RMAX = 1000, CMAX = 1000;
int R,C;//R=rows(γραμμές), C=columns(στήλες)
char G[RMAX][CMAX+1];//το +1 για την αποθήκευση του τελικού '\0' στο string
bool visit[RMAX][CMAX], escapes[RMAX][CMAX];

bool dfs(int y,int x){//true if escapes
    if(y<0||x<0 || x>=C||y>=R)
        return true;
    if(visit[y][x])//έχουμε υπολογίσει τη διαδρομή από εδώ και μετά
        return escapes[y][x];//άρα ξέρουμε αν βγαίνουμε εκτός
        
    visit[y][x] = true;//αν η dfs βρεί κάποιον ατέρμονο κύκλο
    bool result = false;//θα επιστρέψει false
    switch(G[y][x]){
        case 'U':result = dfs(y-1,x);break;
        case 'D':result = dfs(y+1,x);break;
        case 'L':result = dfs(y,x-1);break;
        case 'R':result = dfs(y,x+1);break;
    }
    return escapes[y][x] = result;
}

int main(){
    freopen("fairmaze.in","r",stdin);
    freopen("fairmaze.out","w",stdout);
    scanf("%d%d",&R,&C);
        
    for(int y=0;y<R;y++)
        scanf(" %s",G[y]);
    
    long ans = R*C;
    for(int y=0;y<R;y++)
        for(int x=0;x<C;x++)
            if(dfs(y,x))
                ans--;

    printf("%ld\n",ans);
    return 0;
}

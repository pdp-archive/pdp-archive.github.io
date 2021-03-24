#include <cstdio>

const int RMAX = 1000, CMAX = 1000;
int R,C;//R=rows(γραμμές), C=columns(στήλες)
char G[RMAX][CMAX+1];//το +1 για την αποθήκευση του τελικού '\0' στο string
bool visit[RMAX][CMAX];

long dfs(int y,int x,char exit){
    //ο κόμβος στη γραμμή y και στήλη x αν έχει τιμή exit, έχει πρόσβαση σε έξοδο
    //θα επιστρέψουμε πόσους κόμβους βρήκαμε στην ομάδα, που έχουν έξοδο
    if(y<0||x<0 || x>=C||y>=R || visit[y][x] || G[y][x]!=exit)
        return 0;
    visit[y][x] = true;
    return 1L+dfs(y-1,x,'D') + dfs(y+1,x,'U') + dfs(y,x-1,'R') + dfs(y,x+1,'L');
}

int main(){
    freopen("fairmaze.in","r",stdin);
    freopen("fairmaze.out","w",stdout);
    scanf("%d%d",&R,&C);
        
    for(int y=0;y<R;y++)
        scanf(" %s",G[y]);
    
    long ans = R * C;
    for(int y=0;y<R;y++)
        ans -= dfs(y,0,'L') + dfs(y,C-1,'R');
    for(int x=0;x<C;x++)
        ans -= dfs(0,x,'U') + dfs(R-1,x,'D');

    printf("%ld\n",ans);
    return 0;
}

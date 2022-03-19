#include <cstdio>
#include <stack>

using namespace std;

const int RMAX = 1000, CMAX = 1000;
int R,C;//R=rows(γραμμές), C=columns(στήλες)
char G[RMAX][CMAX+1];//το +1 για την αποθήκευση του τελικού '\0' στο string
bool visit[RMAX][CMAX];

struct test {
    int x,y;
    char escape_path;
    test(int y,int x,char escape_path):x(x),y(y),escape_path(escape_path){}
};

long dfs(int y,int x,char escape_path){
    //ο κόμβος στη γραμμή y και στήλη x αν έχει τιμή escape_path, έχει διέξοδο
    //θα επιστρέψουμε πόσους κόμβους βρήκαμε στην ομάδα, που έχουν διέξοδο
    long count = 0;
    stack<test> S;
    S.push(test(y,x,escape_path));
    
    while(!S.empty()){
        y = S.top().y, x = S.top().x, escape_path = S.top().escape_path;
        S.pop();
        if(y<0||x<0 || x>=C||y>=R || visit[y][x] || G[y][x]!=escape_path)
            continue;

        visit[y][x] = true;
        count++;
        S.push(test(y-1,x,'D'));
        S.push(test(y+1,x,'U'));
        S.push(test(y,x-1,'R'));
        S.push(test(y,x+1,'L'));
    }
    return count;
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

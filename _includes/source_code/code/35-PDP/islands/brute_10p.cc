#include <cstdio>
#include <vector>

using namespace std;

int main(){
    freopen("islands.in","r",stdin);
    freopen("islands.out","w",stdout);
    long N,Q,ans;
    scanf("%ld%ld",&N,&Q);
    vector<bool> Z(N+1,false);//πίνακας με τα απαιτούμενα εισιτήρια
    while(Q--){
        char c;long a,b;
        scanf(" %c%ld%ld",&c,&a,&b);
        switch(c){
        case 'D':
        case 'B':
            for(long i=a+1;i<=b;i++)
                Z[i] = (c == 'D');
            break;
        case 'Q':
            ans = a;
            while(ans<N && (!Z[ans+1] || b-->0))
                ans++;
            printf("%ld\n",ans);
            break;
        }
    }
    return 0;
}

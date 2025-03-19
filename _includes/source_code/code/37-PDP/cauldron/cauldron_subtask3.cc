#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
#ifdef CONTEST
    freopen("cauldron.in","r",stdin);
    freopen("cauldron.out","w",stdout);
#endif
    long t, N, K, c, w0;
    scanf("%ld%ld%ld%ld",&t,&N,&K,&c);
    ll ans = K;
    if(t==3){
        scanf("%ld",&w0);//διάβασε ποσότητα ζωμού ενός βάζου
        if(c>0){
            long jars = min(K/w0,N);
            ans += (ll)jars*c;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

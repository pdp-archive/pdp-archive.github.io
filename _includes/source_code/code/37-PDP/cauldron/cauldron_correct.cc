#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
#ifdef CONTEST
    freopen("cauldron.in","r",stdin);
    freopen("cauldron.out","w",stdout);
#endif
    long t, N, K, c;
    scanf("%ld%ld%ld%ld",&t,&N,&K,&c);
    vector<long> w(N);
    ll ans = K;
    for(auto& x:w)
        scanf("%ld",&x);
    if(c>0){
        sort(w.begin(),w.end());
        long Krem = K;//πόσο μαγικό νερό παραμένει στο καζάνι
        for(auto e:w){
            if(e<=Krem){
                ans += c;
                Krem -= e;
            } else break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
